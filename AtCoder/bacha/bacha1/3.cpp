#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
string S , T , U ;
int A[26] , B[26] , C[26] , D[26] ;

int main(){
    fast_input_output
    cin >> S >> T >> U ;
    for(char u : S) A[u-'A']++ ;
    for(char u : T) B[u-'A']++ ;
    for(char u : U) C[u-'A']++ ;
    for(char u : U) D[u-'A']++ ;
    // 1
    n = S.size() ;
    int s = 0 , t = 0 ;
    rep(i,26){
        if(C[i] > A[i]){
            s += A[i] ;
            C[i] -= A[i] ;
        }
        else{
            s += C[i] ;
            C[i] = 0 ;
        }
    }
    if(s < n / 2){
        cout << "NO" << endl ;
        return 0 ;
    }
    rep(i,26){
        if(C[i] > B[i]){
            cout << "NO" << endl ;
            return 0 ;
        }
        else{
            t += C[i] ;
            C[i] = 0 ;
        }
    }
    rep(i,26){
        if(C[i] > 0){
            cout << "NO" << endl ;
            return 0 ;
        }
    }
    rep(i,26){
        int val = min(D[i],A[i]) + min(D[i],B[i]) - D[i] ;
        int tmp = s - n / 2 ;
        int x = min(val,tmp) ;
        s -= x ;
        t += x ;
    }
    if(s == n/2 && t == n/2) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}