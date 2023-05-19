#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<char,char> P ;
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
string S ;
map<P,int> mp ;

int main(){
    cin >> n >> S ;
    int res = 0 ;
    char x , y ;
    rep(i,n-1){
        char a = S[i] , b = S[i+1] ;
        mp[P(a,b)]++ ;
        if(mp[P(a,b)] > res){
            x = a ;
            y = b ;
            res = mp[P(a,b)] ;
        }
    }
    cout << x << y << endl ;
}