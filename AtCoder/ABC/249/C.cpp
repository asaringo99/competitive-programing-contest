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

int n , k ;
set<char> st[20] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n){
        string S ;
        cin >> S ;
        for(char u : S) st[i].insert(u) ;
    }
    int res = 0 ;
    rep(S,1<<n){
        int sum = 0 ;
        if(bit_count(S) < k) continue ;
        map<char,int> mp ;
        rep(i,n) if(S >> i & 1){
            for(char u : st[i]) mp[u]++ ;
        }
        for(auto it : mp) if(it.second == k) sum++ ;
        chmax(res,sum) ;
    }
    cout << res << endl ;
}