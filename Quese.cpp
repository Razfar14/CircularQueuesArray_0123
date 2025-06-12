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
        // If the queue is empty,
        if (front == -1){
            front = 0; //2.a
            rear = 0;  //2.b 
        } 
        else { // if rear is at the end of the queue, GO back to the start
            if (rear == max - 1) {
                rear = 0; 
            }
            else {
                rear = rear + 1;
            }
        } 
        queue_arr[rear] = num; 
        
    }

    void remove(){
        //check if the queue is empty
        if (front == -1) {
            cout << "\nQueue underflow\n"; 
            return;                      
        }
        cout << "\nThe element deleted from the que is: " << queue_arr[front] << endl;

        //check if the queue has only one element
        if (front == rear) {
            front = -1; 
            rear = -1;  
        } 
        else { //if front is at the end of the queue, GO back to the start
            if (front == max - 1) {
                front = 0; 
            } 
            else {
                front = front + 1;
            }
        }
    }

    void display(){
        int front_position = front;
        int rear_position = rear;

        //check if the queue is empty
        if (front == -1) {
            cout << "\nQueue is empty\n";
            return;
        }
        cout << "\nThe elements in the queue are... \n";

        //if front_position <= rear_position, print from front to rear
        if (front_position <= rear_position){
            while (front_position <= rear_position) {
                cout << queue_arr[front_position] << " ";
                front_position++;
            }
            cout << endl;
        }
        else{
            //if front_position > rear_position, print from front to end 
            while (front_position <= max - 1) {
                cout << queue_arr[front_position] << " ";
                front_position++;
            }
            front_position = 0; 

            while (front_position <= rear_position) {
                cout << queue_arr[front_position] << " ";
                front_position++;
            }
            cout << endl;
        }
    }
};

