template <int d0>
struct Range1D {
    static constexpr int dim = d0;
};

constexpr int TestRange1D() {
    return Range1D<10>::dim;
}

int Test() {
    return TestRange1D();
}