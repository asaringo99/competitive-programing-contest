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

int n , q ;
unordered_map<string,int> d ;
unordered_map<string,bool> use ;

unordered_map<string,vector<string>> G ;

void bfs(string S){
    if(use[S]) return ;
    use[S] = true ;
    queue<string> que;
    que.push(S) ;
    while(!que.empty()){
        string v = que.front() ; que.pop();
        for(string t : G[v]){
            if(!use[t]){
                d[t] = d[v] + 1 ;
                que.push(t) ;
                use[t] = true ;
            }
        }
    }
}

int main(){
    cin >> n >> q ;
    rep(x,q){
        string S ;
        cin >> S ;
        string T = S;
        sort(T.begin(),T.end()) ;
        if(!use[T]){
            do {
                rrep(i,1,n){
                    string t = "" ;
                    for(int s = i ; s >= 0 ; s--) t += T[s] ;
                    for(int s = i + 1 ; s < n ; s++) t += T[s] ;
                    G[T].push_back(t) ;
                }
            } while (next_permutation(T.begin(),T.end()));
        }
        bfs(T) ;
        cout << d[S] << endl ;
    }
}