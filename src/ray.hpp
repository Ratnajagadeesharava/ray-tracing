
#pragma once

#include "typedefs.hpp"
class ray
{
public:
    ray(const point& origin, const vec3& direction)
        : o(origin), d(direction)
    {
    }

    point getOrigin() const { return o; }
    vec3 getDirection() const { return d; }
    point at(float t) const { return o + d * t; }

private:
    point o;
    vec3 d;
};
