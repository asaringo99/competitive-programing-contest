#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S , T ;
int SA[101010] , SB[101010] ;
int TA[101010] , TB[101010] ;
int q ;

int main(){
    cin >> S >> T >> q ;

    int s = S.size() , t = T.size() ;
    rep(i,s){
        SA[i+1] = SA[i] ;
        SB[i+1] = SB[i] ;
        if(S[i] == 'A') SA[i+1]++ ;
        if(S[i] == 'B') SB[i+1]++ ;
    }
    rep(i,t){
        TA[i+1] = TA[i] ;
        TB[i+1] = TB[i] ;
        if(T[i] == 'A') TA[i+1]++ ;
        if(T[i] == 'B') TB[i+1]++ ;
    }

    rep(i,q){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        int sa = SA[b] - SA[a-1] + (SB[b] - SB[a-1]) * 2 ;
        int ta = TA[d] - TA[c-1] + (TB[d] - TB[c-1]) * 2 ;
        if(sa % 3 == ta % 3) cout << "YES" << endl ;
        else cout << "NO" << endl ;
    }
}