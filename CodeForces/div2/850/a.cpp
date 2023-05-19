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
    int i = 1, d = 1;
    int aw = 1, ab = 0, bw = 0, bb = 0;
    bool b = true;
    while(i < n){
        int k = i + (++d) + (++d);
        if(k >= n) k = n;
        int t = k - i;
        if(b){
            bb += t % 2 != 0 ? t / 2 + 1 : t / 2;
            bw += t / 2;
        }
        else{
            aw += t % 2 != 0 ? t / 2 + 1 : t / 2;
            ab += t / 2;
        }
        b ^= 1;
        i = k;
    }
    cout << aw << " " << ab << " " << bw << " " << bb << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}