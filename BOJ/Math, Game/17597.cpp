//Zipline
/*
  그림 없이 설명하기가 매우 어렵다.
  세 기둥 중 중간 기둥만큼 바닥을 위로 올리고,
  오른쪽 기둥을 반전시켜서 두 점의 직선거리를 구하면 해결이다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;

int T;
double w, g, h, r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while (T--) {
		cin >> w >> g >> h >> r;
		printf("%.7lf ", sqrt((g - h)*(g - h) + w * w));
		printf("%.7lf\n", sqrt((g + h - r - r)*(g + h - r - r) + w * w));
	}

	return 0;
}
