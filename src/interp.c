#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

static char *ASTop[] = { "+", "-", "*", "/" };

int interpreterAST(struct ASTnode *n)
{
    int leftval, rightval;

    if (n->left)
        leftval = interpreterAST(n->left);
    if (n->right)
        rightval = interpreterAST(n->right);

    /*
    if (n->op == A_INTLIT)
        printf("int %d\n", n->intvalue);
    else
        printf("%d %s %d\n", leftval, ASTop[n->op], rightval);
    */

    switch (n->op) {
        case A_ADD:
            return (leftval + rightval);
        case A_SUBSTRACT:
            return (leftval - rightval);
        case A_MULTIPLY:
            return (leftval * rightval);
        case A_DIVIDE:
            return (leftval / rightval);
        case A_INTLIT:
            return (n->intvalue);
        default:
            fprintf(stderr, "Unknown AST operator %d\n", n->op);
            exit(1);
    }
}

