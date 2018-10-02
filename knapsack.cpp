#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
    if (a>b) return a; 
    else return b;
}

pair<double,vector<int>>
knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values){
    int i,j;
    int n = weights.size();
    vector <vector<double>> K(n+1,vector<double>(weightLimit+1));

    for(i=0;i<=n;i++){
        for(j=0;j<=weightLimit;j++){
            if (i==0) K[i][j]=0;
            else if (weights[i-1]>j)
                K[i][j] = K[i-1][j];
            else
                K[i][j]=max(K[i-1][j], values[i-1]+K[i-1][j-weights[i-1]]);
        }
    }
    vector<int> items;
    double weightIndex = K[n][weightLimit];
    for(int s=n;s>0;--s){
        if (K[s][weightLimit]>K[s-1][weightLimit]) {
            items.push_back(s-1);
            weightLimit -= weights[s-1];
        }

    }
    pair <double,vector<int>> ret = make_pair(weightIndex,items);
    return ret;
}

//     j....n
//ks(W,j):
//  if(j>n): 0
//  if(W>=weight[j]
//  else: value[j]+ks(w-weightj,j+1) 
//  ks(W,j+1)
