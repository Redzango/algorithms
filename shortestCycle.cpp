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
    
    bitset<23> visited;
    vector<vector<int>> K(1<<connects.size())(vector<int>(n));
    K[visited.to_ulong()][0]=0;
    for(int i=1;i<=n;++i){
    	visited.set(i);
	K[visited.to_ulong][i]=connects[0][i];
	visited.reset(i);
    }

    for(int c=1;c<n;c++){
    	bitset subd = sub(c,visited);
	vector<int>
        for(int x=1;x<n;++x)
        if(subd[x]=="1") K[visited.to_ulong()][c]=shortPath(connects,visited,c,x);
    }
    
    return smallElem(weights);
}

