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

int n ;
string S ;

int main(){
    cin >> n >> S ;
    int p = 0 , x = 0 , y = 0 ;
    rep(i,n){
        if(S[i] == 'R') (p += 1) %= 4 ;
        else{
            if(p == 0) x++ ;
            if(p == 1) y-- ;
            if(p == 2) x-- ;
            if(p == 3) y++ ;
        }
    }
    cout << x << " " << y << endl ;
}