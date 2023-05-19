#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
#define INFO 200005

int N , p ;

int main(){
  int k = 0 ;
  cin >> N ;
  bool P[INFO] ;
  fill(P,P+N,true) ;
  for(int i = 0 ; i < N ; i++){
    cin >> p ;
    P[p] = false ;
    if(P[k] != false) cout << k << endl ;
    else{
      while(P[k] == false){
        k++ ;
      }
      cout << k << endl ;
    }
  }
}