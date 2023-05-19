#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

ll k ;

int main(){
  cin >> k ;
  int count = 0 ;
  for(ll a = 1 ; a <= k ; a++){
    for(ll b = 1 ; a * b <= k ; b++){
      for(ll c = 1 ; a * b * c <= k ; c++){
        if(a * b * c <= k) count++ ;
      }
    }
  }
  cout << count << endl ;
}