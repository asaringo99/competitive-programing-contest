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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> A(n,vector<ll>(m)), B(n,vector<ll>(m)), C(n,vector<ll>(m));
    rep(i,n){
        string s;
        cin >> s;
        rep(j,m) cin >> A[i][j] >> B[i][j] >> C[i][j];
    }
    ll res = 0;
    rep(i,n){
        rep(j,n){
            // if(i == j) continue;
            vector<pair<ll,ll>> X(m);
            rep(x,m){
                X[x] = {B[j][x] - A[i][x], C[i][x]};
            }
            sort(all(X),greater<pair<ll,ll>>());
            ll sum = 0;
            ll cnt = 0;
            rep(x,m){
                auto[val, c] = X[x];
                if(val <= 0) break;
                if(cnt + c >= k){
                    sum += (k - cnt) * val;
                    break;
                }
                cnt += c;
                sum += c * val;
            }
            chmax(res,sum);
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}