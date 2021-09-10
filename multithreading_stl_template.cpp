#include<iostream>
#include<thread>
#include<initializer_list>
#include<vector>


using namespace std;

//template<typename type>
void threadfn(initializer_list<int> il)
{
    cout<<"I am inside thread function"<<endl;
    cout<<"size of initializer list=> "<<il.size()<<endl;
    //cout<<this_thread::get_id()<<endl;
   // cout<<"Type is: "<<typeid(type).name()<<endl;
    //cout<<"v2=>"<<v2<<endl;

}

//By using lambda expression
/*int main()
{
    int localvalue=100;
    int value=200;
    thread t1{[&](){
    cout<<"I am inside thread function"<<endl;
    cout<<"localvalue=>"<<localvalue++<<endl;
    value++;
    }};

    t1.join();    //wait
    cout<<"localvalue=>"<<localvalue<<endl;
    cout<<"value=>"<<value<<endl;
    return 0;

}*/

//By Using thread function
int main()
{
    initializer_list<int> il={1,2,3,4};
    thread t1 {threadfn,il};
    //thread t1{threadfn<int>};
    //this_thread::sleep_for(chrono::milliseconds(1000));
    //thread t2{threadfn<float>};
    //cout<<this_thread::get_id()<<endl; //Thread ID

    t1.join();    //wait & join out thread with main thread
    //t2.join();
    return 0;

}

