#pragma once


class MouseHandler
{
public:
	void HandleMouseMove(double xpos, double ypos);
	float GetXOffset();
	float GetYOffset();
private:
	double lastX = 0;
	double lastY = 0;
	double xoffset = 0;
	double yoffset = 0;
	bool firstMouse = true;
};