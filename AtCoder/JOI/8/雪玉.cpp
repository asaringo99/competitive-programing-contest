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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n, q ;
ll X[202020];
ll W[202020];
set<P> L, R;
P res[202020];

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> X[i];
    rep(i,q) cin >> W[i];
    rep(i,n){
        if(i == n - 1) R.insert(P(1e18,i));
        else R.insert(P(X[i+1]-X[i],i));
    }
    rep(i,n){
        if(i == 0) L.insert(P(1e18,i));
        else L.insert(P(X[i]-X[i-1],i));
    }
    ll lef = 0, rig = 0, pos = 0;
    rep(i,q){
        ll w = W[i];
        if(w >= 0){
            auto itr = R.upper_bound(P(pos+lef+w,-1));
            pos = pos + lef + w;
            chmax(rig,pos);
            auto it = R.begin();
            while(it != itr){
                if(it == itr) break;
                auto[d,id] = *it;
                ll x = X[id];
                it++;
            }
        }
        else{

        }
    }
}