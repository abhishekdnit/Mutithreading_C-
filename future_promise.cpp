#include<iostream>
#include<thread>
#include<future>


using namespace std;

void fun(promise<int> &&y)
{
    int x=0;
    ++x;

    y.set_value(x);
}


int main()
{
    promise<int> x;

    future<int> f=x.get_future();

    thread t1(fun,move(x));

    cout<<"x= "<<f.get();

    t1.join();

}
