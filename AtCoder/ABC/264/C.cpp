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

int H, W, R, C ;
int A[11][11], B[11][11] ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j];
    cin >> R >> C;
    rep(i,R) rep(j,C) cin >> B[i][j];
    rep(S,1<<H){
        if(bit_count(S) + R != H) continue;
        vector<bool> row(H);
        rep(i,H) if(S >> i & 1) row[i] = true;
        rep(T,1<<W){
            if(bit_count(T) + C != W) continue;
            vector<bool> col(W);
            rep(i,W) if(T >> i & 1) col[i] = true;
            vector<vector<int>> mat;
            rep(i,H){
                if(row[i]) continue;
                vector<int> el;
                rep(j,W){
                    if(col[j]) continue;
                    el.push_back(A[i][j]);
                }
                mat.push_back(el);
            }
            bool ok = true;
            rep(i,R) rep(j,C) if(mat[i][j] != B[i][j]) ok = false;
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}