#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
map<string,bool> rem ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        string S ;
        cin >> S ;
        if(!rem[S]) cout << i + 1 << endl ;
        rem[S] = true ;
    }
}