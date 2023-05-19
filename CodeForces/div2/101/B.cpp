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
    ll a, x, y;
    cin >> a >> x >> y;
    bool l = false;
    if(x < 0) l = true;
    x = abs(x);
    if(y % a == 0){
        cout << -1 << endl;
        return;
    }
    y /= a;
    if(y < 2){
        y++;
        if(a <= abs(x * 2)){
            cout << -1 << endl;
            return;
        }
        cout << y << endl;
        return;
    }
    y -= 2;
    if(y % 2 == 0){
        if(x == 0){
            cout << -1 << endl;
            return;
        }
        if(a <= abs(x)){
            cout << -1 << endl;
            return;
        }
        y /= 2;
        y++;
        if(l) cout << 3 * y << endl;
        else cout << 3 * y + 1 << endl;
    }
    else{
        if(a <= abs(x * 2)){
            cout << -1 << endl;
            return;
        }
        y /= 2;
        y++;
        cout << y * 3 + 2 << endl;
    }
}

int main(){
    fast_io
    solve();
}