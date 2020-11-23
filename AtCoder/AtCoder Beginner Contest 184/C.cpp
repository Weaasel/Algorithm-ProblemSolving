//C. Super Ryuma
/*
  격자상에서 어떤 점으로부터(그림의 노란 점) 한번의 이동으로 이동할 수 있는 점들을 표현한 그림이다.
  X자로 교차하는 선은 무한한 직선이다.
  이 때, 주어진 (x1,y1) -> (x2,y2) 로 이동하기 위한 최소 이동 횟수를 구하는 문제이다. 적당한 Case work를 하자.
  abc의 세번째 문제도 보통 이렇게 거저다. 라고 하고 싶은데 너무 귀찮았다ㅠㅠ
  이 격자판을 체스판이라고 생각하면 흰색 격자에서 흰색 격자로는 무조건 2번 이하로 이동이 가능하다.
  따라서 모든 점에 대해 3번 이하로 이동이 가능하다.
  따라서 대각선으로 이동 가능하니? 를 return하는 line함수, 마름모 영역 안에 있니? 를 return하는 square 함수를 정의해 두고,
  0번 1번 2번이 필요한 경우에 대해 각각 검사한다. (최대 3번이면 어디든 갈 수 있기 때문에)
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

bool line(int x1, int y1, int x2, int y2) {
	if (x1 + y1 == x2 + y2) return true;
	if (x1 - y1 == x2 - y2) return true;
	return false;
}

bool square(int x1, int y1, int x2, int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 3) return true;
	return false;
}

int r1, c1, r2, c2;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;
	if (r1 == r2 && c1 == c2) return cout << 0, 0;
	if (line(r1, c1, r2, c2) || square(r1, c1, r2, c2)) return cout << 1, 0;
	if ((r1 + c1) % 2 == (r2 + c2) % 2) return cout << 2, 0;
	for (int i = -3; i <= 3; i++) {
		for (int j = -3; j <= 3; j++) {
			if (square(r1, c1, r1 + i, c1 + j) && line(r1 + i, c1 + j, r2, c2)) return cout << 2, 0;
		}
	}
	cout << 3;
	return 0;
}
