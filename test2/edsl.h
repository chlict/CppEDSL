#pragma once

namespace edsl {
    struct Expr {};

    struct IndexExpr : Expr {};

    template <long long I>
    struct Index : IndexExpr {};

    constexpr Index<1> _i1;
    constexpr Index<2> _i2;
    constexpr Index<3> _i3;

    // template <long long I>
    // Index _i;

    struct Scalar : Expr {
        constexpr Scalar& operator*(int &&v) {
            return *this; // doesn't matter what it is
        }
    };

    struct Tensor : Expr {
        template <long long I>
        Scalar& operator[](Index<I>) {
            return scalar_;
        }

    private:
        Scalar scalar_;
    };

    struct StmtBlock {
        template <typename ... Stmts>
        StmtBlock operator[](Stmts... stmt) {
            return StmtBlock{};
        }
    };

    struct Range {};

    template <long long I>
    struct RangeIterExpr {};

    template <long long I>
    RangeIterExpr<I> operator << (Index<I>, Range) {
        return RangeIterExpr<I>{};
    }

    struct AffineDialect {
        StmtBlock For(Range r, const char *i) const {
            return StmtBlock{};
        }

        template <long long I>
        StmtBlock For(RangeIterExpr<I>) const {
            return StmtBlock{};
        }
    };

    constexpr AffineDialect affine;

    template <int S, int E, int STEP>
    struct range : Range {
        static constexpr int start = S;
        static constexpr int end = E;
        static constexpr int step = STEP;
    };
}