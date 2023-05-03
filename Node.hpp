#ifndef node
#define node
#include <iostream>
using namespace std;

class Node{
    private: 
        int v;
        int w;
    public:
        Node(int node, int weight);
        Node();
        void setV(int val);
        void setW(int val);
        int getV();
        int getW();
};
#endif