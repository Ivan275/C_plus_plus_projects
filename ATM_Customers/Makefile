all: atm_sim

atm_sim: atm_sim.o Node.o ATM.o ATMQueue.o Customer.o
	g++ -o atm_sim atm_sim.o Node.o ATM.o ATMQueue.o Customer.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes all classes can depend on each other, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.
atm_sim.o: atm_sim.cpp Node.h ATM.h ATMQueue.h Customer.h
	g++ -c atm_sim.cpp

Node.o: Node.cpp Node.h ATM.h ATMQueue.h Customer.h
	g++ -c Node.cpp

ATM.o: ATM.cpp ATM.h Node.h ATMQueue.h Customer.h
	g++ -c ATM.cpp

ATMQueue.o: ATMQueue.cpp ATMQueue.h Node.h ATM.h Customer.h
	g++ -c ATMQueue.cpp

Customer.o: Customer.cpp Customer.h Node.h ATM.h ATMQueue.h
	g++ -c Customer.cpp

clean:
	rm -f atm_sim *.o
