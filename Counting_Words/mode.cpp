#include <iostream>
using namespace std;



// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//

int mode (int *arr, int n) {
    int count= 0;
    int *num = new int[n];// make a new array

    while(count < n){
        int total = 0;
        for(int i= 0; i<n; i++){
            if(arr[count]== arr[i]){//find the same number
                total ++;//calculate the total same number
            }

        }
        num[count] = total;//assign the total number into the array
        count++;
    }

    int max =0;
    int totall =0;
    for(int i = 0; i< n; i++){
        if(num[i]> max){
            max = num[i];//find the max number in the array
            totall = i;// the index of max number
        }
    }
    delete []num;
    return arr[totall];//return the friquently number

}



// Input is the number of elements, followed by that many integers.
// Return value is the mode of these integers.
int main (void) {
  // Read a set of elements into an array (as in lab 1).
  int n;
  int *arr;

  // Get the number of elements
  cout << "Enter the number of elements:" << endl;
  cin >> n;

  // Create array in dynamic memory.
  arr = new int[n];

  for (int i=0; i<n; i++) {
    cout << "Enter a number:" << endl;
    cin >> arr[i];
   }

  int m = mode(arr,n);

  cout << "The mode is " << m << endl;

  // Free up memory.  Note use of delete [], since this is an array.
  delete [] arr;

  return m;
}
