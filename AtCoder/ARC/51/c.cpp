#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mm = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mm ;
        (x *= x) %= mm ;
        n >>= 1 ;
    }
    return res ;
}

ll n , a , b ;
ll A[55] ;

int main(){
    cin >> n >> a >> b ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    if(a == 1){
        rep(i,n) cout << A[i] << endl ;
        return 0 ;
    }
    priority_queue<ll,vector<ll>,greater<ll>> que ;
    vector<ll> vec ;
    rep(i,n) que.push(A[i]) ;
    while(b > 0 && !que.empty()){
        ll v = que.top() ; que.pop() ;
        if(v * a >= A[n-1]) vec.push_back(v*a) ;
        else que.push(v * a) ;
        b-- ;
    }
    while(!que.empty()){
        ll v = que.top() ; que.pop() ;
        vec.push_back(v) ;
    }
    sort(vec.begin(),vec.end()) ;
    ll mod = b % n ;
    ll div = b / n ;
    rrep(i,mod,n) cout << (vec[i] % mm * powmod(a,div) % mm) << endl ;
    rep(i,mod) cout << (vec[i] % mm * powmod(a,div+1) % mm) << endl ;
}