#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[404040] ;

int main(){
    cin >> n ;
    ll XOR = 0 ;
    rep(i,n){
        cin >> A[i] ;
        XOR ^= A[i] ;
    }
    rep(i,n){
        if(A[i] == XOR){
            cout << "Win" << endl ;
            return 0 ;
        }
    }
    if(n % 2 == 0) cout << "Lose" << endl ;
    else cout << "Win" << endl ;
}