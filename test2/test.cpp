#include "edsl.h"

using namespace edsl;

void Test1(Tensor t1, Tensor t2) {
    affine.For(_i1 << range<0, 10, 1>{}) [
        t2[_i1] = t1[_i1]
    ];
}

void Test2(Tensor t1, Tensor t2) {
    affine.For(_i1 << range<0, 10, 1>{}) [
        affine.For(_i2 << range<0, 20, 2>{}) [
            t2[_i1] = t1[_i1] * 2,
            t2[_i3] = t1[_i1]
        ]
    ];
}