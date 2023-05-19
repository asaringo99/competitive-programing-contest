#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
bool prime[55556] ;
vector<int> vec ;

constexpr void ertstns(){
    prime[0] = prime[1] = true ;
    for(int i = 2 ; i <= 55555 ; i++){
        if(prime[i]) continue ;
        if(i % 10 == 1) vec.push_back(i) ;
        for(int j = 2 * i ; j <= 55555 ; j += i) prime[j] = true ;
    }
}

int main(){
    cin >> n ;
    ertstns() ;
    rep(i,n) cout << vec[i] << " " ;
    cout << endl ;
}