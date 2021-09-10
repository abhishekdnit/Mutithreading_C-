#include<iostream>
#include<thread>

using namespace std;

/*void threadfn(int &value)
{
    cout<<"I am inside thread function"<<endl;
    cout<<"value=>"<<value++<<endl;
    //cout<<"v2=>"<<v2<<endl;
}*/

//By using lambda expression
int main()
{
    int localvalue=100;
    int value=200;
    thread t1{[&](){
    cout<<"I am inside thread function"<<endl;
    cout<<"localvalue=>"<<localvalue++<<endl;
    value++;
    }};

    //t1.join();    //main thread wait for child thread to finish
    t1.detach(); // child thread detached from main thread & run independently--- daemon process
    cout<<"localvalue=>"<<localvalue<<endl;
    cout<<"value=>"<<value<<endl;
    if(t1.joinable())
    t1.join();
    return 0;

}

//By Using thread function
/*int main()
{
    int localvalue=100;
    thread t1{threadfn,ref(localvalue)};

    t1.join();    //wait
    cout<<"localvalue=>"<<localvalue<<endl;

    return 0;

}*/
