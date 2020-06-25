//블랙잭
//brute force
/*
  될 수 있는 세 수의 조합을 3중 for문으로 전부 고려한다.
*/

#include <iostream>
using namespace std;
int n, m, a[101], ans;
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                int s=a[i]+a[j]+a[k];
                if(s <= m && m - s < m - ans) ans = s;
            }
        }
    }
    cout<<ans;
}
