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

vector<vector<ll>> A;

ll calc(vector<int> &X){
    ll sum = 0;
    int n = X.size();
    rep(i,n){
        rrep(j,i+1,n){
            int v = X[i];
            int u = X[j];
            sum += A[v][u];
        }
    }
    return sum;
}

int n;

int main(){
    fast_io
    cin >> n;
    A = vector<vector<ll>>(n,vector<ll>(n));
    rep(i,n){
        rrep(j,i+1,n) cin >> A[i][j];
    }
    rep(i,n){
        rrep(j,i+1,n) A[j][i] = A[i][j];
    }
    ll res = -1e18;
    rep(S,1<<n){
        vector<int> Z, vec;
        rep(i,n) {
            if(S >> i & 1) vec.push_back(i);
            else Z.push_back(i);
        }
        int m = (int)vec.size();
        rep(T,1<<m){
            vector<int> X, Y;
            rep(j,m) {
                if(T >> j & 1) X.push_back(vec[j]);
                else Y.push_back(vec[j]);
            }
            ll sum = calc(X)+calc(Y)+calc(Z);
            chmax(res,sum);
        }
    }
    cout << res << endl;
}