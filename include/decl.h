#ifndef DECL_H
#define DECL_H

int scan(struct token* t);

struct ASTnode* mkastnode(int op, struct ASTnode* left, 
                          struct ASTnode* right, int int_value);
struct ASTnode* mkastleaf(int op, int int_value);
struct ASTnode* mkastunary(int op, struct ASTnode* left, int int_value);
struct ASTnode* binexpr(int exp);

int interpretAST(struct ASTnode* n);

#endif //DECL_H
