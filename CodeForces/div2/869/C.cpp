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
    int n, q;
    cin >> n >> q;
    vector<ll> A(n), S(n+1);
    rep(i,n) cin >> A[i];
    int b = 0;
    bool down = false;
    rep(i,n){
        S[i+1] = S[i];
        if(A[i] > b){
            S[i+1]++;
            down = false;
        }
        else{
            if(!down) S[i+1]++;
            down = true;
        }
        b = A[i];
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        if(r - l <= 1){
            cout << r - l + 1 << endl;
        }
        else cout << 2 + S[r] - S[l+1] << endl;
    }
}

int main(){
    fast_io
    solve();
}