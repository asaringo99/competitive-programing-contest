#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<char,int> P ;
typedef pair<P,int> PP ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string AL[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"} ;

int n ;
string S ;
vector<P> vec ;
map<string,int> conv ;
map<int,string> con ;
map<P,int> C ;

int main(){
    fast_input_output
    rep(i,13) conv[AL[i]] = i ;
    rep(i,13) con[i] = AL[i] ;
    cin >> S ;
    n = S.size() ;
    bool ok = false ;
    int a = -1 , b = -1 ;
    char aa , bb ;
    int i = 0 ;
    while(i < n){
        cout << S[i] << endl ;
        if(S[i] == 'S'){
            i++ ;
            string T = "" ;
            while(i < n && S[i] != 'S' && S[i] != 'H' && S[i] != 'D' && S[i] != 'C'){
                T += S[i] ;
                i++ ;
            }
            cout << T << endl ;
            vec.push_back(P('S',conv[T])) ;
            C[P('S',conv[T])]++ ;
            if(!ok && C[P('S',conv[T])] == 3) ok = true , a = conv[T] , aa = 'S' ;
            if(ok && C[P('S',conv[T])] == 2) {
                b = conv[T] ;
                bb = 'S' ;
                break ;
            }
        }
        if(S[i] == 'H'){
            i++ ;
            string T = "" ;
            while(i < n && S[i] != 'S' && S[i] != 'H' && S[i] != 'D' && S[i] != 'C'){
                T += S[i] ;
                i++ ;
            }
            vec.push_back(P('H',conv[T])) ;
            C[P('H',conv[T])]++ ;
            if(!ok && C[P('H',conv[T])] == 3) ok = true , a = conv[T] , aa = 'H' ;
            if(ok && C[P('H',conv[T])] == 2) {
                b = conv[T] ;
                bb = 'H' ;
                break ;
            }
        }
        if(S[i] == 'D'){
            i++ ;
            string T = "" ;
            while(i < n && S[i] != 'S' && S[i] != 'H' && S[i] != 'D' && S[i] != 'C'){
                T += S[i] ;
                i++ ;
            }
            vec.push_back(P('D',conv[T])) ;
            C[P('D',conv[T])]++ ;
            if(!ok && C[P('D',conv[T])] == 3) ok = true , a = conv[T] , aa = 'D' ;
            if(ok && C[P('D',conv[T])] == 2) {
                b = conv[T] ;
                bb = 'D' ;
                break ;
            }
        }
        if(S[i] == 'C'){
            i++ ;
            string T = "" ;
            while(i < n && S[i] != 'S' && S[i] != 'H' && S[i] != 'D' && S[i] != 'C'){
                T += S[i] ;
                i++ ;
            }
            vec.push_back(P('C',conv[T])) ;
            C[P('C',conv[T])]++ ;
            if(!ok && C[P('C',conv[T])] == 3) ok = true , a = conv[T] , aa = 'C' ;
            if(ok && C[P('C',conv[T])] == 2) {
                b = conv[T] ;
                bb = 'C' ;
                break ;
            }
        }
    }
    for(P p : vec){
        auto [cha, val] = p ;
        if(cha == aa && val == a){
            C[P(cha,val)]-- ;
            if(C[P(cha,val)] < 0) cout << cha << con[val] ;
        }
        else if(cha == bb && val == b){
            C[P(cha,val)]-- ;
            if(C[P(cha,val)] < 0) cout << cha << con[val] ;
        }
        else cout << cha << con[val] ;
    }
    cout << endl ;
}