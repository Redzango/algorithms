#include <iostream>
#include <vector>
using namespace std;

bool isIn(int elm, vector<int> vec){
    bool here = false;
    for(int i=0;i<vec.size();++i){
        if(vec[i]==elm) here = true;
    }
    return here;
}

int smallElem(vector<int> vec){
    int s = vec[0];
    for(int i=0;i<vec.size();++i) if(s>vec[i]) s=vec[i];
    return s;
}

int shortPath(const vector<vector<int>>&connects, vector<int> visited, int here, int cost){
    int n = connects.size();
    if(visited.size()==(n-1)) return cost;
    else{
        visited.push_back(here);
        vector<int> weights;
        for(int i=1;i<n;++i){
            if(!isIn(i,visited)) {
                weights.push_back(shortPath(connects,visited,i,cost+connects[here][i]));
            }
        }
        return smallElem(weights);
    }
}

int shortestCycle(const vector<vector<int>>&connects){
    int n = connects.size();
    
    vector<int> visited;
    vector<int> weights;

    visited.push_back(0);

    for(int i=1;i<n;++i){
        weights.push_back(shortPath(connects,visited,i,connects[0][i]));
    }
    
    return smallElem(weights);
}

