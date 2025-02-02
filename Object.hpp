#pragma once
#include "Vector2d.hpp"
#include "Colliders.hpp"

struct Object {
	Vector2d Position; // struct with 3 floats for x, y, z or i + j + k
	Vector2d Velocity;
	Vector2d Force;
	Collider* Collider;
	float Mass;
};