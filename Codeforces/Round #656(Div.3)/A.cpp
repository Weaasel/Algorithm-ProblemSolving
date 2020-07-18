//A - Three Pairwise Maximums	
/*
  a >= b 인 두 수 a, b 가 있다고 할 때,
  (a,a,b) 꼴의 input이 들어와야 정답이 된다는 사실.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;
int T, a[3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        if(a[1]==a[2]) {
            cout<<"YES\n";
            cout<<a[0]<<" "<<a[0]<<" "<<a[1]<<"\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}
