#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z){
        int n, m;
        cin >> n >> m;
        rep(i,n){
            rep(j,m){
                if(i % 2 == 1) {
                    if(j < m - 1) cout << i * m + j + 1 << " ";
                    else cout << i * m + j + 1 << endl;
                }
            }
        }
        rep(i,n){
            rep(j,m){
                if(i % 2 == 0) {
                    if(j < m - 1) cout << i * m + j + 1 << " ";
                    else cout << i * m + j + 1 << endl;
                }
            }
        }
    }
}