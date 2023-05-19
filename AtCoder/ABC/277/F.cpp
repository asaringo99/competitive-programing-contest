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

int H, W ;

int main(){
    // fast_input_output
    cin >> H >> W ;
    vector<vector<int>> A(H,vector<int>(W));
    vector<vector<int>> S(W,vector<int>(H));
    vector<TP> B(H);
    rep(i,H) rep(j,W) cin >> A[i][j];
    rep(i,H) rep(j,W) S[j][i] = A[i][j];
    rep(i,H){
        int mn = 1e9, mx = 0;
        rep(j,W) if(A[i][j] != 0){
            chmax(mx,A[i][j]);
            chmin(mn,A[i][j]);
        }
        chmax(mx,mn);
        B[i] = {mx,mn,i};
    }
    sort(B.begin(),B.end(),greater<TP>());
    int mn = 1e9;
    bool ok = true;
    rep(i,H){
        auto [x,y,id] = B[i];
        if(mn < x) ok = false;
        mn = y;
    }
    if(!ok) {
        cout << "No" << endl;
        return 0;
    }
    int s = 0;
    vector<int> query;
    rep(i,H){
        auto [mx,mn,id] = B[i];
        vector<P> C;
        rrep(j,s,W) if(S[j][id] != 0) C.push_back({S[j][id],j});
        sort(C.begin(),C.end());
        rep(x,C.size()){
            auto[val,ik] = C[x];
            if(s+x < ik) swap(S[s+x],S[ik]);
        }
        s += C.size();
        if(!C.empty()) query.push_back(s);
    }
    rep(i,H) {
        int s = 0;
        for(int t : query){
            rrep(j,s,t-1) {
                if(j == W-1) continue;
                if(S[j][i] == 0) continue;
                if(S[j+1][i] == 0) continue;
                if(S[j][i] > S[j+1][i]) ok = false;
            }
            s = t;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}