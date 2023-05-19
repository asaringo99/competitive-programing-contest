#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , L ;


int main(){
    cin >> n >> L ;
    vector<vector<int>> res(n,vector<int>(L-1,0));
    rep(i,n-1){
        int id = L - 2 ;
        vector<int> vec = res[i] ;
        vec[L-2]++ ;
        while(id >= 0 && vec[id] % 3 == 0){
            vec[id] = 0 ;
            id-- ;
            vec[id]++ ;
        }
        res[i+1] = vec ;
    }
    vector<string> ans ;
    rep(i,n){
        unordered_map<int,int> mp ;
        mp[0] = 1 ;
        mp[1] = 2 ;
        mp[2] = 0 ;
        string S = "0" ;
        rep(j,L-1) S += to_string(mp[res[i][j]]) ;
        ans.push_back(S) ;
    }
    rep(i,n){
        unordered_map<int,int> mp ;
        mp[0] = 2 ;
        mp[1] = 0 ;
        mp[2] = 1 ;
        string S = "1" ;
        rep(j,L-1) S += to_string(mp[res[i][j]]) ;
        ans.push_back(S) ;
    }
    sort(ans.begin(),ans.end()) ;
    rep(i,2*n) cout << ans[i] << "\n" ;
    rep(i,n){
        cout << 2 ;
        rep(j,L-1) cout << res[i][j] ;
        cout << endl;
    }
}