#pragma once
#include "typedefs.hpp"
//#include "ray.hpp"
class Hit_Point {
public:
	point point_of_contact;
	vec3 normal;
	double t;
	bool front_face;
	color Color;

	/*void set_face_normal(const ray& r, const vec3& outward_normal) {

		front_face = r.getDirection().dot(outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}*/
};

class Hittable {
	public:
	virtual ~Hittable() = default;
	virtual bool hitRecord( ray& r,Interval interval, Hit_Point& rec) const = 0;
};
