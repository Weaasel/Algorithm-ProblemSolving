//Nesting Depth

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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, depth = 0;
string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		depth = 0;
		cout << "Case #" << tc << ": ";
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			while (depth < str[i] - '0') {
				cout << "(";
				depth++;
			}
			while (depth > str[i] - '0') {
				cout << ")";
				depth--;
			}
			cout << str[i];
		}
		while (depth--) {
			cout << ")";
		}
		cout << "\n";
	}
	return 0;
}
