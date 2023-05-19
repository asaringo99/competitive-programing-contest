#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e8+7

int main(){
  int a[] = {1,3,5,6,8,9,13} ;
  int b = *lower_bound(a,a+6,200) , c = *upper_bound(a,a+6,200) ;
  upper_bound(a,a+7,9) - a ;
  cout << b << " " << c << endl ;
}