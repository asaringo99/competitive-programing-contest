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
#define all(a) a.begin(), a.end()
#define endl "\n"

int H,W;
int A[1010][1010];
bool S[1010][1010];

int f(int res, bool flip){
    bool ok = true;
    int sum = flip ? 1 : 0;
    vector<bool> fre(W,false);
    rep(i,W) if(S[0][i]) fre[i] = true;
    rrep(i,1,H){
        bool flag = false;
        bool fin = false;
        rep(j,W){
            if(!ok) break;
            if(fre[j]) continue;
            if(fin){
                if(flip && flag) {if(1 - A[i-1][j] != 1 - A[i][j]) ok = false;}
                else if(flip) {if(1 - A[i-1][j] != A[i][j]) ok = false;}
                else if(flag) {if(A[i-1][j] != 1 - A[i][j]) ok = false;}
                else {if(A[i-1][j] != A[i][j]) ok = false;}
            }
            else{
                if(flip){
                    if(1 - A[i-1][j] != A[i][j]) flag = true, sum++;
                }
                else{
                    if(A[i-1][j] != A[i][j]) flag = true, sum++;
                }
                fin = true;
            }
        }
        if(!ok) break;
        fre.clear();
        fre.resize(W,false);
        rep(j,W){
            if(S[i][j]) fre[j] = true;
            if(flip && flag) {if(1 - A[i-1][j] == 1 - A[i][j]) fre[j] = true;}
            else if(flip) {if(1 - A[i-1][j] == A[i][j]) fre[j] = true;}
            else if(flag) {if(A[i-1][j] == 1 - A[i][j]) fre[j] = true;}
            else {if(A[i-1][j] == A[i][j]) fre[j] = true;}
        }
        flip = flag;
    }
    rep(i,W) if(!fre[i]) ok = false;
    if(ok) chmin(res,sum);
    return res;
}

int main(){
    fast_input_output
    cin >> H >> W;
    rep(i,H) rep(j,W) cin >> A[i][j];
    rep(i,H) rep(j,W){
        if(j > 0){
            if(A[i][j] == A[i][j-1]) S[i][j] = true;
        }
        if(j + 1 < W){
            if(A[i][j] == A[i][j+1]) S[i][j] = true;
        }
    }

    int res = 1e9;
    res = f(res,false);
    cout << res << endl;
    res = f(res,true);
    cout << res << endl;
    res = res == 1e9 ? -1 : res;
    cout << res << endl;
}