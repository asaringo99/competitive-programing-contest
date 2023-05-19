#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int A[202020] ;
set<int> st ;

int main(){
    cin >> n >> m ;
    rep(i,n){
        ll a ;
        cin >> a ;
        st.insert(a) ;
    }
    cout << st.size() << " " ;
    if(st.size() == 1 && n == m) cout << 1 << endl ;
    else cout << 0 << endl ;
}