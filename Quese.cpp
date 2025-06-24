/***
 * @mainpage Documentation Circular Queue
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queue dengan pendekatan circular queue.
 * 
 * @section Operations
 * project ini memiliki beberapa operasi antara lain:
 * 1. insert
 * 2. delete
 * 3. display
 * 
 * @section Cara Penggunaan
 * 1.  en queue
 * 2.  de queue
 * 3. display 
 * 
 * @author profil
 * -nama: Raja Zhafar Akbar Rangkuty
 * -nim: 20240140123
 * - kelas: C
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright {raja.zhafar.ft24@mail.umy.ac.id} (c) 2025
 */
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queue
 */

class Queues{
private:
    int front;///<variabel private untuk menyimpan posisi depan dari queue
    int rear;///<variabel private untuk menyimpan posisi belakang dari queue
    int max = 5;////<variabel private untuk menyimpan ukuran maksimal dari queue   
    int queue_arr[5];////<variabel private untuk menyimpan elemen-elemen queue

public:
/***
 * @brief Construk a new queue object
 * set default queue number to -1
 * with front and rear at -1
 */
    Queues(){
        front = -1;
        rear = -1;
    }
    /**
     * @brief method untuk memasukkan elemen/data ke dalam queue
     * data dimaskkan dalam variable queue_array
     */

    void insert(){
        int num;///<variabel untuk menyimpan nilai
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
    /**
     * @brief method untuk menghapus elemen/data dari queue
     * data yang dihapus disimpan dalam variable queue_array
     */
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
    /**
     * @brief method untuk menampilkan elemen/data dari queue
     * data yang ditampilkan yang berada dalam variable queue_array
     */
    void display(){
        int front_position = front;///< variabel front_position untuk menandakan posisi elemen pertama pada variabel depan(front)
        int rear_position = rear;////< variabel rear_position untuk menandakan posisi elemen terakhir pada variabel belakang(rear)

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
/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int                   
 */

int main(){

    Queues q;///< objek untuk menggunakan member yang ada pada class Queues
    char ch;////< variabel untuk menyimpan pilihan pada menu yang diberikan

    while(true){
        try{
            cout << "\nmenu\n";
            cout << "1. implement insert operation\n";
            cout << "2. implement remove operation\n";
            cout << "3. display value\n";
            cout << "4. exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch(ch){
                case '1':
                    q.insert();
                    break;
                case '2':
                    q.remove();
                    break;
                case '3':
                    q.display();
                    break;
                case '4':
                    cout << "Exiting the program.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (exception &e){
            cout << "Check for the values entered.\n";
        }
    }
}
