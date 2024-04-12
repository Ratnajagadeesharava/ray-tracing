#pragma once
#include "typedefs.hpp"
#include "ray.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable
{
public: 
	color Color = color(1.0, 1.0, 0);
	point center;
	public:
	Sphere(point center,float radius);
	~Sphere();
	float isRayHitSpehere( ray r);

	bool hitRecord( ray& r, double t_min, double t_max, Hit_Point& rec) const;
	
private:
	
	float radius;
};

