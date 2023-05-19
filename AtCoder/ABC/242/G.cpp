using namespace std ;
#include <bits/stdc++.h>
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

const int SQRT = 320 ;

int n , q ;
int A[101010] ;
vector<TP> query[320] ;
int res[1010101] ;
int color[101010] ;

namespace Mos{
    void add1(int& l , int lef , int &sum){
        while(l < lef){
            color[A[l]]-- ;
            if(color[A[l]] % 2 == 1) sum-- ;
            l++ ;
        }
    }
    void add2(int& l , int lef , int &sum){
        while(l > lef){
            l-- ;
            color[A[l]]++ ;
            if(color[A[l]] % 2 == 0) sum++ ;
        }
    }
    void add3(int& r , int rig , int &sum){
        while(r < rig){
            color[A[r]]++ ;
            if(color[A[r]] % 2 == 0) sum++ ;
            r++ ;
        }
    }
    void add4(int& r , int rig , int &sum){
        while(r > rig){
            r-- ;
            color[A[r]]-- ;
            if(color[A[r]] % 2 == 1) sum-- ;
        }
    }
}
using namespace Mos ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    cin >> q ;
    rep(i,q){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        query[l/SQRT].push_back({r,l,i}) ;
    }
    rep(i,320) sort(query[i].begin(),query[i].end()) ;
    int lef = 0 , rig = 0 ;
    int sum = 0 ;
    rep(i,320){
        for(TP tp : query[i]){
            auto [r,l,id] = tp ;
            add3(rig,r,sum) ;
            add4(rig,r,sum) ;
            add1(lef,l,sum) ;
            add2(lef,l,sum) ;
            res[id] = sum ;
        }
    }
    rep(i,q) cout << res[i] << endl ;
}