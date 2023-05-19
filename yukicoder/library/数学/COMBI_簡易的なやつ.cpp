#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

ll L ;

ll combination(ll a , ll b){
    map<int,bool> rem ;
    ll tmp = 1 ;
    int i = 0 ; 
    while(i < b){
        tmp *= (a - i) ;
        for(int j = 2 ; j <= b ; j++){
            if(rem[j]) continue ;
            if(tmp % j == 0){
                tmp /= j ;
                rem[j] = true ;
            }
        }
        i++ ;
    }
    return tmp ;
}