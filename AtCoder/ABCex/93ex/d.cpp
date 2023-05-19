#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int q ;

int main(){
    cin >> q ;
    rep(i,q){
        ll a , b ;
        cin >> a >> b ;
        if(a == b) cout << (a - 1) * 2 << endl ;
        else if((ll)sqrt(a*b) * (ll)sqrt(a*b) == a*b) cout << (ll)sqrt(a*b) * 2 - 3 << endl ;
        else if((ll)sqrt(a*b) * ((ll)sqrt(a*b) + 1) < a*b) cout << (ll)sqrt(a*b) * 2 - 1 << endl ;
        else cout << (ll)sqrt(a*b) * 2 - 2 << endl ;
    }
}