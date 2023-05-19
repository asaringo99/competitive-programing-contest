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
#define endl "\n"

int n ;
P A[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i].first >> A[i].second ;
    sort(A,A+n) ;
    ll fir = A[0].first , end = A[0].second ;
    vector<P> res ;
    rrep(i,1,n){
        auto [sta , fin] = A[i] ;
        if(sta > end){
            res.push_back(P(fir,end)) ;
            fir = sta ;
            end = fin ;
        }
        else{
            end = max(end,fin) ;
        }
    }
    res.push_back(P(fir,end)) ;
    for(P p : res) cout << p.first << " " << p.second << endl ;
}