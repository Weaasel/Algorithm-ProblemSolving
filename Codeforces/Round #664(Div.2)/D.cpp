//D. Boboniu Chats with Du
//prefix sum, greedy, brute force
/*
  단순하게 m보다 큰 수를 몇개 고를것인지 선택한다. (개수가 정해지면 어차피 큰 순으로 골라야 한다.)
  그러고 나면 d*(고른 수의 개수-1) 개를 포기해야 하는데, m보다 큰 수를 전부 버리고 크기가 작은 순으로 버리면 된다.
  이렇게 해서 얻어지는 값은 prefix sum을 이용해 O(1) 시간에 구할 수 있고,
  
  큰 수를 고를 수 있는 모든 경우의 수에 대해 최대값을 구하면 된다.
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

ll n, d, m, asz, bsz, ans;
ll asum[100001], bsum[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>d>>m;
    for(int i=0;i<n;i++) {
        ll cur; cin>>cur;
        if(cur>m) bsum[++bsz] = cur;
        else asum[++asz] = cur;
    }
    sort(asum+1,asum+1+asz);
    sort(bsum+1,bsum+1+bsz);
    for(int i=1;i<=asz;i++) asum[i]+=asum[i-1];
    for(int i=1;i<=bsz;i++) bsum[i]+=bsum[i-1];
    for(int i=0;i<=bsz;i++) {
        ll rem = n - i;
        ll take = min(rem - d*(i-1),asz);
        if(take<0) continue;
        ans = max(ans, bsum[bsz] - bsum[bsz-i] + asum[asz] - asum[asz-take]);
    }
    cout<<ans;
    return 0;
}
