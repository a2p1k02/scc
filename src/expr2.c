#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

struct ASTnode* additive_expr(void);

static struct ASTnode* primary() {
    struct ASTnode* n;

    switch (Token.token) {
        case T_INT_LIT:
            n = mkastleaf(A_INT_LIT, Token.int_value);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "syntax error on line %d, token %d\n", line, Token.token);
            exit(1);
    }
}

static int arithop(int tok) {
    switch (tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "syntax error on line %d, token %d\n", line, tok);
            exit(1);
    }
}

struct ASTnode* multiplicative_expr() {
    struct ASTnode *left, *right;
    int tokentype;

    left = primary();

    tokentype = Token.token;
    if (tokentype == T_EOF)
        return left;

    while ((tokentype == T_STAR) || (tokentype == T_SLASH)) {
        scan(&Token);
        right = primary();

        left = mkastnode(arithop(tokentype), left, right, 0);

        tokentype = Token.token;
        if (tokentype == T_EOF) 
            break;
    }

    return left;
}

struct ASTnode* additive_expr() {
    struct ASTnode *left, *right;
    int tokentype;

    left = multiplicative_expr();

    tokentype = Token.token;
    if (tokentype == T_EOF) 
        return left;

    while (1) {
        scan(&Token);

        right = multiplicative_expr();
        left = mkastnode(arithop(tokentype), left, right, 0);

        tokentype = Token.token;
        if (tokentype == T_EOF)
            break;
    }

    return left;
}

struct ASTnode* binexpr(int exp) {
    return additive_expr();
}

