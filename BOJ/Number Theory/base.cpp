#include <vector>
#define ll long long

using namespace std;

vector<ll> prime;
bool notp[40101];

/*
   eratosthenes's seive for 1e9
*/
void era() {
	for (int i = 2; i*i < 40101; i++) {
		if (notp[i]) continue;
		for (int j = i * i; j < 40101; j += i) notp[j] = true;
	}
	for (int i = 2; i < 40101; i++) if (!notp[i]) prime.pb(i);
}

/*
   Euler Phi function: n 이하의 n과 서로소인 수의 개수
*/
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
