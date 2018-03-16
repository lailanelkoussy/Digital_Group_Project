//
// Created by Laila Nasser ElKoussy 900160812 and Yousef Mohab Koura 900160083 on 3/2/18.
//

#ifndef GROUP_PROJECT_KMAP_H
#define GROUP_PROJECT_KMAP_H

#include <iostream>
#include <vector>

using namespace std;
class KMap {
	public:
		 KMap();
		~KMap();
		void Generate(string &); //takes in string input, put values in storage vector as ints and counts number of
                            // ones and sets them. It also calls the rest of the functions that do the rest of the tasks. 
	private:
		//Structs
		struct Minterms {
        int value;
        int noOfInclusions;
        int decIndex;

        Minterms();

    };
		struct Implicant {
        string name; //its boolean expression (product)
        vector<int> mins;
        int size; //the number of ones inside of it

    };

		//Variables
		vector<int> storage; // storage vector for the minterms
		void noOfOnes ();
		int ones;
		Minterms map[2][4];
		vector<Implicant> imps; //vector containing all prime implicants
		vector <Implicant> primeImps; //vector containing all essential prime implicants
	
		//Functions
		void fill (); //takes the storage vector and fills the array with the values
		int getIndex (int&);
		void printMap();
		void extract(); //this function extracts all possible implicants from the KMap
		bool useless (Implicant &); //function that checks if an implicant is useless (all its minterms are contained in other implicants), if useless returns true
		void order (); //orders imps from biggest size to smallest
		void translate (Implicant &); //translates implicant into string equivalent
		void simplify();
		void process(); //gets called by Generate and then calls one function after the other
		void tautology(); //processes the k-map if it's all 1's
		string decToBin(int); //converts decimal number into its bit equivalent
};

#endif //GROUP_PROJECT_KMAP_H
