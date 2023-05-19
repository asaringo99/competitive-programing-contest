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
    vector<int> A(12);
    int sum = 0;
    rep(i,12) cin >> A[i], sum += A[i];
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    if(n > sum){
        cout << -1 << endl;
        return;
    }
    sort(all(A),greater<int>());
    sum = 0;
    rep(i,12){
        sum += A[i];
        if(sum >= n){
            cout << i + 1 << endl;
            return;
        }
    }
}

int main(){
    fast_io
    solve();
}