#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

map<char,int> mp ;

int main(){
    char a , b ;
    cin >> a >> b ;
    mp['N'] = 0 ;
    mp['E'] = 1 ;
    mp['S'] = 2 ;
    mp['W'] = 3 ;
    cout << (mp[b] - mp[a] + 4) % 4 << endl ; ;
}