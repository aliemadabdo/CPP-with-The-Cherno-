#include <iostream>

#include <stdbool.h>

using namespace std;

class Resource{

private:
    int* data;

public:

    /*This approach is more practical as it encapsulates the memory management within the class,
      where the class manages its resources internally.

      Implicit conversion from int to Resource.
    */
    Resource() : data(new int(0)) {} // Default parametraized constructor
    Resource(int value) : data(new int(value)) {}

    /* Explicit conversion from float to int then implicit conversion from int to Resource.
     as only one implicit conversion could happen 
    
    The use of explicit prevents unintended implicit conversions, making it safer

    use case: dealing with floating point numbers
    */
    explicit Resource(float value) : data(new int(static_cast<int>(value))) {}
    
    // operator overloading
    Resource operator+ (const Resource& obj) const {
        return Resource(*this->data + *obj.data);
    }

    int getData() const {
        return *this->data;
    }
    // resource2 is passed by reference
    bool greaterThan(Resource &obj) const {
        return *this->data > *obj.data? true : false;
    }

    void printData() const {
        cout << "\ndata = " << *this->data;
    }

    /* free the allocated resources internally when the life time or the scope of the object end*/
    ~Resource(){
        cout << "\nObject with data(" << *data << ") deleted";
        delete data;
    }

    // friend: This declares the << operator as a friend of the Resource class,
    // allowing it to access private members like data.
    friend ostream& operator << (ostream& os, const Resource& obj);

};

ostream& operator << (ostream& os, const Resource& obj){
    
    /* If you try to call a non-const member function on a const object,
       the compiler will generate an error because the function might modify
       the object's state, which is not allowed for const objects.*/
    os << obj.getData(); 

    os << *obj.data; // The stream object is just like a buffer 
                     // so we will get same value printed twice
    return os;
}

int main(){
    Resource resource1(10.4f), resource2(-5);

    // resource2 is passed by reference
    cout << "\nr1 > r2?" << resource1.greaterThan(resource2); 


    // call the destructor with scope and life time end
    {
        Resource sum = resource1 + resource2;  
        sum.printData();
    }
    cout << "\nScope end";
    cout << "\nObj r1: " << resource1;
    cout << "\nObj r2: " << resource2;

}