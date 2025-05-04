#include "../include/defs.h"
#define extern_
#include "../include/data.h"
#undef extern_
#include "../include/decl.h"
#include <errno.h>

static void init() {
    line = 1;
    _putback = '\n';
}

static void usage(char* prog) {
    fprintf(stderr, "Usage: %s infile \n", prog);
    exit(1);
}

int main(int argc, char* argv[]) {
    struct ASTnode* n;

    if (argc != 2)
        usage(argv[0]);

    init();

    if ((in_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan(&Token);
    n = binexpr();
    printf("%d\n", interpretAST(n));
    exit(0);
}
