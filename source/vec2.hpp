/*
	Includegurads(ifndef) verhinidern doppelte einbindung von Headern per #include
*/

#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2
{
	float x_;
	float y_;
	
	Vec2();
	Vec2(float xx,float yy);
	
};



#endif