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
	
	system("pause");
    return 0;
}