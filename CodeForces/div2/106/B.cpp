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
    int n;
    string S;
    cin >> S;
    vector<int> T, U;
    bool c = false;
    for(char u : S){
        if(u == ':') {
            c = true;
            continue;
        }
        int num = u - '0';
        if(0 <= u - 'A' && u - 'A' < 26) num = (u - 'A') + 10;
        if(c) U.push_back(num);
        else T.push_back(num);
    }
    reverse(all(T));
    while(T.size() > 1){
        if(T[T.size()-1] == 0) T.pop_back();
        else break;
    }
    reverse(all(U));
    while(U.size() > 1){
        if(U[U.size()-1] == 0) U.pop_back();
        else break;
    }
    int mt = 0, mu = 0;
    rep(i,T.size()) chmax(mt,T[i]);
    rep(i,U.size()) chmax(mu,U[i]);
    reverse(all(T));
    reverse(all(U));
    mt++;
    mu++;
    int base = max(mt,mu);
    int m = 0, h = 0;
    rep(i,U.size()){
        m *= base;
        m += U[i];
    }
    rep(i,T.size()){
        h *= base;
        h += T[i];
    }
    if(h >= 24 || m >= 60){
        cout << 0 << endl;
        return;
    }

    if(T.size() == 1 && U.size() == 1){
        cout << -1 << endl;
        return;
    }
    rrep(b,base,101){
        h = 0;
        m = 0;
        rep(i,U.size()){
            m *= b;
            m += U[i];
        }
        rep(i,T.size()){
            h *= b;
            h += T[i];
        }
        if(h >= 24 || m >= 60) break;
        cout << b << " ";
    }
    cout << endl;
}

int main(){
    fast_io
    solve();
}