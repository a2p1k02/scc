#include "../include/defs.h"
#define extern_
#include "../include/data.h"
#undef extern_
#include "../include/decl.h"
#include <errno.h>

char* tokstr[] = { "+", "-", "*", "/", "intlit" };

static void init() {
    line = 1;
    _putback = '\n';
}

static void usage(char* prog) {
    fprintf(stderr, "Usage: %s infile \n", prog);
    exit(1);
}

static void scanfile() {
    struct token T;
    while (scan(&T)) {
        printf("token: %s", tokstr[T.token]);
        if (T.token == T_INTLIT) printf(", value %d", T.int_value);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) usage(argv[0]);
    init();
    if ((in_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scanfile();
    exit(0);
}
