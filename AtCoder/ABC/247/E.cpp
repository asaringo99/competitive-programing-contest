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

ll n , x , y ;
ll A[202020] ;
set<ll> mn , mx ;
vector<P> vec ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    vector<int> ins ;
    rep(i,n) {
        cin >> A[i] ;
        if(y <= A[i] && A[i] <= x) ins.push_back(i) ;
        else if(!ins.empty()) {
            vec.push_back(P(ins[0],ins[ins.size()-1])) ;
            ins = {} ;
        }
    }
    if(!ins.empty()) vec.push_back(P(ins[0],ins[ins.size()-1])) ;
    ll res = 0 ;
    int m = vec.size() ;
    rep(z,m){
        auto [minv, maxv] = vec[z] ;
        mn = {} ;
        mx = {} ;
        rrep(i,minv,maxv+1){
            if(A[i] == y) mn.insert(i) ;
            if(A[i] == x) mx.insert(i) ;
        }
        rrep(i,minv,maxv+1){
            if(mn.size() == 0) break ;
            if(mx.size() == 0) break ;
            auto it = mn.begin() ;
            auto jt = mx.begin() ;
            ll mni = *it , mxi = *jt ;
            ll id = max(mni,mxi) ;
            res += maxv + 1 - id ;
            if(mni == i) mn.erase(it) ;
            if(mxi == i) mx.erase(jt) ;
        }
    }
    cout << res << endl ;
}