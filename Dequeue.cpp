#include "Dequeue.h"
#include <iostream>
#include <string>

using namespace std;

Dequeue::Dequeue() {
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

//Add individual that entered the office in person to the dequeue
void Dequeue::addPerson(Node* newPerson) {
    if (this->size != 0) {
        this->last->setNext(newPerson);
    }
    else {
        this->first = newPerson;
    }
    this->last = newPerson;
    this->size += 1;
    return;
}

//Add client that called on the phone to the dequeue
void Dequeue::addCall(Node* newCall) {
    if (this->size != 0) {
        newCall->setNext(this->first);
    }
    else {
        this->last = newCall;
    }
    this->first = newCall;
    this->size += 1;
    return;
}

//Returns the size of the dequeue
int Dequeue::getSize() {
    return this->size;
}

//Returns client at the front of the line
Node* Dequeue::getNextInLine() {
    return this->first;
}

//"Removes" the client at the front of the line and makes the next client the
//new front
void Dequeue::remove() {
    if (this->size > 1) {
    this->first = this->first->getNext();
    }
    else {
        this->first = nullptr;
        this->last = nullptr;
    }
    this->size -= 1;
    return;
}