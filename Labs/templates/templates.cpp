#include <iostream>

struct Complex{
    float real;
    float imaginary;

    Complex(float x, float y) : real(x), imaginary(y) {}
};

/* FUNCTION TEMPLATE */
template<typename T>
void print(T value){
    std::cout << value << std::endl;
    std::cout << sizeof(T) << std::endl;
}

/* FUNCTION TEMPLATE Specialization  */
template<>
void print<Complex>(Complex value){
    std::cout << value.real << "+i" << value.imaginary << std::endl;
    std::cout << sizeof(Complex) << std::endl;
}


template<class T> // not created ever if it isn't called
void printButWithClassTemp(T value){
    std::cout << value << std::endl;
    std::cout << sizeof(T) << std::endl;

}


/* CLASS TEMPLATE Specialization */template<typename T, int N>
class Array{
private:
    T arr[N];
public:
    int getSize() const {
        return N;
    }
};

template<>
class Array<bool, 2>{
private:
    bool arr[2] = {true, false};
public:
    int getSize() const {
        std::cout << arr[0] << " | " << arr[1] << std::endl;
        return 2;
    }
};


int main(){
    
    Array<int, 67> arr; // nore the syntax of the class declration
    Array<bool, 2> spetialArr; // 
 
    print(arr.getSize());
    print(spetialArr.getSize());
    print("ali");
    print<char>('a');
    printButWithClassTemp(2.4);

    print(Complex(3, 4));
}