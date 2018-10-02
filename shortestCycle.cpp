#include <iostream>
#include <vector>
#include <bitset>
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

bitset sub(int index, bitset bit){
    bitset[index]=0;
    return bitset;
}

int shortPath(const vector<vector<int>>&connects, vector<int> visited, int here, int prev){
    int n = connects.size();
    if(prev==0) return connects[0][here];
    else{
        visited.push_back(here);
        vector<int> weights;
        for(int i=1;i<n;++i){
            if(!isIn(i,visited)) {
                weights.push_back(shortPath(connects,visited,i);
            }
        }
        return smallElem(weights);
    }
}

int shortestCycle(const vector<vector<int>>&connects){
    int n = connects.size();
    
    bitset<n> visited;
    visited.flip();
    vector<vector<int>> K(visited.to_ulong())(n);
    visited.flip();
    K(visited.to_ulong())(0)=0;
    visited.flip();

    for(int c=1;c<n;++c){
    	bitset subd = sub(c,visited);
        for(int x=1;x<n;++x)
        if(subd[x]=="1") K[visited.to_ulong()][c]=shortPath(connects,visited,c,x);
    }
    
    return smallElem(weights);
}

