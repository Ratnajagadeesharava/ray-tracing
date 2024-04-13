#include "Sphere.h"

Sphere::Sphere(point center, float radius) : center(center), radius(radius) 
{
}

Sphere::~Sphere()
{
}

float Sphere::isRayHitSpehere(ray r)
{
    vec3 direction = r.getDirection();
    vec3 origin = r.getOrigin();
    vec3 oc = origin - center;
    float a = direction.dot(direction);
    float b = 2.0f * oc.dot(direction);
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;
    if (discriminant < 0.0f) {
        return -1.0f;
    }
    float sqrtDiscriminant = sqrtf(discriminant);
    float t1 = (-b - sqrtDiscriminant) / (2.0f * a);
    return t1;
}

bool Sphere::hitRecord(ray& r, Interval interval, Hit_Point& record) const
{
 // OC^2 - r^2 + (t*dir)^2 +2*t*(OC.dir)= 0
    vec3 OC = r.getOrigin() - center;
    float a = r.getDirection().dot(r.getDirection());
    float b = 2.0f * OC.dot(r.getDirection());
    float c = OC.dot(OC) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;
    if (discriminant < 0.0f) {
        return false;
    }
    float sqrtDiscriminant = sqrtf(discriminant);
    float t = (-b - sqrtDiscriminant) / (2.0f * a);
   
    if (!interval.isInRange(t)) {
        return false;
    }
    record.point_of_contact = r.at(t);
    record.t = t;
    record.Color = Color;
    record.normal = record.point_of_contact - center;
    return true;
}