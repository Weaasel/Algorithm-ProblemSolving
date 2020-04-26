//B - Binary Period	

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
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
using namespace std;

int T;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		int len = s.size();
		bool flg = 0;
		for (int i = 0; i < len - 1; i++) {
			if (s[i] != s[i + 1]) flg = 1;
		}
		if (flg) {
			for (int i = 0; i < len; i++) {
				cout << "10";
			}
			cout << "\n";
		}
		else {
			cout << s << "\n";
		}
	}
	return 0;
}
