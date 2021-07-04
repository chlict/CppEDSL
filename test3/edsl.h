#pragma once

#include <type_traits>

namespace edsl {
    struct Expr {};

    /// -------------------------------------------
    /// Expr := VarDeclExpr
    /// VarDeclExpr := 'let'(VarInitExpr)
    /// VarInitExpr := Var '=' ValueListExpr
    /// ValueListExpr := Value | {Value, ...}
    /// Value := '_v'{IntegerLiterals}
    /// -------------------------------------------

    struct VarDeclExpr : Expr {};
    struct VarInitExpr {};

    // Value & ValueListExpr
    struct _v {
        _v() = delete;

        // Valid when initialized with integers, e.g. _v{1, 2, 3}
        template <typename ... Literals,
            std::enable_if_t<(std::is_same_v<Literals, int> && ...), bool> = true>
        constexpr _v(Literals... literals) {
            static_assert(sizeof...(literals) > 0, "At least 1 literal required");
        }

        // Valid when initialized with multiple vectors, e.g. _v{_v{1, 2, 3}, _v{4, 5, 6}}
        template <typename... Vs,
            std::enable_if_t<(std::is_same_v<Vs, _v> && ...), bool> = true>
        constexpr _v(Vs... vs) {
            static_assert(sizeof...(vs) > 0, "At least 1 vector value required");
        }
    };

    template <int I>
    struct Var {
        // Var = _v{...} is a valid VarInitExpr
        constexpr VarInitExpr operator=(const _v &value) const {
            return VarInitExpr{};
        }
    };

    constexpr Var<0> var_a;
    constexpr Var<1> var_b;
    constexpr Var<2> var_c;

    VarDeclExpr let(const VarInitExpr &var_init) {
        return VarDeclExpr{};
    }

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