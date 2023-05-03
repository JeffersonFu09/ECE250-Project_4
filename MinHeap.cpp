#include <iostream> 
#include <climits>
#include "MinHeap.hpp"
using namespace std;

MinHeap::MinHeap(){
    for(int i=0; i < 50001; i++ ){
        parents[i] = Node(-1, INT_MAX);
    }
}

void MinHeap::insert(int a){
    q[size] = Node(a, INT_MAX);
    positions[a] = size;
    size++;
}

void MinHeap::print(){
    for (int i = 0; i < size; i++){
        cout << "Vertex: " <<  q[i].getV() << " cost: " << q[i].getW() << endl; 
    }
}

Node MinHeap::extractMin(){
    Node root = q[0];
    q[0]= q[size-1];
    positions[root.getV()] = -1;
    positions[q[size-1].getV()] = 0;
    size--;
    heapify(0);

    return root;
}

void MinHeap::heapify(int i){
    int leftChild = (2*i + 1);
    int rightChild = (2*i + 2);
    int lower = i;
    if(leftChild<size && q[leftChild].getW() < q[i].getW()){
        lower = leftChild;
    }
    if(rightChild<size && q[rightChild].getW() < q[lower].getW()){
        lower = rightChild;
    }
    if (lower!=i){
        Node temp = q[lower];
        int lowerV = q[lower].getV();
        int curV= q[i].getV();

        q[lower]= q[i];
        q[i] = temp;

        int temp2 = positions[lowerV];
        int temp3 = positions[curV];
        positions[lowerV] = temp3;
        positions[curV] = temp2;
        heapify(lower); 
    }
}

int MinHeap::getWeight(int a){ 
    int index = positions[a]; 
    return q[index].getW(); 
}

int MinHeap::getSize(){
    return size;
}

void MinHeap::setWeight(int a, int weight){
    int index = positions[a];
    q[index].setW(weight);
}
void MinHeap::update(int a){
    int index = positions[a];
    while (index>0 && q[index].getW() < q[(index-1)/2].getW()){
        Node temp = q[(index-1)/2];
        int lowerV = q[(index-1)/2].getV();
        int curV = q[index].getV();

        q[(index-1)/2] = q[index];
        q[index] = temp;

        int temp2 = positions[lowerV];
        int temp3 = positions[curV];
        positions[lowerV]= temp3;
        positions[curV] = temp2;

        index = (index -1)/2;
    }
}

bool MinHeap::existsInPQ(int a){
    if (positions[a] != -1){
        return true;
    }
    return false;
}

void MinHeap::setParent(int index, Node tempNode){
    parents[index] = tempNode;
}

void MinHeap::printParents(){
    for (int i =0 ; i < 50001; i ++ ){
        if (parents[i].getV() != -1){
            cout << parents[i].getV() << " " << i << " " << parents[i].getW() << " ";
        }
    }
    cout << endl;
}
