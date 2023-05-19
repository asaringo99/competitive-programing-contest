#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
int k ;

int main(){
    cin >> S >> k ;
    sort(S.begin(),S.end()) ;
    do
    {
        k-- ;
        if(k == 0){
            cout << S << endl ;
            return 0 ;
        }
    } while (next_permutation(S.begin(),S.end()));
    
}