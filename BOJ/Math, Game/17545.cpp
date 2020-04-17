// Deceptive Dice
// 기대값을 구하는 문제. 최대 k번 던질 기회가 있을 때의 기대값을 k-1번 던질 기대값을 이용해 구해나간다.

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int n, m, k;
double f(int k) {
	if (k == 1) return (double)(n + 1) / 2;
	double res = f(k - 1);

	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i > res) cnt++, sum += i;
	}
	return double(sum) / n + double(n - cnt) / n * res;
}

vector<int> a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	printf("%.8lf", f(k));
	return 0;
}
