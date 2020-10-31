//중복 제거
//Data Structure, Bitset
/*
  입력으로 주어지는 수들 중 처음 등장한 수만 출력하는 문제이다. 메모리가 8MB이다.
  수들을 전부 받아두고 vector unique를 이용해 중복을 제거하면 되는데, 수가 500만개가 들어와 불가능하다.
  그러면 등장한 수들에 대한 체크를 해둬야 하는데
  범위는 2^25개이기 때문에 이 역시 어렵다.
  Bitset을 사용하면 수 하나 당 1bit의 메모리로 체크해둘 수 있기 때문에 2^22 byte = 4MB 메모리로 해결이 가능하다.
  
  ps. 정해는 int 수가 32비트인 것을 이용해 배열값으로 32개 수의 존재여부를 체크하는 형태이다.
  이렇게 하면 2^25/32 = 2^20 사이즈 int 배열로 해결 가능하다.
  사실 이게 bitset의 구현이 아닌가 싶다.
*/

#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
bitset<33554433> bs;
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	bs.reset();
	while (cin >> n) {
		if (!bs[n]) {
			bs[n] = true;
			cout << n << " ";
		}
	}	
	return 0;
}
