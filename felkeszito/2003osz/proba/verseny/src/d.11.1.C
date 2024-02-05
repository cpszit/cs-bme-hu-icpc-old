#include "stdio.h"

int fin[10], fout[10], N;
int stat[10], nstat = 0, scen = 0;

int test() {
	int stack[20], ss, res;

	for (int i = 0; i < N; i++) {
		stack[0] = fin[i];
		ss = 1;
		for (int j = 0; j < nstat; j++) {
			switch(stat[j]) {
			case 4:
				if (ss) {
					stack[ss] = stack[ss - 1];
					ss++;
				} else return 0;
				break;
			case 0:
				if (ss >= 2) {
					res = stack[ss - 1] + stack[ss - 2];
				} else return 0;
				break;
			case 1:
				if (ss >= 2) {
					res = stack[ss - 2] - stack[ss - 1];
				} else return 0;
				break;
			case 2:
				if (ss >= 2) {
					res = stack[ss - 1] * stack[ss - 2];
				} else return 0;
				break;
			case 3:
				if (ss >= 2) {
					if (stack[ss - 1] == 0) return 0;
					res = stack[ss - 2] / stack[ss - 1];
				} else return 0;
				break;
			}
			if (stat[j] <= 3) {
				if (abs(res) > 30000) return 0;
				stack[ss - 2] = res;
				ss -= 1;
			}
		}
		if (ss != 1) return 0;
		if (stack[0] != fout[i]) return 0;
	}

	return 1;
}

int solve(int Z) {
	if (nstat == Z) return test();
	nstat++;

	for (int i = 0; i <= 4; i++) {
		stat[nstat - 1] = i;
		if (solve(Z)) return 1;
	}

	nstat--;
	return 0;
}

int solve2() {
	for(int i = 0; i <= 10; i++) {
		nstat = 0;
		if (solve(i)) return 1;
	}
	return 0;
}

int main(void) {
	char *name[] = { "ADD", "SUB", "MUL", "DIV", "DUP" };

	for (;;) {
		scanf("%d\n", &N);
		if (!N) return 0;

		for (int i = 0; i < N; i++) scanf("%d", fin + i);
		for (int i = 0; i < N; i++) scanf("%d", fout + i);

		scen++;
		printf("Program %d\n", scen);
		nstat = 0;
		if (solve2()) {
			if (nstat) for (int i = 0; i < nstat; i++)
				printf("%s ", name[stat[i]]);
			else printf("Empty sequence");
		} else printf("Impossible");
		printf("\n\n");
	}
	return 0;
}
