//Jackpot
//math
/*
  어떤 조건 하에서 기댓값의 최대값을 구하는 문제이다.
  func 함수가 변수 x에 따른 값 함수이다.
  
  이 함수는 2차함수/1차함수 꼴을 가지고, 미분하고 개형을 그려보면 삼차함수 꼴이 나오기 때문에
  양 끝점과 극대값 세 점만 비교하면 구간 최대값을 구할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

double n, m, f, res;

double func(double x) {
    return (m - f * f*x*x) / (n - x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> f;
    if (n*f*f <= m / n) res = max(func(0), func(n - 1));
    else {
        double lmx = n - sqrt(f*f - (m / n) / n) * n / f;
        double lmx1 = floor(lmx), lmx2 = ceil(lmx);

        if (lmx1 > n || lmx1 < 0) lmx1 = 0;
        if (lmx2 > n || lmx2 < 0) lmx2 = 0;

        double r = sqrt(m) / f;
        r = floor(r);
        res = max({ func(0),func(lmx1),func(lmx2),func(r), func(n-1) });
    }
    printf("%.7lf", res);
    return 0;
}
