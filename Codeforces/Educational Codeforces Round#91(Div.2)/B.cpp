//B - Universal Solution	
//Greedy
/*
  가위바위보 조합을 어떻게 정해도 기대값의 합은 각각의 선택이 모든 RPS들과 승부를 내야 한다.
  즉 RPS 중 가장 많이 나오는 것을 이기는 수로 전부 채우는 것이 이득이다.
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
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, R, S, P;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> s;
		int sz = s.size();
		R = 0, S = 0, P = 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] == 'R') R++;
			else if (s[i] == 'S') S++;
			else P++;
		}
		if (R >= S && R >= P) {
			for (int i = 0; i < sz; i++) cout << "P";
		}
		else if (S >= R && S >= P) {
			for (int i = 0; i < sz; i++) cout << "R";
		}
		else {
			for (int i = 0; i < sz; i++) cout << "S";
		}
		cout << "\n";
	}
	return 0;
}
