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

ll n , m , k ;
ll a , b , c , T ;
ll S[3030] ;
vector<ll> vec[3030] ;
ll dp[3030][3030] ;

int main(){
    fast_input_output;
    cin >> n >> m >> k ;
    cin >> a >> b >> c >> T ;
    rep(i,m) cin >> S[i] , S[i]--;
    rep(i,m-1){
        ll fir = S[i], fin = S[i+1] - S[i];
        ll base_tim = fir * b;
        ll rem = T - base_tim;
        ll pos = a / (T - base_tim);
        dp[i][0] += pos + 1;
        pos++;
        int j = 0 ;
        while(pos < fin){
            chmax(dp[i+1][j],dp[i][j]);
            base_tim += pos * c;
            rem = T - base_tim;
            if(rem <= 0){

            }
            pos = a / (T - base_tim);

        }
    }
}