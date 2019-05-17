#include "catch.hpp"
#include "surface.h"

TEST_CASE("Surface(path) creates a valid from file", "[surface]") {
    Surface surface("../data/texture.png");

    REQUIRE(surface.get() != nullptr);
}
