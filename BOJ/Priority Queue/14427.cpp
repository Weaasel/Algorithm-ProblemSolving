//수열과 쿼리15
//priority queue
/*
  구간 최소값을 갖는 인덱스를 출력하고, 배열이 update된다. 여기까지만 보면 segment tree를 떠올리기 쉽다.
  그러나 이 문제는 전체 구간에 대한 질의만을 하기 때문에 priority queue로도 해결이 가능하다.
  
  pq에 {val, idx} 형태로 값을 넣어둔다.
  1번 쿼리일 때는 pq에 {new value, idx} 값을 넣어주고 배열값을 update한다.
  2번 쿼리일 때는 pq.top()의 {val, idx} 가 valid한 값이 나올 때까지 pop 하고 맨 위에 있는 idx를 출력한다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int n, m, sz=1, type, idx, val;
int a[100001];
priority_queue<pii> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        pq.push({-a[i], -i});
    }
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>type;
        if(type==1) {
            cin>>idx>>val;
            a[idx]=val;
            pq.push({-val, -idx});
        }
        else {
            while(1) {
                pii p= pq.top();
                if(-p.first == a[-p.second]) {
                    cout<<-p.second<<"\n";
                    break;
                }
                else pq.pop();
            }
        }
    }
    return 0;
}
