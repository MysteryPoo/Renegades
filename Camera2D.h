#pragma once

#include "Transform.h"

class Camera2D
{
	Transform *follow;
public:
	Camera2D();
	Camera2D(Transform *follow);
	~Camera2D();
	void Assign(Transform *follow);
	void Unassign() { follow = nullptr; }
	Transform* getAssigned() { return follow; }
	void Update();
};