//B. Quizzes
/*
  초기점수가 주어지고 o, x로 이루어진 문자열이 주어지는데 앞에서부터 읽으며
  o면 점수 +1점, x면 -1점으로 계산해서 최종점수를 출력한다. 점수는 0점 미만으로 내려갈 수 없다.
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

int n, x;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') x++;
		else x = max(0, x - 1);
	}
	cout << x;
	return 0;
}
