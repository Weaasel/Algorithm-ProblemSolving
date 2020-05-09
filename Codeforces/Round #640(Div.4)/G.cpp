//G. Special Permutation
/*
  [1, 2, ..., n] 인 집합의 순서를 적당히 잘 섞은 것을 permutation이라고 한다.
  n이 주어질 때, 인접한 모든 ai, aj 에 대해
  2 <= abs(ai - aj) <= 4 가 되도록 할 수 있는지, 할 수 있다면 그 순열을 묻는 문제다.
  
  잘 들여다 보면, n = 4일 때 [3, 1, 4, 2] 가 조건을 만족함을 알 수 있고,
  이 때 각 끝 원소가 3, 2 이므로,
  n = 5, 6, 7 ... 에 대해
  n = 4인 배열을 base로 두고 양옆에 하나씩 번갈아 붙여 나가면 된다.
  
  n = 5 : [3, 1, 4, 2, 5]
  n = 6 : [6, 3, 1, 4, 2 ,5]
  ...
  
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9
#define ll long long
using namespace std;
int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		if (n < 4) cout << "-1\n";
		else {
			int l = n % 2 == 0 ? n : n - 1;
			int r = n % 2 == 0 ? n - 1 : n;
			for (int i = l; i > 5; i -= 2) cout << i << " ";
			cout << "3 1 4 2 ";
			for (int i = 5; i <= r; i += 2) cout << i << " ";
			cout << "\n";
		}
	}
}
