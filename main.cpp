#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input,temp="";
    vector <string> storage ;
    int preloc= 0;
    unsigned long size;

    cout<<"insert:";
    getline(cin,input);
    cout<<input<<endl;
    size = input.size();
    if (size>15)
        cout<<"Invalid input";



    for (int i = 0; i<size; i++)
    {
        if ((input[i] ==',')|| (i == size-1))
        {
            for (int j = preloc; j < i; j++)
                temp += input[j];
            if(i==size-1)
                temp+=input[i];
            cout<<temp<<endl;
            storage.push_back(temp);
            temp = "";
            preloc = i+1;

        }
    }
    cout<<"The minterms entered were: ";
    for (auto element:storage)
        cout<<element;



    return 0;
}