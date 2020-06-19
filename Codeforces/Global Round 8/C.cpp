//C - Even Picture	
/*
  주어진 조건을 만족시키면서 1개의 갇힌 cell을 만드는 구조는
     OO
    OOO
    OO
  모양이다. 이제 필요한 cell의 개수만큼 이 구조를 확장해 나가면 된다.
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
#define INF 1e+9

using namespace std;
int n;
vector<pii> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	v.pb({ 0,0 });
	for (int i = 0; i <= n; i++) {
		v.pb({ i, i + 1 });
		v.pb({ i + 1, i + 1 });
		v.pb({ i + 1, i});
	}
	cout << v.size() << "\n";
	for (pii p : v) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
