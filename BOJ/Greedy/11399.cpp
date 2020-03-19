#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, smallest, tmp;
	long sum = 0;
	scanf("%d", &N);
	int* p;
	p = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		smallest = i;
		for (int j = i+1; j < N; j++) {
			if (p[j] < p[smallest]) smallest = j;
		}
		tmp = p[i];
		p[i] = p[smallest];
		p[smallest] = tmp;
	}
	for (int i = 0; i < N; i++) {
		sum += p[i] * (N - i);
	}
	printf("%ld", sum);
	return 0;
}
