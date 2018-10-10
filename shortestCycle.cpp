#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bool isIn(int elm,bitset<23> set){
    /*bool here = false;
    for(int i=0;i<set.size();++i){
        if(set[i]==elm) here = true;
    }*/
    return set[elm];
}

bitset<23> sub(int index, bitset<23> bit){
    bitset<23> n = bit;
    n.reset(index);
    return n;
}

bool isEq(bitset<23> S, int c){
    bool eq = true;
    for(int i=0;i<S.size();i++){
        if(S[i]!=0 && i!=c) {
            eq=false;
            return eq;
        }
    }
    if(S[c]!=1) eq=false;
    return eq;
}

int recurs(const vector<vector<int>>&connects, bitset<23> S, int c, vector<vector<int>>&K){
    if(isEq(S,c)) return connects[0][c];
    if(K[S.to_ulong()][c]>=0) return K[S.to_ulong()][c];//set sefault values to -1
    int best = 1000000000;
    for(int x=1;x<=connects.size()-1;x++){
        if(x!=c && isIn(x,S))
           best = min(best,recurs(connects,sub(c,S),x,K)+connects[x][c]);
    }
    K[S.to_ulong()][c]=best;
    return best;
}

int shortestCycle(const vector<vector<int>>&connects){
    int n = connects.size();
    
    bitset<23> S;

    vector<vector<int>> K(1<<n,vector<int>(n,-1));
    
    int best = 1000000000;

    for(int i=1;i<n;i++){
        S.set(i);
    }

    K[S.to_ulong()][0]=0;
    for(int x=1;x<=n-1;x++){
        best=min(best,recurs(connects,S,x,K)+connects[x][0]);
    }
    return best;
}

