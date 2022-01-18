all: src/cg.c src/gen.c src/expr.c src/misc.c src/stmt.c src/tree.c src/main.c src/scan.c
	cc -o scc src/cg.c src/gen.c src/expr.c src/misc.c src/stmt.c src/tree.c src/main.c src/scan.c

clean:
	rm -rf scc *.o *.s out
