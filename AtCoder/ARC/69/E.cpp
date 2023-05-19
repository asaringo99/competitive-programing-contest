#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
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
    ll A[n] ;
    P AB[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        AB[i] = P(A[i],i) ;
    }
    vector<int> order ;
    int hig = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(hig < A[i]){
            hig = A[i] ;
            order.push_back(i) ;
        }
    }
    sort(AB,AB+n) ;
    sort(order.begin(),order.end()) ;
    int m = order.size() ;
    ll w = 0 ;
    int j = 0 ;
    ll res[n] ;
    memset(res,0,sizeof(res)) ;
    for(int i = 0 ; i < m ; i++){
        while(j < n && AB[j].second != order[i]){
            res[order[i]] += (AB[j].first - w) ;
            j++ ;
        }
        res[order[i]] += (n - j) * (AB[j].first - w) ;
        w = AB[j].first ;
        while(j < n && AB[j].first == AB[j+1].first) j++ ;
        j++ ;
    }
    for(int i = 0 ; i < n ; i++) cout << res[i] << endl ;
}