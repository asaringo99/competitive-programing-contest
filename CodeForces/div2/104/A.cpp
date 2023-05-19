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
    string S;
    int n;
    cin >> n >> S;
    ll sum = 0;
    rep(i,n/2) sum += S[i] - '0';
    rrep(i,n/2,n) sum -= S[i] - '0';
    rep(i,n) if(S[i] != '4' && S[i] != '7'){
        cout << "NO" << endl;
        return;
    }
    if(sum != 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    fast_io
    solve();
}