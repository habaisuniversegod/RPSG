#include "eval.h"
#include <cmath>

double Eval::pop(){
    double value;
    if (eval_stack.empty()){
        fprintf(stderr, "Error: pop from empty stack\n");
        exit(-3);
    }
    value = eval_stack.top();
    eval_stack.pop();
    return value;
}


void Eval::push(double value){
    if (eval_stack.size() >= MAX_STACK_DEPTH){
        fprintf(stderr, "Error: staсk overflow (max depth: %d)\n", MAX_STACK_DEPTH);
        exit(-3);
    }
    eval_stack.push(value);
}

Eval::Eval(){}

Eval::~Eval(){}

double Eval::eval(const std::vector<Token>& t, double var, double length){
    int tpos = 0;
    Token current_token;
    double left, right;

    while (tpos < t.size()){
        current_token = t.at(tpos++);
        switch(current_token.type){
            case T_NUMBER:
                push(current_token.value);
                break;
            case T_VAR:
                push(var);
                break;
            case T_LENGTH:
                push(length);
                break;
            case T_ADD:
                right = pop();
                left = pop();
                push(left + right);
                break;
            case T_SUB:
                right = pop();
                left = pop();
                push(left - right);
                break;
            case T_MULT:
                right = pop();
                left = pop();
                push(left * right);
                break;
            case T_DIV:
                right = pop();
                left = pop();
                push(left / right);
                break;
            case T_FMOD:
                right = pop();
                left = pop();
                push(fmod(left, right));
                break;
            case T_SWAP:
                right = pop();
                left = pop();
                push(right);
                push(left);
                break;
            case T_DUPLICATE:
                left = pop();
                push(left);
                push(left);
                break;
            case T_NEGATE:
                left = pop();
                push(-left);
                break;
            case T_SIGNUM:
                left = pop();
                if (left == 0.0) push(0.0);
                else push(left > 0.0 ? 1.0 : -1.0);
                break;
            case T_ABS:
                left = pop();
                push(left > 0.0 ? left : -left);
                break;
            case T_SIN:
                left = pop();
                push(sin(left));
                break;
            case T_COS:
                left = pop();
                push(cos(left));
                break;
            case T_TAN:
                left = pop();
                push(tan(left));
                break;
            case T_ASIN:
                left = pop();
                push(asin(left));
                break;
            case T_ACOS:
                left = pop();
                push(acos(left));
                break;
            case T_ATAN:
                left = pop();
                push(atan(left));
                break;
            case T_SQRT:
                left = pop();
                push(sqrt(left));
                break;
            case T_FLOOR:
                left = pop();
                push(floor(left));
                break;
            case T_CEIL:
                left = pop();
                push(ceil(left));
                break;
            case T_LOG2:
                left = pop();
                push(log2(left));
                break;
            case T_LOG10:
                left = pop();
                push(log10(left));
                break;
            case T_LOG:
                right = pop();
                left = pop();
                push(log2(left) / log2(right));
                break;
            case T_POW:
                right = pop();
                left = pop();
                push(pow(left, right));
                break;
            case T_EQU:
                right = pop();
                left = pop();
                push(left == right ? 1.0 : 0.0);
                break;
            case T_NEQ:
                right = pop();
                left = pop();
                push(left != right ? 1.0 : 0.0);
                break;
            case T_LESS:
                right = pop();
                left = pop();
                push(left < right ? 1.0 : 0.0);
                break;
            case T_GRE:
                right = pop();
                left = pop();
                push(left > right ? 1.0 : 0.0);
                break;
            case T_LESSEQ:
                right = pop();
                left = pop();
                push(left <= right ? 1.0 : 0.0);
                break;
            case T_GREEQ:
                right = pop();
                left = pop();
                push(left >= right ? 1.0 : 0.0);
                break;
            case T_ROUND:
                right = pop();
                left = pop();
                push(round(left * pow(10, right)) / pow(10, right));
                break;
            case T_RAND:
                left = pop();
                std::srand(left);
                push((std::rand() / (double)RAND_MAX - 0.5) * 2.0);
                break;
            case T_MIN:
                right = pop();
                left = pop();
                push(left < right ? left : right);
                break;
            case T_MAX:
                right = pop();
                left = pop();
                push(left > right ? left : right);
                break;
            default:
                fprintf(stderr, "Blyat, zabyl operator realizovat!\n");
                break;
        }
        //printf("stack pos: %d, top: %f\n", eval_stack.size(), eval_stack.empty() ? (INFINITY) : eval_stack.top());
    }
    //printf("eval end\n");
    return pop();
}