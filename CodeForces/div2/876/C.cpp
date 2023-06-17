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
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    if(A[n-1] == 1){
        cout << "NO" << endl ;
        return;
    }
    vector<int> O, E;
    rep(i,n){
        if(A[i] == 1) O.push_back(i);
        else E.push_back(i);
    }
    cout << "YES" << endl ;
    int que = 0;
    bool ok = false;
    for(int i = n - 1; i >= 0; i--){
        if(A[i] == 1){
            que++;
        }
        if(A[i] == 0){
            if(ok) {
                cout << que << " ";
                ok = false;
            }
            que = 0;
            if(i > 0 && A[i-1] == 1){
                ok = true;
                continue;
            }
        }
        cout << 0 << " ";
    }
    if(ok) cout << que;
    cout << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}