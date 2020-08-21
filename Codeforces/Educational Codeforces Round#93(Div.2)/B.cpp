//B - Substring Removal Game	
/*
  연속한 0의 개수들을 모으고, 큰 순으로 뽑으면 된다. 번갈아 뽑으므로 유의하자.
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

int T, n, a[202020];
string str;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>str;
        int sz = str.size();
        vector<int> v;
        int cnt=0;
        for(int i=0;i<sz;i++) {
            if(str[i]=='0') {
                v.pb(cnt);
                cnt=0;
            }
            else cnt++;
        }
        v.pb(cnt);
        sort(v.begin(), v.end());
        int ssz = v.size(), res = 0;
        for(int i=ssz-1;i>=0;i-=2) {
            res+=v[i];
        }
        cout<<res<<"\n";
    }


    return 0;
}
