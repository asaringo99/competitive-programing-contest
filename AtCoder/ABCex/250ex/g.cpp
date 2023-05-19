#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define endl "\n"
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[202020] , B[202020] ;

ll f(ll x){
    vector<ll> up , down ;
    rep(i,n){
        if(A[i] >= x && !down.empty()) up.push_back(A[i]) ;
        else down.push_back(A[i]) ;
    }
    int m = (int)up.size() ;
    ll sum = 0 ;
    rep(i,m){
        sum += up[i] ;
        sum -= down[i] ;
    }
    return sum ;
}

int main(){
    // fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , B[i] = A[i] ;
    sort(B,B+n) ;
    ll lef = 0 , rig = n;
    int count = 100 ;
    while(count > 0){
        ll lm = (lef * 2 + rig) / 3 , rm = (lef + rig * 2) / 3 ;
        if(f(B[lm]) >= f(B[rm])) rig = rm ;
        else lef = lm ;
        count-- ;
    }
    ll res = 0 ;
    rrep(i,lef,rig+1) chmax(res,f(i)) ;
    cout << res << endl ;
}