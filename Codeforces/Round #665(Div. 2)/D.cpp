//D - Maximum Distributed Tree	
/*
  문제를 환원하면 트리상에서 모든 정점간의 path들을 모았을 때, 각 edge가 쓰이는 횟수로 정렬하고, 주어진 수들을 크기순으로 잘 넣어주면 된다.
  각 edge가 쓰이는 횟수는 전처리를 통해 구할 수 있다.
  (u,v) edge는 u와 v중 leaf에 가까운 정점을 루트로 하는 subtree의 정점개수와 연관이 있는데,
  이를 subs[u]라고 하면 이 edge가 쓰이는 횟수는 subs[u]*(n-subs[u]) 가 된다. 그림을 그려보면 쉽게 알 수 있다.  
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define INF 1e9+1
#define DIV 1000000007

using namespace std;

ll T, n, m;
ll lv[100001], subs[100001];
ll prime[60001];
vector<int> adj[100001];
vector<ll> ecnt;

bool cmp(ll a, ll b) {
    return a>b;
}

ll make_tree(int u, int pre) {
    ll res = 1;
    for(int v:adj[u]) {
        if(v==pre) continue;
        lv[v] = lv[u]+1;
        res += make_tree(v,u);
    }
    subs[u] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--){
        ll res = 0;
        cin>>n;
        ecnt.clear();
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        lv[1]=0;
        make_tree(1,0);

        for(int u=1;u<=n;u++) {
            for(int v:adj[u]) {
                if(u<v) continue;
                int node;
                if(lv[u]>lv[v]) node = u;
                else node = v;
                ecnt.pb(subs[node]*(n-subs[node]));
            }
        }
        sort(all(ecnt));

        cin>>m;
        for(int i=0;i<m;i++) cin>>prime[i];
        sort(prime, prime+m);
        if(m>n-1) {
            for(int i=m-1;i>=n-1;i--) {
                prime[i-1]*=prime[i];
                prime[i-1]%=DIV;
                prime[i]=0;
            }
        }
        //prime 0~m-1 까지 들어있음 이거 n-1개보다 작을 수도 있음.
        int psz = min(m, n-1);
        int ewlk = n-2, pwlk = psz-1;
        while(ewlk>=0 && pwlk>=0) {
            ll cnt = ecnt[ewlk]%DIV, val = prime[pwlk]%DIV;
            res += cnt*val%DIV;
            res %= DIV;
            ewlk--;pwlk--;
        }
        for(int i=0;i<=ewlk;i++) {
            res += ecnt[i]%DIV;
            res %= DIV;
        }
        cout<<res<<"\n";
    }
    return 0;
}
