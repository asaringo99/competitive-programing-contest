#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[101010] , B[101010] , C[101010] ;
vector<ll> BB , CC ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n) cin >> C[i] ;
    sort(A,A+n) ;
    sort(B,B+n) ;
    sort(C,C+n) ;
    int index_a = 0 , index_b = 0 ;
    rep(i,n){
        if(A[index_a] < B[i]){
            index_a++ ;
            BB.push_back(B[i]) ;
        }
    }
    rep(i,n){
        if(BB.size() == index_b) break ;
        if(BB[index_b] < C[i]){
            index_b++ ;
            CC.push_back(C[i]) ;
        }
    }
    cout << CC.size() << endl ;
}