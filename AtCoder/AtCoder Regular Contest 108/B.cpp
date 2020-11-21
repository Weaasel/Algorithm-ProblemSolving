//B - Abbreviate Fox	

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

int n, c;
string s;
stack<char> st;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'x') st.push(s[i]);
		else {
			if (st.size() < 2) st.push(s[i]);
			else {
				char c1 = st.top(); st.pop();
				char c2 = st.top();
				if (c1 == 'o' && c2 == 'f') {
					c++;
					st.pop();
				}
				else {
					st.push(c1);
					st.push(s[i]);
				}
			}
		}
	}

	cout << n - c * 3;
	return 0;
}
