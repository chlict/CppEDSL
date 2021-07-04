#include "edsl.h"

using namespace edsl;

void Test1() {
    // auto v0 = _v{};  // invalid
    // auto v0 = _v{1.0};  // invalid
    auto v1 = _v{1, 2, 3};
    auto v2 = _v{ _v{1, 2, 3}, _v{4, 5, 6} };
}

void Test2() {
    let(var_a = _v{1, 2, 3});
    let(var_b = {1, 2, 3});
    let(var_c = {_v{1, 2, 3}, _v{4, 5, 6}});
}