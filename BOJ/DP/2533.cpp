//사회망 서비스
//TreeDP

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m;
int dp[1010101][2];
vector<int> adj[1010101];

int go(int u, int prv, int type) {
    if(dp[u][type] > -1) return dp[u][type];
    int ret = 0;
    if(type==0) {
        for(int v:adj[u]) if(v!=prv)
            ret += go(v,u,1);
    }
    else {
        ret++;
        for(int v:adj[u]) if(v!=prv)
                ret += min(go(v,u,0), go(v,u,1));
    }
    return dp[u][type] = ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout<<min(go(1,0, 0), go(1, 0, 1));
    return 0;
}
