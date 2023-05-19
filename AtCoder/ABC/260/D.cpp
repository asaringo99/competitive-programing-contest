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
set<TP> st ;
int res[202020] ;
set<int> uf[202020] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] , A[i]-- ;
    rep(i,n) res[i] = -1 ;
    rep(i,n){
        int a = A[i] ;
        if(st.empty()){
            if(k == 1){
                res[a] = i + 1 ;
                continue;
            }
            st.insert({a,1,a}) ;
            uf[a].insert(a) ;
            continue;
        }
        auto it = st.lower_bound({a,-1,-1}) ;
        if(it == st.end()){
            st.insert({a,1,a}) ;
            uf[a].insert(a) ;
        }
        else{
            auto[val,cnt,id] = *it ;
            uf[id].insert(a) ;
            st.erase(it) ;
            if(cnt + 1 == k){
                for(int u : uf[id]) res[u] = i + 1 ;
            }
            else{
                st.insert({a,cnt+1,id}) ;
            }
        }
    }
    rep(i,n) cout << res[i] << endl ;
}