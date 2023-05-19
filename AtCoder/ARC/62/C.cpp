#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    ll Takahashi , Aoki ;
    cin >> Takahashi >> Aoki ;
    for(int i = 0 ; i < n - 1 ; i++){
        ll T , A ;
        cin >> T >> A ;
        ll t = Takahashi / T + 1 , a = Aoki / A + 1 ;
        if(Takahashi % T == 0) t-- ;
        if(Aoki % A == 0) a-- ;
        Takahashi = max(a,t) * T ;
        Aoki = max(a,t) * A ;
        // cout << Aoki << " " << Takahashi << endl ;
        // cout << t << " " << a << endl ;
    }
    cout << Takahashi + Aoki << endl ;
}