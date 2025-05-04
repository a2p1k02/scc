#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

struct ASTnode* mkastnode(int op, struct ASTnode* left, 
                          struct ASTnode* right, int int_value) {
    struct ASTnode* n;
    n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
    if (n == NULL) {
        fprintf(stderr, "Unable to malloc in mkastnode()\n");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->int_value = int_value;

    return n;
}

struct ASTnode* mkastleaf(int op, int int_value) {
    return mkastnode(op, NULL, NULL, int_value);
}

struct ASTnode* mkastunary(int op, struct ASTnode* left, int int_value) {
    return mkastnode(op, left, NULL, int_value);
}

