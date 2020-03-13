#include <iostream>
#include <exception>

using namespace std;

class MyException {
public:
// const throw means this method cannot throw an exception (optimization for compiler)
// but if something throws exception, program will hang. So best practice is to leave
// out the 'const throw()' part.  But to overload the what() method, we will include it. 
    virtual const char* what() const throw() {
        return "Something bad happened!";
    }

};

class Test {
    public: 

    // adding the throw() means that this function will not throw
    // will result in runtime error 

    // adding throw(bad_alloc) means it can ONLY throw bad_alloc,
    // will result in runtime error
    /*
    void goesWrong() throw(){
        throw MyException();
    }
    */

    void goesWrong() throw(MyException){
        throw MyException();
    }
};


int main(){

    Test test;
    try{
        test.goesWrong();
    }catch(const MyException &e){
        cout << "Error: " << e.what() << endl;
    }


    cout << "Still running!\n";

    return 0;
}