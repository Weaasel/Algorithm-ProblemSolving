//반복
/*
  문자열의 문자 크기가 증가하는 형태라면 한번의 입력으로 표현할 수 있다.
  따라서 증가하지 않는 구간의 개수를 구하면 된다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>

using namespace std;

int sz, cnt;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	sz = s.size();
	for (int i = 1; i < sz; i++) {
		if (s[i - 1] >= s[i]) cnt++;
	}
	cout << cnt + 1;
	return 0;
}
