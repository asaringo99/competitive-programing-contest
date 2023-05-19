#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;
int N , K ;
int L[2020] , R[2020] ;
bool used[2020] ;

int main(){
    cin >> N >> K ;
    rep(i,K){
        char c ; 
        int k ;
        cin >> c >> k ;
        if(c == 'L'){
            L[k-1] = i + 1 ;
            used[k-1] = true ;
        }
        if(c == 'R'){
            R[k-1] = i + 1 ;
            used[k-1] = true ;
        }
    }
    ll res = 1 ;
    rep(i,N){
        if(used[i]) continue ;
        set<int> st ;
        rep(j,N){
            if(i < j && L[j] != 0) st.insert(L[j]) ; 
        }
        rep(j,N){
            if(i > j && R[j] != 0) st.insert(R[j]) ;
        }
        ll tmp = K - st.size() ;
        (res *= tmp) %= mod ;
    }
    cout << res << endl ;
}