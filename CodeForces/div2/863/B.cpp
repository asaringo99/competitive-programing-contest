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
    string S;
    cin >> S;
    int s = S[0] - 'a';
    int k = -1;
    bool ok = false;
    rep(i,s+1){
        for(int j = S.size() - 1; j >= 1; j--){
            if(ok) break;;
            if(S[j] - 'a' == i){
                k = j;
                ok = true;
            }
        }
    }
    if(k == -1) cout << S << endl;
    else{
        cout << S[k];
        rep(i,n) if(i != k) cout << S[i]; cout << endl;
    }
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}