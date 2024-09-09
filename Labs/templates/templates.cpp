#include <iostream>

/* FUNCTION TEMPLATE */
template<typename T>
void print(T value){
    std::cout << value << std::endl;
    std::cout << sizeof(T) << std::endl;
}

template<class T> // not created ever if it isn't called
void printButWithClassTemp(T value){
    std::cout << value << std::endl;
    std::cout << sizeof(T) << std::endl;

}

/* CLASS TEMPLATE */
template<typename T, int N>
class Array{
private:
    T arr[N];
public:
    int getSize() const {
        return N;
    }
};

int main(){
  
    Array<int, 67> arr; // nore the syntax of the class declration
    print(arr.getSize());
    print("ali");
    print<char>('a');
    printButWithClassTemp(2.4);
}