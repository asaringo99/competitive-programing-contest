#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , m ;
map<int,vector<int>> X ;
set<int> timer ;

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int x , y ;
        cin >> x >> y ;
        timer.insert(x) ;
        X[x].push_back(y) ;
    }
    set<int> res ;
    res.insert(n) ;
    for(int t : timer){
        vector<int> erase , add ;
        for(int i = 0 ; i < X[t].size() ; i++){
            if(res.count(X[t][i] - 1) == 1) add.push_back(X[t][i]) ;
            if(res.count(X[t][i] + 1) == 1) add.push_back(X[t][i]) ;
            erase.push_back(X[t][i]) ;
        }
        for(int u : erase) res.erase(u) ;
        for(int u : add) res.insert(u) ;
    }
    cout << res.size() << endl ;
}