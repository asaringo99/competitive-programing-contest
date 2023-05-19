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

const int mod = 10000000 ;

int n , m ;
string S ;
vector<int> vec ;
bool C[30][30] ;
ll dp[303030] ;
int next_[303030][26] ;

void f(){
    rep(i,26) next_[n][i] = n ;
    for(int i = n - 1 ; i >= 0 ; i--){
        rep(j,26) next_[i][j] = next_[i+1][j] ;
        next_[i][S[i]-'A'] = i ;
    }
}

int main(){
    cin >> n >> S >> m ;
    for(char c : S){
        vec.push_back(c-'A') ;
    }
    rep(i,m){
        char a , b ;
        cin >> a >> b ;
        C[a-'A'][b-'A'] = true;
    }
    f() ;
    rep(i,26) dp[next_[0][i]] = 1 ;
    rep(i,n){
        rep(j,26){
            if(C[vec[i]][j]) continue;
            (dp[next_[i+1][j]] += dp[i]) %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,n) (res += dp[i]) %= mod ;
    cout << res << endl ;
}