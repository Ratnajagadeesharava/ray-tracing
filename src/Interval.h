#pragma once
#include "typedefs.hpp"
class Interval {

	public:
	Interval() :start(+infinity), end(-infinity) {}
	Interval(float start, float end) :start(start), end(end) {}
	float start;
	float end;
	bool isInRange(float t) {
		return t >= start && t <= end;
	}

	float size() {
		return end - start;
	}
	static const Interval empty,universe;

};


const Interval Interval::empty = Interval();
const Interval Interval::universe = Interval(-infinity,infinity);