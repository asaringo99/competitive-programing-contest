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

int n , k ;
ll A[202020] ;
vector<int> vec[202020] , B ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    int c = 0 ;
    rep(i,n){
        vec[c%k].push_back(A[i]) ;
        c++ ;
    }
    rep(i,k) sort(vec[i].begin(),vec[i].end()) ;
    int m = vec[0].size() ;
    rep(i,m){
        rep(j,k){
            if(vec[j].size() == i) continue;
            B.push_back(vec[j][i]) ;
        }
    }
    sort(A,A+n) ;
    bool ok = true ;
    rep(i,n) if(A[i] != B[i]) ok = false ;
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}