#include <cstdio>
#include "lexer.h"

const std::map<std::string, TokenType> c_operators = {
    {"add", T_ADD}, 
    {"sub", T_SUB},
    {"mul", T_MULT},
    {"div", T_DIV},
    {"mod", T_FMOD},
    {"pow", T_POW},
    {"log", T_LOG},
    {"round", T_ROUND},
    {"equ", T_EQU},
    {"notequ", T_NEQ},
    {"less", T_LESS},
    {"gre", T_GRE},
    {"lesseq", T_LESSEQ},
    {"greeq", T_GREEQ},
    {"sin", T_SIN},
    {"cos", T_COS},
    {"tan", T_TAN},
    {"asin", T_ASIN},
    {"acos", T_ACOS},
    {"atan", T_ATAN},
    {"floor", T_FLOOR},
    {"ceil", T_CEIL},
    {"sqrt", T_SQRT},
    {"log2", T_LOG2},
    {"log10", T_LOG10},
    {"neg", T_NEGATE},
    {"sgn", T_SIGNUM},
    {"abs", T_ABS},
    {"swp", T_SWAP},
    {"dup", T_DUPLICATE},
    {"rand", T_RAND},
    {"#", T_LENGTH},
    {"min", T_MIN},
    {"max", T_MAX},
   };

const std::string c_tokentypenames[] = {
    "t_number", "t_var", "t_length", "t_add", "t_sub", "t_mul", "t_div", "t_fmod", "t_swap", "t_dup",
    "t_neg", "t_sgn", "t_abs", "t_equ", "t_les", "t_gre", "t_leq", "t_grq", "t_neq", "t_sin", "t_cos",
    "t_tan", "t_sqrt", "t_pow", "t_log10", "t_log2", "t_log", "t_asin", "t_acos", "t_atan",
    "t_round", "t_floor", "t_ceil", "t_rand", "t_min", "t_max"};

int _getoperid(const std::string& val){
    if (c_operators.count(val) > 0) return c_operators.at(val);
    return -1;
}

bool _isdigit(char c){
    return (c >= '0' && c <= '9') || c == '.' || c == '-';
}

bool _isalpha(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9');
}

std::string Token::repr(){
    return "[" + c_tokentypenames[type] + " : " + std::to_string(value) + "]";
}

char Lexer::_get(int d){
    if (pos + d >= source.size()) return '\0';
    return source[pos + d];
}

void Lexer::_next(int d){
    pos += d;
}

void Lexer::process_number(){
    std::string buffer;
    char c;

    while (true){
        if (!_isdigit(c = _get()))
            break;
        buffer += c;
        _next();
    }
    tokens.push_back(Token{T_NUMBER, std::stod(buffer)});
}

void Lexer::process_oper(){
    std::string buffer;
    int oper;
    char c;

    while (true){
        if (!_isalpha(c = _get()))
            break;
        buffer += c;
        _next();
    }
    if ((oper = _getoperid(buffer)) != -1)
        tokens.push_back(Token{(TokenType)oper, 0.0});
    else {
        fprintf(stderr, "Error: unknown operator '%s'\n", buffer.c_str());
        exit(-1);
    }
}

Lexer::Lexer(const std::string& fname){
    std::ifstream file(fname, std::ios::in);
    if (!file){
        fprintf(stderr, "Error: cannot open file '%s'\n", fname.c_str());
        exit(-2);
    }

    for (std::string line; std::getline(file, line, '\n'); ){
        source += line;
        source += '\n';
    }

    file.close();
}

Lexer::~Lexer(){}

std::vector<Token>& Lexer::parse(){
    char c;
    while ((c = _get()) != '\0'){
        if (isdigit(c)){
            process_number();
            continue;
        }
        if (isspace(c)) {
            _next();
            continue;
        }
        if (c == '$'){
            tokens.push_back(Token{T_VAR, 0.0});
            _next();
            continue;
        }
        if (c == '#'){
            tokens.push_back(Token{T_LENGTH, 0.0});
            _next();
            continue;
        }
        process_oper();
    }
    return tokens;
}