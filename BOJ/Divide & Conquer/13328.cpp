//Message Passing
/*
  dp점화식을 구해 행렬 거듭제곱 연산으로 푸는 기본적인 유형이다.
  보통 행렬 거듭제곱 풀이로 넘어가는 문제들은
  
  dp[n] = a1*dp[n-1] + a2*dp[n-2] + ... + ak*dp[n-k]
  꼴로 나타나는 것 같다.
  즉, 현재의 값을 구하기 위해 필요한 요소가 이전 k개이고, k가 충분히 작을 때 쓸 수 있는 것 같다.
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define DIV 31991
#define MAX_SIZE 101
using namespace std;
using ull = long long;

struct M {
	ull matrix[MAX_SIZE][MAX_SIZE] = { 0 };
};

M base;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) base.matrix[i][i] = 1;
}

M assign(M m, ull b[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			m.matrix[i][j] = b[i][j] % DIV;
		}
	}
	return m;
}

M mul(M a, M b) {
	M ret;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			ret.matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			for (int k = 0; k < MAX_SIZE; k++) {
				ret.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
				ret.matrix[i][j] %= DIV;
			}
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			ret.matrix[i][j] %= DIV;
		}
	}
	return ret;
}

M pow(ull m[MAX_SIZE][MAX_SIZE], ull n) {
	M ret;
	if (n == 0) return base;
	if (n == 1) return assign(ret, m);

	M tmp = pow(m, n / 2);
	ret = mul(tmp, tmp);
	if (n % 2) {
		M t;
		ret = mul(ret, assign(t, m));
	}
	return ret;
}

ull d, t, k, a, b, mat[MAX_SIZE][MAX_SIZE];
ull dp[MAX_SIZE][MAX_SIZE];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> d >> t;
	init();
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= d; i++) {
		dp[i][0] = 2 * dp[i - 1][0] % DIV;
	}

	for (int i = 0; i < d; i++) {
		mat[i][i + 1] = 1;
	}
	mat[d][0] = DIV - 1, mat[d][d] = 2;


	M res = pow(mat, t);
	M ret = mul(res, assign(base, dp));
	cout << ret.matrix[0][0];

	return 0;
}
