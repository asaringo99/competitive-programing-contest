#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int q ;
queue<ll> que ;
priority_queue<ll,vector<ll>,greater<ll>> pque ;

int main(){
    cin >> q ;


    rep(i,q){
        int s , x ;
        cin >> s ;
        if(s == 1){
            cin >> x ;
            que.push(x) ;
        }
        if(s == 2){
            if(!pque.empty()){
                cout << pque.top() << endl ;
                pque.pop() ;
            }
            else{
                cout << que.front() << endl ;
                que.pop() ;
            }
        }
        if(s == 3){
            while(!que.empty()){
                int x = que.front() ; que.pop() ;
                pque.push(x) ;
            }
        }
    }
}