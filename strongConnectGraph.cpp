#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

struct node {
    int index;
    bool visited;
    node *left, *right;
    node(int index, bool visited){
        left = right = NULL;
        this->index = index;
        this->visited = visited;
    }
};

void DFS(stack<int> &s, set<int> &visited,const vector<vector<int>> &roadTo, int index){
    for (int i=0;i<roadTo[index].size();i++){
        int current = roadTo[index][i];
        if(visited.find(current)==visited.end()){
            visited.insert(index);
            DFS(s,visited,roadTo,current);
        }
    }
    s.push(index);
}

void DFSinv(vector<set<int>> &s, set<int> &visited,const vector<vector<int>> &roadTo, int index, int set){
    for (int i=0;i<roadTo[index].size();i++){
        int current = roadTo[index][i];
        if(visited.find(current)==visited.end()) {
            visited.insert(index);
            DFSinv(s,visited,roadTo,current,set);
        }
    }
    s[set].insert(index);
}


vector<set<int>> drivingLegal(const vector<vector<int>> &roadTo){
    int n = roadTo.size();
    stack<int> s;
    set<int> visited;

    //first DFS
    for(int i = 0; i<n; i++){
        if(visited.find(i)==visited.end()){
            DFS(&s,&visited,roadTo,i);
        }
    }
    
    //find transverse graph
    vector<vector<int>> revRoad;
    for(int i=0;i<n;i++){
        for(int j : roadTo[i]){
            revRoad[j].push_back(i);
        }
    }

    //set visited empty
    visited.clear();

    vector<set<int>> SCC;
    //second DFS
    int index = 0;
    while(!s.empty()){
        int i = s.top();
        s.pop();

        if(visited.find(i)==visited.end()){
            DFSinv(&SSC,&visited,&revRoad,i,index);
        }
        ++index;
    }
    return SSC;
}
