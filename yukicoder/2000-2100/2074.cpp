#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

int n ;

void solve(){
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    rep(i,n){
        rrep(j,i+1,n){
            ll g = gcd(A[i],A[j]);
            A[i] /= g;
            A[j] /= g;
        }
    }
    rep(i,n){
        ll s = sqrt(A[i]);
        if(s * s != A[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){
    fast_input_output
    int t;
    cin >> t;
    rep(i,t) solve();
}