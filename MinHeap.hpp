#include <iostream>
#include "Node.hpp"

class MinHeap{
    private:
        Node q [50001];
        int positions[50001];
        int size =0;
        Node parents[50001];
    public: 
        MinHeap();
        int getWeight(int a);
        void setWeight(int a, int weight);
        int getSize();
        void insert(int a);
        void print();
        Node extractMin(); // We only need an int instead of a node because we don't care about the weight edge when getting the min 
        void heapify(int i);
        void prims();
        void update(int a);
        bool existsInPQ(int a);
        void setParent(int a, Node tempNode);
        void printParents();
};
