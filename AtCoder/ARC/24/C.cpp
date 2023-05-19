#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
string S ;
ll cnt[101010][26] ;
map<vector<int>,int> mp ;

int main(){
    cin >> n >> k >> S ;
    rep(i,n) {
        rep(j,26){
            cnt[i+1][j] = cnt[i][j] ;
        }
        cnt[i+1][S[i]-'a']++ ;
    }
    bool ok = false ;
    rrep(i,k,n+1){
        vector<int> vec(26,0) ;
        rep(j,26) vec[j] = cnt[i][j] - cnt[i-k][j] ;
        if(mp[vec] == 0) mp[vec] = i ;
        else if(mp[vec] <= i - k) ok = true ;
    }
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}