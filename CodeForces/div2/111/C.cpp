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
    ll n, k;
    cin >> n >> k;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    sort(all(A));
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && A[i] == A[j]){
            j++;
        }
        ll s = j - i;
        if(k - s * n > 0) k -= s * n;
        else{
            rep(x,n){
                k -= s;
                if(k <= 0){
                    cout << A[i] << " " << A[x] << endl;
                    return;
                }
            }
        }
        i = j;
    }
}

int main(){
    fast_io
    solve();
}