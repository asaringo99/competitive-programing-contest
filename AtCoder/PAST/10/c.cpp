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
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;
string S ;

int main(){
    cin >> S ;
    n = S.size() ;
    int d = n / 3 ;
    int m = n % 3 ;
    if(m == 0){
        d -= 2 ;
        cout << S[0] << S[1] << S[2] << a_z[d] << endl ;
    }
    else{
        d -= 1 ;
        rep(i,m) cout << S[i] ;
        cout << a_z[d] << endl ;
    }
}