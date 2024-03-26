#pragma once

#include "lexer.h"
#include <stack>

class Eval {
    std::stack<double> eval_stack;

    double pop();
    void push(double value);

public:
    const int MAX_STACK_DEPTH = 1024;

    Eval();
    ~Eval();

    double eval(const std::vector<Token>& t, double var, double length);
};