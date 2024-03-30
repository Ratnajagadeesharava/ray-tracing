#pragma once
#include "typedefs.hpp"
class ray
{
public:
	

	ray(point& origin,vec3& direction);

	inline point getOrigin() const { return o; }
	inline vec3 getDirection() const { return d; }
	inline point at(float t) {
		return o + d * t;
	}

private :
	point o;
	//
	vec3 d;
};

