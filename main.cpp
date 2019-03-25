#include "Dequeue.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    cout << "Welcome to the customer service simulation." << endl;

    //Initialize variables for maximum possible values for when an individual
    //enters the office, when someone calls on the phone, and when the clerk
    //answers a question, as well as the to-be-randomized varibles for each of
    //these.
    double answerQuestionMax;
    double answerQuestionTime = 0.0;
    double inPersonMax;
    double inPersonTime = 0.0;
    double onPhoneMax;
    double onPhoneTime = 0.0;

    //Have user determine the maximum possible value for the three variables
    //decribed above.
    cout << "How long should the maximum time be for the customer service ";
    cout << "rep to answer questions (in seconds)? ";
    cin >> answerQuestionMax;
    answerQuestionMax += 0.0;

    cout << "How long should the maximum time be for a customer to enter ";
    cout << "the office in person (in seconds)? ";
    cin >> inPersonMax;
    inPersonMax += 0.0;

    cout << "How long should the maximum time be for a custormer to call ";
    cout << "the service rep on the phone (in seconds)? ";
    cin >> onPhoneMax;
    inPersonMax += 0.0;

    //Initial randomization of those variables.
    inPersonTime = (inPersonMax * ((float) rand())/RAND_MAX);
    onPhoneTime = (onPhoneMax * ((float) rand())/RAND_MAX);

    //Initialize the main dequeue
    Dequeue dequeue;
    //The amount of time devoted to answering a question
    double timeItTook;
    //How much time has elapsed since the start of the simulation
    double elapsed = 0.0;
    //How many clients total
    int clientCount = 0;
    //Which client is currently being helped
    int currentClient = 0;

    cout << endl << endl << "PLease press any key followed by enter to ";
    cout << "run the simulation. ";

    string userinput;
    cin >> userinput;
    cout << endl << endl;

    cout << "Customer Service Representative arrives at work and sits down ";
    cout << "in his chair to start the workday." << endl;

    while (true) {
        //If, according to the randomized variables wither inPersonTime
        //carrying the lowest value, an individual entering the office occurs
        //next.
        if ((inPersonTime < onPhoneTime) &&
            ((dequeue.getSize() == 0) || (inPersonTime < 
             (dequeue.getNextInLine()->getTime())))) {
            if (elapsed + inPersonTime >= 10.0) {
                break;
            }

            clientCount += 1;

            //Move clock forward to this event.
            elapsed += inPersonTime;
            //Subtract amount of time that's passed since last event from time
            //variables for next phone call and next question answered. We do
            //this to produce the amount of time now remaining for these
            //events to occur.
            onPhoneTime -= inPersonTime;
            if (dequeue.getSize() > 1) {
                dequeue.getNextInLine()->
                setTime(dequeue.getNextInLine()->getTime() - inPersonTime);
            }

            //Add client to dequeue
            Node* nodePointer = new Node(answerQuestionTime, clientCount);
            dequeue.addPerson(nodePointer);

            cout << "Client " << clientCount << " has entered the office at ";
            cout << elapsed << " seconds. " << "There are now ";
            if (dequeue.getSize() == 1) {
                cout << "1 person ";
            }
            else {
                cout << dequeue.getSize() << " people ";
            }
            cout << "waiting in line." << endl;
            

            //Generate new random value for next time someone walks into the
            //office.
            inPersonTime = (inPersonMax * ((float) rand())/RAND_MAX);
            //Generate new random value for the amount of time its going to
            //take for the next client to have their quesiton answered.
            answerQuestionTime = (answerQuestionMax * ((float) rand())/RAND_MAX);
        }
        //if someone calling on the phone occurs next.
        else if ((onPhoneTime < inPersonTime) &&
            ((dequeue.getSize() == 0) ||
            (onPhoneTime < (dequeue.getNextInLine()->getTime())))) {
            if (elapsed + onPhoneTime >= 10.0) {
                break;
            }

            clientCount += 1;

            //move clock forward
            elapsed += onPhoneTime;

            //Subtract amount of time passed for other two variables to
            //produce time remaining for those respective events.
            inPersonTime -= onPhoneTime;
            if (dequeue.getSize() > 1) {
                dequeue.getNextInLine()->
                setTime(dequeue.getNextInLine()->getTime() - onPhoneTime);
            }

            //Add client to dequeue
            Node* nodePointer = new Node(answerQuestionTime, clientCount);
            dequeue.addCall(nodePointer);

            cout << "Client " << clientCount << " has called on the phone at ";
            cout << elapsed << " seconds. There ";
            if (dequeue.getSize() == 1) {
                cout << "is now 1 person";
            }
            else {
                cout << "are now " << dequeue.getSize() << " people";
            }
            cout << " waiting in line." << endl;

            //Generate new random variable for amount of time until next phone
            //call
            onPhoneTime = (onPhoneMax * ((float) rand())/RAND_MAX);
            //Generate new random variable for amount of time it takes for the
            //next client to have their quesiton answered.
            answerQuestionTime =
            (answerQuestionMax * ((float) rand())/RAND_MAX);
        }
        //if the next person in line (regardless of on phone or in person) has
        //question answered next.
        else {
            if (elapsed + dequeue.getNextInLine()->getTime() >= 10.0) {
                break;
            }

            currentClient = dequeue.getNextInLine()->getClientNumber();
            timeItTook = dequeue.getNextInLine()->getTime();

            //move clock forward
            elapsed += timeItTook;
            //subtract amount of time from other two time variables to produce
            //time remaining for those events
            inPersonTime -= timeItTook;
            onPhoneTime -= timeItTook;

            //Remove client from dequeue
            dequeue.remove();

            cout << "Client " << currentClient << " has had their question ";
            cout << "answered at " << elapsed << " seconds. There ";
            if (dequeue.getSize() == 1) {
                cout << "is now 1 person";
            }
            else {
                cout << "are now " << dequeue.getSize() << " people";
            }
            cout << " waiting in line." << endl;
        }
    }

    cout << "Workday ends. Representative goes home." << endl << endl;

    return 0;
}