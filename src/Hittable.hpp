#include "ray.hpp"

#ifndef HITTABLE_H
#define HITTABLE_H
class Hit_Point {
public:
	point point_of_contact;
	vec3 normal;
	double t;
};

class Hittable {
	virtual ~Hittable() = default;
	virtual bool hitRecord( ray& r, double t_min, double t_max, Hit_Point& rec) const = 0;
};

#endif // !HITTABLE_H
