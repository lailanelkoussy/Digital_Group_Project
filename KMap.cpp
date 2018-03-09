//
// Created by Laila Nasser ElKoussy 900160812 on 3/2/18.
//

#include "KMap.h"
#include <vector>
#include <iomanip>

KMap::KMap() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            map[i][j].value = 0;


}

KMap::~KMap() {

}

void KMap::inputEx(string &a) {
    string temp = "";
    int preloc = 0;
    bool inte = true;
    unsigned long isize = a.length(); //size of the input


    for (int i = 0; i < isize; i++) {
        if ((a[i] == ',') || (i == isize - 1)) { // checks for commas or end of input
            for (int j = preloc; j < i; j++) //basically just goes from the last saved location (where the number
                temp += a[j];            //started) to right before the current comma and puts it all in temp
            if (i == isize - 1)
                temp += a[i];            //when it's the last position it skips the last one so I just add it lol
            cout << temp << endl;            //the random couts scattered are used for debugging

            if (temp.length() > 1) //checking to see if got any periods or spaces characters
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
	fill();
}

void KMap::noOfOnes() {
    ones = storage.size();
}

void KMap::fill() {
    int index;

    for (auto element: storage) {
        index = getIndex(element);
        if (element % 2 == 0) // all even minterms are in the first row
        {   map[0][index].value = 1;
            map[0][index].decIndex = element; }

        else {
            map[1][index].value = 1;
            map[1][index].decIndex = element;
        }

    }

    cout << "The K-Map looks like this: " << endl;
    printMap();

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
            for (int j = 0; j < 4; j++) {
                if (map[i][j].value == 1){ //the if statement that includes the minterm itself only
                    temp.mins.push_back(map[i][j]);
                    temp.size = 1;
                    imps.push_back(temp);
                    map[i][j].noOfInclusions++;

                    if (map[i][(j+1)%4].value == 1) { // checking if the one next to it is 1
                        temp.mins.push_back(map[i][(j+1)%4]);
                        temp.size = 2;
                        imps.push_back(temp);
                        map[i][j].noOfInclusions++;
                        map[i][(j+1)%4].noOfInclusions++;
                        temp.mins.pop_back();

                    }



                    if (j==0){
                        if ((map[i][1].value == 1) && (map[i][2].value == 1) && (map[i][3].value == 1)) { //handles line of 4s
                            for (int k =1; k<4; k++)
                            {   temp.mins.push_back(map[i][k]);
                                map[i][k].noOfInclusions++;}

                            map[i][0].noOfInclusions++;
                            temp.size = 4;
                            imps.push_back(temp);

                            temp.mins.clear();
                            temp.mins.push_back(map[i][j]);
                            }

                    }

                    if (i==0){
                        if (map[1][j].value == 1){ // checking under
                            temp.mins.push_back(map[1][j]);
                            temp.size = 2;
                            imps.push_back(temp);
                            map[0][j].noOfInclusions++;
                            map[1][j].noOfInclusions++;

                            if ((map[0][(j+1)%4].value == 1) && (map[1][(j+1)%4].value == 1)){ // checking the square
                                temp.mins.push_back(map[0][(j+1)%4]);
                                temp.mins.push_back(map[1][(j+1)%4]);
                                map[0][j].noOfInclusions++;
                                map[1][j].noOfInclusions++;
                                map[0][(j+1)%4].noOfInclusions++;
                                map[1][(j+1)%4].noOfInclusions++;

                                temp.size = 4;

                                imps.push_back(temp);


                            }



                        }

                    }
                }






            }


}