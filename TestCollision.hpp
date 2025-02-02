#pragma once

#include "Transform.hpp"
#include "Colliders.hpp"
#include <cmath>
#include <utility>

// реализуйте эти функции
CollisionPoints Test_Sphere_Sphere(
	Collider* a, const Transform* ta,
	Collider* b, const Transform* tb){
		SphereCollider* spc1 = dynamic_cast<SphereCollider*>(a);
		SphereCollider* spc2 = dynamic_cast<SphereCollider*>(b);

		spc1->Center += ta->Position;
		spc2->Center += tb->Position;

		float o1o2 = std::pow(std::pow(spc1->Center.x - spc2->Center.x, 2) + std::pow(spc1->Center.y - spc2->Center.y, 2) , 0.5);
		float o1a = o1o2 - spc1->Radius;
		float o2b = o1o2 - spc2->Radius;
		
		Vector2d A = {spc1->Center.x + o1a, spc2->Center.y + o1a};
		Vector2d B = {spc1->Center.x - o2b, spc2->Center.y - o2b};

		return {A, B, A - B, (spc1->Center + spc2->Center).lenght - o1a};
	}

/*
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

struct Vector2d{

    float x;
    float y;
    const float defaultLenght = 1.0;
    float lenght;

*/

CollisionPoints Test_Sphere_Plane(
	 Collider* a, const Transform* ta,
	 Collider* b, const Transform* tb){
		SphereCollider* c1 = dynamic_cast<SphereCollider*>(a);
		if( c1 != nullptr){
			PlaneCollider* c2 = dynamic_cast<PlaneCollider*>(b);

			float norm = std::pow((std::pow(c2->Normal.x,2)+std::pow(c2->Normal.y, 2)),1/2);
			Vector2d norm1 = Vector2d(c2->Normal.x / norm, c2->Normal.y / norm);

			Vector2d distVec = Vector2d(c2->Distance * norm1.x, c2->Distance * norm1.y);

			float c = c2->Normal.x * distVec.x + c2->Normal.y * distVec.y;
			float OB = (std::abs(2 * c)) / (norm);
			float AB = (c1->Radius - OB);
			Vector2d ABvec = Vector2d(AB * norm1.x, AB * norm1.y);
			
			std::cout << "sdfsd";
		}else{
			PlaneCollider* c2 = dynamic_cast<PlaneCollider*>(a);
			SphereCollider* c1 = dynamic_cast<SphereCollider*>(b);

			
		}
	 }


using FindContactFunc = CollisionPoints(*)(
		 Collider*, const Transform*, 
		 Collider*, const Transform*);

CollisionPoints TestCollision(
	 Collider* a, const Transform* at, 
	 Collider* b, const Transform* bt)
{
	static const FindContactFunc tests[2][2] = 
	{
		// Sphere             Plane
		{ Test_Sphere_Sphere, Test_Sphere_Plane }, // Sphere
		{ nullptr,            nullptr           }  // Plane
	};

    // If we are passed a Plane vs Sphere, swap the 
	// colliders so it's a Sphere vs Plane
	bool swap = b->Type > a->Type;

	if (swap)
	{
		std::swap(a, b);
		std::swap(at, bt);
	}

    // now we can dispatch the correct function
	CollisionPoints points = tests[a->Type][b->Type](a, at, b, bt);

	// if we swapped the order of the colliders, to keep the
	// results consistent, we need to swap the points
	if (swap)
	{
		std::swap(points.A, points.B);
		points.Normal = -points.Normal;
	}

	return points;
}