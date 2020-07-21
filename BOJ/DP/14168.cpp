//Cow checklist
//DP
/*
  3차원 dp.
  dp[i][j][type]: 두 타입의 소들을 각각 i번째, j번째까지 봤고 Hi, Gj 중 마지막으로 방문한 타입(0,1)에 따른 최단거리
  if type == 0 이라면 마지막 소가 Hi 라는 뜻이므로,
    (dp[i-1][j][0] + Hi-1 ~ Hi 거리), (dp[i-1][j][1] + Gj ~ Hi 거리) 중 작은 것을 택하면 되겠다.
  type==1 일 때도 비슷하게 처리할 수 있다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll INF = 2e15;
const int mx = 10000001;
using namespace std;

ll H, G;
pll s, h[1001], g[1001];
ll dp[1001][1001][2];

ll dist(pii a, pii b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
ll go(int hi, int gi, int type) {
    if(dp[hi][gi][type] > -1) return dp[hi][gi][type];
    ll res=INF;
    if(type==0) {
        res = min(res, go(hi - 1, gi, 0) + dist(h[hi], h[hi - 1]));
        res = min(res, go(hi - 1, gi, 1) + dist(h[hi], g[gi]));
    }
    else {
        res = min(res, go(hi, gi - 1, 0) + dist(g[gi], h[hi]));
        res = min(res, go(hi, gi - 1, 1) + dist(g[gi], g[gi - 1]));
    }
    return dp[hi][gi][type] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>G;
    memset(dp, -1, sizeof(dp));
    cin>>s.first>>s.second;
    for(int i=1;i<=H-1;i++) cin>>h[i].first>>h[i].second;
    for(int i=1;i<=G;i++) cin>>g[i].first>>g[i].second;
    for(int i=1;i<H;i++) {
        dp[i][0][1] = INF;
    }
    for(int i=1;i<=G;i++) {
        dp[0][i][0] = INF;
    }
    dp[1][0][0] = dist(h[1],s);
    dp[0][1][1] = dist(g[1],s);
    for(int i=2;i<H;i++) {
        dp[i][0][0] = dp[i-1][0][0] + dist(h[i-1], h[i]);
    }
    for(int i=2;i<=G;i++) {
        dp[0][i][1] = dp[0][i-1][1] + dist(g[i-1], g[i]);
    }
    cout<<go(H-1, G, 0);
    return 0;
}
