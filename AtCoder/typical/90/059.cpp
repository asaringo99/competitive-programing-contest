#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 100000 ;

ll n , k ;
int doubring[65][100005] ;

int calculation(){
    int cnt = 0 , res = n ;
    while(k > 0){
        if(k & 1) res = doubring[cnt][res] ;
        for(int i = 0 ; i < 100000 ; i++){
            doubring[cnt+1][i] = doubring[cnt][doubring[cnt][i]] ;
        }
        k >>= 1 ;
        cnt++ ;
    }
    return res ;
}

int main(){
    cin >> n >> k ;
    rep(i,100000){
        string s = to_string(i) ;
        int digit = 0 ;
        for(char u : s) digit += (u - '0') ;
        doubring[0][i] = (digit + i) % mod ;
    }
    cout << calculation() << endl ;
}