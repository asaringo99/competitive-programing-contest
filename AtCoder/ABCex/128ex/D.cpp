#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k ;

int main(){
    cin >> n >> k ;
    int V[n] ;
    for(int i = 0 ; i < n ; i++) cin >> V[i] ;
    ll res = 0 ;
    for(int i = 0 ; i <= min(k,n) ; i++){
        priority_queue<ll,vector<ll>,greater<ll>> que ;
        ll val = 0 ;
        for(int lef = 0 ; lef <= i ; lef++){
            if(lef != 0) {
                val += V[lef - 1] ;
                que.push(V[lef-1]) ;
            }
            priority_queue<ll,vector<ll>,greater<ll>> que2 = que ;
            ll val2 = val ;
            for(int rig = 0 ; rig <= i - lef ; rig++){
                //cout << rig << endl ;
                if(rig == 0) continue ;
                val2 += V[n - rig] ;
                que2.push(V[n - rig]) ;
            }
            int num = 0 ;
            while(num < k - i && !que2.empty()){
                ll point = que2.top() ;
                if(point >= 0) break ;
                que2.pop() ;
                // cout << val2 << " " << point << " " << i << endl ;
                val2 -= point ;
                num++ ;
            }
            res = max(res,val2) ;
        }
    }
    cout << res << endl ;
}