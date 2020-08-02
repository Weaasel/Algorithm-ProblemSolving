//사과나무
//math
/*
  사과나무 N 그루의 높이가 주어질 때,
  높이가 전부 0인 상태에서 시작하여 주어진 상태로 만들 수 있는지를 출력하는 문제이다.
  할 수 있는 작업은 높이를 1 증가시키는 물뿌리개와 2 증가시키는 물뿌리개를 한 번씩 뿌리는 일이다.
  우선 높이가 홀수인 나무는 1물뿌리개를 무조건 한 번 이상 뿌렸어야 한다.
  그 이후부터는 모든 나무의 높이가 짝수이기 때문에, 높이 2를 증가시키기 위해 1물뿌리개 2번 / 2물뿌리개 1번 중 선택할 수 있다.
  이 횟수를 잘 분배해서 총 횟수를 같게 나누면 되는데,
  1물뿌리개를 뿌렸던 최소 횟수만큼 2물뿌리개를 뿌리고, 남은 나무 높이의 합이 3의 배수인지 여부가 답이 됨을 알 수 있다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#define ll long long
#define INF 1e9 + 7
#define pb push_back
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
using namespace std;

int n, h, sum, odd;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		sum += h;
		if (h % 2 == 1) odd++;
	}
	sum -= 3 * odd;
	if (sum >= 0 && sum % 3 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
