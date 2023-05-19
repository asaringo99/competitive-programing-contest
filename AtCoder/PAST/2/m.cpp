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

int n, L, D;
ll K[101010], F[101010], T[101010];
vector<int> C[101010], S[101010];

int main(){
    fast_io
    cin >> D >> L >> n;
    rep(i,101010){
        int c;
        cin >> c;
        C[c].push_back(i);
        C[c].push_back(i + D);
    }
    rep(i,101010){
        sort(all(C[i]));
    }
    rep(i,101010){
        S[i].push_back(0);
        rep(j,C[i].size()) S[j].push_back(S[j].back()+C[i][j]) ;
    }
    rep(i,n) cin >> K[i] >> F[i] >> T[i];
    
}