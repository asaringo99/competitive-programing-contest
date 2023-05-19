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

int n;

int main(){
    fast_io
    cin >> n;
    vector<ld> X, Y;
    rep(i,n) {
        int a;
        cin >> a;
        if(a < 0) X.push_back(a);
        else Y.push_back(a);
    }
    sort(all(X));
    sort(all(Y), greater<ld>());
    vector<ld> V;
    rep(i,min(200,(int)X.size())){
        V.push_back(X[i]);
    }
    rep(i,min(200,(int)Y.size())){
        V.push_back(Y[i]);
    }
    if(X.size() > 400){
        sort(all(X),greater<ld>());
        rep(i,min(200,(int)X.size())){
            V.push_back(X[i]);
        }
    }
    if(Y.size() > 400){
        sort(all(Y));
        rep(i,min(200,(int)Y.size())){
            V.push_back(Y[i]);
        }
    }
    ld maxval = -3e18;
    ld minval = 3e18;
    int m = V.size();
    rep(i,m) rrep(j,i+1,m) rrep(k,j+1,m){
        ld sum = V[i] + V[j] + V[k];
        ld pro = V[i] * V[j] * V[k];
        chmax(maxval,sum/pro);
        chmin(minval,sum/pro);
    }
    cout << fixed << setprecision(25) << minval << endl;
    cout << fixed << setprecision(25) << maxval << endl;
}