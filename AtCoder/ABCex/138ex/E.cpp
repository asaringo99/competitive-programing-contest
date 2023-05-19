#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string s , t ;
map<int,vector<int>> rem ;

int main(){
    cin >> s >> t ;
    ll siz = s.size() ;
    for(int i = 0 ; i < s.size() ; i++){
        rem[s[i]-'a'].push_back(i) ;
    }
    ll res = 0 , sum = 0 , num = 0 ;
    for(int i = 0 ; i < t.size() ; i++){
        vector<int> tmp = rem[t[i]-'a'] ;
        if(tmp.size() == 0){
            cout << -1 << endl ;
            return 0 ;
        }
        auto it = lower_bound(tmp.begin(),tmp.end(),num) ;
        if(it == tmp.end()){
            res += siz ;
            num = 0 ;
            auto is = lower_bound(tmp.begin(),tmp.end(),num) ;
            num = *is + 1 ;
        }
        else{
            num = *it + 1 ;
        }
    }
    cout << res + num << endl ;
}