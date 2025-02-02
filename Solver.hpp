#pragma once 
#include <vector>
#include "Collision.hpp"

/*
struct CollisionPoints {
	Vector2d A; // Furthest point of A into B
	Vector2d B; // Furthest point of B into A
	Vector2d Normal; // B – A normalized
	float Depth;    // Length of B – A
	bool HasCollision;
};

struct Object {
	Vector2d Position; // struct with 3 floats for x, y, z or i + j + k
	Vector2d Velocity;
	Vector2d Force;
	Collider* Collider;
	float Mass;
};
*/



class Solver{
    public:
        virtual void solve(std::vector<Collision> colls)=0;       
};

class SSsolver: public Solver{
public:
    
};

class SPsolver: public Solver{

};