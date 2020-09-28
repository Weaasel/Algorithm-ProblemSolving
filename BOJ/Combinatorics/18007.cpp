//Rainbow String
//Combinatorics
/*
  각 알파벳이 최대 1개 포함되는 부분수열의 개수를 세는 문제이다.
  단순하게 각 알파벳의 등장횟수를 센 후에
  1을 더해 전부 곱하면 된다.
  (각 알파벳을 0개포함, 1번째 포함~k번째 포함)
*/

#include <iostream>
#include <string>
#define ll long long
#define DIV 11092019

using namespace std;

string s;
ll cnt[26], sz, res = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	sz = s.size();
	for (int i = 0; i < sz; i++) {
		cnt[s[i] - 'a']++;
	}
    for(int i=0;i<26;i++) {
        res *= cnt[i]+1;
        res %= DIV;
    }

	cout << res;
	return 0;
}
