//Circular Barn Revisited
//DP, prefix sum
/*
  dp[l][r][rest]: l~r 구간 중 rest개를 선택
  
  1~N 원형 구간은 1~2*N 선형 구간으로 펼쳐준다.
  먼저 제일 뒷문이 될 idx를 정하고, i라 하자.
  구간 [i+1, i+n-1] 중 K-1 개를 뽑아 비용을 최소화하고 싶다.
  비용은 2개의 점을 뽑았을 때 그 사이 점들에 대한 비용이 확정된다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using lint = long long;
const lint INF = 1e9 + 7;
lint N, K, a[202];
lint psum[202], psum2[202];
lint dp[102][202][7];

lint s(int l, int r) {
    return psum2[r] - psum2[l - 1] - (psum[r] - psum[l - 1])*(l-1);
}

lint f(int l, int r, int rest) {
    if (r - l + 1 == rest) return 0;
    if (rest == 1) {
        lint ret = INF;
        ret = min(ret, s(l+1, r));
        for (int i = l+1; i < r; i++)
            ret = min(ret, s(l, i - 1) + s(i+1, r));
        ret = min(ret, s(l, r-1));
        return ret;
    }
    lint &ret = dp[l][r][rest];
    if (dp[l][r][rest] != -1) return dp[l][r][rest];
    ret = INF;
    for (int i = l + rest-1; i <= r; i++)
        ret = min(ret, s(i + 1, r) + f(l, i-1, rest - 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> a[i], a[i + N] = a[i];
    for (int i = 1; i <= 2 * N; i++) {
        psum[i] = psum[i - 1] + a[i];
        psum2[i] = psum2[i - 1] + a[i] * i;
    }

    lint ans = INF;
    if(K==1) {
        for(int i=1;i<=N;i++) {
            ans = min(ans, s(i+1,i+N-1));
        }
    }
    else {
        for (int i = 1; i <= N; i++)
            ans = min(ans, f(i + 1, i + N - 1, K - 1));
    }
    cout << ans;
    return 0;
}
