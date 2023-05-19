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

const int dx[] = {1,0,-1,0} , dy[] = {0,1,0,-1} ;
int H , W ;
ll A[2020][2020] ;
int B[2020][2020] ;
bool used[2020][2020];

ll minval , maxval ;

bool g(bool up){
    bool gd = true;
    int lef = W ;
    rep(i,H){
        int l = lef;
        rep(j,W){
            if(up && B[i][j] < 0) {
                l = j;
                break;
            }
            if(!up && B[i][j] > 0) {
                l = j;
                break;
            }
        }
        if(l <= lef) lef = l;
        else {
            gd = false;
            break;
        }
    }
    if(gd) return true;
    gd = true;
    lef = 0;
    rep(i,H){
        int l = lef;
        for(int j = W - 1 ; j >= 0 ; j--){
            if(up && B[i][j] < 0) {
                l = j;
                break;
            }
            if(!up && B[i][j] > 0) {
                l = j;
                break;
            }
        }
        if(l >= lef) lef = l;
        else {
            gd = false;
            break;
        }
    }
    if(gd) return true;
    return false;
}

bool f(ll x){
    rep(i,H) rep(j,W){
        used[i][j] = false;
        if(maxval - x <= A[i][j] && A[i][j] <= minval + x) B[i][j] = 0;
        else if(maxval - x <= A[i][j]) B[i][j] = 1;
        else if(minval + x >= A[i][j]) B[i][j] = -1;
        else return false;
    }
    rep(i,H){
        int bf = 0;
        int cnt = 0;
        rep(j,W){
            if(bf == 1 && B[i][j] == -1) cnt++;
            if(bf == -1 && B[i][j] == 1) cnt++;
            if(cnt == 2) return false;
            if(B[i][j] != 0) bf = B[i][j];
        }
    }
    rep(i,W){
        int bf = 0;
        int cnt = 0;
        rep(j,H){
            if(bf == 1 && B[j][i] == -1) cnt++;
            if(bf == -1 && B[j][i] == 1) cnt++;
            if(cnt == 2) return false;
            if(B[j][i] != 0) bf = B[j][i];
        }
    }
    if(g(true)) return true;
    if(g(false)) return true;
    return false;
}

int main(){
    fast_input_output;
    cin >> H >> W ;
    minval = 1e9;
    maxval = 0;
    rep(i,H) rep(j,W) {
        cin >> A[i][j];
        chmin(minval,A[i][j]);
        chmax(maxval,A[i][j]);
    }
    ll lef = 0 , rig = 1e10;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid;
        else lef = mid;
        // cout << mid << endl;
        // rep(i,H){
        //     rep(j,W) cout << (B[i][j] == -1 ? 2 : B[i][j]) << " " ; cout << endl;
        // }
        // cout << endl;
    }
    cout << rig << endl;
}