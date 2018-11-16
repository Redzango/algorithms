#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <set>
using namespace std;


tuple<vector<int>,vector<int>> distanceFromHome(const vector<vector<tuple<int,int>>> &nearbyDistances){
    int n = nearbyDistances.size();
    vector<int> dist(n);
    vector<int> parent(n);
    set<int> set;
    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> que;
   
    dist[0]=0;
    parent[0]=-1;
    que.push(make_tuple(0,0));
    for(int i=1; i<n;i++){
        dist[i] = 1000000000;
        que.push(make_tuple(dist[i],i));
    }
    set.insert(0);

    while(!que.empty()){
        int u = get<1>(que.top());
        que.pop();
        set.insert(u);
        for(auto i = nearbyDistances[u].begin(); i!=nearbyDistances[u].end(); ++i){
            int v = get<0>(*i);
            int w = get<1>(*i);
            if(dist[v]>(dist[u]+w) && set.find(v)==set.end()){
                //set.insert(v);
                dist[v]=dist[u]+w;
                parent[v]=u;
                que.push(make_pair(dist[v],v));
            }
        }
    }
    
    /*for(int i=1;i<n;i++){
        retFrom[i]=dist[i-1];
        retDist[i]=get<1>(nearbyDistances[dist[i-1]][dist[i]]);
    }*/

    return make_tuple(dist,parent);
}


/*

int main(){
    vector<vector<tuple<int,int>>> nbd = {{make_tuple(1,1)},
                                          {make_tuple(3,4),make_tuple(2,1)},
                                          {make_tuple(3,1),make_tuple(0,1)},
                                          {make_tuple(1,1),make_tuple(2,1)}};
    tuple<vector<int>,vector<int>> ret = distanceFromHome(nbd);
    vector<int> dsts = get<0>(ret);
    vector<int> from = get<1>(ret);
    for(auto i = dsts.begin();i!=dsts.end();++i){
        cout<<(*i);
    }
    cout<<"\n";
    for(auto i = from.begin();i!=from.end();++i){
        cout<<(*i);
    }
}*/
