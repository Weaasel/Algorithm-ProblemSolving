//베스킨라빈스 31
//Constructive, Mathematics
/*
  연속해서 부를 수 있는 수의 최대 개수 n에 대해, 31게임의 필승전략이 존재하냐 안하냐 묻는 문제이다.
  31게임은 결국 30을 부르면 이긴다.
  필승전략은 다음과 같다.
  어떤 수를 부르고 그 다음부터 상대가 부르는 수의 개수에 따라 맞춰갈 수 있으면 된다.
  ex) n이 6이라면
  처음에 1,2 까지만 부르고, 이후로 상대가 어떤 수를 부르던 6+1=7의 배수를 맞춰갈 수 있기 때문에 30을 부를 수 있게 된다.
*/

#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		bool flg = false;
		for (int j = 1; j <= i; j++) {
			if ((30 - j) % (i + 1) == 0) flg = true;
		}
		if (!flg) cout << i << "\n";
	}
	return 0;
}
