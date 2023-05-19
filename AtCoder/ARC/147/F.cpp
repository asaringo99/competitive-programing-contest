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
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n ;

int L[303030], R[303030];

ll f(int x){
    vector<ll> X, Y;
    multiset<int> st;
    rep(i,n){
        if(L[i] <= x && x <= R[i]) st.insert(x);
        else if(x < L[i]) st.insert(L[i]);
        else st.insert(R[i]);
    }
    ll sum = 0;
    auto it = st.begin(); it++;
    int cnt = 1;
    while(it != st.end()){
        sum += cnt * (*it);
        cnt++;
        it++;
    }
    auto et = st.end(); et--;
    st.erase(et);
    it = st.begin();
    cnt = 0;
    while(it != st.end()){
        sum -= (n - 1 - cnt) * (*it);
        cnt++;
        it++;
    }
    return sum;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        cin >> L[i] >> R[i];
    }

    int lef = 0 , rig = 1e8;
    int cnt = 0;
    while(cnt <= 200){
        int lm = (lef * 2 + rig) / 3, rm = (rig * 2 + lef) / 3;
        if(f(lm) > f(rm)) lef = lm;
        else rig = rm;
        cnt++;
    }
    cout << min({f(lef),f(lef+1),f(rig)}) << endl;
    // rrep(i,1,10) cout << f(i) << endl;
}