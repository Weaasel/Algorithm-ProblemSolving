//통신망 분할
//offline query, union-find
/*
  주어진 그래프에서 간선을 하나씩 끊어갈 때, 간선을 이루던 두 정점이 서로 다른 connected component로 나눠진다면
  그 개수의 곱만큼 비용이 드는 문제이다.
  
  문제를 뒤집으면 쉬워진다.
  끊어야 할 마지막 간선이 끊어진 직후의 순간부터 시작해서 간선을 하나씩 연결한다.
  만약 연결하기 전에 두 정점이 같은 집합에 속하지 않았다면 비용이 발생한다.
  반대로 연결하기 전에 두 정점이 이미 같은 집합에 속해 있었다면, 해당 간선을 끊어도 같은 집합이라는 말이므로 비용이 발생하지 않는다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;
const int mx = 100001;

int n, m, q, del[100001];
pii e[100001];
bool chk[100001];
ll par[100001];
ll res;

int find(int a) {
    if(par[a]<0) return a;
    return par[a] = find(par[a]);
}

ll merge(int a, int b) {
    a = find(a), b = find(b);
    if(a==b) return 0;
    ll ret = par[a]*par[b];
    par[a]+=par[b];
    par[b]=a;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(par, -1, sizeof(par));
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) {
        cin>>e[i].first>>e[i].second;
    }
    for(int i=0;i<q;i++) {
        cin>>del[i];
        chk[del[i]] = true;
    }
    for(int i=1;i<=m;i++) {
        if(chk[i])continue;
        merge(e[i].first, e[i].second);
    }
    for(int i=q-1;i>=0;i--) {
        res += merge(e[del[i]].first, e[del[i]].second);
    }
    cout<<res;
    return 0;
}
