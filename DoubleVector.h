
#include <algorithm>
#include <utility>
#include <initializer_list>
#include <vector>
#include <string>
#include <iostream>


class DoubleVector{

friend void swap(DoubleVector&, DoubleVector&);
friend void sort_vector(DoubleVector&);

public:
    // constructors:
    // construct from initializer_list
    DoubleVector(const std::initializer_list<double>&);
    // construct from vector
    DoubleVector(const std::vector<double>&);
    // simple construct
    DoubleVector(std::size_t);
    DoubleVector();
    
    // copy constructor
    DoubleVector(const DoubleVector&);
    
    // copy assignment operator
    DoubleVector& operator=(const DoubleVector&);
    
    // move constructor
    DoubleVector(DoubleVector&&) noexcept;
    
    // move assignment operator
    DoubleVector& operator=(DoubleVector&&) noexcept;
    
    // destructor
    ~DoubleVector();
    
    // returns size
    std::size_t Size() const;
    
    // random access
    double& operator[](std::size_t);
    double  operator[](std::size_t) const;
    
private:
    double* pd;
    std::size_t nSize;
    void check(std::size_t, std::string) const;
};



// friend functions

inline void swap(DoubleVector& lhs, DoubleVector& rhs){
    using std::swap;
    swap(lhs.pd, rhs.pd);
    swap(lhs.nSize, rhs.nSize);
}

inline void sort_vector(DoubleVector& obj){
    std::sort(obj.pd, obj.pd+obj.nSize);
}
