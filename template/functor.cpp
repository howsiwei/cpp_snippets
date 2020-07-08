#include <array>
#include <memory>
#include <vector>
#include <set>
#include <string>

using namespace std;

template <template <typename> class F = shared_ptr>
struct NumExpr {
    virtual ~NumExpr() = default;
};

template <template <typename> class F = shared_ptr>
struct Const : NumExpr<F> {
    string value;

    Const(string value) :
        value(value) {}
};

template <template <typename> class F = shared_ptr>
struct Var : NumExpr<F> {
    string name;

    Var(string name) :
        name(name) {}
};

enum class NumExprBinOp { add, sub, mul, div, mod };

template <template <typename> class F = shared_ptr>
struct BinopNumExpr : NumExpr<F> {
    using Op = NumExprBinOp;
    Op op;
    array<F<NumExpr<F>>, 2> exprs;

    BinopNumExpr(Op op, array<F<NumExpr<F>>, 2> exprs) :
        op(op),
        exprs(exprs) {}

    BinopNumExpr(Op op, F<NumExpr<F>> left, F<NumExpr<F>> right) :
        op(op),
        exprs{left, right} {}
};

weak_ptr<NumExpr<weak_ptr>> f(shared_ptr<NumExpr<>> expr) {
    if (auto const_ = dynamic_pointer_cast<Const<>>(expr)) {
        return make_shared<Const<weak_ptr>>(const_->value);
    } else if (auto bopExpr = dynamic_pointer_cast<BinopNumExpr<>>(expr)) {
        auto op = bopExpr->op;
        array<weak_ptr<NumExpr<weak_ptr>>, 2> exprs;
        for (int i = 0; i < 2; i++) {
            exprs[i] = f(bopExpr->exprs[i]);
        }
        return make_shared<BinopNumExpr<weak_ptr>>(op, exprs);
    }
}

template <typename T>
using StringSet = set<string>;

StringSet<NumExpr<StringSet>> g(shared_ptr<NumExpr<>> expr) {
    return StringSet<NumExpr<StringSet>>{};
    if (auto const_ = dynamic_pointer_cast<Const<>>(expr)) {
        return StringSet<NumExpr<StringSet>>{const_->value};
        // return make_shared<Const<weak_ptr>>(const_->value);
    } else if (auto bopExpr = dynamic_pointer_cast<BinopNumExpr<>>(expr)) {
        // auto op = bopExpr->op;
        array<StringSet<NumExpr<StringSet>>, 2> stringSets;
        for (int i = 0; i < 2; i++) {
            stringSets[i] = g(bopExpr->exprs[i]);
        }
        auto stringSet = move(stringSets[0]);
        for (auto s: stringSets[1]) {
            stringSet.insert(s);
        }
        return StringSet<NumExpr<StringSet>>(stringSet);
        // return make_shared<BinopNumExpr<weak_ptr>>(op, exprs);
    }
}
