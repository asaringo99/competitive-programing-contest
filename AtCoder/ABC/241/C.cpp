#include <bits/stdc++.h>
using namespace std ;
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

int n , m ;
ll A[1010] , B[1010] ;
bool used[1010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,m) cin >> B[i] ;
    bool res = true ;
    rep(i,m){
        bool ok = false ;
        rep(j,n){
            if(used[j]) continue ;
            if(A[j] == B[i]) {
                ok = true ;
                used[j] = true ;
                break ;
            }
        }
        if(!ok) res = false ;
    }
    if(res) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}