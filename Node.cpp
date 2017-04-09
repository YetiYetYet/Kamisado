//
// Created by julie on 09/04/17.
//

#include <cmath>
#include "Node.h"

double Node::UCT_const = 0.4;

Node::Node(Node *parent_, unsigned int depth_, Movement from_move_)
        : parent(parent_), depth(depth_), from_move(from_move_) {}

Node::~Node(){
    for (auto child : this->children)
    delete child;
};

bool Node::UCT_comp(const Node *&n1, const Node *&n2){
    return n1->UTC_eval() < n2->UTC_eval();
}

bool Node::best_comp(const Node *&n1, const Node *&n2){

}

double Node::UTC_eval() const{
    return (this->victories/this->n_playouts) +
            this->UCT_const*sqrt(log(this->parent->n_playouts)/this->n_playouts);
}