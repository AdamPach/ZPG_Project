#pragma once

#include <glm/glm.hpp>

#include "../abstraction/Observer.h"

enum CameraMovement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;

class Camera : public Subject
{
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
	void ProcessKeyboardMovement(CameraMovement direction);
	void ProcessMouseMovement(float xoffset, float yoffset);
	glm::mat4 GetViewMatrix();
private:
	// Defines a position in the space where the camera is located
	glm::vec3 Position;
	// Defines a point where the camera is looking at !! Important the point is defined in the world space not in the camera space
	glm::vec3 Front;
	// A point in the space that is above the camera, which is used to determine the roll of the camera
	glm::vec3 Up;
	// A point in the space that is to the right of the camera, which is used to determine the roll of the camera
	glm::vec3 Right;
	// A point in the space that is above the camera, which is used to determine the roll of the camera
	glm::vec3 WorldUp;

	float Pitch;
	float Yaw;
	float Speed;

	void UpdateCameraVectors();
};

