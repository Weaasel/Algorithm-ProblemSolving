//소수상근수
//math
/*
  어떤 소수를 자릿수의 제곱의 합으로 계속 나타냈을 때, 그 수가 1이 되면 '소수상근수' 라고 한다.
  주어진 n에 대해 n 이하의 소수상근수를 전부 구히면 되는데, n이 최대 10^6 이기 때문에,
  수는 6자리까지 나올 수 있고, 999999의 모든 자리수의 제곱의 합이 500 미만인 것을 알 수 있다.
  따라서 어떤 수에 대해 검사를 할 때 최대 500번의 반복연산만 하면 그 수가 소수상근수인지 아닌지 알 수 있다.
  같은 수가 2번 이상 나오면 절대 1이 될 수 없기 때문이다.
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
#define INF 1e9+7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;
const int mx = 100001;

vector<int> prime;
int n, isp[1000001];
void init() {
    memset(isp,true,sizeof isp);
    for(int i=2;i<sqrt(1000001);i++) {
        if(!isp[i]) continue;
        for(int j=i*i;j<1000001;j+=i) {
            isp[j]=false;
        }
    }
    for(int i=2;i<1000001;i++) if(isp[i]) prime.pb(i);
}

bool go(int p) {
    bool chk[500];
    memset(chk,false,sizeof chk);
    while(1) {
        int curp = p, newp = 0;
        while(p>0) {
            newp += (p%10)*(p%10);
            p/=10;
        }
        if(newp==1) return true;
        if(chk[newp]) return false;
        p=newp;
        chk[p] = true;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    cin>>n;
    for(int p:prime) {
        if(p>n) break;
        if(go(p)) cout<<p<<"\n";
    }
    return 0;
}
