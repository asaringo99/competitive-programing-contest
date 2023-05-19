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
    vector<pair<int,int>> X(n);
    rep(i,n){
        int a;
        cin >> a;
        X[i] = {a,i};
    }
    sort(all(X),greater<pair<int,int>>());
    vector<int> A, B;
    int a = 0, b = 0;
    int i = 0;
    while(i < n){
        auto[x,idx] = X[i++];
        if(i == n){
            if(a < b) A.push_back(idx);
            else B.push_back(idx);
            break;
        }
        auto[y,idy] = X[i++];
        if(a > b){
            swap(x,y);
            swap(idx,idy);
        }
        a += x;
        b += y;
        A.push_back(idx);
        B.push_back(idy);
    }
    cout << A.size() << endl;
    for(int u: A) cout << u + 1 << " "; cout << endl;
    swap(A,B);
    cout << A.size() << endl;
    for(int u: A) cout << u + 1 << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}