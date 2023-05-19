#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int q ;
vector<int> bm , up ;

int main(){
    cin >> q ;
    rep(i,q){
        int t , x ;
        cin >> t >> x ;
        if(t == 1) up.push_back(x) ;
        if(t == 2) bm.push_back(x) ;
        if(t == 3){
            int ans = x > up.size() ? bm[x - up.size() - 1] : up[up.size() - x] ;
            cout << ans << endl ;
        }
    }
}