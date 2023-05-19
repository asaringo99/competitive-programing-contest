#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
P X[202020] , Y[202020] ;
map<P,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n){
        ll x , y ;
        cin >> x >> y ;
        X[i] = P(x,i) ;
        Y[i] = P(y,i) ;
    }
    sort(X,X+n) ;
    sort(Y,Y+n) ;
    mp[P(max(X[n-1].second,X[0].second),min(X[n-1].second,X[0].second))] = max(mp[P(max(X[n-1].second,X[0].second),min(X[n-1].second,X[0].second))],X[n-1].first-X[0].first) ;
    mp[P(max(Y[n-1].second,Y[0].second),min(Y[n-1].second,Y[0].second))] = max(mp[P(max(Y[n-1].second,Y[0].second),min(Y[n-1].second,Y[0].second))],Y[n-1].first-Y[0].first) ;

    mp[P(max(X[n-2].second,X[0].second),min(X[n-2].second,X[0].second))] = max(mp[P(max(X[n-2].second,X[0].second),min(X[n-2].second,X[0].second))],X[n-2].first-X[0].first) ;
    mp[P(max(Y[n-2].second,Y[0].second),min(Y[n-2].second,Y[0].second))] = max(mp[P(max(Y[n-2].second,Y[0].second),min(Y[n-2].second,Y[0].second))],Y[n-2].first-Y[0].first) ;
    
    mp[P(max(X[n-1].second,X[1].second),min(X[n-1].second,X[1].second))] = max(mp[P(max(X[n-1].second,X[1].second),min(X[n-1].second,X[1].second))],X[n-1].first-X[1].first) ;
    mp[P(max(Y[n-1].second,Y[1].second),min(Y[n-1].second,Y[1].second))] = max(mp[P(max(Y[n-1].second,Y[1].second),min(Y[n-1].second,Y[1].second))],Y[n-1].first-Y[1].first) ;

    vector<ll> vec ;
    for(auto it: mp){
        vec.push_back(it.second) ;
    }
    sort(vec.begin(),vec.end()) ;
    cout << vec[vec.size()-2] << endl ;
}