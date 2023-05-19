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

int n , q ;
vector<ll> A[4] ;

vector<P> rec(ll a , int i){
    if(i == 0){
        vector<P> res ;
        auto it = lower_bound(A[1].begin(),A[1].end(),a) ;
        if(it != A[1].end()){
            vector<P> vec = rec(*it,i+1) ;
            for(P p : vec){
                auto[x,y] = p ;
                res.push_back(P(x,y+abs(*it-a))) ;
            }
        }
        if(it == A[1].begin()) return res ;
        it-- ;
        vector<P> vec = rec(*it,i+1) ;
        for(P p : vec){
            auto[x,y] = p ;
            res.push_back(P(x,y+abs(*it-a))) ;
        }
        return res ;
    }
    else if(i == 1){
        vector<P> res ;
        auto it = lower_bound(A[2].begin(),A[2].end(),a) ;
        if(it != A[2].end()){
            vector<P> vec = rec(*it,i+1) ;
            for(P p : vec){
                auto[x,y] = p ;
                res.push_back(P(x,y+abs(*it-a))) ;
            }
        }
        if(it == A[2].begin()) return res ;
        it-- ;
        vector<P> vec = rec(*it,i+1) ;
        for(P p : vec){
            auto[x,y] = p ;
            res.push_back(P(x,y+abs(*it-a))) ;
        }
        return res ;
    }
    else{
        vector<P> res ;
        auto it = lower_bound(A[3].begin(),A[3].end(),a) ;
        if(it != A[3].end()){
            res.push_back(P(*it,abs(*it-a))) ;
        }
        if(it == A[3].begin()) return res ;
        it-- ;
        res.push_back(P(*it,abs(*it-a))) ;
        return res ;
    }
}

int main(){
    cin >> n ;
    rep(i,n) {
        ll a ;
        char c ;
        cin >> a >> c ;
        if(c == 'J') A[0].push_back(a) ;
        if(c == 'O') A[1].push_back(a) ;
        if(c == 'I') A[2].push_back(a) ;
        if(c == 'G') A[3].push_back(a) ;
    }
    rep(i,4) sort(A[i].begin(),A[i].end()) ;
    cin >> q ;
    rep(i,q){
        ll s , t ;
        cin >> s >> t ;
        auto it = lower_bound(A[0].begin(),A[0].end(),s) ;
        ll res = 4e18 ;
        if(it != A[0].end()){
            vector<P> vec = rec(*it,0) ;
            for(P p : vec){
                auto[pos,dist] = p ;
                chmin(res,abs(*it-s)+dist+abs(pos-t)) ;
            }
        }
        if(it == A[0].begin()) {
            cout << res << endl ;
            continue;
        }
        it-- ;
        vector<P> vec = rec(*it,0) ;
        for(P p : vec){
            auto[pos,dist] = p ;
            chmin(res,abs(*it-s)+dist+abs(pos-t)) ;
        }
        cout << res << endl ;
    }
}