#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    sort(S.begin(),S.end(),greater<char>()) ;
    S.pop_back() ;
    int k = n / 2 ;
    int res = 0 ;
    for(int i = 0 ; i < k ; i++){
        if(S[i] == 'g') res++ ;
    }
    cout << res << endl ;
}