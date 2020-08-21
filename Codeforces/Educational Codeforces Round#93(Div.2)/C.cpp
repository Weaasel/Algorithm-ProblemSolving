//C - Good Subarrays	
//Thinking, hashmap, line sweeping
/*
  psum[r] - psum[l-1] = r - l + 1 인 (r,l) 쌍의 개수를 찾는 문제로,
  psum[r] - r = psum[l-1] - (l-1) 로 식을 변형하면
  
  psum[i] - i 를 map 에 모았을 때 같은 쌍의 개수를 찾는 문제가 된다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define pb push_back
#define ll long long
#define INF 1e18
#define DIV 1000000007
const int mxn = 500001;
using namespace std;

int T, n;
ll psum[101010];
string str;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n;
        cin>>str;
        map<int, ll> m;
        for(int i=1;i<=n;i++) {
            psum[i] = (str[i-1]-'0');
            psum[i] += psum[i-1] - 1;
        }
        ll res = 0;
        m[0] = 1;
        for(int i=1;i<=n;i++) {
            res += m[psum[i]];
            m[psum[i]]++;
        }
        cout<<res<<"\n";
    }
    return 0;
}
