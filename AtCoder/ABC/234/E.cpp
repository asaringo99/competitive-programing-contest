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

string x ;
vector<ll> vec ;

int main(){
    cin >> x ;
    int n = x.size() ;
    ll s = 0 ;
    rep(i,n){
        s *= 10 ;
        s += x[i] - '0' ;
    }
    rep(i,10){
        int v = x[0] - '0' ;
        ll y = 0 ;
        bool ok = true ;
        rep(j,n){
            if(v >= 10) ok = false ;
            y *= 10 ;
            y += v ;
            v += i ;
        }
        // if(ok) if(y >= s) cout << y << endl ;
        if(ok) if(y >= s) vec.push_back(y) ;
    }
    rep(i,10){
        int v = x[0] - '0' ;
        ll y = 0 ;
        bool ok = true ;
        rep(j,n){
            if(v < 0) ok = false ;
            y *= 10 ;
            y += v ;
            v -= i ;
        }
        // if(ok) if(y >= s) cout << y << endl ;
        if(ok) if(y >= s) vec.push_back(y) ;
    }
    rep(i,10){
        int v = x[0] - '0' ;
        ll y = 0 ;
        v++ ;
        bool ok = true ;
        rep(j,n){
            if(v < 0) ok = false ;
            y *= 10 ;
            y += v ;
            v -= i ;
        }
        // if(ok) if(y >= s) cout << y << endl ;
        if(ok) if(y >= s) vec.push_back(y) ;
    }
    rrep(i,1,10){
        ll y = 0 ;
        rep(j,n){
            y *= 10 ;
            y += i ;
        }
        // if(y >= s) cout << y << endl ;
        if(y >= s) vec.push_back(y) ;
    }
    sort(vec.begin(),vec.end()) ;
    // rep(i,vec.size()) cout << vec[i] << " " ; cout << endl;
    cout << vec[0] << endl ;
}