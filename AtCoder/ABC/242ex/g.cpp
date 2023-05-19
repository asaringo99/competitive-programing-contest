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

const int SQRT_Q = 1000 ;

int n , q ;
int A[101010] ;
vector<TP> vec[2020] ;
int ans[1010101] ;
int S[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    cin >> q ;
    rep(i,q){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        vec[l/100].push_back({r,l,i}) ;
    }
    rep(i,1010) sort(vec[i].begin(),vec[i].end()) ;
    int lef = 0 , rig = 0 , res = 0 ;
    rep(i,1010){
        for(TP tp : vec[i]){
            auto [rv,lv,id] = tp ;
            while(rig < rv){
                S[A[rig]]++ ;
                if(S[A[rig]] % 2 == 0) res++ ;
                rig++ ;
            }
            while(rig > rv){
                rig-- ;
                S[A[rig]]-- ;
                if(S[A[rig]] % 2 == 1) res-- ;
            }
            while(lef < lv){
                S[A[lef]]-- ;
                if(S[A[lef]] % 2 == 1) res-- ;
                lef++ ;
            }
            while(lef > lv){
                lef-- ;
                S[A[lef]]++ ;
                if(S[A[lef]] % 2 == 0) res++ ;
            }
            ans[id] = res ;
        }
    }
    rep(i,q) cout << ans[i] << endl ;
}