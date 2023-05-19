#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n ;
map<ll,ll> mp ;
vector<ll> vec ;

int main(){
    cin >> n ;
    for(ll i = 1 ; i * i <= n ; i++){
        mp[i] = n / i ;
        mp[n/i] = i ;
        vec.push_back(i) ;
        if(i * i != n) vec.push_back(n/i) ;
    }
    sort(vec.begin(),vec.end()) ;
    ll res = mp[vec[0]] ;
    rrep(i,1,vec.size()){
        res += mp[vec[i]] * (vec[i] - vec[i-1]) ;
    }
    cout << res << endl ;
}