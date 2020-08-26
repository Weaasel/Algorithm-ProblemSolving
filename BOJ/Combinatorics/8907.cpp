//네온사인
//math
/*
  점이 n 개이므로 전체 삼각형의 개수는 nC3 개이다.
  이 중에서 빨간색/파란색 간선이 함께 등장하는 삼각형의 개수를 빼면 '단색삼각형'의 개수를 구할 수 있다.
  각 정점에 대해 빨간색/파란색 간선의 개수를 세어두고 전체 정점을 순회하며 빨간색*파란색 을 누적하면 그 개수를 구할 수 있다.
  주의할 점은 모든 혼합 삼각형은 2번씩 세어지게 되므로 마지막에 2를 나누어야 한다.
  (빨1파2 일 경우, 빨2파1일 경우에 대해 각각 생각해 보자)
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
const int mxn = 1000001;
using namespace std;

int n, T;
ll res, tmp, r[1001], b[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--) {
        res=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            r[i] = 0;
            b[i] = 0;
        }
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                int col; cin>>col;
                if(col) {
                    r[i]++;
                    r[j]++;
                }
                else {
                    b[i]++;
                    b[j]++;
                }
            }
        }
        res = n*(n-1)*(n-2)/6;
        tmp = 0;
        for(int i=1;i<=n;i++) {
            tmp += r[i]*b[i];
        }
        cout<<res - tmp/2<<"\n";
    }
    return 0;
}
