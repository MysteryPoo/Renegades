#pragma once

class Transform
{
	float x, y, direction, speed;
public:
	Transform();
	Transform(float x, float y);
	Transform(float x, float y, float direction);
	Transform(float x, float y, float direction, float speed);
	void Rotate(float direction);
	float getDirection() { return direction; }
	void setSpeed(float speed);
	float getSpeed() { return speed; }
	float getX() { return x; }
	float getY() { return y; }
	void Update(float time);
};