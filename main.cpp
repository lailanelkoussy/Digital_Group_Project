#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int preloc= 0, size, currloc;

    cout<<"insert:";
        cin>>input;
    size = input.size();
    if (size>15)
        cout<<"Invalid input";

    for (int i = 0; i<size; i++)
    { if (i==size-1){


        }
        if (input[i] ==',')
        { for (int j = 0; j< i - preloc; i++)
            {

            }
        }
    }





    return 0;
}