#pragma once
#include "typedefs.hpp"
#include "ray.hpp"
class Sphere
{
public: 
	color Color = color(1.0, 1.0, 0);
	point center;
	public:
	Sphere(point center,float radius);
	~Sphere();
	float isRayHitSpehere( ray r);
	
private:
	
	float radius;
};

