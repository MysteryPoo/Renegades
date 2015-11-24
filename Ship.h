#pragma once

#include "Transform.h"

class Ship
{
	int m_SpriteIndex;
	class app * AppRef;
public:
	Transform * t;
	Ship(class app * app);
	~Ship();
	void Update(float);
	float getDirection() { return t->getDirection(); }
	float getSpeed() { return t->getSpeed(); }
	float getX() { return t->getX(); };
	float getY() { return t->getY(); };
};