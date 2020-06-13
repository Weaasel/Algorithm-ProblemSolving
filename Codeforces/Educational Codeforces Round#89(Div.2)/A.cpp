//A - Shovels and Swords
/*
  a >= 2*b 라면 어차피 b개만큼밖에 못만든다.
  a < 2*b 라면 위의 상태가 될때까지 2*b로 만든다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
const ll INF = 4e10;

using namespace std;
int T, n;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a >= 2 * b) cout << b << "\n";
		else {
			int k = (2 * b - a) / 3;
			a -= 3 * k, b -= 3 * k;
			cout << 2 * k + min(a/2,b) << "\n";
		}
	}
	return 0;
}
