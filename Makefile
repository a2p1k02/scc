scc: src/expr.c src/interp.c src/tree.c src/main.c src/scan.c
	cc -o scc src/expr.c src/interp.c src/tree.c src/main.c src/scan.c

clean:
	rm -rf scc *.o
