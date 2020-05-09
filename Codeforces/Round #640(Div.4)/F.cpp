//F. Binary String Reconstruction

/*
  어떤 binary string(0과 1로만 이루어짐) 이 주어졌을 때, 길이가 2인 부분수열의 종류는 00, 01, 11, 10의 4가지이다.
  00, {01, 10}, 11 의 개수가 주어질 때(n0, n1, n2), 원래의 string을 제시하는 constructive한 문제였다.
  
  나는 000...00을 먼저 깔고, 010101을 반복해 깔고 마지막에 1을 깔았다.
  디테일이 조금 들어간다.
  1. 0을 깔 때, 00의 개수+1 개를 깔아야 하지만, 00의 개수가 0이라면 0 하나를 무조건 깔면 안된다.
  (n1이 0 이라면 1만 깔아야 한다.)
  2. 0과 1을 번갈아 깔 때는, 무조건 1에서 끝나도록 했다.
  0에서 끝내게 해버리면 이후에 1을 깔 때 문제가 생긴다. (01 개수가 하나 더 늠)
  만약 01의 개수가 2개씩 늘렸을 때 하나가 남는다면, 맨 마지막에 0을 하나 더 깔아주면 된다.
  3. 1 역시 n2가 없는 경우가 있어서 그냥 n2개를 깔면 안되고 적당히 처리해주면 된다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9
#define ll long long
using namespace std;
int T, n0, n1, n2;

int main() {
	cin >> T;
	while (T--) {
		cin >> n0 >> n1 >> n2;
		int cnt = 0, flg = 0;
		flg = (n1==0 && n2>0);
		if (n0 > 0 || n1 > 0) {
			for (int i = 0; i < n0 + 1; i++) {
				cout << 0;
				cnt++;
			}
		}
		if (n1 > 0) {
			cout << 1;
			n1--;
		}
		while (n1 > 1) {
			cout << "01";
			n1 -= 2;
		}
		for (int i = 0; i < n2 + flg; i++) cout << 1;
		if (n1 > 0) cout << 0;

		cout << "\n";
	}
}
