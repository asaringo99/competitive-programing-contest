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

int n , q ;
ll A[202020] ;
vector<int> B[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n+1) {
        B[i].push_back(-1) ;
    }
    rep(i,n) {
        cin >> A[i] ;
        B[A[i]].push_back(i) ;
    }
    rrep(i,1,n+1) {
        B[i].push_back(n+10) ;
    }
    // rrep(i,1,n+1){
    //     for(int u : B[i]) cout << u << " " ; cout << endl ;
    // }
    cin >> q ;
    rep(i,q){
        int l , r , x ;
        cin >> l >> r >> x ;
        l-- ; r-- ;
        auto itl = lower_bound(B[x].begin(),B[x].end(),l) ;
        int idl = itl - B[x].begin() ;
        if(B[x][idl] > r){
            cout << 0 << endl ;
            continue ;
        }
        auto itr = upper_bound(B[x].begin(),B[x].end(),r) ; itr-- ;
        int idr = itr - B[x].begin() ; 
        if(B[x][idr] < l){
            cout << 0 << endl ;
            continue ;
        }
        cout << idr - idl + 1 << endl ;
    }
}