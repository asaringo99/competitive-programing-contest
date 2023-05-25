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

int A[505];

void solve(){
    int n, x;
    cin >> n >> x;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] == x) ok = true;
    }
    if(!ok){
        A[n++] = x;
    }
    sort(A,A+n);
    int k = -1;
    int res = 1e8;
    for(int i = 0; i < n; i++){
        if(A[i] != x) continue;
        k = i;
        if(k == (n - 1) / 2){
            chmin(res,0+!ok);
        }
        else if(k < (n - 1) / 2){
            for(int j = 1; j <= 2 * n; j++){
                if(k+j == (n+j-1)/2){
                    chmin(res,j+!ok);
                }
            }
        }
        else{
            for(int j = 1; j <= 2 * n; j++){
                if(k == (n+j-1)/2){
                    chmin(res,j+!ok);
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}