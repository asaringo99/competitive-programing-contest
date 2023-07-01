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
    string S, T;
    cin >> S >> T;
    int n = S.size();
    int m = T.size();
    int g = gcd(n,m);
    vector<int> V;
    for(int x = 1; x * x <= g; x++){
        if(g % x !=0) continue;
        V.push_back(x);
        if(x*x!=g)V.push_back(g/x);
    }
    sort(all(V));
    int i = 0;
    int res = 0;
    for(int v : V){
        string s = "";
        string t = "";
        rep(i,v){
            s += S[i];
            t += T[i];
        }
        bool ok = true;
        if(s != t) ok = false;
        rep(i,n) if(S[i] != s[i%v]) ok = false;
        rep(i,m) if(T[i] != t[i%v]) ok = false;
        if(ok) res++;
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}