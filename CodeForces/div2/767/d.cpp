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
    cin >> n;
    map<string,bool> mp, sp;
    bool ok = false;
    rep(i,n){
        string s;
        cin >> s;
        if(s.size() == 1) ok = true;
        if(s.size() == 2){
            if(s[0] == s[1]) ok = true;
            string t = "";
            t += s[1]; t += s[0];
            if(mp[t]) ok = true;
            mp[s] = true;
            sp[s] = true;
        }
        if(s.size() == 3){
            if(s[0] == s[2]) ok = true;
            string t = "";
            t += s[2]; t += s[1];
            if(sp[t]) ok = true;
            t += s[0];
            if(mp[t]) ok = true;
            mp[s] = true;
            string k = ""; k+=s[0]; k+=s[1];
            mp[k] = true;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}