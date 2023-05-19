#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll x , y ;
queue<P> que ;
map<ll,bool> used ;

int main(){
    cin >> x >> y ;
    ll res = abs(x-y) ;
    if(y & 1) que.push(P(y+1,1)) , que.push(P(y-1,1)) ;
    else que.push(P(y,0)) ;
    int count = 0 ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        ll top = p.first , cnt = p.second ;
        if(used[top]) continue ;
        used[top] = true ;
        res = min(res,abs(top - x)+cnt) ;
        if(top & 1) que.push(P(top+1,cnt+1)) , que.push(P(top-1,cnt+1)) ;
        else que.push(P(top/2,cnt+1)) ;
    }
    cout << res << endl ;
}