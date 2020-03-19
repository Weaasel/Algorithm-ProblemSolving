//합이 0인 네 정수
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

int compare(const void*a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2) return -1;
	if (num1 > num2) return 1;
	return 0;
}
int a[4000], b[4000], c[4000], d[4000], ab[4000 * 4000], cd[4000 * 4000];
int main() {
	int n, i, j;
	long long realcnt = 0;
	int cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ab[cnt] = a[i] + b[j];
			cd[cnt++] = c[i] + d[j];
		}
	}
	sort(cd, cd + n * n);
	int left = 0, right = n * n;
	for (i = 0; i < n*n; i++) {
		while (left < right) {
			int mid = (left + right) / 2;
			if (ab[i] + cd[mid] < 0) left = mid + 1;
			else right = mid;
		}
		int lb = right;
		left = 0, right = n * n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (ab[i] + cd[mid] <= 0) left = mid + 1;
			else right = mid;
		}
		int rb = right;
		realcnt += (long long)(rb - lb);
		left = 0, right = n * n;
	}
	printf("%lld", realcnt);
}
