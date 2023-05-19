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

int n, q;
int A[202];

map<int,vector<int>> mp;

int main(){
    fast_io
    cin >> n;
    rep(i,n) cin >> A[i];
    int m = min(n,20);
    rrep(S,1,1<<m){
        int res = 0;
        vector<int> vec;
        rep(i,m) if(S >> i & 1){
            res += A[i];
            res %= 200;
            vec.push_back(i+1);
        }
        if(mp.count(res) > 0){
            cout << "Yes" << endl;
            cout << mp[res].size() << " ";
            for(int u : mp[res]) cout << u << " "; cout << endl;
            cout << vec.size() << " ";
            for(int u : vec) cout << u << " "; cout << endl;
            return 0;
        }
        mp[res] = vec;
    }
    cout << "No" << endl;
}