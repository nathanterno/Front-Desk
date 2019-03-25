class Node {
public:
    Node(double time, int clientNumber);
    void setNext(Node* next);
    Node* getNext();
    void setTime(double Time);
    double getTime();
    int getClientNumber();

private:
    //The client behind the current client in line
    Node* next;
    //The amount of time it will take for the current client's question to be
    //answered
    double time;
    //This client's number
    int clientNumber;
};