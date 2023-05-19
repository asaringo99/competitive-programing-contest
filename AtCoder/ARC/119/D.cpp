#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
string S , T ;

int main(){
    cin >> n >> S >> T ;
    int cnts = 0 ;
    int cntt = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(S[0] == '0') cnts++ ;
        if(T[0] == '0') cntt++ ;
    }
    if(cnts != cntt){
        cout << -1 << endl ;
        return 0 ;
    }
    set<int> one , zer ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] - '0' == 1) one.insert(i) ;
        else zer.insert(i) ;
    }
    int count = 0 ;
    int i = 0 ;
    while(i < n){
        cout << i << endl ;
        if(S[i] == T[i]){
            i++ ;
            continue ;
        }
        if(T[i] == '1'){
            auto it = one.lower_bound(i) ;
            int j = *it ;
            int fir = j ;
            while(i < n && T[i] == '1' && *it - fir <= 1 && it != one.end()){
                S[i] = '1' ;
                S[*it] = '0' ;
                i++ ;
                fir = *it ;
                zer.insert(*it) ;
                it++ ;
            }
        }
        else{
            auto it = zer.lower_bound(i) ;
            int j = *it ;
            int fir = j ;
            while(i < n && T[i] == '0' && *it - fir <= 1 && it != zer.end()){
                S[i] = '0' ;
                S[*it] = '1' ;
                i++ ;
                fir = *it ;
                one.insert(*it) ;
                it++ ;
            }
        }
        count++ ;
    }
    cout << count << endl ;
}