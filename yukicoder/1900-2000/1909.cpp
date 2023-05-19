#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n , m ;
string S[505050] ;
vector<string> vec ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> S[i] ;
    string s = S[0] ;
    string t = S[1] ;
    string a = "" , b = "" ;
    int i = 0 , j = 0 ;
    bool use_a = false , use_b = false ;
    while(true){
        if(i == m && j == m) break;
        if(i == m){
            a += t[j] ;
            b += t[j] ;
            j++ ;
        }
        else if(j == m){
            a += s[i] ;
            b += s[i] ;
            i++ ;
        }
        else if(s[i] != t[j]){
            if(s[i+1] == t[j+1] && !use_a && !use_b){
                a += s[i] ;
                a += t[j] ;
                b += t[j] ;
                b += s[i] ;
                use_a = true ;
                use_b = true ;
                i++ ;
                j++ ;
            }
            else if(s[i+1] == t[i] && t[i+1] == s[i] && !use_a && !use_b){
                a += s[i] ;
                a += t[j] ;
                a += t[j+1] ;
                b += t[j] ;
                b += s[i] ;
                b += s[i+1] ;
                use_a = true ;
                use_b = true ;
                i+=2 ;
                j+=2 ;
            }
            else if(s[i+1] == t[i] && !use_a) a += s[i] , b += s[i] , i++ , use_a = true ;
            else if(t[j+1] == s[j] && !use_b) b += t[j] , a += t[j] , j++ , use_b = true ;
            else{
                cout << 0 << endl ;
                return 0 ;
            }
        }
        else{
            a += s[i] ;
            b += t[j] ;
            i++ ;
            j++ ;
        }
    }
    bool ok = a == b ? true : false ;
    bool ga = true , gb = true ;
    int res = 2 ;
    rep(i,n){
        int ida = 0 ;
        if(ga) rep(j,m){
            if(!ga) break;
            while(a[ida] != S[i][j]){
                ida++ ;
                if(ida == 2){
                    ga = false ;
                    break ;
                }
            }
            ida++ ;
        }
        int idb = 0 ;
        if(gb) rep(j,m){
            if(!gb) break;
            while(b[idb] != S[i][j]){
                idb++ ;
                if(idb == 2){
                    gb = false ;
                    break ;
                }
            }
            idb++ ;
        }
    }
    if(!ga) res-- ;
    if(!gb) res-- ;
    if(res == 2 && ok) res = 1 ;
    cout << res << endl ;
}