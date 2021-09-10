#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

void threadfn(mutex & mtx)
{
    lock_guard<mutex> lock(mtx);
    cout<<"I locked the mutex...."<<endl;
    this_thread::sleep_for(chrono::seconds(5));

}


int main()
{
    mutex mtx;
    thread th {threadfn,ref(mtx)};
    this_thread::sleep_for(chrono::seconds(1));
    unique_lock<mutex> lock(mtx);
    cout<<"I am inside the Main Thread..."<<endl;
   // lock.unlock();
   // lock.lock();
    th.join();
    return 0;

}
