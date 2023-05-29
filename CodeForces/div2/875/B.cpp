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
    vector<int> B(n);
    vector<int> X(n*2,0);
    vector<int> Y(n*2,0);
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n) cin >> B[i], B[i]--;
    int cnt = 1;
    rrep(i,1,n){
        if(A[i-1] == A[i]){
            cnt++;
        }
        else{
            chmax(X[A[i-1]],cnt);
            cnt = 1;
        }
    }
    chmax(X[A[n-1]],cnt);
    cnt = 1;
    rrep(i,1,n){
        if(B[i-1] == B[i]){
            cnt++;
        }
        else{
            chmax(Y[B[i-1]],cnt);
            cnt = 1;
        }
    }
    chmax(Y[B[n-1]],cnt);
    int res = 0;
    rep(i,2*n) chmax(res,X[i]+Y[i]);
    cout << res << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}