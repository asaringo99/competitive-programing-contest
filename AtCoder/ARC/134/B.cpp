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

int n ;
string S ;
map<int,vector<int>> mp ;

int main(){
    cin >> n >> S ;
    rep(i,n){
        mp[S[i]-'a'].push_back(i) ;
    }
    int id = n ;
    rep(i,n){
        bool ok = false ;
        rep(j,S[i]-'a'){
            if(!mp[j].empty()){
                int k = mp[j][mp[j].size()-1] ;
                if(i < k && k < id){
                    id = k ;
                    mp[j].pop_back() ;
                    ok = true ;
                    break ;
                }
            }
        }
        if(ok) swap(S[i],S[id]) ;
        rep(j,26){
            if(mp[j].empty()) continue ;
            while(!mp[j].empty() && mp[j][mp[j].size()-1] > id) mp[j].pop_back() ;
        }
    }
    cout << S << endl ;
}