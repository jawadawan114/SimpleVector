#include<iostream>
using namespace std;

class Vector {
public:
    int size;
    int capacity;
    int* arr;

    Vector(){
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    ~Vector() {
    delete[] arr;  // deletes the final array
    }


    void add(int ele){
        if (size == capacity){
            capacity *= 2;
            int* arr2 = new int[capacity];
            for (int i=0; i<size; i++ ){
                arr2[i] = arr[i];
            }
            delete[] arr; // deleting the old array
            arr = arr2;
        }
        arr[size++] = ele;
    }

    void print(){
        for (int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int get(int indx){
        if (size == 0){
            cout << "Array is empty" << endl;
            return -1;
        }
        if (indx >= size || indx < 0){
            cout << "Invalid Index " << endl;
            return -1;
        }
        return arr[indx];
    }

    void remove(){
        if (size == 0){
            cout << "Array is empty" << endl; 
            return;       
        }
        size--;
    }
};

int main(){
    Vector v;
    v.add(10); // adds 10 as first element
    v.add(5);  // adds 5 as 2nd element
    v.add(9); // adds 9 as 3rd element
    v.add(4); // add 4 as 4th element
    v.print(); // prints all elements
    cout << v.get(3) << endl; // prints specific element
    v.remove(); // removes last element
    return 0;
}

// g++ dynamicArrray.cpp -o dynamicArrray_program && dynamicArrray_program