#pragma once

#include "lexer.h"
#include <stack>

 // #define MAX_STACK_DEPTH 1024

class Eval {
    std::stack<double> eval_stack;

    double pop();
    void push(double value);

public:
    Eval();
    ~Eval();

    double eval(const std::vector<Token>& t, double var, double length);
};