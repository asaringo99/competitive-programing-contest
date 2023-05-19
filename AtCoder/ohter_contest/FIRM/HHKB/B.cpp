#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
#define M 1000000007

int H , W ;

int main(){
  int count = 0 ;
  char S[100][100] ;
  cin >> H >> W ;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> S[i][j] ;
    }
  }

  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      if(S[i][j] == '#') continue ;
      if(S[i][j+1] == '.' && j + 1 < W) count += 1 ;
      if(S[i+1][j] == '.' && i + 1 < H) count += 1 ;
    }
  }
  cout << count << endl ;
}