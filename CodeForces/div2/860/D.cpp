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
    bool ok = false;
    rep(i,n) if(A[i] != 0) ok = true;
    if(!ok){
        cout << "No" << endl ;
        return;
    }
    sort(all(A));
    vector<ll> ps, ng;
    rep(i,n) {
        if(A[i] >= 0) ps.push_back(A[i]);
        else ng.push_back(A[i]);
    }
    ll sum = 0;
    sort(all(ps));
    sort(all(ng));
    vector<ll> res;
    while(1){
        if(ps.empty() && ng.empty()) break;
        if(sum >= 0 && !ng.empty()){
            sum += ng.back();
            res.push_back(ng.back());
            ng.pop_back();
        }
        else{
            sum += ps.back();
            res.push_back(ps.back());
            ps.pop_back();
        }
    }
    cout << "Yes" << endl ;
    for(ll u : res) cout << u << " "; cout << endl;
}

int main(){
    // fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}