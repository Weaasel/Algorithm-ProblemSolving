//A. Determinant
/*
  2x2 행렬이 주어질 때 determinant(ad-bc) 를 출력하는 문제.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

int a, b, c, d;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c >> d;
	cout << a * d - b * c;
	return 0;
}
