#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//data.begin/end for itterators
template<typename T, typename C>
void quickSort(vector<T> &arr,int left,int right,const C &comp){
    int i = left, j=right;
    T tmp;
    T pivot = arr[(left+right)/2];
    while(i<=j){
        while (comp(arr[i],pivot)==-1)
            i++;
        while (comp(arr[j],pivot)==1)
            j--;
        if(i<=j){
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;
            j--;
        }
    };
    if(left<j) quickSort(arr,left,j,comp);
    if(i<right) quickSort(arr,i,right,comp);
}
template<typename T, typename C>
T &findNth(std::vector<T> &data,int index,const C &comp){
	//sort(data.begin(),data.end(),comp);
    quickSort(data,0,data.size()-1,comp);
    //cout<<data[0]<<"\n";
    //cout<<data[1]<<"\n";
	return data[index];

}
