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
    ld vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    ld pos = t * vp;
    int res = 0;
    while(pos < c){
        ld lef = 0, rig = 1e8;
        int cnt = 0;
        while(cnt < 1010){
            ld mid = (lef + rig) / 2;
            if(pos + mid * vp < vd * mid) rig = mid;
            else lef = mid;
            cnt++;
        }
        pos += lef * vp;
        if(pos >= c) break;
        pos += lef * vp;
        pos += f * vp;
        res++;
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}