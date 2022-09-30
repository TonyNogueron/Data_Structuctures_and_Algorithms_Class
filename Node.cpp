// Antonio Noguerón & Armando Arredondo
// 09/29/2022

#include "Node.h"

Node::Node() {
    data = 0;
}

Node::~Node() {

}

Node::Node(int data_) {
    data = data_;
}

int Node::getData(){
    return data;
}

void Node::setData(int new_data) {
    data = new_data;
}
