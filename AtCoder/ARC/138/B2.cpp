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
int A[202020] , B[202020] ;

bool fin = false ;
bool ok = false ;

void dfs(int l , int r , int t){
    if(fin) return ;
    if(t == 0 && l == r && A[l] == 0) ok = true ;
    if(t == 1 && l == r && B[l] == 0) ok = true ;
    if(ok) fin = true ;
    if(t == 0){
        if(A[r] == 0) dfs(l,r-1,0) ;
        if(fin) return ;
        if(B[l+1] == 0) dfs(l+1,r,1) ;
        if(fin) return ;
    }
    if(t == 1){
        if(B[r] == 0) dfs(l,r-1,1) ;
        if(fin) return ;
        if(A[l+1] == 0) dfs(l+1,r,0) ;
        if(fin) return ;
    }
    if(fin) return ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) B[i] = A[i] == 1 ? 0 : 1 ;
    if(A[0] == 1){
        cout << "No" << endl ;
        return 0 ;
    }
    dfs(0,n-1,0) ;
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}