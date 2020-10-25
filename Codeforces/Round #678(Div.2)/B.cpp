//B - Prime Square	
/*
  각 row와 column에 대해 모든 수의 합이 소수가 되는 n*n 크기의 배열을 만들어야 한다.
  각 위치 arr[i][j]에 적힌 수는 1 이상의 non-prime이어야 한다.
  간단하게 모든 수를 1로 깔고, 어떤 수 A를 정의해 1*(n-1) + A 가 prime이 되게 하자.
  ex) 4*4 array
    1 1 1 A
    1 1 A 1
    1 A 1 1
    A 1 1 1
  과 같은 형태로 출력하면 모든 row와 column들에 대해 조건을 만족시킬 수 있겠다.
  이제 우리가 할 일은 n-1 + A 가 prime인 not-prime A를 찾으면 된다.
  이건 A = 1 ~ 10000의 완전탐색을 통해 얻을 수 있다고 생각했다.
  증명은 없다. (...)
*/

#include <iostream>
#include <string>

using namespace std;

int T, n;
bool chk[10101];
void era() {
	memset(chk, true, sizeof chk);
	for (int i = 2; i < sqrt(10101); i++) {
		if (!chk[i]) continue;
		for (int j = i * i; j < 10101; j += i) {
			chk[j] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	era();
	while (T--) {
		cin >> n;
		if (chk[n]) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << "1 ";
				}
				cout << "\n";
			}
		}
		else {
			int wlk = n;
			while (!chk[wlk] || chk[wlk - n + 1]) wlk++;
			int p = wlk - n + 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j == i) cout << p << " ";
					else cout << "1 ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}
