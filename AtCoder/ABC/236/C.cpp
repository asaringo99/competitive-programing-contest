#include <bits/stdc++.h>
using namespace std ;
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

int n , m ;
map<string,bool> mp ;
string S[101010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> S[i] ;
    rep(i,m){
        string T ;
        cin >> T ;
        mp[T] = true ;
    }
    rep(i,n){
        if(mp[S[i]]) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}