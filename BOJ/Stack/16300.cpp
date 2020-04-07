//BAPC 2018 Preliminaries H. HtoO
//stack

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

string str;
int n, len, cnt[26], need[26], walk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> n;

	len = str.size();
	stack<char> s;
	while (walk < len) {
		if (str[walk] <= 'Z' && str[walk] >= 'A') {
			s.push(str[walk]);
			walk++;
		}
		else {
			int c = 0;
			while (str[walk] <= '9' && str[walk] >= '0') {
				c *= 10;
				c += str[walk] - '0';
				walk++;
			}
			char tmp = s.top(); s.pop();
			cnt[tmp - 'A'] += c;
		}
	}
	while (!s.empty()) {
		char tmp = s.top(); s.pop();
		cnt[tmp - 'A'] ++;
	}
	for (int i = 0; i < 26; i++) cnt[i] *= n;

	cin >> str;
	//need에 똑같이 진행
	walk = 0;
	len = str.size();
	while (walk < len) {
		if (str[walk] <= 'Z' && str[walk] >= 'A') {
			s.push(str[walk]);
			walk++;
		}
		else {
			int c = 0;
			while (str[walk] <= '9' && str[walk] >= '0') {
				c *= 10;
				c += str[walk] - '0';
				walk++;
			}
			char tmp = s.top(); s.pop();
			need[tmp - 'A'] += c;
		}
	}
	while (!s.empty()) {
		char tmp = s.top(); s.pop();
		need[tmp - 'A'] ++;
	}

	int res = INF;
	for (int i = 0; i < 26; i++) {
		if (!need[i]) continue;
		res = min(res, cnt[i] / need[i]);
	}
	cout << res;
	return 0;
}
