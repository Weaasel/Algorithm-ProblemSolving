//A - FashionabLee	
/*
  180도 - 내각 이 정수배를 했을 때 90도가 되어야 한다.
  그냥 4의배수 각형이면 위 조건을 만족한다.
  이 사실을 너무 늦게 캐치했다.
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

ll T, n;
int a[200001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n % 4 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
