#include "Sphere.h"

Sphere::Sphere(point center, float radius) :center(center), radius(radius)
{
}
Sphere::~Sphere()
{
}
float Sphere::isRayHitSpehere(  ray r)
{
	vec3 direction = r.getDirection();
	vec3 origin = r.getOrigin();
	float  a = direction.dot(direction);
	vec3 oc = origin - center;
	float b = 2.0 * oc.dot(direction);
	float c = oc.dot(oc) - radius * radius;
	float k = b * b - 4 * a * c;
	if (k < 0) {
		return -1.0;
	}
	float t1 = (-b - sqrt(k)) / (2.0 * a);
	return t1;
}
