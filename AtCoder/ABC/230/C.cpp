#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , a , b , p , q , r , s ;
char C[3030][3030] ;

int main(){
    cin >> n >> a >> b >> p >> q >> r >> s ;
    ll k1 = max(1-a,1-b) , k2 = min(n-a,n-b) ;
    ll l1 = max(1-a,b-n) , l2 = min(n-a,b-1) ;
    for(ll i = p ; i <= q ; i++){
        for(ll j = r ; j <= s ; j++){
            if(a + k1 <= i && i <= a + k2 && b + k1 <= j && j <= b + k2 && i - a == j - b) cout << '#' ;
            else if(a + l1 <= i && i <= a + l2 && b - l2 <= j && j <= b - l1 && i - a == b - j) cout << '#' ;
            else cout << '.' ;
        }
        cout << endl ;
    }
}