//Milk Visits
//LCA
/*
  쿼리로 들어오는 u,v 사이의 path에 H 혹은 G의 값을 가지는 정점이 존재하는지를 출력하는 문제이다.
  H, G에 각각 0, 1 이라는 값을 부여하고, lca 함수를 해당 path 위에 놓인 정점값들의 합으로 반환하여
  그 값이 0이라면 경로상에 H만 존재, 정점 개수와 같다면 G만 존재, 둘다 아니라면 H, G가 모두 존재하는 것으로 설정해 해결했다.
  
  훨씬 쉬운 dfs 솔루션이 존재한다. 모든 정점들에 대해 같은 알파벳인 인접한 점들을 같은 색으로 칠해
  u, v가 한 색으로 이루어져 있는지, 여러 색으로 이루어져 있는지 확인하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define INF 2e9

using namespace std;
int n, m, u, v, type[100001], lv[100001];
pii par[100001][21];
string s;
vector<int> res, adj[100001];
char c;

void make_tree(int u, int pre) {
    for(int v:adj[u]) {
        if(v==pre) continue;
        par[v][0] = {u, type[u]};
        lv[v] = lv[u]+1;
        make_tree(v,u);
    }
    return;
}

void init() {
    for(int i=1;i<21;i++) {
        for(int u=1;u<=n;u++) {
            int p = par[u][i-1].first, val = par[u][i-1].second;
            par[u][i].first = par[p][i-1].first;
            par[u][i].second = par[p][i-1].second + val;
        }
    }
}

pii lca(int u, int v) {
    if(lv[u] > lv[v]) swap(u,v);
    int diff = lv[v] - lv[u];
    int val = type[v];

    for(int i=20;i>=0;i--) {
        if(diff>=(1<<i)) {
            diff -= (1<<i);
            val += par[v][i].second;
            v = par[v][i].first;
        }
    }
    if(u==v) return {u, val};
    val += type[u];
    for(int i=20;i>=0;i--) {
        if(par[u][i].first == par[v][i].first) continue;
        val += par[u][i].second;
        val += par[v][i].second;
        u = par[u][i].first;
        v = par[v][i].first;
    }
    return {par[u][0].first, val + type[par[u][0].first]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++) {
        if(s[i]=='H') type[i+1]=0;
        else type[i+1]=1;
    }
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lv[1] = 0;
    make_tree(1, 0);
    init();
    for(int i=0;i<m;i++) {
        cin>>u>>v>>c;
        if(u==v) {
            if(c=='H' && type[u]==0) res.pb(1);
            else if(c=='G' && type[u]==1) res.pb(1);
            else res.pb(0);
        }
        else {
            pii p = lca(u, v);
            int anc = p.first, sum = p.second;
            int cnt = lv[u] + lv[v] - 2 * lv[anc] + 1;
            if (c == 'H') {//0이 하나라도 있으면 됨.
                if (sum < cnt) res.pb(1);
                else res.pb(0);
            }
            else {//1이 하나라도 있으면 됨.
                if (sum > 0) res.pb(1);
                else res.pb(0);
            }
        }
    }
    for(int i:res)cout<<i;
    return 0;
}
