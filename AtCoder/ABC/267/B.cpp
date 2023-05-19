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
string S;
int C[10];

int main(){
    fast_input_output
    cin >> S ;
    if(S[6] == '1') C[0]++;
    if(S[3] == '1') C[1]++;
    if(S[1] == '1') C[2]++;
    if(S[7] == '1') C[2]++;
    if(S[0] == '1') C[3]++;
    if(S[4] == '1') C[3]++;
    if(S[2] == '1') C[4]++;
    if(S[8] == '1') C[4]++;
    if(S[5] == '1') C[5]++;
    if(S[9] == '1') C[6]++;
    if(S[0] == '1'){
        cout << "No" << endl;
        return 0;
    }
    rep(i,7){
        rrep(j,i+1,7){
            rrep(k,j+1,7){
                if(C[i] > 0 && C[j] == 0 && C[k] > 0){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}