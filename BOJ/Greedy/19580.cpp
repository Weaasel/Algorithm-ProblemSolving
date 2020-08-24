//
//Greedy, multiset
/*
  마스크를 {가격, 개수} 형태로 multiset에 보관한다.
  사람들을 쓸 수 있는 돈의 {최소값, 최대값} 형태로 모아둔다.
  최대 사용가능 비용이 작은 순으로, 최소 사용가능 비용이 작은 순으로 마스크를 먼저 분배하는 것이 이득이다.
  따라서 e->s 우선순위로 정렬해 둔 사람들을 앞에서부터 읽으며
  
  s의 lower bound인 마스크를 찾고 그 가격이 e 이하인지 검사한 후에 분배하는 로직을 적절히 구현하면 된다.
  
  ps. 이 순서대로 정렬하는 것이 왜 최적일까?
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

int n, c, res;
vector<pll> man;
multiset<pll> ms;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++) {
        ll s, e; cin>>s>>e;
        man.pb({s,e});
    }
    sort(all(man), [&](pll a, pll b) {
        if(a.second == b.second) return a.first<b.first;
        return a.second<b.second;
    });

    for(int i=0;i<c;i++) {
        ll cost, cnt; cin>>cost>>cnt;
        ms.insert({cost,cnt});
    }

    for(pll p:man) {
        auto it = ms.lower_bound({p.first,1});
        if(it != ms.end() && (*it).first<=p.second && (*it).second > 0) {
            res++;
            pll tmp = (*it);
            ms.erase(it);
            tmp.second--;
            if(tmp.second > 0) ms.insert(tmp);
        }
    }
    cout<<res;
    return 0;
}
