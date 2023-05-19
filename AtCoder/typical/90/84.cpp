#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string S ;

int main(){
    cin >> n >> S ;
    int lef = 0 , rig = 0 ,  white = 0 , black = 0 ;
    ll res = 0 , cnt = 0 ;
    while(rig < n){
        while(rig < n && (white == 0 || black == 0)){
            if(S[rig] == 'x') white++ ;
            if(S[rig] == 'o') black++ ;
            rig++ ;
        }
        while(black > 0 && white > 0){
            res += (n - rig + 1) ;
            if(S[lef] == 'x') white-- ;
            if(S[lef] == 'o') black-- ;
            lef++ ;
        }
    }
    cout << res << endl ;
}