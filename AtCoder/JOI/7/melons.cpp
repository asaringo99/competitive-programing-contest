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

ll n , L ;
ll A[202020] , S[202020] ;
int mp[202020] ;
bool used[202020] ;
P res[202020] ;

P rec(int v){
    if(used[v]) return res[v] ;
    if(mp[v] == n){
        used[v] = true ;
        return res[v] = P(1,S[n]-S[v]) ;
    }
    auto[cnt,val] = rec(mp[v]) ;
    used[v] = true ;
    return res[v] = P(cnt+1,val) ;
}

int main(){
    cin >> n >> L ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    rep(i,n){
        auto it = upper_bound(S,S+n+1,S[i]+L) ; it-- ;
        int id = it - S ;
        mp[i] = id ;
    }
    rep(i,n){
        auto[cnt,val] = rec(i) ;
        cout << cnt << " " << val << endl ;
    }
}