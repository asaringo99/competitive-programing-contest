#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int SQRTN=200;

struct edge{
    int to,c;
};

int n,m;
int need[10101];
unordered_map<ll,ll> d[10101];
vector<edge> G[10101];

void bfs(){
    for(int i=0;i<n;i++) need[i]=1e6;
    need[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v=que.front(); que.pop();
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(e.c==0){
                if(need[e.to]>need[v]){
                    need[e.to]=need[v];
                    que.push(e.to);
                }
            }
            if(e.c==1){
                if(need[e.to]>need[v]+1){
                    need[e.to]=need[v]+1;
                    que.push(e.to);
                }
            }
        }
    }
}

void djikstra(){
    for(int i=0;i<n;i++) for(int j=need[i];j<need[i]+SQRTN;j++) d[i][j]=1e14;
    d[0][0]=0;
    priority_queue<TP,vector<TP>,greater<TP>> que;
    que.push({0,0,0});
    while(!que.empty()){
        TP tpl=que.top(); que.pop();
        ll dist,cnt,v;
        tie(dist,cnt,v)=tpl;
        if(d[v][cnt]<dist) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(e.c==0){
                if(d[e.to][cnt]>d[v][cnt]+1){
                    d[e.to][cnt]=d[v][cnt]+1;
                    que.push({d[e.to][cnt],cnt,e.to});
                }
            }
            if(e.c==1){
                if(cnt+1>need[e.to]+SQRTN) continue;
                if(d[e.to][cnt+1]>d[v][cnt]+cnt+1){
                    d[e.to][cnt+1]=d[v][cnt]+cnt+1;
                    que.push({d[e.to][cnt+1],cnt+1,e.to});
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int c,a,b;
        cin>>c>>a>>b;
        G[a].push_back(edge{b,c});
        G[b].push_back(edge{a,c});
    }
    bfs();
    djikstra();
    for(int i=0;i<n;i++){
        ll res=1e17;
        for(int j=need[i];j<need[i]+SQRTN;j++) res=min(res,d[i][j]);
        cout<<res<<"\n";
    }
}