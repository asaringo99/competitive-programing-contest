#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , m ;
P A[100007] ;

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++) cin >> A[i].second >> A[i].first ;
    sort(A,A+n,greater<P>()) ;
    set<int> st ;
    for(int i = 1 ; i <= m ; i++) st.insert(i) ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        auto it = st.lower_bound(A[i].second) ;
        if(it == st.end()) continue ;
        st.erase(it) ;
        res += A[i].first ;
    }
    cout << res << endl ;
}