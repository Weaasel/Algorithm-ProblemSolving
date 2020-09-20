//Janitor Troubles
//Math
/*
  브라마굽타의 공식... 이라는 공식이다.
  원에 내접하는 사각형의 네 변의 길이를 a, b, c, d라고 할 때, s = (a+b+c+d)/2 라 하자.
  사각형의 넓이 S = sqrt((s-a)*(s-b)*(s-c)*(s-d)) 가 된다.
  심지어 흔히 쓰던 헤론의 공식이 여기에서 d=0 으로 만든 특수 케이스로 나온 공식이다.
*/

#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
#define DIV 1000000007

using namespace std;

double s, a[4];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	s = (a[0] + a[1] + a[2] + a[3]) / 2;
	printf("%.6lf", sqrt((s - a[0])*(s - a[1])*(s - a[2])*(s - a[3])));
	return 0;
}
