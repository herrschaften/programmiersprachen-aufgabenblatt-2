#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "box.hpp"
#include "circle.hpp"

#include <iostream>
#include <cmath>

TEST_CASE("constructive conrtuctor testing" )
{
	Vec2 v1{2.0f,2.0f};
	REQUIRE(2.0f==v1.x_);
	REQUIRE(2.0f==v1.y_);

}

TEST_CASE("oppresive opperand testing" )
{
	
	//	+=
	Vec2 v1{2.0f,2.0f};
	Vec2 v2{3.0f,3.0f};
	v1+=v2;
	REQUIRE(v1.x_==5.0f);
	REQUIRE(v1.y_==5.0f);
	//+++++++++++++++++++++++++++
	//	-=
	Vec2 v3{2.0f,2.0f};
	Vec2 v4{3.0f,3.0f};
	v4-=v3;
	REQUIRE(v4.x_==1.0f);
	REQUIRE(v4.y_==1.0f);

	Vec2 v5{2.0f,2.0f};
	Vec2 v6{3.0f,3.0f};
	v5-=v6;
	REQUIRE(v5.x_== (-1.0f));
	REQUIRE(v5.y_== (-1.0f));
	//++++++++++++++++++++++++++
	//	*=
	Vec2 v7{2.0f,2.0f};
	float f1=3.0f;
	v7*=f1;
	REQUIRE(v7.x_== (6.0f));
	REQUIRE(v7.y_== (6.0f));

	Vec2 v8{2.0f,2.0f};
	float f2=(-3.0f);
	v8*=f2;
	REQUIRE(v8.x_== (-6.0f));
	REQUIRE(v8.y_== (-6.0f));
	//++++++++++++++++++++++++++
	//	/=
	Vec2 v9{10.0f,10.0f};
	float f3=(2.0f);
	v9/=f3;
	REQUIRE(v9.x_== (5.0f));
	REQUIRE(v9.y_== (5.0f));

}

TEST_CASE("fabulous free function testing" )
{
	Vec2 v1{};
	Vec2 v2{2.0f,2.0f};
	Vec2 v3{2.0f,2.0f};
	v1=v2+v3;
	REQUIRE(v1.x_==4.0f);
	REQUIRE(v1.y_==4.0f);

	Vec2 v4{};
	Vec2 v5{3.0f,3.0f};
	Vec2 v6{2.0f,2.0f};
	v4=v5-v6;
	REQUIRE(v4.x_==1.0f);
	REQUIRE(v4.y_==1.0f);

	Vec2 v7{};
	Vec2 v8{3.0f,3.0f};
	float f1=2.0f;
	v7=v8*f1;
	REQUIRE(v7.x_==6.0f);
	REQUIRE(v7.y_==6.0f);

	Vec2 v9{};
	Vec2 v10{10.0f,10.0f};
	float f2=2.0f;
	v9=v10/f2;
	REQUIRE(v9.x_==5.0f);
	REQUIRE(v9.y_==5.0f);
}

TEST_CASE("molesting matrix testing" )
{
	Mat2 m1{2.0f,2.0f, 2.0f, 2.0f};
	Mat2 m2{2.0f,2.0f, 2.0f, 2.0f};

	m1*=m2;

	REQUIRE(m1.a_==8.0f);
	REQUIRE(m1.b_==8.0f);
	REQUIRE(m1.c_==8.0f);
	REQUIRE(m1.d_==8.0f);
	
}

/*TEST_CASE("constructive conrtuctor testing" )
{
	Color clr{};
	Vec2 v1{};
	Vec2 v2{2.0f,2.0f};
	Box b{v1, v2, clr};

}*/

TEST_CASE("color testing" )
{
	Color c1{};
	Color c2{5.0f};
	Color c3{1.0f, 2.0f, 3.0f};
	REQUIRE(c1.r_==255.0f);
	REQUIRE(c2.g_==5.0f);
	REQUIRE(c3.b_==3.0f);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
