//Coprime integers
//Math, Number Theory, Mobius function
/*
  주어진 두 구간에서 서로소인 쌍의 개수를 구하는 문제이다.
  -> 전체 쌍 개수중 서로소가 아닌 쌍의 개수를 뺀다.
  -> gcd가 1이 아닌 쌍의 개수를 뺀다.
  
  1. 2의배수, 3의배수, 5의배수 ...
  2. 6의배수, 10의배수, 15의배수 ... 은 2번씩 빠졌으니 더해줘야 한다.
  -> 포함배제의 원리로 소인수 1개짜리, 2개짜리, 3개짜리 ... 들에 대해 빼고 더하고를 반복.
  -> 소인수가 짝수개인지 홀수개인지의 여부를 mobius function으로 판단한다.
  
  **Appendix
  뫼비우스 함수는
  M(n) = 1 (n = 1)
         0 (n이 어떤 소수 p에 대해 p^2|n 일 때)
         (-1)^r (n=p1*p2*...*pr 꼴일 때, p1, ... pr 은 prime)
  로 정의되는 함수이다.  
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#define pb push_back
#define ll long long
const ll INF = 2e9;
const int mx = 10000001;
using namespace std;

ll a, b, c, d;
int mobius[mx];

void init() {
    fill(mobius, mobius+mx, 1);
    //memset(mobius, 1, sizeof(mobius));
    for (int i = 2; i * i <= mx; i++)
        if (mobius[i] == 1) { //prime들에 대해
            for (int j = i; j <= mx; j += i) mobius[j] *= -i;
            for (int j = i * i; j <= mx; j += i * i) mobius[j] = 0;
        }

    for (int i = 2; i <= mx; i++) {
        if (mobius[i] == i) mobius[i] = 1;
        else if (mobius[i] == -i) mobius[i] = -1;
        else if (mobius[i] < 0) mobius[i] = 1;
        else if (mobius[i] > 0) mobius[i] = -1;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>a>>b>>c>>d;
    ll res = (b-a+1)*(d-c+1);
    for(int i=2;i<=mx;i++) {
        res += (b/i-(a-1)/i)*(d/i-(c-1)/i) * mobius[i];
    }
    cout<<res;
    return 0;
}
