#include <vector>
#define ll long long

using namespace std;

/*
   Euler Phi function: n 이하의 n과 서로소인 수의 개수
*/
vector<ll> prime;
ll euler(ll n) {
   ll ret = 1;
   for (ll p : prime) {
      ll pow = 1;
      while (n%p == 0) {
         n /= p;
         pow *= p;
      }
      if (pow != 0) {
         ret *= (pow - (pow / p));
      }
   }
   if (n != 1) ret *= (n - 1);
   return ret;
}
