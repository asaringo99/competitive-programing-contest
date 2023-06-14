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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

const ll TO[] = {1,10,100,1000,10000};

void f(){

}

void solve(){
    ll n;
    string S;
    cin >> S;
    n = S.size();
    ll sum = 0;
    int maxv = -1;
    vector<bool> mns(n,true);
    for(int i = n - 1; i >= 0; i--){
        char c = S[i];
        int id = c - 'A';
        int val = TO[id];
        if(val >= maxv){
            maxv = val;
            sum += val;
            mns[i] = false;
        }
        else sum -= val;
    }
    vector<vector<int>> U(5);
    vector<int> X(5,0);
    vector<vector<int>> Y(n,vector<int>(5,0));
    vector<vector<int>> Z(n,vector<int>(5,0));
    for(int i = n - 1; i >= 0; i--){
        char c = S[i];
        int id = c - 'A';
        X[id]++;
        U[id].push_back(i);
        ll vl = TO[id];
        int cnt = 0;
        rrep(j,id+1,5) cnt += X[j];
        if(cnt == 0) {
            rrep(j,id+1,5) Z[i][j] = vl;
        }
        if(cnt == 1) {
            int v = -1;
            rrep(j,id+1,5) if(X[j] == 1) v = U[j][0];
            rep(j,id+1) Y[v][j] += vl;
        }
    }
    vector<vector<int>> J(n+1,vector<int>(5,0));
    rep(i,n){
        rep(j,5){
            J[i+1][j] = J[i][j] + Z[i][j];
        }
    }
    ll res = -1e14;
    vector<int> Q(5,0);
    rep(i,n){
        char c = S[i];
        int id = c - 'A';
        Q[id]++;
        ll vl = TO[id];
        rep(x,5){
            ll minusval = -J[i][x] * 2;
            ll plusval = Y[i][x] * 2;
            ll add = TO[x];
            ll h = mns[i] ? vl : -vl;
            chmax(res,sum+h+plusval+minusval+add);
            // cout << i << " " << x << " " << minusval << " " << plusval << " " << add << " " << h << " " << sum << " " << res << endl;
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}