//B - Last Year's Substring	
/*
  주어진 문자열에서 한 substring을 들어내어 "2020"으로 만들 수 있는 지 여부를 묻는 문제이다.
  "2020"이 길이 4인 문자열이기 때문에 될 수 있는 후보는 최대 5가지이다.
  ____
  ___ _
  __ __
  _ ___
   ____
  로 표현 가능하다. 이 경우들에 대해 검사해 주자.
*/

#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		bool flg = false;
		if (s == "2020") flg = true;

		for (int i = 0; i < 5; i++) {
			string tmp = "";
			for (int j = 0; j < i; j++) tmp += s[j];
			for (int j = n - 4 + i; j < n; j++) tmp += s[j];
			if (tmp == "2020") flg = true;
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
