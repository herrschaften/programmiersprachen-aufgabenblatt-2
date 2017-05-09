#ifndef BOX_HPP
#define BOX_HPP
#include "Vec2.hpp"

class Box
{
public:
	Box(Vec2 min, Vec2 max);
	Vec2 getmin();
	Vec2 getmax();
	

private:
	Vec2 min_;
	Vec2 max_;	
}


#endif