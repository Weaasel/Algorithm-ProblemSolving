//서로소
//소수판별, 포함-배제의 원리
/*
  [a, b] 구간에 존재하는 수들 중 n 과 서로소인 수의 개수를 세는 문제이다.
  우선 n을 소인수분해하여 소인수들을 d에 저장한다.
  이제 구간 [a, b] 에서,
  n과 1개 이상의 소인수가 겹치는 수들을 빼고,
  2개 이상의 소인수가 겹치는 수들을 더하고,
  ...
  를 반복한다.
  이렇게 n의 소인수들에 대해 각각을 포함/미포함 하는 경우를 완전탐색하면 구간 내 소인수의 개수를 구할 수 있다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, sz, chk[20];
ll a, b, res;
bool isP[35000];
vector<int> prime;
vector<int> d;

void init() {
    memset(isP, true, sizeof(isP));
    for(int i=2;i<sqrt(35000);i++) {
        if(!isP[i]) continue;
        for(int j=i*i;j<35000;j+=i) {
            isP[j]=false;
        }
    }
    for(int i=2;i<35000;i++) if(isP[i]) prime.pb(i);
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
        res += (b/r-(a-1)/r)*cnt;
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
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        d.clear();
        cin>>a>>b>>n;
        res = b-a+1;
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
        cout<<"Case #"<<tc<<": ";
        cout<<res<<"\n";
    }
    return 0;
}
