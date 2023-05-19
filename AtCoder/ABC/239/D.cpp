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

int a , b , c , d ;
bool prime[101010] ;

void f(){
    prime[0] = prime[1] = true ;
    for(int i = 0 ; i < 100000 ; i++){
        if(!prime[i]){
            for(int j = 2 * i ; j < 100000 ; j += i) prime[j] = true ;
        }
    }
}

int main(){
    cin >> a >> b >> c >> d ;
    f() ;
    bool win = false ;
    rrep(i,a,b+1){
        bool ok = true ;
        rrep(j,c,d+1){
            if(!prime[i + j]) ok = false ;
        }
        if(ok) win = true ;
    }
    if(win) cout << "Takahashi" << endl ;
    else cout << "Aoki" << endl ;
}