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

int n , m ;
vector<vector<bool>> A , B ;

int main(){
    cin >> n >> m ;
    A.resize(n,vector<bool>(n,false)) ;
    B.resize(n,vector<bool>(n,false)) ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        A[a][b] = true ;
        A[b][a] = true ;
    }
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        B[a][b] = true ;
        B[b][a] = true ;
    }
    int X[n] ;
    rep(i,n) X[i] = i ;
    do
    {
        vector<vector<bool>> vec(n,vector<bool>(n,false)) ;
        rep(i,n) rep(j,n) vec[i][j] = B[X[i]][X[j]] ;
        if(vec == A){
            cout << "Yes" << endl ;
            return 0 ;
        }
    } while (next_permutation(X,X+n));
    cout << "No" << endl ;
}