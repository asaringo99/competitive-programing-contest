#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll H , W , N ;

int main(){
    cin >> H >> W >> N ;
    ll sum = (H - 2) * (W - 2) ;
    map<P,bool> rem ;
    vector<P> vec ;
    for(int i = 0 ; i < N ; i++){
        int a , b ;
        cin >> a >> b ;
        rem[P(a,b)] = true ;
        vec.push_back(P(a,b)) ;
    }
    ll res[10] ;
    memset(res,0,sizeof(res)) ;
    map<P,int> only ;
    for(int i = 0 ; i < N ; i++){
        P p = vec[i] ;
        int x = p.first , y = p.second ;
        ll S[6][6] ;
        memset(S,0,sizeof(S)) ;
        for(int j = 0 ; j < 5 ; j++){
            for(int k = 0 ; k < 5 ; k++){
                S[j+1][k+1] = S[j+1][k] + S[j][k+1] - S[j][k] ;
                if(rem[P(x-2+j,y-2+k)]) S[j+1][k+1]++ ;
            }
        }
        for(int j = 3 ; j < 6 ; j++){
            for(int k = 3 ; k < 6 ; k++){
                if(x + (j - 5) < 1 || x + (j - 3) > H) continue ;
                if(y + (k - 5) < 1 || y + (k - 3) > W) continue ;
                if(only[P(x+j-3,y+k-3)]) continue ;
                only[P(x+j-3,y+k-3)] = true ;
                if(S[j][k]+S[j-3][k-3]-S[j][k-3]-S[j-3][k] == 0) continue ;
                res[S[j][k]+S[j-3][k-3]-S[j][k-3]-S[j-3][k]]++ ;
                sum-- ;
            }
        }
    }
    res[0] = sum ;
    for(ll u : res) cout << u << endl ;
}