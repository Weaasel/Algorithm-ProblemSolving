//1학년
//dp

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

ll dp[21][101];
int arr[101], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[arr[0]][0] = 1;
	for (int i = 1; i < n - 1; i++) {
		int a = 1;
		for (int j = 0; j < 21; j++) {
			if (j - arr[i] >= 0 && j - arr[i] <= 20) dp[j][i] += dp[j - arr[i]][i - 1];
			if (j + arr[i] >= 0 && j + arr[i] <= 20) dp[j][i] += dp[j + arr[i]][i - 1];
		}
	}
	cout << dp[arr[n - 1]][n - 2];
}
