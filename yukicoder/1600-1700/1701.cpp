#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll w ;
int n ;

ll A[20] ;

int main(){
    cin >> n >> w ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rep(S,1<<n){
        if(S == 0) continue ;
        vector<ll> vec ;
        rep(i,n) if(S >> i & 1) vec.push_back(A[i]) ;
        int m = vec.size() ;
        bool ok = false ;
        rep(T,1<<m){
            vector<ll> tor ;
            rep(i,m) {
                if(T >> i & 1) tor.push_back(vec[i] / 2) ;
                else tor.push_back(vec[i]) ;
            }
            ll sum = 0 ;
            rep(i,m) sum += tor[i] ;
            if(sum == w) ok = true ;
        }
        if(ok) res++ ;
    }
    cout << res << endl ;
}