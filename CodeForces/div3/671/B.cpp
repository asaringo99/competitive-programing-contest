#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    rep(i,n){
        ll t ;
        cin >> t ;
        ll sum = 1 , pro = 1 , res = 0 , count = 0 ;
        while(res <= t){
            res += sum ;
            pro *= 2 ;
            sum *= 2 ;
            sum += pro * pro ;
            count++ ;
        }
        cout << count - 1 << endl ;
    }
}