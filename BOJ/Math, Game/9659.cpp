//돌 게임5
//Game
/*
  상대방에게 4의 배수의 수만 만들어서 넘겨줄 수 있다면, 그 이후부터 상대의 행동에 따라 맞춰가며 이길 수 있다.
  상대가 1개를 가져간다면 3개를 가져가고, 상대가 3개를 가져간다면 1개를 가져가면 된다.
  따라서 이 문제는 상대방에게 4의 배수의 수를 만들어서 줄 수 있느냐 없느냐로 승패가 갈리게 된다.
*/

#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    int res = n%4;
    if(res==1 || res==3) cout<<"SK";
    else cout<<"CY";
    return 0;
}
