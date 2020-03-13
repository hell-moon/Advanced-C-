#include <iostream>
using namespace std;

void goesWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected){
        throw bad_cast();
    }

    if(error2Detected){
        throw exception();
    }
}

int main(){

    try{
        goesWrong();
    }
    // will catch this exception block first, because of polymorphism.  
    // bad_cast is thrown first, but since it is a child of the exception class, 
    //
    catch(exception &e){
        cout << "catching exception:" << e.what() << endl;
    }
    catch(bad_cast &e){
        cout << "catching bad cast " << e.what() << endl;
    }
    
    

    return 0;
}