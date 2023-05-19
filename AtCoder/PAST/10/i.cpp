#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
map<int,vector<int>> X , Y , S , T ;
vector<P> A , B ;

int main(){
    cin >> n ;
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        X[x].push_back(y) ;
        Y[y].push_back(x) ;
        A.push_back(P(x,y)) ;
    }
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        S[x].push_back(y) ;
        T[y].push_back(x) ;
        B.push_back(P(x,y)) ;
    }
    sort(A.begin(),A.end()) ;
    sort(B.begin(),B.end()) ;
    if(A == B){
        cout << "Yes" << endl;
        return 0 ;
    }
    for(auto it : X){
        int i = it.first ;
        sort(X[i].begin(),X[i].end()) ;
    }
    for(auto it : Y){
        int i = it.first ;
        sort(Y[i].begin(),Y[i].end()) ;
    }
    for(auto it : S){
        int i = it.first ;
        sort(S[i].begin(),S[i].end(),greater<int>()) ;
    }
    for(auto it : T){
        int i = it.first ;
        sort(T[i].begin(),T[i].end(),greater<int>()) ;
    }
    bool ok = true ;
    set<int> st ;
    for(auto it : X){
        int i = it.first ;
        if(X[i].size() != S[i].size()){
            ok = false ;
            break ;
        }
        int m = X[i].size() ;
        rep(j,m){
            int k = X[i][j] + S[i][j] ;
            st.insert(k) ;
        }
        if(st.size() > 1){
            ok = false ;
            // break ;
        }
    }
    if(ok){
        cout << "Yes" << endl ;
        return 0 ;
    }
    st = {} ;
    ok = true ;
    for(auto it : Y){
        int i = it.first ;
        if(Y[i].size() != T[i].size()){
            ok = false ;
            break ;
        }
        int m = Y[i].size() ;
        rep(j,m){
            int k = Y[i][j] + T[i][j] ;
            st.insert(k) ;
        }
        if(st.size() > 1){
            ok = false ;
            // break ;
        }
    }
    if(ok){
        cout << "Yes" << endl ;
        return 0 ;
    }
    cout << "No" << endl ;
}