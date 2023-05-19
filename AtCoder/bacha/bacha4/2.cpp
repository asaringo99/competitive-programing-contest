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
vector<ll> vec1 , vec2 ;
vector<P> res ;


int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        if(a >= 0) vec1.push_back(a) ;
        else vec2.push_back(a) ;
    }
    sort(vec1.begin(),vec1.end()) ;
    sort(vec2.begin(),vec2.end()) ;
    if(vec1.empty()){
        ll val = vec2[n-1] ;
        rep(i,n-1){
            res.push_back(P(val,vec2[i])) ;
            val -= vec2[i] ;
        }
        cout << val << endl ;
        for(P p : res) cout << p.first << " " << p.second << endl ;
    }
    else if(vec2.empty()){
        ll val = vec1[0] ;
        rrep(i,1,n-1){
            res.push_back(P(val,vec1[i])) ;
            val -= vec1[i] ;
        }
        res.push_back(P(vec1[n-1],val)) ;
        val = vec1[n-1] - val ;
        cout << val << endl ;
        for(P p : res) cout << p.first << " " << p.second << endl ;
    }
    else{
        rep(i,vec1.size()-1){
            res.push_back(P(vec2[0],vec1[i])) ;
            vec2[0] -= vec1[i] ;
        }
        ll val = vec1[vec1.size()-1] ;
        rep(i,vec2.size()){
            res.push_back(P(val,vec2[i])) ;
            val -= vec2[i] ;
        }
        cout << val << endl ;
        for(P p : res) cout << p.first << " " << p.second << endl ;
    }
}