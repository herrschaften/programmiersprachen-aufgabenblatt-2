#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


TEST_CASE("constructive conrtuctor testing" )
{
	Vec2 v1{2.0f,2.0f};
	REQUIRE(2.0f==v1.x_);
	REQUIRE(2.0f==v1.y_);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
