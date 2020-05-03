//Abandoned Animal
/*
  문제를 환원하자면,
  주어진 조건을 만족하는 경로들이 존재하지 않는지(IMPOSSIBLE) / 유일한지(unique) / 여러 개인지(ambiguous) 출력하는 문제이다.
  
  경로를 찾기 위해 모든 경우들을 탐색하려는 시도는 입력 범위에 의해 무조건 TLE를 받게 될 것이다.
  
  모든 경로중, 좌측으로 가장 밀착시킨 경로와, 우측으로 가장 밀착시킨 경로를 구해 두 경로가 서로 다르면 ambiguous를 출력하도록 했다.
  (실제로 좌측, 우측이라는 방향은 존재하지 않지만 편의상 이렇게 설명했다.)
  (즉 되도록 앞의 가게에서 물건을 사는 경로와, 되도록 뒤의 가게에서 물건을 사는 경로를 뜻한다.)
*/

#include <iostream>
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
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

int n, k, m;

int a;
string s;
vector<int> res1, res2;

map<string, vector<int>> mp1;
map<string, vector<int>> mp2;
vector<string> query;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> s;
		mp1[s].pb(a);
		mp2[s].pb(-a);
	}

	for (auto &vec : mp1) {
		sort(all(vec.second));
	}
	for (auto& vec : mp2) {
		sort(all(vec.second));
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		query.pb(s);
	}

	int cur = 0, flg = 0;
	for (int i = 0; i < m; i++) {
		if (mp1[query[i]].empty()) {
			flg = 1;
			break;
		}
		int idx = lower_bound(all(mp1[query[i]]), cur) - mp1[query[i]].begin();
		if (idx == mp1[query[i]].size()) {
			flg = 1;
			break;
		}
		res1.pb(mp1[query[i]][idx]);
		cur = mp1[query[i]][idx];
	}

	cur = -n+1;
	for (int i = m - 1; i >= 0; i--) {
		if (mp2[query[i]].empty()) {
			flg = 1;
			break;
		}
		int idx = lower_bound(all(mp2[query[i]]), cur) - mp2[query[i]].begin();
		if (idx == mp2[query[i]].size()) {
			flg = 1;
			break;
		}
		res2.pb(-mp2[query[i]][idx]);
		cur = mp2[query[i]][idx];
	}
	reverse(all(res2));
	if (flg) cout << "impossible";
	else if (res1 == res2) cout << "unique";
	else cout << "ambiguous";

	return 0;
}
