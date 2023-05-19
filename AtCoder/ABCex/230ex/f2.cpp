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

const int mod = 998244353 ;

int n ;
unordered_map<ll,ll> mp ;
set<ll> st ;
ll dp[202020] , A[202020] , S[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] , st.insert(S[i+1]) ;
    rrep(i,1,n+1) if(st.count(S[i]) == 1) {
        dp[i]++ ;
        st.erase(S[i]) ;
    }
    mp[0] = 0 ;
    ll sum = 0 , res = 1 ;
    rrep(i,1,n){
        ll val = mp[S[i]] ;
        mp[S[i]] = sum ;
        (dp[i] += sum - val + mod) %= mod ;
        (sum += dp[i]) %= mod ;
        (res += dp[i]) %= mod ;
    }
    cout << res << endl ;
}