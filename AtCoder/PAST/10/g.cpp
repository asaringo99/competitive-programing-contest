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

ld a , b , c ;

ld f(ld x){
    return a * x * x * x * x * x + b * x + c ;
}

int main(){
    cin >> a >> b >> c ;
    ld lef = 1 , rig = 2 ;
    int count = 0 ;
    while(count < 100){
        ld ml = (lef * 2 + rig) / 3 , mr = (lef + 2 * rig) / 3 ;
        if(abs(f(ml)) < abs(f(mr))) rig = mr ;
        else lef = ml ;
        count++ ;
    }
    cout << fixed << setprecision(25) << rig << endl ;
}