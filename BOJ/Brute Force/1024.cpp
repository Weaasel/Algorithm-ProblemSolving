//수열의 합
//Brute force
/*
  특별한 알고리즘은 없고, 수열의 길이 i를 l ~ 100 까지 돌려보며
  n이 i개의 연속한 수의 합으로 나타내어질 수 있는지 먼저 검사하고,
  나타내어질 수 있다면 수열의 시작이 0 이상인지 검사하고 전부 만족한다면 출력하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
const int INF = 1e9 + 7;
using namespace std;
int n, l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;

    for(int i=l;i<=100;i++) {
        if(i%2==1) {
            if(n%i!=0) continue;
            int mid = n/i, s = mid - i/2, e = mid + i/2;
            if(s<0) continue;
            for(int j=s;j<=e;j++) {
                cout<<j<<" ";
            }
            return 0;
        }
        else {
            if(n%(i/2)!=0) continue;
            int mid = n/(i/2);
            if(mid%2==0) continue;
            int s = mid/2 - (i-1)/2, e = mid/2 + 1 + (i-1)/2;
            if(s<0) continue;
            for(int j=s;j<=e;j++) {
                cout<<j<<" ";
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
