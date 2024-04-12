#include "Sphere.h"



float Sphere::isRayHitSpehere(ray r)
{
    vec3 direction = r.getDirection();
    vec3 origin = r.getOrigin();
    vec3 oc = origin - center;
    float a = direction.dot(direction);
    float b = 2.0 * oc.dot(direction);
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return -1.0;
    }
    float sqrtDiscriminant = sqrt(discriminant);
    float t1 = (-b - sqrtDiscriminant) / (2.0 * a);
    return t1;
}

bool Sphere::hitRecord(ray& r, double t_min, double t_max, Hit_Point& record) const
{
    // OC^2 - r^2 + (t*dir)^2 +2*t*(OC.dir)= 0
    vec3 OC = r.getOrigin() - center;
    float a =r.getDirection().dot(r.getDirection());
    float b = OC.dot(r.getDirection()) * 2;
    float c = OC.dot(OC) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if(discriminant < 0) {
		return false;
	}
    float sqrtDiscriminant = sqrt(discriminant);
	float t = (-b - sqrtDiscriminant) / (2.0 * a);
	if (t < t_min || t > t_max) {
		t = (-b + sqrtDiscriminant) / (2.0 * a);
		if (t < t_min || t > t_max) {
			return false;
		}
	}
	record.point_of_contact = r.at(t);
    record.t = t;
    record.normal = record.point_of_contact - center;
    return false;
}