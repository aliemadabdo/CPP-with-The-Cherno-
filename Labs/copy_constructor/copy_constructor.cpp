/* 
Topics coverd:
    1- copy constructor
    2- arrow "->" operator 
    3- STL insights

*/
/*
Yes, you can write data types that are more optimized for specific use cases
 than those provided by the Standard Template Library (STL).
 However, the STL is designed to be general-purpose, 
 and its performance and flexibility usually cover a wide range of scenarios.
 But if your project has very specific needs or constraints, 
 such as strict memory requirements or faster execution for particular operations, 
 creating a custom data type can be beneficial.
*/
/* 
Problem: Shallow Copy in Copy Assignment (Student student2 = student1;):

When student2 is created as a copy of student1 (using the default copy constructor), 
the grades pointer in student2 will point to the same memory location as student1.
This results in both objects sharing the same dynamically allocated memory,
which leads to problems when one of them is destructed 
(because both objects try to delete the same memory).

Fix: You need to implement a deep copy to ensure that each object has its 
own copy of the grades array.
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Student{
private:
    int numOfSubs;
    int* grades;
    string name;


public:

    int arrow1, arrow2, arrow3;

    Student(string s, int num, int arr[]) : name(s), numOfSubs(num) {
        grades = new int[num];
        for (int i = 0; i < num; ++i) {
            grades[i] = arr[i];  // Copy array elements, not the pointer
        }
    } 

    /* Deep copy constructor */ // the copy is the first constructor
    Student(const Student& copy) : name(copy.name), numOfSubs(copy.numOfSubs) { 
        grades = new int[numOfSubs]; // all dynamic allocations must have new memory space
        for (int i = 0; i < numOfSubs; ++i) {
            grades[i] = copy.grades[i];  // Copy array elements, not the pointer
        }
    }



    int& operator[] (const unsigned int index){
        return grades[index];
    }

    /* CAN NOT OVERLOAD TWICE WITH SAME SIGNATURE */

    // char& operator[] (unsigned int i){
    //     return name[index];
    // }

    void printData(){
        cout << name << endl;
        // cout << numOfSubs << endl;
        for(auto i=0; i<numOfSubs; i++)
            cout << grades[i] << " ";
        
        cout << endl;

    }

    ~Student(){
        delete[] grades;
        // delete[] grades;
        // printData();
    }
};

int main(){
    int arr[] =  {10, 29, 22, 25};
    Student student1("ali", 4, arr);
    Student student2 = student1;

    cout << (int)&((Student*)nullptr)->arrow1 << endl ;
    cout << &((Student*)nullptr)->arrow2 << endl ;
    cout << &((Student*)0)->arrow3 << endl ;

    student1[2] = 30;

    student1.printData();
    student2.printData();
}
