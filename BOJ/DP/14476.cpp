//최대공약수 하나 빼기
//gcd, prefix sum
/*
  결국 문제에서 가장 중요한 task는 배열에서 한 원소만 뺀 최대공약수를 구하는 일이다.
  이를 prefix sum + gcd로 구간 gcd로 가지고 있으면 한 원소만 제거했을 때,
  1~i-1, i+1~n 까지의 gcd로 구할 수 있다.
  앞에서부터 / 뒤에서부터 총 2개의 prefix sum 배열이 필요하다.
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n, a[1000001], psum1[1000001], psum2[1000001];
int res=-1, resval;

int gcd(int a, int b) {
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        psum1[i] = a[i];
        psum2[n+1-i] = a[i];
    }
    for(int i=1;i<=n;i++) {
        psum1[i] = gcd(psum1[i], psum1[i-1]);
        psum2[i] = gcd(psum2[i], psum2[i-1]);
    }
    int tot = psum1[n];
    for(int i=1;i<=n;i++) {
        int cur = gcd(psum1[i-1], psum2[n-i]);
        if(cur==tot) continue;
        if(cur>res) {
            res = cur;
            resval = a[i];
        }
    }
    if(res==-1) cout<<-1;
    else cout<<res<<" "<<resval;
    return 0;
}
