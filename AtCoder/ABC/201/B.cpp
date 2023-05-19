#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,string> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    P st[n] ;
    for(int i = 0 ; i < n ; i++){
        string S ;
        int t ;
        cin >> S >> t ;
        st[i] = P(t,S) ;
    }
    sort(st,st+n) ;
    cout << st[n - 2].second << endl ;
}