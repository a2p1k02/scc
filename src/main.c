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

    // Open file
    if ((Infile = fopen(av[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", av[1], strerror(errno));
        exit(1);
    }

    // Create file
    if ((Outfile = fopen("out.s", "w")) == NULL) {
        fprintf(stderr, "Unable to create out.s: %s\n", strerror(errno));
        exit(1);
    }

    scan(&Token);
    n = binexpr(0);
    printf("%d\n", interpreterAST(n));

    generatecode(n);
    fclose(Outfile);

    exit(0);
}
