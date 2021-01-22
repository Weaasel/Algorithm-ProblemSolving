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

/*
  mobius inversion
*/
int mobius[mx];
void init() {
    fill(mobius, mobius+mx, 1);
    //memset(mobius, 1, sizeof(mobius));
    for (int i = 2; i * i <= mx; i++)
        if (mobius[i] == 1) { //prime들에 대해
            for (int j = i; j <= mx; j += i) mobius[j] *= -i;
            for (int j = i * i; j <= mx; j += i * i) mobius[j] = 0;
        }

    for (int i = 2; i <= mx; i++) {
        if (mobius[i] == i) mobius[i] = 1;
        else if (mobius[i] == -i) mobius[i] = -1;
        else if (mobius[i] < 0) mobius[i] = 1;
        else if (mobius[i] > 0) mobius[i] = -1;
    }

}


