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
set<int> st ;

int main(){
    cin >> n ;
    rrep(i,1,2*n+2) st.insert(i) ;
    while(!st.empty()){
        auto it = st.begin() ;
        cout << *it << endl ;
        st.erase(it) ;
        int a ;
        cin >> a ;
        if(a == 0) break ;
        st.erase(a) ;
    }
}