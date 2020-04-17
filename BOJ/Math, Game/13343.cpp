//Block Game
/*
  내가 이기기 위한 조건은 다음과 같다.
  1. 실제로 블럭을 전부 없앨 수 있거나
  2. 상대에게 원하는 state를 줄 수 있을 때
*/

#include <iostream>
#include <cstdio>
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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

ll a, b;
bool win = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;

	while (1) {
		if (a < b) swap(a, b);
		if (a%b == 0) break;
		if (a > 2 * b) break;
		a -= b;
		win = !win;
	}
	if (win) cout << "win";
	else cout << "lose";
	return 0;
}
