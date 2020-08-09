//같은 탑
//dynamic programming
/*
  도저히 모르겠어서 구글링을 통해 해결했다.
  처음 풀어 본 형태이지만 ucpc2020의 피자배틀이나, knapsack 과 비슷한 유형이라 생각하고 앞으로 보면 풀어야 한다.
  
  dp[idx][diff]: idx번째 탑까지 봤을 때, 작은 탑과의 높이차이가 diff인 탑의 최대 높이
  로 정의하면
  dp[idx-1][diff] 로부터 idx번째 탑을 보고
  더 높은 쪽에 쌓는 경우 / 더 낮은 쪽에 쌓는 경우로 업데이트 가능하다.  
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
const int mxn = 500001;
using namespace std;

int n, mx, mn, a[51];
int dp[51][mxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=0;j<mxn;j++) dp[i][j] = dp[i-1][j];
        for(int j=0;j<mxn;j++) {
            if(dp[i-1][j] == -1) continue;
            int cur = dp[i-1][j];

            if(j+a[i]<mxn) dp[i][j+a[i]] = max(dp[i][j+a[i]], cur + a[i]);
            if(cur-j+a[i]<mxn) {
                mx = max(cur, cur-j+a[i]);
                mn = min(cur, cur-j+a[i]);
                dp[i][mx-mn] = max(dp[i][mx-mn],mx);
            }
        }
    }
    if(!dp[n][0]) dp[n][0] = -1;
    cout<<dp[n][0];
    return 0;
}
