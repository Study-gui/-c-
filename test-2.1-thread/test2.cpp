 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

queue<int> q;
mutex m1;
condition_variable g_cv;
//生产者
void Producer()
{
	for (int i = 1; i < 10; i++)
	{
		unique_lock<mutex>lock(m1);
		q.push(i);
		g_cv.notify_one();
		cout << "Producer: " << i << endl;
		this_thread::sleep_for(chrono::microseconds(100));
	}
	
}


//消费者
void Consumer()
{
	while (1)
	{
		unique_lock<mutex>lock(m1);
		g_cv.wait(lock, []() {
			return !q.empty();
			});
		int value = q.front();
		
		q.pop();
		cout << "Consumer: " << value << endl;

	}
}


int main()
{
	thread t1(Producer);
	thread t2(Consumer);
	t2.join();
	t1.join();
	
	system("pause");
	return 0;
	
}