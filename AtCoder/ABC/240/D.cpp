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
ll A[202020] ;
vector<int> vec ;

ll f(){
    int m = vec.size() ;
    int v = vec[m-1] ;
    int count = 0 ;
    for(int i = m - 1 ; i >= 0 ; i--){
        if(v == vec[i]) count++ ;
        else break ;
    }
    return count ;
}

void g(){
    int m = vec.size() ;
    int v = vec[m-1] ;
    while(!vec.empty() && vec[vec.size()-1] == v){
        vec.pop_back() ;
    }
}

int main(){
    cin >> n ;
    int bef = -1 , count = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(bef == a){
            count++ ;
        }
        else{
            bef = a ;
            count = 1 ;
        }
        vec.push_back(a) ;
        int m = vec.size() ;
        // cout << count << " " << a << " " << vec[m-1] << " " << vec.size() << endl ;
        if(count == vec[m-1]){
            g() ;
            count = f() ;
            bef = vec[vec.size() - 1] ;
        }
        cout << vec.size() << endl ;
    }
}