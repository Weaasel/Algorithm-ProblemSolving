//공유기 설치
/*
  n 개의 집 위치가 주어지고, c대의 공유기를 설치할 때, 공유기 사이의 거리를 극대화하는 문제다.
  공유기 사이의 최소거리 d를 binary search할 것인데,
  chk 함수는 d 이상의 거리가 되게 공유기를 놓았을 때, 남는 공유기가 있냐 없냐로 판단한다.
*/

#include <iostream>
#include <algorithm>
#define ll long long
#define INF 1e9

using namespace std;

ll n, c, a[200001];

bool chk(ll d) {
    int cur=0;
    for(int i=0;i<c - 1;i++) {
        int wlk = cur;
        while(wlk < n && a[wlk] - a[cur] < d) wlk++;
        if(wlk==n) return false;
        cur = wlk;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    ll l = 1, r = INF, mid, ans = 0;
    while(l<=r) {
        mid = (l+r)/2;
        if(chk(mid)) {
            l = mid+1;
            ans = max(ans, mid);
        }
        else r = mid-1;
    }
    cout<<ans;
    return 0;
}
