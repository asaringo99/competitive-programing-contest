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
bool used[303030] ;
int A[303030] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    if(2 * k > n){
        cout << -1 << endl ;
        return 0 ;
    }
    set<int> st , p ;
    rrep(i,1,n+1) st.insert(i) ;
    rrep(i,1,n+1) p.insert(i) ;
    rrep(i,1,k+1){
        A[i] = i + k ;
        st.erase(i) ;
        p.erase(i+k) ;
    }
    rep(i,k){
        A[n-i-k] = n - i ;
        p.erase(n-i) ;
        st.erase(n-i-k) ;
    }
    rrep(i,2*k+1,n-k+1){
        auto it = st.lower_bound(i+k) ;
        if(it != st.end()){
            int id = *it ;
            A[id] = i ;
            st.erase(it) ;
            continue;
        }
        it = st.upper_bound(i-k) ;
        if(it == st.begin()){
            cout << -1 << endl ;
            return 0 ;
        }
        it-- ;
        int id = *it ;
        A[id] = i ;
        st.erase(it) ;
    }
    int x = 1 ;
    for(int u : st){
        A[u] = x ;
        x++ ;
    }
    rrep(i,1,n+1) cout << A[i] << " " ; cout << endl ;
}