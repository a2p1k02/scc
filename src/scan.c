#include "../include/defs.h"
#include "../include/data.h"
#include "../include/decl.h"

static int chrpos(char *s, int c) {
    char *p;

    p = strchr(s, c);
    return p ? p - s : -1;
}

static int next(void) {
    int c;

    if (_putback) {
        c = _putback;
        _putback = 0;
        return c;
    }

    c = fgetc(in_file);
    if ('\n' == c)
        line++;
    return c;
}

static void putback(int c) {
    _putback = c;
}

static int skip() {
    int c;
    c = next();

    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        c = next();
    }

    return c;
}

static int scanint(int c) {
    int k, val = 0;

    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    putback(c);
    return val;
}

int scan(struct token* t) {
    int c;

    c = skip();

    switch (c) {
        case EOF:
            return 0;
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            if (isdigit(c)) {
                t->int_value = scanint(c);
                t->token = T_INTLIT;
                break;
            }
            printf("Unrecognised character %c on line %d\n", c, line);
            exit(1);
    }

    return 1;
}
