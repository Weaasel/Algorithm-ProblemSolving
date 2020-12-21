//C. Poman Numbers
//constructive, bitmasks, math
/*
  주어진 operation을 가지고 |S|가 1일 때부터 5일 때까지 모든 경우를 따져봤다.
  전부 따져보는 것은 어렵지 않다. 예컨대 길이가 5라면 1+4, 2+3, 3+2, 4+1 을 합치는 느낌이기 때문에.
  다음과 같은 관찰을할 수 있었다.
  맨 뒤에 있는 알파벳은 무조건 더해야 하고, 그 앞에 있는 알파벳은 무조건 빼야 하고, 나머지는 더하던 빼던 마음대로.
  따라서 이 문제는 knapsack-like 문제가 되었다.
  
  아직 완전히 이해하지 못했는데, 이런 식으로 풀 수 있음을 알았다.
  각 비트의 수들을 적당히 더하거나 빼서 T를 만들 수 있는지 여부를 알고 싶을때,
  우선 전부 더한다.
  상위비트부터 보면서 T가 2*상위비트보다 크면 뺀다. (빼는게 더한거->뺀거로 바꾸는 것이기 때문에 값*2가 빠져야 됨)
  이런식으로 쭉 내려왔을 때, T가 0이어야 한다.
  글을 쓰면서 생각해보니 이런 그리디한 풀이가 무조건 맞는 것 같다. 한 수 배웠다.
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, cnt[61], chk[61];
string s;
ll T;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> T;
	cin >> s;
	T += pow(2, s[n - 2] - 'a') - pow(2, s[n - 1] - 'a');
	T = abs(T);
	for (int i = 0; i < n - 2; i++) {
		cnt[s[i] - 'a']++;
		T += pow(2, s[i] - 'a');
	}
	for (int i = 60; i >= 0; i--) {
		while (cnt[i] && pow(2, i + 1) <= T) {
			cnt[i]--;
			T -= pow(2, i + 1);
		}
	}
	if (T != 0) cout << "No";
	else cout << "Yes";
	return 0;
}
