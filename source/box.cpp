#include "box.hpp"

Box::Box(Vec2 min,Vec2 max):
	min_(min);
	max_(max);

Vec2 const& getmin()
{
	return(min_);
}

Vec2 const& getmax()
{
	return(max_);
}


