//이사
//greedy, brute force
/*
  2차원 평면 위에 N개의 점이 주어진다.
  평면 위의 다른 한 점을 잡고 해당 점에서 N개의 점까지 뻗은 거리들 중 (최대 + 최소) 를 minimize하는 점을 찾아야 한다.
  문제를 조금 바꿔보자.
  어떤 한 점 C 에서 minimize가 달성되었다고 하자. 이 때 N개의 점 중 최대/최소를 만족시켜준 점을 A, B라고 하자.
  A-C-B 는 한 직선 위에 있을 것이고, 이 직선 위에서 B쪽으로 한없이 가까워지더라도 A-C는 그만큼 더 멀어지고, C-B는 그만큼 더 가까워지므로
  최대/최소를 만족시키는 점이 A, B 라는 조건은 변하지 않을 것이다. 최소값이 작아지는 만큼 최대값이 커지므로 (최대 + 최소) 도 변하지 않는다.
  
  즉, 답은 N개의 점 중 하나라고 할 수 있다.
  이제 brute force로 찾으면 된다.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
const int INF = 1e9 + 7;
int n, mnidx = -1;
double x[1001], y[1001], mn = INF;

double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    for(int i=0;i<n;i++) {
        double locmx = -1;
        for(int j=0;j<n;j++) {
            double tmp = dist(i, j);
            locmx = max(locmx, tmp);
        }
        if(locmx < mn) {
            mn = locmx, mnidx = i;
        }
    }
    cout<<x[mnidx]<< " " <<y[mnidx];
    return 0;
}
