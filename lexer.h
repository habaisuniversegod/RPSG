#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <map>

enum TokenType {
    T_NUMBER, T_VAR, T_LENGTH, T_ADD, T_SUB, T_MULT, T_DIV, T_FMOD, T_SWAP, T_DUPLICATE, T_NEGATE, T_SIGNUM, T_ABS,
    T_EQU, T_LESS, T_GRE, T_LESSEQ, T_GREEQ, T_NEQ, T_SIN, T_COS, T_TAN, T_SQRT, T_POW, 
    T_LOG10, T_LOG2, T_LOG, T_ASIN, T_ACOS, T_ATAN, T_ROUND, T_FLOOR, T_CEIL, T_RAND, T_MIN, T_MAX
};

extern const std::string c_tokentypenames[];

extern const std::map<std::string, TokenType> c_operators;

struct Token {
    TokenType type;
    double value;

    std::string repr();
};

class Lexer {
    std::string source;
    int pos = 0;
    std::vector<Token> tokens;

    char _get(int d = 0);
    void _next(int d = 1);

    void process_number();
    void process_oper();

public:
    Lexer(const std::string& filename);
    ~Lexer();

    std::vector<Token>& parse();
};