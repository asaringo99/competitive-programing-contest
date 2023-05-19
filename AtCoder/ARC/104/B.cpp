#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define INF (ll)1e5

int n ;
string T ;

int main(){
  cin >> n >> T ;

  int count = 0 ;
  for(int i = 0 ; i < n ; i++){
    pair<int,int> AT , CG ;
    for(int j = i ; j < n ; j++){
      if(T[j] == 'A') AT.first++ ;
      if(T[j] == 'T') AT.second++ ;
      if(T[j] == 'C') CG.first++ ;
      if(T[j] == 'G') CG.second++ ;

      if(AT.first == AT.second && CG.first == CG.second) count++ ;
    }
  }
  cout << count << endl ;
}