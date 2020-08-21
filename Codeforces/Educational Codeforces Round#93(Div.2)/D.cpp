//D - Colored Rectangles	
//simple dp
/*
  우선 같은 조건에서는 긴 변들끼리 조합하는게 이득이다. 따라서 각 변들을 크기순으로 정렬해 둔다.
  dp[i][j][k]: R의 i번째까지, G의 j번째까지, B의 k번째까지 사용 가능할 때 얻을 수 있는 최대 넓이
  로 정의하면,
  dp[i][j][k] comes from dp[i-1][j-1][k] or dp[i][j-1][k-1] or dp[i-1][j][k-1] 셋 중 하나에서 뻗어나옴을 알 수 있다.
  탈출조건의 인덱스 처리에만 유의하자.
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

ll asz, bsz, csz, a[201], b[201], c[201], dp[201][201][201];
ll go(int aa, int bb, int cc) {
    int cnt = 0;
    if(aa<=0) cnt++;
    if(bb<=0) cnt++;
    if(cc<=0) cnt++;
    if(cnt>=2) return 0;
    if(dp[aa][bb][cc] > -1) return dp[aa][bb][cc];
    ll res = 0;
    if(aa>0 && bb>0) {
        res = max(res, go(aa-1, bb-1, cc) + a[aa]*b[bb]);
    }
    if(cc>0 && bb>0) {
        res = max(res, go(aa, bb-1, cc-1) + c[cc]*b[bb]);
    }
    if(aa>0 && cc>0) {
        res = max(res, go(aa-1, bb, cc-1) + a[aa]*c[cc]);
    }
    return dp[aa][bb][cc] = res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>asz>>bsz>>csz;
    for(int i=1;i<=asz;i++) cin>>a[i];
    sort(a+1, a+asz+1);
    for(int i=1;i<=bsz;i++) cin>>b[i];
    sort(b+1, b+bsz+1);
    for(int i=1;i<=csz;i++) cin>>c[i];
    sort(c+1, c+csz+1);

    cout<<go(asz,bsz,csz);
    return 0;
}
