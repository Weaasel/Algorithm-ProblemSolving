//D - Orac and Medians	
/*
  operation : 배열의 [l, r] 구간의 모든 값을 [l, r] 구간의 중앙값으로 전부 바꿀 수 있다.
  주어진 배열을 전부 k 로 바꿀 수 있는지 여부를 묻는 문제이다.
  
  이 operation이 가진 의미에 대해 생각해보자.
  1. k 이상의 수와 k가 연속한다면, k 이상의 수를 k로 바꿀 수 있다.
  2. 어떤 연속한 두 수가 k라면, 한 원소씩 확장하는 방식으로 모든 배열의 수를 k로 만들 수 있다.
  
  이 두가지 성질에 의해, 문제는 "주어진 배열을 모두 k 이상의 수로 만들 수 있는가?" 의 문제로 확장되고,
  
  이를 만족시키기 위해서는,
  1. 어떤 연속한 두 수가 모두 k 이상
  2. 연속한 세 수 중 두 수가 k 이상
  위의 두 조건 중 하나를 만족해야 함을 알 수 있다.  
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

int T, n, k, a[100001];
bool flg;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		flg = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == k) flg = 1;
		}
		if (!flg) {
			cout << "no\n";
			continue;
		}
		flg = false;
		if (n == 1) flg = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] >= k && a[i + 1] >= k) flg = true;
		}
		for (int i = 0; i < n - 2; i++) {
			if (a[i] >= k && a[i + 2] >= k) flg = true;
		}
		if (flg) cout << "yes\n";
		else cout << "no\n";
	}

}
