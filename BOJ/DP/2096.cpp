//내려가기
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
#define MAX 
#define DIV 1000000
#define INF 1000000000

using namespace std;
int n, arr[100001][3], pre[3], nex[3];

void init() {
	for (int i = 0; i < 3; i++) {
		pre[i] = arr[1][i];
	}
}

int mx(int n) {
	for (int i = 2; i <= n; i++) {
		nex[0] = arr[i][0] + max(pre[0], pre[1]);
		nex[1] = arr[i][1] + max(pre[2], max(pre[0], pre[1]));
		nex[2] = arr[i][2] + max(pre[2], pre[1]);
		pre[0] = nex[0]; pre[1] = nex[1]; pre[2] = nex[2];
	}
	return max(pre[0], max(pre[1], pre[2]));
}

int mn(int n) {
	for (int i = 2; i <= n; i++) {
		nex[0] = arr[i][0] + min(pre[0], pre[1]);
		nex[1] = arr[i][1] + min(pre[2], min(pre[0], pre[1]));
		nex[2] = arr[i][2] + min(pre[2], pre[1]);
		pre[0] = nex[0]; pre[1] = nex[1]; pre[2] = nex[2];
	}
	return min(pre[0], min(pre[1], pre[2]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	init();
	cout << mx(n) << " ";
	init();
	cout<< mn(n);

	return 0;
}
