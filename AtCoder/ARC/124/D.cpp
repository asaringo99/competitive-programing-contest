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

unordered_map<int,vector<P>> dp ;

int main(){
    cin >> n ;
    dp[0].push_back(P(0,0)) ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        set<P> st ;
        for(P p : dp[i]){
            ll s = p.first , t = p.second ;
            ll A = gcd(s,a) , B = gcd(t,b) ;
            if(A > B) swap(A,B) ;
            st.insert(P(A,B)) ;
            A = gcd(t,a) ;
            B = gcd(s,b) ;
            if(A > B) swap(A,B) ;
            st.insert(P(A,B)) ;
        }
        for(P p : st) dp[i+1].push_back(p) ;
    }
    ll res = 1 ;
    for(P p : dp[n]){
        ll A = p.first , B = p.second ;
        res = max(res,lcm(A,B)) ;
    }
    cout << res << endl ;
}