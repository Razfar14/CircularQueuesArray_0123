#include <iostream>
using namespace std;

class Queues{
private:
    int front, rear, max = 5;
    int queue_arr[5];

public:

    Queues(){
        front = -1;
        rear = -1;
    }

    void insert(){
        int num;
        cout << "Enter a number :";
        cin >> num;
        cout << endl;

        // Check if the queue is full
        if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
            cout << "\nQueue is full\n";//1.a
            return;                     //1.b
        }

