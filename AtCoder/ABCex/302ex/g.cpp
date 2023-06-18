#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define ptv(v) for(auto u : v) cout << u << " "; cout << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    vector<int> A(n), X(n);
    vector<int> B(4,0);
    vector<vector<int>> C(4,vector<int>(4,0));
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n) B[A[i]]++;
    for(int i = 0; i < n;){
        rep(x,4){
            rep(j,B[x]){
                X[i] = x;
                i++;
            }
        }
    }
    rep(i,n){
        C[X[i]][A[i]]++;
    }
    int res = 0;
    // 2交換
    rep(i,4){
        rrep(j,i+1,4){
            int &x = C[i][j];
            int &y = C[j][i];
            int z = min(x,y);
            x -= z;
            y -= z;
            res += z;
        }
    }
    // 3交換
    rep(i,4){
        rep(j,4){
            rep(k,4){
                if(i == j || j == k || k == i) continue;
                int &x = C[i][j];
                int &y = C[j][k];
                int &z = C[k][i];
                int w = min({x,y,z});
                x -= w;
                y -= w;
                z -= w;
                res += 2 * w;
            }
        }
    }
    // 4交換
    rep(i,4){
        rep(j,4){
            rep(k,4){
                rep(l,4){
                    if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
                    int &x = C[i][j];
                    int &y = C[j][k];
                    int &z = C[k][l];
                    int &w = C[l][i];
                    int s = min({x,y,z,w});
                    x -= s;
                    y -= s;
                    z -= s;
                    w -= s;
                    res += 3 * s;
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}