#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , w ;
P A[303030] ;

int main(){
    cin >> n >> w ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        A[i] = P(a,b) ;
    }
    sort(A,A+n,greater<P>()) ;
    ll res = 0 ;
    rep(i,n){
        P p = A[i] ;
        if(w - p.second < 0){
            res += w * p.first ;
            break ;
        }
        res += p.first * p.second ;
        w -= p.second ;
    }
    cout << res << endl ;
}