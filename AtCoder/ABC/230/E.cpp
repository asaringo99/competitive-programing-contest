#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , d ;
TP A[202020] ;
priority_queue<P,vector<P>,greater<P>> que ;
bool used[202020] ;

int main(){
    cin >> n >> d ;
    rep(i,n){
        ll l , r ;
        cin >> l >> r ;
        A[i] = {r,l,i} ;
        que.push(P(l,i)) ;
    }
    sort(A,A+n) ;
    int sum = 0 ;
    rep(i,n){
        int l , r , id ;
        tie(r,l,id) = A[i] ;
        if(used[id]) continue ;
        while(!que.empty()){
            P p = que.top() ;
            // cout << r << " " << p.first << " " << p.second << endl ;
            if(p.first > r + d - 1) break ;
            que.pop() ;
            used[p.second] = true ;
        }
        sum++ ;
    }
    cout << sum << endl ;
}