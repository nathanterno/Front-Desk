#include "Node.h"

class Dequeue {
public:
    Dequeue();
    void addPerson(Node* newPerson);
    void addCall(Node* newCall);
    int getSize();
    Node* getNextInLine();
    void remove();

private:
    //The size of the dequeue
    int size;
    //The client in the front of the line
    Node* first;
    //The client in the back of the line
    Node* last;
};