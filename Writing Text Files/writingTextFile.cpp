#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    //output file object
    // ofstream outFile;
    string outputFileName = "text.txt";

    fstream outFile;

    outFile.open(outputFileName, ios::out);

    // check if file is open
    if(outFile.is_open()){
        // can write to file with insertion operator just like cout << 
        /*outFile << "Hello there" << endl;
        outFile << "poopy";
        outFile << 123 << endl;*/

        for(int i = 0; i < 10; i++){
            outFile << i + 1 << ": hello world!" << endl;
        }

        // remember to close the file object
        outFile.close();
    }
    else{
        cout << "Could not create file: " << outputFileName << endl;
    }


    return 0;
}