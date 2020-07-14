//음식물 피하기
//DFS, BFS
/*
  connected component의 최대 개수를 세는 전형적인 그래프 탐색 문제이다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;

int n, m, k, r, c, a[101][101], cnt[10010], idx = 2;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void dfs(int r, int c) {
    a[r][c] = idx;
    cnt[idx]++;
    for(int i=0;i<4;i++) {
        int nr = r+dx[i], nc = c+dy[i];
        if(nr<1 || nr>n) continue;
        if(nc<1 || nc>m) continue;
        if(a[nr][nc] != 1) continue;
        dfs(nr, nc);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) {
        cin>>r>>c;
        a[r][c] = 1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]!=1) continue;
            dfs(i, j);
            idx++;
        }
    }
    int mx=-1;
    for(int i=2;i<10010;i++) mx = max(mx, cnt[i]);
    cout<<mx;
    return 0;
}
