//E - Directing Edges	
//dfs, topological order
/*
  주어진 그래프는 directed / undirected edge가 섞인 형태고,
  undirected edge들에게 적당한 방향을 주어 그래프를 acyclic 하게 만드는 문제이다.
  
  최종적으로 그래프를 DAG 형태로 만들어야 하므로,
  적당히 우선순위가 높은 vertex부터 진행해 DAG 형태로 만들어가면 된다고 생각했다.
  
  로직은
  1. indegree가 0인 vertex가 현재 priority가 높은 vertex이다.
  2. indegree가 무조건 감소하기만 하는 평소의 topological sort 와는 달리, undirected edge에 방향을 주는 과정에서
      indegree가 증가할 수도 있다.
  3. 현재 보는 vertex u에 연결된 undirected edge들은 모두 u에서 출발하는 방향을 준다.(DAG에서의 우선순위가 높으니)
  4. 이미 본 vertex는 건너뛰고, 나중에 adj에서의 순회를 할 때 다시 한번 등장하면 cycle 이 존재한다는 뜻이니 flag를 false로 만든다.  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;

vector<int> adj[202020], raw[202020];
int T, n, m, t, u, v, ind[202020];
bool vis[202020];
bool f;

void dfs(int u) {
    if(vis[u]) return;
    vis[u]=true;
    for(int v:raw[u]) {
        if(vis[v]) continue;
        adj[u].pb(v);
        ind[v]++;
    }
    for(int v:adj[u]) {
        if(vis[v]) {
            f=false;
            continue;
        }
        ind[v]--;
        if(ind[v]==0) dfs(v);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n>>m;
        f=true;
        memset(vis, false, sizeof(vis));
        for(int i=1;i<=n;i++) {
            adj[i].clear(), raw[i].clear();
            ind[i]=0;
        }
        for(int i=0;i<m;i++) {
            cin>>t>>u>>v;
            if(t==0) {
                raw[u].pb(v);
                raw[v].pb(u);
            }
            else {
                adj[u].pb(v);
                ind[v]++;
            }
        }
        for(int i=1;i<=n;i++) {
            if(ind[i]==0 && !vis[i]) dfs(i);
        }
        for(int i=1;i<=n;i++) if(!vis[i]) f= false;
        if(!f) cout<<"NO\n";
        else {
            cout << "YES\n";
            for (int u = 1; u <= n; u++) {
                for (int v:adj[u]) {
                    cout << u << " " << v << "\n";
                }
            }
        }
    }
    return 0;
}
