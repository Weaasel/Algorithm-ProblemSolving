#include<stdio.h>
#include<stdlib.h>

int main() {
	int N, K, tmp, cnt = 0;
	scanf("%d %d", &N, &K);
	int* arr;
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = N - 1; i >= 0; i--) {
		tmp = K / arr[i];
		K -= tmp * arr[i];
		cnt += tmp;
	}
	printf("%d", cnt);
	return 0;
}
