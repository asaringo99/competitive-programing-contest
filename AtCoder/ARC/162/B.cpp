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

void solve(){
    ll n;
    cin >> n;
    vector<int> P(n);
    rep(i,n) cin >> P[i], P[i]--;
    vector<pair<int,int>> res;
    int i = 0;
    while(i < n - 2){
        int k = -1;
        rep(j,n){
            if(P[j] == i) {
                k = j;
                break;
            }
        }
        // cout << k << endl;
        if(i == k){
            i++;
            // rep(i,n) cout << P[i] << " "; cout << endl;
            continue;
        }
        if(k == n - 1){
            vector<int> Q;
            rep(j,i) Q.push_back(P[j]);
            Q.push_back(P[n-2]);
            Q.push_back(P[n-1]);
            rrep(j,i,n-2) Q.push_back(P[j]);
            res.push_back({k,i});
            P = Q;
        }
        else{
            vector<int> Q;
            rep(j,i) Q.push_back(P[j]);
            Q.push_back(P[k]);
            Q.push_back(P[k+1]);
            rrep(j,i,n) {
                if(j == k) continue;
                if(j == k+1) continue;
                Q.push_back(P[j]);
            }
            res.push_back({k+1,i});
            P = Q;
            i++;
        }
    }
    if(P[n-1] != n - 1){
        cout << "No" << endl ;
        return;
    }
    cout << "Yes" << endl ;
    cout << res.size() << endl;
    for(auto[i,j] : res) cout << i << " " << j << endl;
}

int main(){
    fast_io
    solve();
}