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

int n, q;
string S;
int K[101];
ll state[80];
ll pos[80][2];
ll res[101];

int main(){
    fast_input_output
    cin >> n >> S >> q;
    rep(i,q) cin >> K[i];
    rep(i,n){
        rep(j,q){
            int x = K[j];
            if(i - x >= 0 && S[i - x] == 'D'){
                state[j] -= pos[j][1];
                pos[j][0]--;
            }
            if(i - x >= 0 && S[i - x] == 'M'){
                pos[j][1]--;
            }
        }
        if(S[i] == 'D'){
            rep(j,q) pos[j][0]++;
        }
        if(S[i] == 'M'){
            rep(j,q) pos[j][1]++, state[j] += pos[j][0];
        }
        if(S[i] == 'C'){
            rep(j,q) res[j] += state[j];
        }
    }
    rep(i,q) cout << res[i] << endl;
}