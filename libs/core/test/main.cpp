#include <gtest/gtest.h>

#include "input_manager_test.hpp"

auto main(int argc, char ** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}