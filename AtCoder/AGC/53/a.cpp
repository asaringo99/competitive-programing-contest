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
string S ;
int A[101] ;

int main(){
    fast_input_output
    cin >> n >> S ;
    rep(i,n+1) cin >> A[i] ;
    int res = 1 ;
    rrep(x,1,10001){
        bool ok = true ;
        rep(i,n){
            if(S[i] == '<') if(A[i+1] - A[i] < x) ok = false ;
            if(S[i] == '>') if(A[i] - A[i+1] < x) ok = false ;
        }
        if(ok) res = x ;
    }
    vector<vector<int>> vec(res,vector<int>(n+1)) ;
    rep(i,n+1){
        ll val = A[i] / res ;
        ll mod = A[i] % res ;
        rep(j,res) vec[j][i] = val ;
        rep(j,mod) vec[res-1-j][i]++ ;
    }
    cout << res << endl ;
    rep(i,res){
        rep(j,n+1) cout << vec[i][j] << " " ; cout << endl ;
    }
}