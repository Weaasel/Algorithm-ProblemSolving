//C. Boboniu and Bit Operations
//Brute force
/*
  답이 될 수 있는 값의 크기가 2^9=512 미만이므로 모든 값에 대해 될수 있는지 여부를 조사한다.
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

int n, m, a[201], b[201];

bool chk(int res) {
    for(int i=0;i<n;i++) {
        bool flg = false;
        for(int j=0;j<m;j++) {
            int cur = a[i]&b[j];
            if((cur|res) == res) flg = true;
        }
        if(!flg) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int res=0;res<512;res++) {
        if(chk(res)) {
            cout<<res;
            return 0;
        }
    }

    return 0;
}
