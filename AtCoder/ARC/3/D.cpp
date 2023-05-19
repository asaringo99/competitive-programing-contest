#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m , k ;
int A[20] , B[20] ;

// 乱数発生器
random_device rnd ;
mt19937 mt(rnd()) ;

int main(){
    cin >> n >> m >> k ;
    uniform_int_distribution<> rand100(0, n - 1) ;
    rep(i,m) cin >> A[i] >> B[i] ;
    ll res = 0 ;
    rep(i,500000){
        vector<int> vec ;
        rep(j,n) vec.push_back(j) ;
        rep(j,k){
            int r = rand100(mt) , l = rand100(mt) ;
            while(r == l){
                r = rand100(mt) ;
                l = rand100(mt) ;
            }
            swap(vec[l],vec[r]) ;
        }
        set<int> G[n] ;
        rep(j,n){
            G[vec[j]].insert(vec[(j-1+n)%n]) ;
            G[vec[j]].insert(vec[(j+1)%n]) ;
        }
        bool ok = true ;
        rep(j,m) if(G[A[j]].count(B[j]) == 1) ok = false ;
        if(ok) res++ ;
    }
    cout << setprecision(15) << (double) res / 500000 << endl ;
}