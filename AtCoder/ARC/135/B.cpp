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
ll S[303030] , A[303030] ;
bool use[303030] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> S[i] ;
    if(n == 1){
        cout << "Yes" << endl ;
        cout << S[0] << " " << 0 << " " << 0 << endl ;
        return 0 ;
    }
    if(n == 2){
        cout << "Yes" << endl ;
        cout << S[0] << " " << 0 << " " << 0 << " " << S[1] << endl ;
        return 0 ;
    }
    bool ok = false ;
    rrep(i,0,3){
        rrep(j,1,4){
            rrep(k,2,5){
                if(i == j || j == k || k == i) continue ;
                A[i] = S[0] ;
                A[j] = S[1] ;
                A[k] = S[2] ;
                rrep(a,3,n){
                    A[a+2] = S[a] - A[a] - A[a+1] ;
                }
                bool gd = true ;
                rep(a,n+2) if(A[a] < 0) gd = false ;
                rep(a,n) if(A[a] + A[a+1] + A[a+2] != S[a]) gd = false ;
                if(gd){
                    rep(a,n+2){
                        cout << A[a] << " " ;
                        cout << endl ;
                        return 0 ;
                    }
                }
            }
        }
    }
    cout << "No" << endl ;
}