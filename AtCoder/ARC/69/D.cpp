#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    char S[n] ;
    for(int i = 0 ; i < n ; i++) cin >> S[i] ;
    for(int p = 0 ; p < 4 ; p++){
        bool animal[n] ;
        for(int q = 0 ; q < 2 ; q++){
            if(p >> q & 1) animal[q] = true ;
            else animal[q] = false ;
        }
        bool ok1 = animal[0] ;
        bool ok2 = animal[1] ;
        for(int i = 1 ; i < n + 1 ; i++){
            if(S[i%n] == 'o'){
                animal[(i+1)%n] = animal[i%n] ? animal[i-1] : !animal[i-1] ;
            }
            else{
                animal[(i+1)%n] = animal[i%n] ? !animal[i-1] : animal[i-1] ;
            }
        }
        if(ok1 == animal[0] && ok2 == animal[1]){
            for(int i = 0 ; i < n ; i++){
                if(animal[i]) cout << "S" ;
                else cout << "W" ;
            }
            cout << endl ;
            return 0 ;
        }
    }
    cout << -1 << endl ;
}