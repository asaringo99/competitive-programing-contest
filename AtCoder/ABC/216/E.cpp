#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll k ;
ll A[101010] ;

ll calculation(ll a , ll b){
    return b * (b + 1) / 2 - a * (a + 1) / 2 ;
}

int main(){
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    A[n] = 0 ;
    ll res = 0 , cnt = 1 ;
    sort(A,A+n,greater<ll>()) ;
    for(int i = 0 ; i < n ; i++){
        if((A[i] - A[i+1]) * cnt > k){
            ll tmp = k / cnt , mod = k % cnt ;
            res += calculation(A[i]-tmp,A[i]) * cnt ;
            res += (A[i] - tmp) * mod ;
            break ;
        }
        else{
            res += calculation(A[i+1],A[i]) * cnt ;
            k -= cnt * (A[i] - A[i+1]) ;
            cnt++ ;
            if(k == 0) break ;
        }
    }
    cout << res << endl; 
}