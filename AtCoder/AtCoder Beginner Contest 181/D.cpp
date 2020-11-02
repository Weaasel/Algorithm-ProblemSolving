//D - Hachi
/*
  주어진 한자리 수(1~9)들을 적절히 배치해 8의 배수로 만들 수 있냐를 묻는 문제이다.
  8의 배수가 되기 위한 조건은 맨 뒤 세 자리수가 8의 배수여야 한다이기 때문에,
  1 ~ 999까지 중 모든 8의 배수들에 대해 이러한 수를 만들 수 있는지 검사해 주면 된다.
  주의할 점은 주어진 수의 자리수이다.
  만약 주어진 수가 4자리수라면, 8같은 수는 만들 수가 없다. 8을 만들기 위해 008을 만들어야 하기 때문이다.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[10];
bool flg;
string s;

bool chk(int n) {
	int ccnt[10];
	for (int i = 0; i < 10; i++) ccnt[i] = 0;
	while (n > 0) {
		ccnt[n % 10]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) if (ccnt[i] > cnt[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for (char c : s) cnt[c - '0']++;
	if (s.size() == 1) {
		for (int i = 1; i < 10; i++) {
			//i를 만들 수 있는지
			if (!chk(i)) continue;
			if (i % 8 == 0) flg = true;
		}
	}
	else if (s.size() == 2) {
		for (int i = 10; i < 100; i++) {
			//i를 만들 수 있는지
			if (!chk(i)) continue;
			if (i % 8 == 0) flg = true;
		}
	}
	else {
		for (int i = 100; i < 999; i++) {
			//i를 만들 수 있는지
			if (!chk(i)) continue;
			if (i % 8 == 0) flg = true;
		}
	}

	if (flg) cout << "Yes";
	else cout << "No";
	return 0;
}
