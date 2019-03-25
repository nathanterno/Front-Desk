Nathan Moliterno
1/29/19 17:04

The Purpose of this program is to simulate a typical workday of an office
clerk.
Over the course of the day, three different events can occur:
	1. An new client will enter the office
	2. A new client will call the clerk on the office phone
	3. The clerk will answer a clients query
Every client that enters the office or calls on the phone has a query to be
answered by the clerk. Considering more than one individual can have a query
for the clerk to anwer, the clients must form a line and wait until it is their
turn at the front to have the question answered. This line makes up a
combination of both the clients that are there in the office, as well as those
that are on the phone. When a client enters the office, they are added to the
end of the line. When a new client calls on the phone, whoever's question is
currently being answered is interrupted, that caller is added to the front of
the line, and that caller's query immediately begins to be answered by the
clerk.

The amout of time it takes for each of the three possible events to occur is
randomly determined. This value for each event variable is between 0 and a
double (non-integer) value to be determined by the user. The program then
compares the times set for each variable, finds which event is to occur first,
executes that event, and advances the clock of the simulation forward according
to that interval of time. A new value is then generated randomly again for the
next time that same type of event is to occur (still between 0 and the
predetermined max). Additionally, the time values for the other two of the
three event types is also subtracted by the amount of time that just passed.

At the start of the program, there aren't any clients. Therefore, there isn't
any question to answer yet. So at this point, the program then only compares
the time value for when the first client enters the office with when the first
phone call occurs. Whichever event occurs first, program then assigns the time
value for answering a query to that specific client. That client is then first
in line, and their question begins to be answered. A new value for answering a
query is randomly generated, which will be assigned to the next client that
either comes in the door or calls.

IMPORTANT: From then on, when the program determines which of the three events
occurs next, it compares when either a client entering the office or a call
with the remaining time left for the first client in line's query - not
necessarily the most recently generated value for the time it takes to answer
a query.

Example: The clerks day begins at 0 seconds. The time value for when a client
enters the office is set to 1.4 seconds, the time value for when a client
calls is 0.4 seconds, and the time value for when a query is answered is 0.7
seconds. Therefore:
	1. A call from a new client (client 1) is determined to occur first
	2. The clock is advanced .04 seconds.
	3. Client 1 then gets assigned the time value of 0.7 for how long it
	takes their question to be answered.
	4. Client 1's question begins to be answered.
	5. A value for when the next call will occur is generated to be 1.6
	seconds.
	6. A value for how long it will take for the next client's query to
	be answered is generated to be 0.3 seconds.
	7. Client 1's question being answered is determined to occur next
	(0.7 + 0.4 = 1.1; 1.1 < 1.4 and 1.1< 1.6).
	8. The clock is advanced to 1.1 seconds, where client 1's question
	is answered.
	9. The program determines that a new client (client 2) will enter the
	office.
	10.The Clock is advanced to 1.4 seconds.
	11.Client 2 gets assigned the time value of 0.3 for how long it takes
	their question to be answered.
	etc...

Note: If the intial time determined for answering a query is lower than the
time values for receiving a new client, the value for answering a query is
ignored and a new client is received by the clerk first (whether that be in
person or over the phone).

How To Run: On the command line, under the directory where this program is
located, type "make" and then hit enter. Then type "./FrontDesk" and hit enter
again.

Bug: When the user is prompted to enter the three initial values, if the
user's input is non-numerical, the simulation will run in a wildly
unexpected manner.

Cited Sources: https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9
	Under the section titled: "Declare a pointer while assigning its
	address a value", I used the information there to remind myself how
	to create a new pointer.
