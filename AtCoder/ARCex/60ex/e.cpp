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

int n , L , q ;

ll X[101010] , U[101010][60] ;

void doubling(){
    rrep(k,1,60){
        rep(i,n){
            U[i][k+1] = U[U[i][k]][k] ;
        }
    }
}

bool f(int x , int n , int y){
    int c = 1 ;
    while(n > 0){
        if(n & 1) x = U[x][c] ;
        n >>= 1 ;
        c++ ;
    }
    return x >= y ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i] ;
    cin >> L >> q ;
    rep(i,n){
        auto it = upper_bound(X,X+n,X[i]+L) ; it-- ;
        int id = it - X ;
        U[i][1] = id ;
    }
    doubling() ;
    rep(i,q){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        if(a > b) swap(a,b) ;
        int lef = 0 , rig = n ; 
        while(rig - lef > 1){
            int mid = (lef + rig) / 2 ;
            if(f(a,mid,b)) rig = mid ;
            else lef = mid ;
        }
        cout << rig << endl ;
    }
}