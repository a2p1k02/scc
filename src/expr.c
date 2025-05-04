#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

static int op_prec[] = { 0, 10, 10, 20, 20, 0 };

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

int arithop(int tok) {
    switch (tok) {
        case T_PLUS:
            return A_ADD;
        case T_MINUS:
            return A_SUBTRACT;
        case T_STAR:
            return A_MULTIPLY;
        case T_SLASH:
            return A_DIVIDE;
        default:
            fprintf(stderr, "syntax error on line %d, token %d\n", line, tok);
            exit(1);
    }
}

static int op_precedence(int tok) {
    int prec = op_prec[tok];

    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", line, tok);
        exit(1);
    }

    return prec;
}

struct ASTnode* binexpr(int exp) {
    struct ASTnode *n, *left, *right;
    int tokentype;

    left = primary();

    tokentype = Token.token;
    if (tokentype == T_EOF)
        return left;

    while (op_precedence(tokentype) > exp) {
        scan(&Token);
        
        right = binexpr(op_prec[tokentype]);
        left = mkastnode(arithop(tokentype), left, right, 0);

        tokentype = Token.token;
        if (tokentype == T_EOF)
            return left;
    }

    return left;
}

