#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;

ll K[5050][5050] , S[5050] , T[5050] ;
ll P[5050] , C[5050] ;


int main(){
    cin >> n >> k ;
    rep(i,n) {
        cin >> P[i] ;
        P[i]-- ;
    }
    rep(i,n) cin >> C[i] ;
    ll res = -1e17 ;
    rep(i,n){
        if(k <= n){
            ll sum = 0 , count = 0 , v = i ;
            while(count < k){
                v = P[v] ;
                sum += C[v] ;
                res = max(res,sum) ;
                count++ ;
            }
            continue ;
        }
        bool used[5050] ;
        memset(used,0,sizeof(used)) ;
        ll sum = 0 , count = 0 ;
        int v = i ;
        while(!used[v]){
            used[v] = true ;
            v = P[v] ;
            sum += C[v] ;
            res = max(res,sum) ;
            count++ ;
        }
        if(sum <= 0) continue ;
        ll tmp = k / count - 1 , mod = k % count + count ;
        sum *= tmp ;
        res = max(res,sum) ;
        while(mod > 0){
            v = P[v] ;
            sum += C[v] ;
            res = max(res,sum) ;
            mod-- ;
        }
    }
    cout << res << endl ;
}