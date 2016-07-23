#include <iostream>
#include <fstream>
using namespace std;


string* readWords(string fname, int & arrSz);
int writeArray(string fname, float *arr, int arrSz);
int  f6(string s);
int main (void) {
	int nwords;
	string wlfname = "wordlist";
	string outfname = "average_comps.txt";


	// This reads the words from wlfname.
	// nwords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wlfname,nwords);

	int total1 = 0;
	int total2 = 0;
	int max_length=0;
	for (int i=0; i<nwords; i++) {
	    total1 = total1 + words[i].length();// the total number of characters
        total2= total2 + f6(words[i]);// the total comparisons of the words
        while((int)words[i].length() > max_length){
            max_length = words[i].length(); //find the max of length
        }
	}

	float avg_length = (float)total1/nwords;// avearage of the number of characters
	float avg_comp = (float)total2/nwords;// the average of comprisons of the words
    cout << "the max length of word: "<< max_length<< endl;
	cout << "the average length of word: "<<avg_length<<endl;
	cout << "the total comparisons: "<<avg_comp <<endl;

    int length = 1;
	float *avg_comps;
	avg_comps = new float[max_length];

	 while((length<=max_length)) {//the length must be less than max length
	     float total3 = 0.0;
	     float c = 0.0;
	     for(int i= 0; i<nwords-1;i++){//check each words

            if((int)words[i].length()== length){//find the same length
                total3 = total3 +f6(words[i]);//total comparison of length i
                c++;
            }

	     }

        avg_comps[length-1]= (total3/c);//assign each comprison for each length from 1 to 24
        //cout<< "avg[i]:"<<avg_comps[length-1]<<endl;
        length ++;

	}
    for(int i = 0; i<max_length-1;i++){

       cout<< avg_comps[i]<<endl;//print each comparison for each length
    }

	// Print output to a file for plotting.
	writeArray(outfname,avg_comps,max_length);
	delete[] avg_comps;
    // Clean up memory and return.
	delete[] words;
	return 0;
}

int  f6(string s){//check one word comparisons
    int count = 0;
	int ln = s.length();//the length of the word
	for (int i = 0; i < ln - 1; ++i){
		if (s.at(i) >s.at(i+1) ){//comoparison between the letters
		  return i+1;
		}
		count++;
	}
	return count;//return the total comprisons of one word
	//return true;
}
// Writes the array arr to a file named fname.
// Returns 0 if successful, 1 otherwise.
int writeArray(string fname, float *arr, int arrSz) {
	ofstream out_stream;
	out_stream.open (fname.c_str());

	if (!out_stream.fail()) {
		for (int i=0; i<arrSz; i++) {
			out_stream << i << " " << arr[i] << endl;
		}
		out_stream.close();
		return 0;
	} else {
		cerr << "Error opening " << fname << endl;
		return 1;
	}
}



// Reads lines from a file named fname.
// Returns an array of strings, one per line of the file fname, the reference parameter arrSz contains the size
string* readWords(string fname, int & arrSz){
	string* result = NULL;
	string temp;
	arrSz = 0;

	// Create a file object and open the file
	ifstream in_stream;
	in_stream.open(fname.c_str());

	// Only process file if opening it is successful
	if (!in_stream.fail()) {
		// Find out how big the file is to make the result array
		// reads line into temp and moves to next line
		while (getline(in_stream,temp)) {
			arrSz++;
		}

		// Administrative stuff to refresh file
		in_stream.close();
		in_stream.clear();
		in_stream.open(fname.c_str());

		// Read file contents into result, now that size is known
		result = new string[arrSz]; //create results array
		for (int i=0; i < arrSz; i++){
			getline(in_stream,result[i]);
		}
		in_stream.close(); //don't forget to close file
	}else{
		cout << "... file not found ...";
	}
    return result;
}
