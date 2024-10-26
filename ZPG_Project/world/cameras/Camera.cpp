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
	UpdateCameraVectors();
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
	Notify();
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
	Notify();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return projection->GetProjectionMatrix();
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
