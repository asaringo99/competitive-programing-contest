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

struct Divisor{
    ll n ;
    vector<int> res ;
    Divisor(ll n_){
        n = n_ ;
        build() ;
    }

    void build(){
        for(ll i = 1 ; i * i <= n ; i++){
            if(n % i == 0) {
                res.push_back(i) ;
                if(i * i != n) res.push_back(n/i) ;
            }
        }
    }

    vector<int> divisorList() { return res ; }
    vector<int> divisorListBySort(){
        sort(res.begin(),res.end()) ;
        return res ;
    }
    int origin() { return n ; }
    size_t size(){ return res.size() ; }
    inline ll operator [] (int i) { return res[i] ; }
};

int n ;
ll A[2020] ;
unordered_map<ll,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    int com = A[0] ;
    rep(i,n){
        Divisor B(A[i]) ;
        int m = B.size() ;
        rep(j,m) mp[B[j]] = gcd(A[i],mp[B[j]]) ;
    }
    int count = 0 ;
    for(auto it : mp) if(it.second == it.first && it.first <= com) count++ ;
    cout << count << endl ;
}