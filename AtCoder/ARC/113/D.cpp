#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define mod (ll)998244353

ll n , m , k ;

ll cal(ll x , ll n){
  ll res = 1 ;
  while(n > 0){
    if(n & 1) res = res * x % mod ;
    x = x * x % mod ;
    n >>= 1 ;
  }
  return res % mod ;
}

int main(){
  cin >> n >> m >> k ;
  ll count = 0 ;
  ll tmp = 0 ;
  if(n == 1 || m == 1){
    if(n > m) swap(n,m) ;
    for(int i = 1 ; i <= k ; i++){
      count += cal(i,m) - cal(i-1,m) ;
      count %= mod ;
    }
  }
  else{
    for(int i = 1 ; i <= k ; i++){
    ll pes = cal(i,n) ;
    count += (pes - tmp + mod) % mod * cal(k-i+1,m) % mod ;
    tmp = pes ;
    }
  }
  cout << count % mod << endl ;
}