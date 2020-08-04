//Untangling chain
//Constructive
/*
  방향 입력이 1이면 왼쪽으로 꺾고, -1이면 오른쪽으로 꺾는 상황에서 n개의 선분들에 대해 길이를 잘 줘서 지났던 점을 다시 지나지 않게 만드는 문제이다.
  여러 방식으로 답을 구성할 수 있는데, 내가 한 방식은 먼저 방향을 동서남북으로 변환시키고, 동-서, 남-북 끼리의 관계만 본다.
  그랬을 때 동쪽으로 간 만큼보다 서쪽으로 조금 가게 하고, 남쪽으로 간 만큼보다 북쪽으로 조금 가게 하면 절대 지났던 점을 다시 지나지 않는다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll INF = 2e16;
const int mx = 10000001;
using namespace std;

int n, a, b[10001];
char dir[10001];
int res[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b[i];
    }
    dir[0] = 'R';
    for(int i=1;i<n;i++) {
        if(dir[i-1]=='U') {
            if(b[i-1]==1) {
                dir[i]= 'L';
            }
            else {
                dir[i] = 'R';
            }
        }
        else if(dir[i-1]=='D') {
            if(b[i-1]==1) {
                dir[i]= 'R';
            }
            else {
                dir[i] = 'L';
            }
        }
        else if(dir[i-1]=='L') {
            if(b[i-1]==1) {
                dir[i]= 'D';
            }
            else {
                dir[i] = 'U';
            }
        }
        else if(dir[i-1]=='R') {
            if(b[i-1]==1) {
                dir[i]= 'U';
            }
            else {
                dir[i] = 'D';
            }
        }
    }

    vector<pair<char, int>> v1, v2; //{direction, idx}
    for(int i=0;i<n;i++) {
        if(dir[i]=='L' || dir[i] == 'R') v1.pb({dir[i], i});
        else v2.pb({dir[i], i});
    }
    //L, R 만 셀거
    //v1에는 L, R, L, L, L, R, R, ...
    int sz = v1.size(), w1 = 0, w2 = 0, cnt = 0, sum = n;
    while(w1 < sz) {
        if(w2<sz && v1[w1].first == v1[w2].first) {
            cnt++;
            w2++;
        }
        else {
            for(int i=w1;i<w2-1;i++) {
                res[v1[i].second] = 1;
            }
            res[v1[w2-1].second] = sum - (cnt-1);
            sum = sum - cnt;
            w1=w2, cnt=0;
        }
    }
    sz = v2.size(), w1 = 0, w2 = 0, cnt = 0, sum = n;
    while(w1 < sz) {
        if(w2<sz && v2[w1].first == v2[w2].first) {
            cnt++;
            w2++;
        }
        else {
            for(int i=w1;i<w2-1;i++) {
                res[v2[i].second] = 1;
            }
            res[v2[w2-1].second] = sum - (cnt-1);
            sum = sum - cnt;
            w1=w2, cnt=0;
        }
    }
    for(int i=0;i<n;i++) cout<<res[i]<<"\n";

    return 0;
}
