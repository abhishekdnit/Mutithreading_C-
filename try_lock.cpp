#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <mutex>
using namespace std;

mutex m;
int x=0;

void run()
{
   for(int i=0;i<100000;i++)
   {
   if(m.try_lock())
   {
    ++x;
    m.unlock();
   }
   }
}

int main()
{

    thread t1(run);
    thread t2(run);

    t1.join();
    t2.join();

    cout<<x<<endl;

}

