#include <iostream>
#include <queue>
#include <cstdlib>
//#include <vector>
using namespace std;

int numCells(double endTime,double minSplit,double maxSplit){
    priority_queue<double,std::vector<double>,std::greater<double>> que;
    int num = 1;
    que.push(0);
    while(que.top()<=endTime){
        que.push(que.top()+minSplit + rand()*(maxSplit-minSplit)/RAND_MAX);
        que.push(que.top()+minSplit + rand()*(maxSplit-minSplit)/RAND_MAX);
        que.pop();
        ++num;
    }

    return num;
}

