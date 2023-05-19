#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

string S ;
map<char,ll> mp ;

// chokudai

int main(){
    cin >> S ;
    int n = S.size() ;
    rep(i,n){
        if(S[i] == 'c') (mp['c'] += 1) %= mod ;
        if(S[i] == 'h') (mp['h'] += mp['c']) %= mod ;
        if(S[i] == 'o') (mp['o'] += mp['h']) %= mod ;
        if(S[i] == 'k') (mp['k'] += mp['o']) %= mod ;
        if(S[i] == 'u') (mp['u'] += mp['k']) %= mod ;
        if(S[i] == 'd') (mp['d'] += mp['u']) %= mod ;
        if(S[i] == 'a') (mp['a'] += mp['d']) %= mod ;
        if(S[i] == 'i') (mp['i'] += mp['a']) %= mod ;
    }
    cout << mp['i'] << endl ;
}