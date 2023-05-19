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

int n , m ;
P A[202020] , B[202020] ;
map<int,vector<int>> X , Y ;
int C[202020] ;
int D[202020] ;
multiset<int> mst ;
set<int> st ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i].first ;
    rep(i,n) cin >> A[i].second ;
    rep(i,m) cin >> B[i].first ;
    rep(i,m) cin >> B[i].second ;
    rep(i,n){
        auto [a,b] = A[i] ;
        X[a].push_back(b) ;
        st.insert(a);
    }
    rep(i,m){
        auto [a,b] = B[i] ;
        Y[a].push_back(b) ;
        st.insert(a);
    }
    auto it = st.end() ; it-- ;
    bool ok = true ;
    while(true){
        vector<int> ve = Y[*it] ;
        for(int u : ve) mst.insert(u) ;
        vector<int> vec = X[*it] ;
        for(int u : vec){
            auto itr = mst.lower_bound(u) ;
            if(itr == mst.end()){
                cout << "No" << endl ;
                return 0 ;
            }
            mst.erase(itr) ;
        }
        if(it == st.begin()) break ;
        it-- ;
    }
    cout << "Yes" << endl ;
}