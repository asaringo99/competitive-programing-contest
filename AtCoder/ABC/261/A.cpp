#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
char A[1010][1010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    bool ok = true ;
    rep(i,n){
        rep(j,n){
            if(i == j){
                if(A[i][j] != '-') ok = false ;
            }
            else{
                if(A[i][j] == 'W'){
                    if(A[j][i] != 'L') ok = false ;
                }
                if(A[i][j] == 'L'){
                    if(A[j][i] != 'W') ok = false ;
                }
                if(A[i][j] == 'D'){
                    if(A[j][i] != 'D') ok = false ;
                }
            }
        }
    }
    if(ok) cout << "correct" << endl ;
    else cout << "incorrect" << endl ;
}