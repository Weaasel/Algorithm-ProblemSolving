//Code Word
//Simple DP
/*
  dp[i][j][l] : (i,j)번째 버튼을 l번째로 누른 password의 개수 로 정의하자.
  
  dp[i][j][l] = sum(dp[i][j][l-1]) - sum(dp[인접한 i][인접한 j][l-1]) 이 된다.
  이걸 전부 더하는 식으로 구현하면 비효율적이므로,
  각 단계에서 전체 sum을 구해놓고 각 점에 대해 9개의 인접한 점을 빼는 형태로 구하자.
*/

#include <iostream>
#include <algorithm>
#define ll long long
const int INF = 1e9 + 7;
int r, c, len;
ll dp[101][101][201], sum[201];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c>>len;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            dp[i][j][1] = 1;
            sum[1]++;
        }
    }

    for(int l=2;l<=len;l++) {
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                ll s = sum[l - 1];
                for(int k=0;k<9;k++) {
                    int nr = i + dx[k], nc = j + dy[k];
                    if(nr<0 || nr>=r) continue;
                    if(nc<0 || nc>=c) continue;
                    s -= dp[nr][nc][l-1];
                }
                while(s<0) s+=INF;
                dp[i][j][l] = s;
                sum[l]+=s;
                sum[l]%=INF;
            }
        }
    }
    cout<<sum[len];
    return 0;
}
