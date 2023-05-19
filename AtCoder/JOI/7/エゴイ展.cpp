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

int n,m ;
ll A[202020] , B[202020] ;

int main(){
    cin >> n >> m;
    rep(i,n) cin >> A[i] >> B[i] ;
    ll fir = 0 , sec = 0 , res = 0 ;
    int a = -1 , b = -1 ;
    rep(i,n){
        ll x = A[i] , cost = B[i] ;
        if(x != a){
            ll v = fir + cost ;
            if(v > fir){
                swap(fir,sec) ;
                swap(a,b) ;
                fir = v ;
                a = x ;
            }
            else if(v > sec){
                sec = v ;
                b = x ;
            }
            chmax(res,v) ;
        }
        else {
            ll v = sec + cost ;
            if(v > fir){
                fir = v ;
                a = x ;
            }
            chmax(res,v) ;
        }
    }
    cout << res << endl;
}