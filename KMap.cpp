//
// Created by Laila Nasser ElKoussy 900160812 and Yousef Mohab Koura 900160083 on 3/2/18.
//

#include "KMap.h"
#include <iomanip>
#include <string>

KMap::KMap() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            map[i][j].value = 0;
}

KMap::~KMap() {

}

void KMap::Generate(string &a) {
    string temp = "";
    int preloc = 0;
    bool inte = true;
    unsigned long isize = a.length(); //size of the input

    for (int i = 0; i < isize; i++) {
        if ((a[i] == ',') || (i == isize - 1)) { // checks for commas or end of input
            for (int j = preloc; j < i; j++) //basically just goes from the last saved location (where the number
                temp += a[j];            //started) to right before the current comma and puts it all in temp
            if (i == isize - 1)
                temp += a[i];            //when it's the last position it skips the last one so it's added

            if (temp.length() > 1) //checking to see if got any periods or space characters
            {
                for (int r = 0; r < temp.length() && inte; r++) {
                    if ((temp[r] == '.') || (isspace(temp[r]))) {
                        inte = false;
                        temp.erase(r, 1);
                    }
                }
            }
            storage.push_back(stoi(temp)); //turns temp into an int and pushes it into storage
            temp = "";
            preloc = i + 1; //updates where the next number starts (after the comma by one)
        }
    }

    noOfOnes(); // updates numbers of ones based on the size of storage
	if(ones<8) process(); //checks if it's a tautology (no need to process if it is)
	else tautology();
}

void KMap::noOfOnes() {
    ones = storage.size();
}

void KMap::fill() {
    int index;

    for (auto element: storage) {
        index = getIndex(element);

        map[element % 2 != 0][index].value = 1;
        map[element % 2 != 0][index].decIndex = element;



    }

    cout << "\nThe K-Map looks like this: " << endl;
    printMap();
	cout << endl;
}

int KMap::getIndex(int &a) { //this is me taking the easy way out instead of using binary conversion lol
    switch (a) {
        case 0:
        case 1:
            return 0;
        case 2:
        case 3:
            return 1;
        case 6:
        case 7:
            return 2;
        default :
            return 3;

    }
}

void KMap::printMap() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(4) << map[i][j].value;
        cout << endl;
    }
}

KMap::Minterms::Minterms() {
     value = 0;
     noOfInclusions = 0;
 }

void KMap::extract() {
	KMap::Implicant temp;

	 for (int i = 0; i < 2; i++)
		 for (int j = 0; j < 4; j++) 
		 {
			 if (map[i][j].value == 1) { //the if statement that includes the minterm itself only
				 temp.mins.push_back(map[i][j].decIndex);
				 temp.size = 1;
				 imps.push_back(temp);
				 map[i][j].noOfInclusions++;

				 if (map[i][(j + 1) % 4].value == 1) { // checking if the one next to it is 1
					 temp.mins.push_back(map[i][(j + 1) % 4].decIndex);
					 temp.size = 2;
					 imps.push_back(temp);
					 map[i][j].noOfInclusions++;
					 map[i][(j + 1) % 4].noOfInclusions++;
					 temp.mins.pop_back();

				 }

				 if (ones > 3) 
				 {
					 if (j == 0) {
						 if ((map[i][1].value == 1) && (map[i][2].value == 1) && (map[i][3].value == 1)) { //handles line of 4s
							 for (int k = 1; k < 4; k++)
							 {
								 temp.mins.push_back(map[i][k].decIndex);
								 map[i][k].noOfInclusions++;
							 }

							 map[i][0].noOfInclusions++;
							 temp.size = 4;
							 imps.push_back(temp);

							 temp.mins.clear();
							 temp.mins.push_back(map[i][j].decIndex);
						 }

					 }
				 }


				 if (i == 0) 
				 {
					 if (map[1][j].value == 1) { // checking under
						 temp.mins.push_back(map[1][j].decIndex);
						 temp.size = 2;
						 imps.push_back(temp);
						 map[0][j].noOfInclusions++;
						 map[1][j].noOfInclusions++;

						 if (ones > 3) 
						 {
							 if ((map[0][(j + 1) % 4].value == 1) && (map[1][(j + 1) % 4].value == 1)) { // checking the square
								 temp.mins.push_back(map[0][(j + 1) % 4].decIndex);
								 temp.mins.push_back(map[1][(j + 1) % 4].decIndex);
								 map[0][j].noOfInclusions++;
								 map[1][j].noOfInclusions++;
								 map[0][(j + 1) % 4].noOfInclusions++;
								 map[1][(j + 1) % 4].noOfInclusions++;

								 temp.size = 4;

								 imps.push_back(temp);
							 }
						 }
					 }
				 }
			 }

			 temp.mins.clear(); //Clears the temporary k-map so its terms aren't added to the next one
			 temp.size = 0;
		 }
 }

bool KMap::useless (Implicant & a) {
	int index;
	for (auto element : a.mins) //for each element in min
	{
		index = getIndex (element);

        if (map[element % 2 != 0][index].noOfInclusions == 1) //if it contains a minterms with only one inclusion then it isn't useless
            return false;


	}

	return true;
}

void KMap::simplify() {
// when called, imps is already ordered from biggest size to smallest (job done by order, called by process)
    int index, size = imps.size();
    for (int i = 0 ; i< size ; i++) {
        if (useless(imps.back())) {

            for (auto element : imps.back().mins) { //before deleting the implicant, we decrease the number of inclusions for each one of its minterms
                index = getIndex(element);
                map[element % 2 != 0][index].noOfInclusions--;

            }
        }

        else
            primeImps.push_back(imps.back());

        imps.pop_back(); //deletes the implicant
    }

	cout << "The simplified version contains " << primeImps.size() << " essential prime implicant(s)." << endl << endl;
    for (int i = 0; i<primeImps.size(); i++){
		cout<<"Implicant #"<<i+1<<endl
            <<"\tincludes: ";
            for (auto element : primeImps[i].mins){
                cout<<element<<" ";
            }

            cout<<endl;

    }
	cout << "\nThe reduced boolean expression is: ";
	for (int i = 0; i < primeImps.size(); i++)
	{
		translate(primeImps[i]);
		cout << primeImps[i].name;
		if (i != primeImps.size() - 1)cout << " + ";
	}
	cout << endl;
}

void KMap::process() {
    fill();
    extract();
    order();
    simplify();
}

void KMap::tautology()
{
	fill();
	cout << "This k-map represents a tautology (always true), F = 1." << endl;
}

string KMap::decToBin(int n)
{
	string binS;
	int r, p = 1, binI = 0;
	while (n > 0)
	{
		r = n % 2;
		binI += r*p;
		n /= 2;
		p *= 10;
	}

	binS = to_string(binI);

	while (binS.size() < 3) // add 0's at the beginning of the bitstring to make sure it's a 3-bit string
	{
		binS = '0' + binS;
	}
	return binS;
}

void KMap::order() {
    bool swapped;
    Implicant temp;
	do {
		swapped = false;
		 for (int i = 0; i<imps.size()-1 ; i++)
			if (imps[i].size < imps[i+1].size){
				temp = imps[i];
				imps[i] = imps[i+1];
				imps[i+1] = temp;
				swapped = true;

		}
	} while (swapped);
}

void KMap::translate(Implicant &imp)
{
	vector<string> minBits;
	string exp;
	bool equivalent = true;
	int trackloc = 0;

	for (int i = 0; i < imp.mins.size(); i++) //fills vector with the bit equivalents of all included minterms
		minBits.push_back(decToBin(imp.mins[i]));

	for (int j = 0; j < 3; j++) //handles the jth bit of all minterms simultaneously
	{
		for (int k = 0; k < minBits.size() - 1 && (equivalent == true); k++) //checks to see if the jth bit is the same for all minterms (if not, then the jth literal is excluded)
		{
			if (minBits[k].at(j) != minBits[k + 1].at(j)) equivalent = false;
		}

		if (equivalent) //if the jth variable is found to be equivalent, the jth literal is add (as is or complemented based on whether it's a 0 or a 1)
		{
			if (minBits[0].at(j) == '1') exp+= char(int('A') + j);
			else
			{
				string temp = "";
				temp += char('A' + j);
				temp += '\'';
				exp += temp;
				trackloc++;
			}
		}
		equivalent = true;
	}
	
	imp.name = exp; //updates the implicants name to hold its expression (product)
}
