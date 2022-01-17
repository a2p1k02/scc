#include "../include/defs.h"
#define extern_
#include "../include/data.h"
#undef extern_
#include "../include/decl.h"
#include <errno.h>

static void init()
{
    Line = 1;
    Putback = '\n';
}

static void usage(char *prog)
{
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

int main(int ac, char **av)
{
    struct ASTnode *n;

    if (ac != 2)
        usage(av[0]);

    init();

    if ((Infile = fopen(av[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", av[1], strerror(errno));
        exit(1);
    }

    scan(&Token);
    n = binexpr();
    printf("%d\n", interpreterAST(n));
    exit(0);
}
