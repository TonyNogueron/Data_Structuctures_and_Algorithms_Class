//
// Created by Antonio Nogueron Barcenas on 9/19/22.
//

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
