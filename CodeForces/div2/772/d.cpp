#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define all(a) a.begin(), a.end()
#define endl "\n"

const int mod = 1000000007 ;

ll A[202020], B[202020];
ll dp[202020][2];

void solve(){
    int n, p;
    cin >> n >> p;
    set<int> st;
    rep(i,n) cin >> A[i], st.insert(A[i]);
    sort(A,A+n);
    for(int i = n - 1; i >= 0; i--){
        int a = A[i];
        bool e = false;
        while(a != 1){
            if(a % 4 == 0) a /= 4;
            else if(a % 2 == 0) break;
            else a /= 2;
            if(st.count(a) == 1){
                e = true;
            }
        }
        if(e) st.erase(A[i]);
    }
    ll val = 1, cnt = 1;
    while(val < ((ll)1 << 40)){
        val <<= 1;
        auto it = st.begin();
        while(it != st.end()){
            if(*it < val) {
                B[cnt]++;
                st.erase(it++);
            }
            else break;
        }
        cnt++;
    }
    ll res = 0;
    rrep(i,1,p+1){
        (dp[i][0] += B[i]) %= mod;
        (dp[i+2][0] += dp[i][0] + dp[i][1]) %= mod;
        (dp[i+1][1] += dp[i][0] + dp[i][1]) %= mod;
        (res += dp[i][0] * (p - i + 1) % mod) %= mod;
    }
    cout << res << endl;
    // rep(i,p+1) cout << dp[i] << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}