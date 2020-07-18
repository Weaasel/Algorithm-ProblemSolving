//D - a-Good String	
//Divide and Conquer, DP, Bitmask
/*
  dp[pow][char][start] : 알파벳 char로 start부터 2^pow 개의 구간을 채우기 위한 비용
  으로 정의하고,
  dp[pow][char][start] = min(dp[pow-1][char+1][start] + (start+2^(pow-1) ~ start+2^pow 구간을 char로 채우는 비용),
                            dp[pow-1][char+1][start] + (start+2^(pow-1) ~ start+2^pow 구간을 char로 채우는 비용))
  임을 알 수 있다.
  내 풀이는 메모리를 많이 써야 해서 메모리 최적화에 신경써야 했는데,
  simple한 [divide & conquer]로도 해결이 가능한 문제였다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define pb push_back
#define pi 3.141592
const int INF = 1e9 + 7;
using namespace std;
int T, n;
string str;
int dp[20][20][131073];
int go(int pow, int s, char c) {
    if(dp[pow][c-'a'][s]>-1) return dp[pow][c-'a'][s];
    if(pow==0) return dp[pow][c-'a'][s] = str[s]==c?0:1;
    int c1=0, c2=0, len = (1<<pow-1);
    for(int i=s;i<s+len;i++) {
        if(str[i]!=c) c1++;
    }
    for(int i=s+len;i<s+len*2;i++) {
        if(str[i]!=c) c2++;
    }
    return dp[pow][c-'a'][s] = min(c1+go(pow-1,s+len,c+1), c2+go(pow-1,s,c+1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n>>str;
        for(int i=0;i<20;i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        if(n==1) {
            if(str[0]=='a')cout<<0<<"\n";
            else cout<<1<<"\n";
            continue;
        }
        int pow=0,nn=1;
        while(nn<n){
            pow++;nn*=2;
        }
        cout<<go(pow, 0, 'a')<<"\n";
    }
    return 0;
}
