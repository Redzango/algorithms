#include "order.h"
#include <iostream>
#include <vector>
using namespace std;



int main(){
    auto intComp = [](int i,int j){
        return(i<j) ? -1:((i>j) ? 1 : 0);
    };
	vector<int> lst{2,1,3};
	cout<<lst[0]<<"\n";
	cout<<findNth(lst,0,intComp)<<"\n";
}
