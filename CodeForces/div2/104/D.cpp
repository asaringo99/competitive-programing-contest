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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(c - d) > 1){
        cout << -1 << endl;
        return;
    }
    if(a < c || b < c){
        cout << -1 << endl;
        return;
    }
    if(a < d || b < d){
        cout << -1 << endl;
        return;
    }
    if(d == c){
        if(d + c >= a + b){
            cout << -1 << endl;
            return;
        }
        if(a > d){
            rep(i,a-d-1) cout << 4;
            rep(i,d) cout << 47;
            rep(i,b-d) cout << 7;
            cout << 4;
            cout << endl;
        }
        else{
            cout << 7;
            rep(i,d) cout << 47;
            rep(i,b-d-1) cout << 7;
            cout << endl;
        }
    }
    else if(d > c){
        cout << 7;
        rep(i,a-c-1) cout << 4;
        rep(i,c) cout << 47;
        rep(i,b-c-1) cout << 7;
        cout << 4;
        cout << endl;
    }
    else{
        rep(i,a-d) cout << 4;
        rep(i,d) cout << 74;
        rep(i,b-d) cout << 7;
        cout << endl;
    }
}

int main(){
    fast_io
    solve();
}