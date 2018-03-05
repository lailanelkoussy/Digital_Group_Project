#include <iostream>
#include <string>
#include <vector>
#include "KMap.h"


using namespace std;

int main() {
    string input, temp="";
    KMap kmap;
    int preloc = 0;
    bool inte = true;
    bool accepted = true;
    unsigned long isize;
    vector<int> storage;

    cout<<"Please enter the minterms: ";
    do
    {
        getline(cin,input);
        cout<<input<<endl;
        isize = input.size();


        for (int i = 0; i<isize-1; i++){
            if (input[i] == '.')
            { accepted = false;
                cout<<"invalid input. Please re-enter: ";
                break; }

            else accepted = true;

                                        }

    } while (!accepted);

    kmap.inputEx(input);


/*
    for (int i = 0; i < isize; i++) {
        if ((input[i] == ',') || (i == isize - 1)) { // checks for commas or end of input
            for (int j = preloc; j < i; j++) //basically just goes from the last saved location (where the number
                temp += input[j];            //started) to right before the current comma and puts it all in temp
            if (i == isize - 1)
                temp += input[i];            //when it's the last position it skips the last one so I just add it lol
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
cout<<"The entered minterms are: ";

    for (auto element: storage)
        cout<<element<<endl;

        */


    return 0;
}