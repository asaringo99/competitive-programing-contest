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
typedef pair<int,int> P ;
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

int n, k ;
char S[101010];

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> S[i];
    int rig = 0, lef = 0, res = 0;

    rep(i,n){
        if(k == 0){
            if(S[i] == '0'){
                rig = i;
                break;
            }
            continue;
        }
        if(S[i] == '0' && S[i+1] == '1') k--;
        chmax(res,i+1);
    }
    chmax(res,rig-lef);
    while(rig < n){
        while(S[rig] == '0') rig++;
        while(S[rig] == '1') rig++;
        while(S[lef] == '1') lef++;
        while(S[lef] == '0') lef++;
        chmax(res,rig-lef);
    }
    cout << res << endl;
}