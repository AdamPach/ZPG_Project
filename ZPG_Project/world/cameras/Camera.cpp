#include "Camera.h"
#include <glm/ext/matrix_transform.hpp>

Camera::Camera(Projection* projection, glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
	Front = glm::vec3(0.0f, 0.0f, -1.0f);
	Speed = SPEED;

	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;

	this->projection = projection;
	projectionSubject.SetValue(projection->GetProjectionMatrix());

	positionSubject.SetValue(Position);
	UpdateCameraVectors();

	viewSubject.SetValue(GetViewMatrix());
}

Camera::~Camera()
{
	delete projection;
}

void Camera::ProcessKeyboardMovement(CameraMovement direction)
{
	float velocity = Speed * 0.1f;

	if (direction == FORWARD)
	{
		Position += Front * velocity;
	}
	if (direction == BACKWARD)
	{
		Position -= Front * velocity;
	}
	if (direction == LEFT)
	{
		Position -= Right * velocity;
	}
	if (direction == RIGHT)
	{
		Position += Right * velocity;
	}

	positionSubject.SetValue(Position);
	viewSubject.SetValue(GetViewMatrix());
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
	xoffset *= SENSITIVITY;
	yoffset *= SENSITIVITY;

	Yaw += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	UpdateCameraVectors();
	viewSubject.SetValue(GetViewMatrix());
}


UniformVariableSubject<glm::vec3>* Camera::GetPositionSubject()
{
	return &positionSubject;
}

UniformVariableSubject<glm::mat4>* Camera::GetProjectionSubject()
{
	return &projectionSubject;
}

UniformVariableSubject<glm::mat4>* Camera::GetViewSubject()
{
	return &viewSubject;
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::UpdateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}
