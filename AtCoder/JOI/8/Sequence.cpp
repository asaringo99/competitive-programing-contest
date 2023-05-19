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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

ll m , p , q ;
int X[30] , Y[30] ;

int main(){
    cin >> m >> p >> q ;
    ll cnt = 0 ;
    rep(i,m) {
        cin >> X[i] ;
        Y[i] = X[i] ;
        if(X[i] & 1) cnt++ ;
    }
    int a = X[0] ;
    int num = m ;
    rrep(i,m,1<<m){
        X[i%m] = (X[i%m] ^ X[(i-1+m)%m]) ;
        if(X[i%m] == a) break ;
        if(X[i%m] & 1) cnt++ ;
        num++ ;
    }
    ll seq = num ;
    ll res = 0 ;
    if((q-1)/seq == (p-1)/seq){
        p-- ;
        q-- ;
        p %= seq ;
        q %= seq ;
        rep(i,m) X[i] = Y[i] ;
        rep(i,m) if(X[i] & 1 && p <= i && i <= q) res++ ;
        rrep(i,m,seq){
            X[i%m] = (X[i%m] ^ X[(i-1+m)%m]) ;
            if(X[i%m] & 1 && p <= i && i <= q) res++ ;
        }
    }
    else{
        res = ((q-1)/seq-(p-1)/seq-1)*cnt ;
        p-- ;
        q-- ;
        p %= seq ;
        q %= seq ;
        rep(i,m) X[i] = Y[i] ;
        rep(i,m) if(X[i] & 1 && p <= i) res++ ;
        rrep(i,m,seq){
            X[i%m] = (X[i%m] ^ X[(i-1+m)%m]) ;
            if(X[i%m] & 1 && p <= i) res++ ;
        }
        rep(i,m) X[i] = Y[i] ;
        rep(i,m) if(X[i] & 1 && i <= q) res++ ;
        rrep(i,m,seq){
            X[i%m] = (X[i%m] ^ X[(i-1+m)%m]) ;
            if(X[i%m] & 1 && i <= q) res++ ;
        }
    }
    cout << res << endl ;
}