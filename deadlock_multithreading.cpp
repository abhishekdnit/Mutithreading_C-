#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>
using namespace std;

mutex m1,m2;

int x=0;
void produce(char c,int i)
{
//lock_guard<mutex> lock(m);
while(1)
{
 m1.lock();
 //this_thread::sleep_for(chrono::seconds(2));
 m2.lock();
 //cout<<"1 ="<<x;
 cout<<"Thread "<<c<<" entered\n";
 m1.unlock();
 m2.unlock();
}
}

void consume(char c,int i)
{
while(1)
{
 m2.lock();
 //this_thread::sleep_for(chrono::seconds(2));
 m1.lock();
 //cout<<"2 ="<<x;
 cout<<"Thread "<<c<<" entered\n";
 m2.unlock();
 m1.unlock();
}
}

int main()
{

    thread t1(produce,'1',50);
    thread t2(consume,'2',10);

    t1.join();
    t2.join();
    //cout<<"x ="<<x;

}
