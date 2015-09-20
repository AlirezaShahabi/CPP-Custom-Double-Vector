
#include "DoubleVector.h"
#include <stdexcept>   // out_of_range()


// constructors:
// construct from initializer_list
DoubleVector::DoubleVector(const std::initializer_list<double>& il) :
                           pd(new double[il.size()]),nSize(il.size()){
    std::copy(il.begin(), il.end(), pd);
}
// construct from vector
DoubleVector::DoubleVector(const std::vector<double>& v) :
                           pd(new double[v.size()]), nSize(v.size()) {
    std::copy(v.begin(),  v.end(),  pd);
}
// simple construct
DoubleVector::DoubleVector(std::size_t n) : pd(new double[n]),nSize(n) {}
DoubleVector::DoubleVector() : pd(new double[0]),nSize(0) {}

// copy constructor
DoubleVector::DoubleVector(const DoubleVector& obj):
                           pd(new double[obj.nSize]),nSize(obj.nSize){
    std::copy(obj.pd, obj.pd+obj.nSize, pd);
    std::cout << "copy constructor" << std::endl;
}

// copy assignment operator
DoubleVector& DoubleVector::operator=(const DoubleVector& obj){
    auto new_pd = new double[obj.nSize];
    for (std::size_t i=0; i<obj.nSize; ++i) {new_pd[i] = obj.pd[i];}
    delete[] pd;
    pd    = new_pd;
    nSize = obj.nSize;
    std::cout << "copy assignment" << std::endl;
    return *this;
}

// move constructor
DoubleVector::DoubleVector(DoubleVector&& obj) noexcept: pd(obj.pd),nSize(obj.nSize){
    obj.pd    = 0;
    obj.nSize = 0;
    std::cout << "move constructor" << std::endl;
}

// move assignment operator (use swap)
DoubleVector& DoubleVector::operator=(DoubleVector&& obj) noexcept{
    swap(*this,obj);
    std::cout << "move assignment" << std::endl;
    return *this;
}

// destructor
DoubleVector::~DoubleVector() {delete[] pd;}

// returns size
std::size_t DoubleVector::Size() const {return nSize;}

// random access
double& DoubleVector::operator[](std::size_t i){
    check(i, "index out of range!");
    return pd[i];
}
double DoubleVector::operator[](std::size_t i) const{
    check(i, "index out of range!");
    return pd[i];
}


// private member function
void DoubleVector::check(std::size_t x, std::string msg) const{
    if (x > nSize-1) {throw std::out_of_range(msg);}
}


