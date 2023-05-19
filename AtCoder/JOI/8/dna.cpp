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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n ;
string R ;
int dp[150011] ;
unordered_set<ll> st ;

ll f(ll x , char c){
    if(c == 'A') return x * 5 + 1 ;
    else if(c == 'T') return x * 5 + 2 ;
    else if(c == 'G') return x * 5 + 3 ;
    else return x * 5 + 4 ;
}

int main(){
    fast_input_output
    cin >> n >> R ;
    rrep(i,1,n+1){
        string S ;
        cin >> S ;
        ll x = 0 ;
        for(char u : S) x = f(x,u) ;
        st.insert(x) ;
    }
    int m = R.size() ;
    rep(i,m+1) dp[i] = 1e9 ;
    dp[1] = 0 ;
    rrep(i,1,m){
        ll x = 0 ; x = f(x,R[i-1]) ;
        int end = -1 ;
        for(int j = 1 ; j <= 19 ; j++){
            if(i+j>m) continue;
            x = f(x,R[i+j-1]) ;
            if(st.count(x) == 0) continue;
            end = i + j ;
        }
        rrep(j,i+1,end+1) chmin(dp[j],dp[i]+1) ;
    }
    cout << dp[m] << endl ;
} 