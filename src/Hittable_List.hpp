#pragma once

#include "typedefs.hpp"
#include "ray.hpp"
class Hittable_List:public Hittable
{
private:
	std::vector<std::shared_ptr<Hittable>> objects;

public:
	Hittable_List();
	~Hittable_List();
	void addHittableObject(std::shared_ptr<Hittable> object);

	virtual bool hitRecord( ray& r, Interval interval, Hit_Point& rec) const;


};

