
#include "DoubleVector.h"


void disp(const DoubleVector& v){
    for (std::size_t i=0; i<v.Size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


int main(){
    
    DoubleVector vec1({10,20,30});
    disp(vec1);
    
    DoubleVector vec2(vec1);
    disp(vec2);
    
    DoubleVector vec3;
    vec3 = vec2;
    disp(vec3);
    
    DoubleVector vec4(5);
    DoubleVector vec5(std::move(vec4));
    vec5[2] = 7.7;
    disp(vec5);
    
    std::vector<double> dv{-10.1,-66,23.8,-30.5};
    DoubleVector vec6(dv);
    DoubleVector vec7;
    vec7 = std::move(vec6);
    disp(vec7);
    
    sort_vector(vec7);
    disp(vec7);
    
    return 0;
}

