#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;
string T ;

int main(){
    cin >> n >> T ;
    if(T == "1"){
        ll ans = 2e10 ;
        cout << ans << endl ;
        return 0 ;
    }
    ll S = 1e10 ;
    ll cnt = 0 ;
    for(char u : T) if(u == '0') cnt++ ;
    S = S - cnt ;
    if(T[n-1] == '0') S = S + 1 ;
    if(T[0] == '1' && T[1] == '0'){
        string t = "1" ;
        T = t + T ;
    }
    else if(T[0] == '0'){
        string t = "11" ;
        T = t + T ;
    }
    if(T[T.size() - 2] == '1' && T[T.size() - 1] == '1'){
        string t = "0" ;
        T = T + t ;
    }
    else if(T[T.size() - 1] == '1'){
        string t = "10" ;
        T = T + t ;
    }
    bool ok = true ;
    for(int i = 0 ; i < T.size() ; i++){
        if(i % 3 == 0 && T[i] == '1') continue ;
        if(i % 3 == 1 && T[i] == '1') continue ;
        if(i % 3 == 2 && T[i] == '0') continue ;
        ok = false ;
    }
    if(!ok){
        cout << T << endl ;
        cout << 0 << endl ;
        return 0 ;
    }
    cout << S << endl ;
    cout << T << endl ;
}
