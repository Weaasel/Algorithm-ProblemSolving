//C - Make It Good	
/*
  주어진 배열의 Prefix 를 삭제했을 때,
  a1<=a2<=a3...<=ai>=ai+1>=ai+2...>=an 꼴이 되어야 한다.
  따라서 뒤에서부터 보면서 이런 형태가 되는 가장 긴 suffix의 길이를 세면 된다.
  while문 2개로 구현 가능하다. (뒤에서부터 최대한 ascending 하고 최대한 descending 하고)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;
int T, n, a[202020];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int w=n-2;
        while(w>=0&&a[w]>=a[w+1])w--;
        while(w>=0&&a[w]<=a[w+1])w--;
        cout<<w+1<<"\n";
    }
    return 0;
}
