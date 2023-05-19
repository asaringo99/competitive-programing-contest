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
map<int,vector<int>> mp;
map<int,ll> dp;
int A[10];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        cin >> A[i];
        mp[A[i]].push_back(i);
        dp[A[i]] = 1;
    }
    for(auto &it : mp){
        sort(it.second.begin(),it.second.end(),greater<int>());
    }
    ll res = 0;
    rep(i,n){
        int a = A[i];
        ll val = dp[a];
        for(int j = a ; j < 1010101 ; j += a){
            
        }
    }
}