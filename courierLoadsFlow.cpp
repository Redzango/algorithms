#include <queue>
#include <vector>
#include <iostream>
#include <tuple>
using namespace std;


bool bfs(vector<vector<int>> &rgraph,  vector<int> &parent){
    int n = rgraph.size();
    int s = 0;
    int t = n-1;
    bool visited[n];
    for(int i=0;i<n;i++) visited[i]=false;

    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0;i<n;i++){
            int v=i;
            int cap = rgraph[u][v];
            if(visited[v]==false && cap>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}

vector<tuple<int,int,int>> courierLoads(const vector<int> &orders,const vector<tuple<int,int,int>> &capacities){
    int n = orders.size()+1;
    int s = 0;
    int t = n-1;
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<vector<int>> rgraph(n,vector<int>(n,0));
    for(int i=0;i<capacities.size();i++){
        tuple<int,int,int> vals = capacities[i];
        int so = get<0>(vals);
        int si = get<1>(vals);
        int w = get<2>(vals);
        graph[so][si]=w;
        rgraph[so][si]=w;
    }
    for(int i=0;i<t;i++){
        graph[i][t] = 100000000;
        rgraph[i][t] = 100000000;
    }
    vector<int> parent(n,-1);
    
    while (bfs(rgraph,parent)){
        cout<<1;
        int path_flow = 100000000;
        for(int v=t;v!=s;v=parent[v]){
            auto u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        for(int v=s;v!=0;v=parent[v]){
            auto u=parent[v];
            rgraph[u][v] = rgraph[u][v] - path_flow;
            rgraph[v][u] = rgraph[v][u] + path_flow;
        }
    }
    
    bool pass = true;
    vector<tuple<int,int,int>> ret;

    for(auto t = capacities.begin() ; t!=capacities.end(); ++t){
        int from = get<0>(*t);
        int to = get<1>(*t);
        int c = get<2>(*t);
        int flow = c-rgraph[from][to];
        ret.push_back(make_tuple(from,to,flow));
    }
    return ret;
}

int main(){
    vector<tuple<int,int,int>> routs = {make_tuple(0,1,1),make_tuple(0,2,1),make_tuple(1,2,1)};
    vector<int> orders = {0,1,2};
    vector<tuple<int,int,int>> vals = courierLoads(orders,routs);
    cout<<vals.size();
    cout<<" "<<get<2>(vals[2]);
}
