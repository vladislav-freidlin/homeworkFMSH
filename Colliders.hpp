#pragma once
#include "Vector2d.hpp"

enum ColliderType {
	SPHERE,
	PLANE
};

class Collider {
public:
	ColliderType Type;
	virtual void foo(){}
};

class SphereCollider : public Collider {
public:
	Vector2d Center;
	float Radius;
	void foo() override{}
};

class PlaneCollider : public Collider {
public:
	Vector2d Normal;
	float Distance;
	void foo() override{}
};