#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstdlib>
#include <unordered_map>
using namespace std;
typedef pair<char,vector<bool>> code;

struct node {
    char ch;
    unsigned freq;
    node *left, *right;
    node(char ch, unsigned freq){
        left = right = NULL;
        this->ch=ch;
        this->freq=freq;
    }
};

struct compare {
    bool operator()(node* l,node* r){
        return(l->freq > r->freq);
    }
};

bool isIn(vector<char> v, char c){
    int n = v.size();
    bool ret = false;
    for(int i=0;i<n;i++){
        if(v[i]==c) ret = true;
    }
    return ret;
}

void getCodes(struct node* root, vector<bool> cd, unordered_map<char,vector<bool>> &codes){
    if(!root) return;
    if(root->ch != '$'){
        codes[root->ch] = cd;
    }
    auto recF = cd;
    auto recT = cd;
    recF.push_back(false);
    recT.push_back(true);
    getCodes(root->left,recF,codes);
    getCodes(root->right,recT,codes);
}


void huffman(const string &message, vector<bool> &encoding){
    
    int n = message.size();

    priority_queue<node*,vector<node*>,compare> que;
    
    unordered_map<char,int> freq;

    for(int i=0;i<n;i++){
        freq[message[i]] += 1;
    }
    for(pair<char,int> elem : freq){
        que.push(new node(elem.first,elem.second));
    }

    while(que.size() != 1){
        auto left = que.top();
        que.pop();
        auto right = que.top();
        que.pop();
        auto top = new node('$',left->freq + right->freq);

        top -> left = left;
        top -> right = right;

        que.push(top);
    }
    
    unordered_map<char,vector<bool>> codes;
    vector<bool> boolCount;
    getCodes(que.top(),boolCount,codes);

    for(int i=0;i<n;i++){
        vector<bool> cd = codes[message[i]];
        encoding.insert(encoding.end(),cd.begin(),cd.end());
    }
}
