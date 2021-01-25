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
  num의 약수들의 집합을 return
*/
vector<int> get_divs(int num){
	vector<pii> d;
	for (int p : prime) {
		if (num%p == 0) {
			int cnt = 0;
			while (num%p == 0) {
				num /= p;
				cnt++;
			}
			d.pb({ p,cnt });
		}
	}
	if (num > 1) d.pb({ num,1 });
	
	vector<int> divs;
	int sz = d.size();
	for (pii p : d) {
		int val = p.x, cnt = p.y;
		int dsz = divs.size();
		for (int j = 0; j < dsz; j++) {
			int cur = divs[j], vv = val;
			for (int k = 0; k < cnt; k++) {
				divs.pb({ cur*vv });
				vv *= val;
			}
		}
		int vv = val;
		for (int k = 0; k < cnt; k++) {
			divs.pb({ vv });
			vv *= val;
		}
	}
	divs.pb(1);
	return divs;
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


