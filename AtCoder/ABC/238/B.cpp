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

int n ;
int A[450] ;
set<int> st ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int sum = 0 ;
    st.insert(0) ;
    rep(i,n){
        sum += A[i] ;
        st.insert(sum % 360) ;
    }
    st.insert(360) ;
    vector<int> vec ;
    for(int u : st) vec.push_back(u) ;
    int m = vec.size() ;
    int res = 0 ;
    rep(i,m-1) chmax(res,vec[i+1] - vec[i]) ;
    cout << res << endl ;
}