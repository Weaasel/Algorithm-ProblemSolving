//A - Distance and Axis	
/*
  말그대로 잘 하면 되는 껄끄러운 문제.
  k가 n 왼쪽에 있을 때와 오른쪽에 있을때를 잘 나누어 처리하면 된다.
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

int T, n, k, b;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        int res = INF;
        if(n>=k) {
            if(n%2==k%2) cout<<"0\n";
            else cout<<"1\n";
        }
        else cout<<abs(n-k)<<"\n";
    }
    return 0;
}
