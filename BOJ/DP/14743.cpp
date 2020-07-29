//Labor
//prefix sum, binary search
/*
  사다리꼴을 만들기 위해서는, 윗줄에서 두 점을 고르고 아랫줄에서 왼쪽 점보다는 앞에 있는 점, 오른쪽 점보다는 뒤에 있는 점을 뽑아야 한다.
  윗줄의 각 점에 대해
  alow[i]: i번째 점보다 작은 아랫줄 점의 개수
  ahigh[i]: i번째 점보다 큰 아랫줄 점의 개수
  로 잡고 ahigh는 prefix sum처럼 쌓아 사용한다.
  
  이런 작업을 두 번 반복하면 된다.
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
ll n, m, a[mx], b[mx];
ll alow[mx], ahigh[mx], blow[mx], bhigh[mx];
ll c1, c2, res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>a[0]>>a[0];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    for(int i=0;i<n;i++) {
        ll idx = lower_bound(b, b+m, a[i]) - b;
        alow[i]=idx;
        idx = upper_bound(b, b+m, a[i]) - b;
        if(i>0)ahigh[i] = ahigh[i-1];
        ahigh[i]+=m-idx;
    }
    for(int i=0;i<n;i++) {
        res += (alow[i] * (ahigh[n-1] - ahigh[i]))%DIV;
    }
    for(int i=0;i<m;i++) {
        ll idx = lower_bound(a, a+n, b[i]) - a;
        blow[i]=idx;
        idx = upper_bound(a, a+n, b[i]) - a;
        if(i>0)bhigh[i] = bhigh[i-1];
        bhigh[i]+=n-idx;
    }
    for(int i=0;i<m;i++) {
        res += (blow[i] * (bhigh[m-1] - bhigh[i]))%DIV;
    }
    cout<<res%DIV;
    return 0;
}
