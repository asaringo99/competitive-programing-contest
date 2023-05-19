#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;

int main(){
    cin >> H >> W ;
    if(H == 1 || W == 1) cout << H * W << endl ;
    else cout << ((H - 1) / 2 + 1) * ((W - 1) / 2 + 1) << endl ;
}