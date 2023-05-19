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

int t ;

void solve(){
    int n ;
    map<ll,vector<ll>> mp ;
    vector<int> L = {1000000010} ;
    cin >> n ;
    rep(i,n){
        int l , r ;
        cin >> l >> r ;
        mp[l].push_back(r) ;
        L.push_back(l) ;
    }
    sort(L.begin(),L.end()) ;
    multiset<int> st ;
    int i = 1 ;
    while(i < 1000000010){
        for(int u : mp[i]) st.insert(u) ;
        if(st.empty()){
            auto it = lower_bound(L.begin(),L.end(),i) ;
            i = *it ;
            continue ;
        }
        auto it = st.begin() ;
        if(*it < i){
            cout << "No" << endl ;
            return ;
        }
        st.erase(it) ;
        i++ ;
    }
    cout << "Yes" << endl ;
}

int main(){
    fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}