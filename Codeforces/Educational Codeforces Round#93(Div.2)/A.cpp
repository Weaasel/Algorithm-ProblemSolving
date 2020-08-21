//A - Bad Triangle	
/*
  Bad triangle의 존재성을 묻는 문제이므로
  가장 작은 두 수에 대해 합 이상인 수가 있는지 찾으면 된다.
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
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        if(a[1]+a[2]<=a[n]) cout<<"1 2 "<<n<<"\n";
        else cout<<"-1\n";
    }


    return 0;
}
