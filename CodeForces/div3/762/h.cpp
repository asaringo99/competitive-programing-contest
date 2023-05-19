#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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

const int S = 100;

int n, q ;
int A[101010], B[101010], C[101010];

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n){
        int x = i;
        rep(j,S){
            x = A[x];
        }
        B[i] = x;
        C[A[i]] = i;
    }
    rep(i,q){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            x--; y--;
            swap(A[x],A[y]);
            swap(C[A[x]],C[A[y]]);
            int nx = x;
            rep(j,S) {
                nx = A[nx];
            }
            rep(j,S){
                B[x] = nx;
                x = C[x];
                nx = C[nx];
            }
            int ny = y;
            rep(j,S) {
                ny = A[ny];
            }
            rep(j,S){
                B[y] = ny;
                y = C[y];
                ny = C[ny];
            }
        }
        else{
            x--;
            while(y > S){
                x = B[x];
                y -= S;
            }
            while(y > 0){
                x =  A[x];
                y--;
            }
            cout << x + 1 << endl;
        }
    }
}