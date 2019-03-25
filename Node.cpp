#include "Node.h"

Node::Node(double time, int clientNumber) {
    this->time = time;
    this->clientNumber = clientNumber;
    this->next = nullptr;
}

//Links the client that is to be behind the current client in line to the
//current client
void Node::setNext(Node* next) {
    this->next = next;
}

//Returns the client that is behind the current client in line
Node* Node::getNext() {
    return this->next;
}

//Sets the amount of time it will take for this client's query to be answered
void Node::setTime(double time) {
    this->time = time;
}

//Returns the amount of time it will take for this client's query to be
//answered
double Node::getTime() {
    return this->time;
}

//Returns this client's number
int Node::getClientNumber() {
    return this->clientNumber;
}