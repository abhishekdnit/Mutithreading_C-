#include<iostream>
#include<thread>

using namespace std;

void fun1(){
cout<<"You inside fun1..."<<endl;
}

int main()
{

    thread t1(fun1); //t1 thread running
    //using RAII
    // Wrapper w(t1);
      // int i=thread::hardware_concurrency();  // Tells No. of threads running concurrently
    try{
    for(int i=0;i<100;i++)
        cout<<"from main: "<<i<<endl;
    }catch(...){
    t1.join();
    throw;
    }
    //t1.join();
//    cout<<i;

    return 0;

}
