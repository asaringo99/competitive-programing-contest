#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int z ;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    rep(i,n){
        string S;
        cin >> S;
        ll s = 0;
        rep(j,m){
            s += (1LL << (m-1-j)) * (S[j] - '0');
        }
        A[i] = s;
    }
    ll v = (1LL << m) - 1;
    ll med = v / 2;
    set<ll> st;
    rrep(i,max(med-55,0LL),min(med+55,v+1)){
        st.insert(i);
    }
    auto it = st.lower_bound(med);
    rep(i,n){
        if(i % 2 == 0){
            if(*it >= A[i]){
                it++;
            }
            st.erase(A[i]);
        }
        else{
            if(*it <= A[i]){
                it--;
            }
            st.erase(A[i]);
        }
    }
    ll x = *it;
    vector<int> vec;
    rep(i,m){
        if(x >> (m - 1 - i) & 1) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}