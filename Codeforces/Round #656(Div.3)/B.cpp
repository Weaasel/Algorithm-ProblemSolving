//B - Restore the Permutation by Merger	
/*
  같은 순서의 permutation 두 개가 적당히 겹쳐진 input 이 들어오므로,
  모든 숫자에 대해 첫번째로 등장했을 때 출력해주면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;
int T, n, num, vis[51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<2*n;i++) {
            cin>>num;
            if(vis[num]) continue;
            vis[num]=true;
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
