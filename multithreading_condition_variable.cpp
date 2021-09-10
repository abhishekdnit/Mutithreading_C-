#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>
using namespace std;

mutex m;
condition_variable cv;
int x=0;
void produce(char c,int i)
{
    x=i;

    lock_guard<mutex> lg(m);

    cout<<"Thread "<<c<<" entered\n";

    cv.notify_one();                                   //Note 1
}

void consume(char c)
{
    cout<<"Thread "<<c<<" entered initially \n";

    unique_lock<mutex> ul(m);                         //Note 2
    cv.wait(ul,[](){return (x==5)? true:false;} );    //Note 3

    cout<<"x = "<<x<<endl;
    cout<<"Thread "<<c<<" exit\n";
}
int main()
{

    thread t2(consume,'2');
    thread t1(produce,'1',5);

    t1.join();
    t2.join();
    //cout<<"x ="<<x;

}
