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
    vector<pair<int,int>> S(n);
    int minval = 2e9;
    int k = -1;
    rep(i,n) {
        cin >> A[i];
        S[i] = {A[i],i};
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int xx = A[0];
    bool ok = true;
    rep(i,n) if(A[i] != xx) ok = false;
    if(ok){
        cout << 0 << endl;
        return;
    }
    int c = 0;
    rep(i,n) if(A[i] == 1) c++;
    if(c > 0){
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    vector<pair<int,int>> res;
    while(1){
        sort(all(S));
        if(S[0].first == S[n-1].first){
            break;
        }
        for(int i = n - 2; i >= 0; i--){
            auto [s, x] = S[i+1];
            auto [t, y] = S[i];
            while(t < s){
                s--;
                s /= t;
                s++;
                res.push_back({x+1,y+1});
                sum++;
            }
            S[i+1].first = s;
        }
        if(sum > 30*n){
            cout << -1 << endl;
            return;
        }
    }
    cout << res.size() << endl;
    for(auto[x,y] : res){
        cout << x << " " << y << endl;
    }
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}