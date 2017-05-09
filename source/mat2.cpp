#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

//	KONSTRUKTOREN
Mat2::Mat2():
	a_(1),
	b_(0),
	c_(0),
	d_(1)
	{}

Mat2::Mat2(float aa, float bb, float cc, float dd):
	a_(aa),
	b_(bb),
	c_(cc),
	d_(dd)
	{}	
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//	MEMBERFUNKTIONEN	
Mat2& Mat2::operator*=(Mat2 const& m)
{
	Mat2 tmp{a_, b_, c_, d_};

	a_=(tmp.a_*m.a_)+(tmp.b_*m.c_);
	b_=(tmp.a_*m.b_)+(tmp.b_*m.d_);
	c_=(tmp.c_*m.a_)+(tmp.d_*m.c_);
	d_=(tmp.c_*m.c_)+(tmp.c_*m.d_);

	return *this;
}

float Mat2::det() const
{
	float ret;
	ret=(a_*d_)-(c_*b_);

	return ret;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//	FREIE FUNKTIONEN
Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 ret{};

	ret.a_=(m1.a_*m2.a_)+(m1.b_*m2.c_);
	ret.b_=(m1.a_*m2.b_)+(m1.b_*m2.d_);
	ret.c_=(m1.c_*m2.a_)+(m1.d_*m2.c_);
	ret.d_=(m1.c_*m2.c_)+(m1.c_*m2.d_);

	return ret;
}	

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	Vec2 ret{};
	ret.x_=m.a_*v.x_+m.b_+v.y_;
	ret.y_=m.c_*v.x_+m.d_+v.y_;
	
	return ret;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
	Vec2 ret{};
	ret.x_=m.a_*v.x_+m.b_+v.y_;
	ret.y_=m.c_*v.x_+m.d_+v.y_;
	return ret;	
}

Mat2 inverse(Mat2 const& m)
{
	if(m.det()==0)
	{
		return m;
	}

	Mat2 ret{};
	float det=m.det();
	ret.a_=(m.a_/det);
	ret.b_=(-m.c_/det);
	ret.c_=(-m.b_/det);
	ret.d_=(m.d_/det);

	return ret;	
}

Mat2 transpose(Mat2 const& m)
{
	Mat2 ret{m};
	
	ret.b_=m.c_;
	ret.c_=m.b_;

	return ret;
}

Mat2 rotate(float w)
{
	Mat2 ret{};
	ret.a_=cos(w);
	ret.b_=-sin(w);
	ret.c_=sin(w);
	ret.d_=cos(w);

	return ret;

}
