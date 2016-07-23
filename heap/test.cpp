/*************************************************************
   Test Program for Basic Heap Class - Preliminiary Version.
**************************************************************/
#include <iostream>
#include "Heap.h"
using namespace std;

void heapTest();
 
int main(){
      heapTest();
      return 0;
}

void Show( Heap & H, string s ){
      cout << s << ".capacity=" << H.capacity() << endl;
      cout << s << ".size=" << H.size() << endl;
      cout << s << "=" ; H.display(); cout << endl;
      cout << "-----------------------\n";
} 
 
void heapTest(){

      // Test default constructor and basic functions 
      Heap H;
      Show( H, "H" );
 
      H.insert(7);
      H.insert(1);
      H.insert(3);
      H.insert(13);
      H.insert(11);
      H.insert(4);

      Show( H, "H" );
 
      cout << "Empty it: ";
      while(!H.empty()) cout << H.extract_min() << "; " ;
      cout << endl;

      Show( H, "H" );

}

