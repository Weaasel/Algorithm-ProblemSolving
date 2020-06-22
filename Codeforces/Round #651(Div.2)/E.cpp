//E - Binary Subsequence Rotation	
/*
  일단 주어진 두 string이 0의 개수가 서로 다른 경우가 -1 case인 것을 처리한다.
  1로 바뀌어야 할 것을 1, 0으로 바뀌어야 할 것을 0이라고 하면,
  늘어선 0과 1들의 수열에서,
  0101...01 type의 chain과 1010...10 type의 체인을 적절히 사용해가며 최소 개수의 chain을 구하면 되는 문제이다.
  여기까진 쉽게 보인다.
  그래서 그걸 어떻게 세? 가 해결이 안돼서 upsolving 한 문제이다.
  
  c0 : 0으로 끝나는 체인의 개수
  c1 : 1로 끝나는 체인의 개수
  라고 정의하고, 앞에서부터 본다.
  
  val[i] == 0이고 앞서 내가 1로 끝나는 체인을 1개 이상 갖고 있었다면, 그 뒤에 이어주면 된다.
  그렇게 되면 c1은 1개 감소할 것이고, c0는 1개 증가하여 전체 개수는 유지될 것이다.
  그런 체인이 없었다면, 0으로 끝나는 체인만 하나 늘어나게 된다. 전체 개수도 하나 늘어나게 된다.
  
  이렇게 처음부터 끝까지 세고, c0 + c1을 더하면 된다.
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

int n, cnt1, cnt2, res1, res2;
int cons1[1000001], cons2[1000001];
int val[1000001];
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		if (s1[i] == '0') cnt1++;
		if (s2[i] == '0') cnt2++;
	}
	if (cnt1 != cnt2) cout << -1;
	else {
		int wlk = 0;
		for (int i = 0; i < n; i++) {
			if (s1[i] == s2[i]) continue;
			if (s1[i] == '1') val[wlk++] = 0;
			else val[wlk++] = 1;
		}
		if (wlk == 0) cout << 0;
		else {
			int c0 = 0, c1 = 0; //0으로 끝나는 체인, 1로 끝나는 체인
			for (int i = 0; i < wlk; i++) {
				if (val[i] == 0) {
					c0++;
					if (c1 > 0) c1--;
				}
				else {
					c1++;
					if (c0 > 0) c0--;
				}
			}
			cout << c0 + c1;
		}
	}
	return 0;
}
