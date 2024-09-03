#include <iostream>
#include <memory>
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

void printSmartPointers(){
    Resource* ptr1; 
    // ptr1 is uninitialized, so it's unsafe to dereference or use it directly.
    cout << "ptr1 is uninitialized and cannot be dereferenced." << endl;

    Resource* ptr2 = new Resource(42); 
    cout << "ptr2 data: " << ptr2->getData() << endl;

    unique_ptr<Resource> unique_ptr1(new Resource(42));
    cout << "unique_ptr1 data: " << unique_ptr1->getData() << endl;

    unique_ptr<Resource> unique_ptr2 = make_unique<Resource>(88);
    cout << "unique_ptr2 data: " << unique_ptr2->getData() << endl;

    auto unique_ptr3 = make_unique<Resource>(89);
    cout << "unique_ptr3 data: " << unique_ptr3->getData() << endl;
    
    shared_ptr<Resource> shared_ptr1(new Resource(91));
    cout << "shared_ptr1 data (before move): " << shared_ptr1->getData() << endl;

    shared_ptr<Resource> shared_ptr2 = make_shared<Resource>(91);
    cout << "shared_ptr2 data: " << shared_ptr2->getData() << endl;

    auto shared_ptr3 = make_shared<Resource>(92);
    cout << "shared_ptr3 data: " << shared_ptr3->getData() << endl;
    
    weak_ptr<Resource> weak_ptr1 = shared_ptr1;
    cout << "weak_ptr1 data expected 91: " << weak_ptr1.lock()->getData() << endl;
    /*Directly dereferencing or printing the result of *weak_ptr1.lock() can be problematic;
     use member functions like getData() to retrieve the value properly.*/


    weak_ptr<Resource> weak_ptr2 = make_shared<Resource>(4);
    if (auto locked_ptr = weak_ptr2.lock()) {
        cout << "weak_ptr2 data (before expiration): " << locked_ptr->getData() << endl;
    } else {
        cout << "weak_ptr2 is expired." << endl;
    }

    // Move ownership from unique_ptr1 to shared_ptr1
    shared_ptr1 = move(unique_ptr1);
    if (shared_ptr1) {
        cout << "shared_ptr1 data (after move from unique_ptr1): " << shared_ptr1->getData() << endl;
    } else {
        cout << "shared_ptr1 is null after move." << endl;
    }

    // Lock weak_ptr1 and assign it to shared_ptr1
    shared_ptr1 = weak_ptr1.lock();
    if (shared_ptr1) {
        cout << "shared_ptr1 data (after locking weak_ptr1): " << shared_ptr1->getData() << endl;
    } else {
        cout << "shared_ptr1 is null after locking weak_ptr1 (weak_ptr1 may be expired)." << endl;
    }

    weak_ptr1 = shared_ptr1; // Re-assigning weak_ptr1 to observe shared_ptr1
    weak_ptr1 = weak_ptr2;   // Re-assigning weak_ptr1 to observe weak_ptr2
    if (auto locked_ptr = weak_ptr1.lock()) {
        cout << "weak_ptr1 data (after re-assignment to weak_ptr2): " << locked_ptr->getData() << endl;
    } else {
        cout << "weak_ptr1 is expired after re-assignment." << endl;
    }

    // Cleaning up the raw pointer
    delete ptr2;
}


void demonstrateSmartPointers(){
    Resource* ptr1; // it's null by default so you can not derefrence it before assignment
    
    /*If an exception is thrown after new data_type(42) but before
     the ptr is fully constructed 
     (e.g., during copy/move operations or if there’s a bug in the constructor),
     the memory allocated by new will not be properly managed,
     leading to a potential memory leak.(the allocated memory might not be cleaned)*/
    Resource* ptr2 = new Resource(42); // this also need to be cleaned from memory
    unique_ptr<Resource> unique_ptr1(new Resource(42));

    /* Make_unique<data_type>(42) does the memory allocation and the construction
        of the unique_ptr in a single, atomic step.
       
       This approach is exception-safe because if any exception occurs during this operation,
        the memory will still be properly managed and no leak will occur.*/
    unique_ptr<Resource> unique_ptr2 = make_unique<Resource>(88);
    /*When using make_unique or make_shared, you don’t need to repeat the type,
     as the type is automatically deduced from the function's arguments*/
    auto unique_ptr3 = make_unique<Resource>(89);
    
    /*When you use new with std::shared_ptr, there are typically two memory allocations:
         one for the object itself and 
         one for the control block 
         (which stores the reference count and other metadata).*/
    shared_ptr<Resource> shared_ptr1(new Resource(91));  
    /*make_shared optimizes this by combining the allocation of the object 
      and the control block into a single memory allocation. 
      This reduces the overhead associated with memory management.*/
    shared_ptr<Resource> shared_ptr2 = make_shared<Resource>(91);
    /*When using make_unique or make_shared, you don’t need to repeat the type,
     as the type is automatically deduced from the function's arguments*/
    auto shared_ptr3 = make_shared<Resource>(92);
    
    weak_ptr<Resource> weak_ptr1 = make_shared<Resource>(94);
    weak_ptr<Resource> weak_ptr2 = make_shared<Resource>(4);

    // INVALID! unique_ptr1 = shared_ptr1;

    // INVALID! shared_ptr1 = unique_ptr1;
    shared_ptr1 = move(unique_ptr1);

    // INVALID! shared_ptr1 = weak_ptr1;
    // INVALID! shared_ptr1 = move(weak_ptr1);
    /* This will create a new std::shared_ptr if 
       the object is still valid, or return a nullptr if the object has already been destroyed.*/
    shared_ptr1 = weak_ptr1.lock();

    weak_ptr1 = shared_ptr1;
    weak_ptr1 = weak_ptr2;
    /*After the object is deleted, all std::weak_ptrs that were observing this object become "expired."
      
      An expired std::weak_ptr no longer points to a valid object, 
      and calling lock() on it will return a std::shared_ptr that is nullptr.*/
    
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

    printSmartPointers();
}