#pragma once
#include "typedefs.hpp"
#include "ray.hpp"
class Sphere
{
public: 
	color Color = color(1.0, 1.0, 0);
	public:
	Sphere(point center,float radius);
	~Sphere();
	bool isRayHitSpehere(const ray r);
	
private:
	point center;
	float radius;
};

