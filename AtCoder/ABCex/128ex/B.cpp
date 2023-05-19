#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<string,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    map<P,int> rem ;
    P res[n] ;
    for(int i = 0 ; i < n ; i++){
        string S ;
        int p ;
        cin >> S >> p ;
        rem[P(S,-p)] = i ;
        res[i] = P(S,-p) ;
    }
    sort(res,res+n) ;
    for(int i = 0 ; i < n ; i++){
        cout << rem[res[i]] + 1 << endl ;
    }
}