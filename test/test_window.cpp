#include "catch.hpp"
#include "client/view/window.h"

TEST_CASE( "get() returns a valid pointer", "[window]" ) {
    Window window(800, 600);

    REQUIRE(window.get() != nullptr);
}
