#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[101010] , S[101010] ;
int G[101010][3] ;
P query[101010] ;

int main(){
    cin >> n ;
    rep(i,n){
        int r , h ;
        cin >> r >> h ;
        r-- ; h-- ;
        A[r]++ ;
        G[r][h]++ ;
        query[i] = P(r,h) ;
    }
    rep(i,100010) S[i+1] = S[i] + A[i] ;
    rep(i,n){
        int r = query[i].first , h = query[i].second ;
        cout << S[r] + G[r][(h+1)%3] << " " << G[r][(h+2)%3] + S[100010] - S[r+1] << " " << G[r][h] - 1 << endl ;
    }
}