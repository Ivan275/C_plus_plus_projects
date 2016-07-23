#include <iostream>
#include "ATM.h"
#include "Customer.h"
using namespace std;

int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int C);
void processing(){

}

int main () {
    // TO DO:: Rename these
    int M,N,C;
    int *atime_list, *ttime_list;

    // Total wait time for all customers in the simulation.
    int total_wait_time = 0;

    // Input code to read simulation parameters
    int param_err = getSimParameters(M, N, C, atime_list, ttime_list);
    if (param_err) {
        cerr << "Error in simulation parameters." << endl;
        return -1;
    }

    int min = 0;
    int remainingCustomer = C;// customers
    int smallest;
    ATM *atm = new ATM[N];// make a ATM type array.
    Customer* currentCustomer;
    while(min < M && remainingCustomer != 0)
    {
        for(int i = 0; i < C; i++)
        {//check each customer
            if (atime_list[i] == min)
            {//check arrival time
                smallest = 0;
                int minimumAtm = atm[0].atmQueue->getSize();//assign customer to shortest queue
                for( int j = 1; j < N ; j++)
                {//loop each another ATM
                    if (atm[j].atmQueue->getSize()< minimumAtm)
                    {
                        minimumAtm = atm[j].atmQueue->getSize();//find the position of shorstest ATM
                        smallest = j;// find the minimun
                    }
                }
                currentCustomer = new Customer(ttime_list[i],atime_list[i]);// assign all value to customers
                atm[smallest].atmQueue->add(currentCustomer);// add a customer to shortest atm queue.
            }
        }
        for (int a = 0; a < N; a++)
        {
            atm[a].processCustomer(min);//process each ATM
        }
        min ++;// increment the time by 1.
        remainingCustomer--;// decrement customer by 1
    }

    for(int d = 0; d < N; d++)
    {
        total_wait_time = total_wait_time + atm[d].getWaitingTime();// calculate the total waiting;

    }
    delete []atm;
    // Display statistics on the simulation.
    displaySimResults(total_wait_time, C);
    // Return total_wait_time, will be used by test script.
    return total_wait_time;
}




// Read the simulation parameters from standard input (cin).
// Parameters:
// M: minutes to run simulation
// N: number of ATMs
// C: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
//
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> M;
  // Check input validity.
  if (M < 1) {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }


  cout << "Enter the number of ATMs" << endl;
  cin >> N;
  // Check input validity.
  if (N < 1) {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> C;
  if (C < 1) {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [C];
  ttime_list = new int [C];

  // Read C customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<C; i++) {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= M) {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// C: total number of customers in simulation.
void displaySimResults(int wait, int C) {
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << C << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) C) << endl;
}
