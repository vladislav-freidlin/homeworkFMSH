#pragma once 
#include "Object.hpp"
#include <vector>
#include "Vector2d.hpp"
#include "Solver.hpp"

class PhysicsWorld {
private:
	std::vector<Object*> m_objects;
	std::vector<Solver*> solvers;
	Vector2d m_gravity = Vector2d(0, -9.81f);
 
public:
	void AddObject   (Object* object) { 
		m_objects.push_back(object);
	 }
	void RemoveObject(Object* object) { /* ... */ }

	
	void Step(float dt)
	{
		for (Object* obj : m_objects) {
			obj->Force += obj->Mass * m_gravity; // apply a force
 
			obj->Velocity += obj->Force / obj->Mass * dt;
			obj->Position += obj->Velocity * dt;
 
			obj->Force = Vector2d(0, 0); // reset net force at the end
		}
	}
	void resolveCollisions(float dt){
		std::vector<Collision> colls;
		
		for(int i = 0; i < m_objects.size()-1; i++){
			for(int j = i+1; j < m_objects.size(); j++){
				Collision coll{m_objects[i], m_objects[j]};
				if(coll.getCollisionPoints()->HasCollision){
					colls.push_back(coll);
				}
			}
		}

		for(Collision coll: colls){
			
		}
		// for(Solver* solv: solvers){
		// 	solv->solve(colls);
		// }

	}
};