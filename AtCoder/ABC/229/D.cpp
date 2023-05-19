#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
string S ;

int main(){
    cin >> S >> k ;
    n = S.size() ;
    ll lef = 0 , rig = 0 ;
    ll cnt = 0 , sum = 0 , ans = 0 ;
    while(rig < n){
        while(rig < n && cnt < k){
            if(S[rig] == '.') cnt++ ;
            sum++ ;
            rig++ ;
        }
        while(rig < n && S[rig] == 'X'){
            sum++ ;
            rig++ ;
        }
        ans = max(ans,sum) ;
        while(lef < n && cnt == k){
            if(S[lef] == '.') cnt-- ;
            sum-- ;
            lef++ ;
        }
    }
    cout << ans << endl ;

}