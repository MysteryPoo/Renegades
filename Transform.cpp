#include "Transform.h"
#include <math.h>
#include <agk.h>

Transform::Transform()
{
	Transform(0.0f, 0.0f);
}

Transform::Transform(float x, float y)
{
	Transform(x, y, 0.0f);
}

Transform::Transform(float x, float y, float direction)
{
	Transform(x, y, direction, 0.0f);
}

Transform::Transform(float x, float y, float direction, float speed)
{
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->speed = speed;
}

void Transform::Rotate(float direction)
{
	this->direction += direction;
}

void Transform::setSpeed(float speed)
{
	this->speed = speed;
}

void Transform::Update(float time)
{
	x += speed * time * agk::Cos(direction);
	y += speed * time * agk::Sin(direction);
}
