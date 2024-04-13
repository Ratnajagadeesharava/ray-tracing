#include "Hittable_List.hpp"


Hittable_List::Hittable_List()
{
}

Hittable_List::~Hittable_List()
{
}

void Hittable_List::addHittableObject(std::shared_ptr<Hittable >object)
{
		objects.push_back(object);
}



bool Hittable_List::hitRecord( ray& r, Interval interval, Hit_Point& rec) const
{
	bool hit_anything = false;

	color Color = color(0, 0, 0);
	for(const auto& object : objects)
	{
		if(object->hitRecord(r, interval, rec))
		{
			hit_anything = true;
			if (interval.end < rec.t)
			{
				rec.Color = Color;
			}
			else {
				Color = rec.Color;
				interval.end = rec.t;
			}
		}
	}
	return hit_anything;
}
