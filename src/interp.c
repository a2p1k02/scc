#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

static char* ASTop[] = { "+", "-", "*", "/" };

int interpretAST(struct ASTnode* n) {
    int leftval, rightval;

    if (n->left)
        leftval = interpretAST(n->left);
    if (n->right)
        rightval = interpretAST(n->right);

    // if (n->op == A_INT_LIT)
    //     printf("int %d\n", n->int_value);
    // else
    //     printf("%d %s %d\n", leftval, ASTop[n->op], rightval);

    switch (n->op) {
        case A_ADD:
            return (leftval + rightval);
        case A_SUBTRACT:
            return (leftval - rightval);
        case A_MULTIPLY:
            return (leftval * rightval);
        case A_DIVIDE:
            return (leftval / rightval);
        case A_INT_LIT:
            return (n->int_value);
        default:
            fprintf(stderr, "Unknown AST operator %d\n", n->op);
            exit(1);
    }
}
