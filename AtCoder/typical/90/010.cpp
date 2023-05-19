#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , q ;
ll S[100007] , T[100007] ;

int main(){
    cin >> n ;
    memset(S,0,sizeof(S)) ;
    memset(T,0,sizeof(T)) ;
    for(int i = 1 ; i <= n ; i++){
        int c , p ;
        cin >> c >> p ;
        S[i] = S[i-1] ;
        T[i] = T[i-1] ;
        if(c == 1){
            S[i] += p ;
        }
        else{
            T[i] += p ;
        }
    }
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        int l , r ;
        cin >> l >> r ;
        cout << S[r] - S[l-1] << " " << T[r] - T[l-1] << endl ;
    }
}