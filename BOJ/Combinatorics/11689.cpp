//GCD(n,k)=1
//소수판별, 포함-배제의 원리
/*
  [1, n] 구간에 존재하는 수들 중 n 과 서로소인 수의 개수를 세는 문제이다.
  우선 n을 소인수분해하여 소인수들을 d에 저장한다.
  이제 구간 [1, n] 에서,
  n과 1개 이상의 소인수가 겹치는 수들을 빼고,
  2개 이상의 소인수가 겹치는 수들을 더하고,
  ...
  를 반복한다.
  이렇게 n의 소인수들에 대해 각각을 포함/미포함 하는 경우를 완전탐색하면 구간 내 소인수의 개수를 구할 수 있다.
  완전탐색이 가능한 이유는 서로 다른 소인수의 개수가 최대 12개 이하이기 때문이다.(n <= 1e12) 
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
const int mxn = 1000001;
using namespace std;

ll n, nn, sz, res, chk[20];
bool isP[mxn];
vector<int> prime;
vector<ll> d;

void init() {
    memset(isP, true, sizeof(isP));
    for(int i=2;i<sqrt(mxn);i++) {
        if(!isP[i]) continue;
        for(int j=i*i;j<mxn;j+=i) {
            isP[j]=false;
        }
    }
    for(int i=2;i<mxn;i++) if(isP[i]) prime.pb(i);
    return;
}

void go(int idx) {
    if(idx==sz) {
        ll r = 1, cnt = 0;
        for(int i=0;i<sz;i++) {
            if(chk[i]) {
                r*=d[i], cnt++;
            }
        }
        if(!cnt) return;
        cnt=cnt%2==0?1:-1;
        res += (nn/r)*cnt;
        return;
    }
    chk[idx]=0;
    go(idx+1);
    chk[idx]=1;
    go(idx+1);
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    cin>>n;
    res = nn = n;
    for(int p:prime) {
        if(p>n)break;
        if(n%p==0) {
            d.pb(p);
            while(n%p==0) n/=p;
        }
    }
    if(n>1) d.pb(n);
    sz = d.size();
    go(0);
    cout<<res<<"\n";

    return 0;
}
