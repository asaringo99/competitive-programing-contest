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

int n , a , b ;

int main(){
    cin >> n >> a >> b ;
    if(a >= n){
        cout << "Takahashi" << endl ;
        return 0 ;
    }
    if(a > b){
        if(n - 1 == b) cout << "Aoki" << endl ;
        else cout << "Takahashi" << endl ;
        return 0 ;
    }
    else if(a < b){
        if(a >= n) cout << "Takahashi" << endl ;
        else cout << "Aoki" << endl ;
        return 0 ;
    }
    else{
        if(n % (a + 1) == 0) cout << "Aoki" << endl ;
        else cout << "Takahashi" << endl ;
    }
}