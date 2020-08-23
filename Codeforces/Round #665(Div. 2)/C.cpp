//C - Mere Array	
/*
  배열에서 최소의 수가 있으면 그 수를 경유해 모든 수의 위치를 바꿀 수 있다.
  바꿀 수 없는 수는 최소값의 배수가 아닌 수 뿐이다.
  이 바꿀 수 없는 수들이 정렬후 있어야 할 적합한 위치에 있는지 검사하면 된다.
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

int T, n;
pii a[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int mn = INF;
        bool flg = true;
        for(int i=0;i<n;i++) {
            cin>>a[i].first;
            mn = min(mn, a[i].first);
            a[i].second = i;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(i==a[i].second) continue;
            if(a[i].first%mn) flg = false;
        }
        if(flg) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
