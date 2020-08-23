//B - Ternary Sequence	
/*
  array A에서 2를 최대한 B의 1과 매치시키고, array B의 2를 최대한 A의 0과 매치시킨 후에 값을 계산하면 된다.
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
#define INF 1e9
#define DIV 1000000007

using namespace std;

int T, a0, a1, a2, b0, b1, b2, mn;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--){
        ll res = 0;
        cin>>a0>>a1>>a2>>b0>>b1>>b2; //0, 1, 2개수
        mn = min(a0, b2);
        a0-=mn, b2-=mn;
        mn = min(a2, b1);
        res += 2LL*mn;
        a2 -= mn, b1 -= mn;
        res -= 2LL*max(0, b2 - a2 - a0);

        cout<<res<<"\n";
    }
    return 0;
}
