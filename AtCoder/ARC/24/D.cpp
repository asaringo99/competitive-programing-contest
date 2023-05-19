#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m , k ;
string S ;
map<vector<int>,int> mp ;

int main(){
    cin >> n >> m >> S ;
    k = m ;
    vector<int> alf(26,0) ;
    int lef = 0 , rig = 0 ;
    bool ok = false ;
    while(rig < n){
        while(rig < n && k > 0){
            k-- ;
            alf[S[rig] - 'a']++ ;
            rig++ ;
        }
        if(mp[alf] != 0){
            if(mp[alf] + m <= lef + 1) ok = true ;
        }
        else mp[alf] = lef + 1 ;
        k++ ;
        alf[S[lef] - 'a']-- ;
        lef++ ;
    }
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}