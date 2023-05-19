#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
P A[100] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a / gcd(a,b) * b ;
}

int main(){
    cin >> n ;
    ll resa = 0 , resb = 0 ;
    rep(i,n) cin >> A[i].second >> A[i].first ;
    sort(A,A+n,greater<P>()) ;
    rep(i,n){
        ll a = A[i].first , b = A[i].second ;
        if(lcm(gcd(resa,a),gcd(resb,b)) > lcm(gcd(resa,b),gcd(resb,a))){
            resa = gcd(resa,a) ;
            resb = gcd(resb,b) ;
        }
        else{
            resa = gcd(resa,b) ;
            resb = gcd(resb,a) ;
        }
    }
    cout << lcm(resa,resb) << endl ;
}