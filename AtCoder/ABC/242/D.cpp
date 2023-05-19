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

int q ;
string S ;

char f(char s , int k){
    if(s == 'A'){
        if(k == 0) return 'B' ;
        else return 'C' ;
    }
    else if(s == 'B'){
        if(k == 0) return 'C' ;
        else return 'A' ;
    }
    else{
        if(k == 0) return 'A' ;
        else return 'B' ;
    }
}

int main(){
    cin >> S >> q ;
    rep(zz,q){
        ll t , k ;
        cin >> t >> k ;
        k-- ;
        int n = S.size() ;
        vector<int> pre ;
        if(t <= 1){
            while(t > 0){
                if(k % 2 == 0) pre.push_back(0) ;
                else pre.push_back(1) ;
                t-- ;
                k /= 2 ;
            }
            reverse(pre.begin(),pre.end()) ;
            char res = S[k] ;
            rep(i,pre.size()){
                res = f(res,pre[i]) ;
            }
            cout << res << endl ;
        }
        else {
            while(k > 0){
                if(k % 2 == 0) pre.push_back(0) ;
                else pre.push_back(1) ;
                k /= 2 ;
                t-- ;
            }
            char res ;
            if(t % 3 == 1) res = 'A' ;
            if(t % 3 == 2) res = 'B' ;
            if(t % 3 == 0) res = 'C' ;
            reverse(pre.begin(),pre.end()) ;
            rep(i,pre.size()){
                res = f(res,pre[i]) ;
            }
            cout << res << endl ;
        }
    }
}