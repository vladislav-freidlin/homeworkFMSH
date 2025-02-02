#pragma once
#include "Vector2d.hpp"

struct CollisionPoints {
	Vector2d A; // Furthest point of A into B
	Vector2d B; // Furthest point of B into A
	Vector2d Normal; // B – A normalized
	float Depth;    // Length of B – A
	bool HasCollision;
};
 
struct Transform { // Describes an objects location
	Vector2d Position;
	Vector2d Scale;
	// Quaternion Rotation;
	Transform(const Vector2d &pos, const Vector2d &sc){
		this->Position = pos;
		this->Scale = sc;
	}
	Transform(){
		this->Position = {1, 0};
		this->Scale = {0, 0};
	}
};