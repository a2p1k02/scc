#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INT_LIT
};

struct token {
    int token;
    int int_value;
};

enum {
    A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INT_LIT
};

struct ASTnode {
    int op;
    struct ASTnode* left;
    struct ASTnode* right;
    int int_value;
};

#endif //DEFS_H
