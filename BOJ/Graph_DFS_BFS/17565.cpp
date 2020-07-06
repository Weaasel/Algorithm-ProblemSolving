//Analogue Cluster
//DFS
/*
  연결된 정점들끼리는 같은 값을 가져야 하는데, 주어진 그래프에서 모든 정점들이 이 조건을 만족하기 위해 정점의 값을 변경해야 하는 최소 횟수
  dfs를 돌며 connected component의 총 개수, 그 안에서 가장 많은 값의 개수를 알아내도록 하고,
  각 connected component마다 총 개수 - 가장 많은 값의 개수 를 전부 더하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define pb push_back
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define INF 1e9

using namespace std;

int n, c, u, v, res, cnt, mxcnt;
int a[1001];
bool vis[1001];
vector<int> adj[1001];
map<int, int> m;

void go(int u) {
    vis[u] = true;
    m[a[u]]++;
    cnt++;
    mxcnt = max(mxcnt, m[a[u]]);
    for(int v:adj[u]) {
        if(vis[v]) continue;
        go(v);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<c;i++) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            cnt = 0, mxcnt = 0;
            go(i);
            res += cnt - mxcnt;
            m.clear();
        }
    }
    cout<<res;
    return 0;
}
