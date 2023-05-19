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

int n, q, m;
char C[3030][3030];
int X[6060][10101];
int Y[6060][10101];

int main(){
    fast_input_output
    cin >> n >> m;
    rrep(i,1,n+1) rrep(j,1,n+1) cin >> C[i][j];
    rrep(i,1,n+1){
        rrep(j,1,n+1){
            if(C[i][j] == 'O'){
                X[i][j]++;
                Y[i][j+2*m]--;
                Y[i+m][j]++;
                X[i+m][j]--;
            }
        }
    }
    rrep(i,1,3*n+1){
        rrep(j,1,5*n+1){
            Y[i][j] += Y[i-1][j+2];
        }
    }
    rrep(i,1,3*n+1){
        rrep(j,1,5*n+1){
            X[i][j] += X[i-1][j];
        }
    }
    rrep(i,1,3*n+1){
        rrep(j,1,5*n+1){
            X[i][j] += Y[i][j];
        }
    }
    rrep(i,1,3*n+1){
        rrep(j,1,5*n+1){
            X[i][j] += X[i][j-1];
        }
    }
    // rrep(i,1,n+1){
    //     rrep(j,1,n+1) cout << X[i][j] << " "; cout << endl;
    // }
    cin >> q;
    rep(i,q){
        int x, y;
        cin >> x >> y;
        cout << X[x][y] << endl;
    }
}