#include<iostream>
#include<thread>
#include<future>
#include<algorithm>

using namespace std;

int fun()
{
    int x=0;
    ++x;
    cout<<"Thread ID:"<<this_thread::get_id()<<endl;
    return x;
}


int main()
{
    //promise<int> x;

    //future<int> f=x.get_future();

    cout<<"Main() ID:"<<this_thread::get_id()<<endl;
    future<int> f=async(launch::async,fun);  // thread is created & return value from fun() function is taken by future.In case of deferred thread not created.

    cout<<"\nx= "<<f.get();

//    t1.join();

}
