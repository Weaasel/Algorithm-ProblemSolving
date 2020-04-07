//BAPC 2018 Preliminaries B. Bee Problem
//BFS

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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000
using namespace std;

int dx[6] = { 0,0,-1,-1,1,1 };
int dy[6] = { -2,2,-1,1,-1,1 };
int n, m, h;
//char honey[1001][2001];
string honey[1000];
int visited[1000][2001];
vector<int> greedy;

bool cmp(int a, int b) {
	return a > b;
}

int dfs(int row, int col) {
	int ret = 1;
	visited[row][col] = 1;
	for (int i = 0; i < 6; i++) {
		if (row + dx[i] >= n || row + dx[i] < 0 || col + dy[i] >= 2 * m || col + dy[i] < 0)
			continue;

		if (!visited[row + dx[i]][col + dy[i]] && honey[row + dx[i]][col + dy[i]] == '.')
			ret += dfs(row + dx[i], col + dy[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> h >> n >> m;
	getline(cin, honey[0]);
	for (int i = 0; i < n; i++) {		
		getline(cin, honey[i]);
		if (i % 2 == 0)
			honey[i].push_back(' ');
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * m; j++)
			if (visited[i][j] == 0 && honey[i][j] == '.')
				greedy.push_back(dfs(i, j));
	sort(greedy.begin(), greedy.end(), cmp);
	int ans = 0;
	int idx = 0;
	while (idx<greedy.size() && h >0) {
		h -= greedy[idx++];
		ans++;
	}
	cout << ans;
}
