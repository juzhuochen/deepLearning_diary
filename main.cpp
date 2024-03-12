#include <vector>

#include <iostream>
#include <string>
#include <sstream>
template<typename T> int sign(T val){
    return (T(0)<val)-(val<T(0));
}

int main(){
    float x0=1.0f,x1=0.0f,x2=-1.0f;
    float w0=-5,w1=0.0f,w2=0.0f;
    float target = 1.0f;
    float learningRate=1.0f;
    float y=0.0f;
    float input=0.0f;
    float output=0.0f;
    std::ostringstream console;
    for (int i=0; i<100; ++i) {
        console<<"loop "<<i<<" w0: "<<w0<<" w1: "<<w1t<<" w2: "<<w2<<"\n";
        input= x0 * w0 + x1 * w1 + x2 * w2;
        output= sign(input);
        if ((target-output)>1e-5) {
        
        w0 += learningRate * (target - output) * x0;

        w1 += learningRate * (target - output) * x1;
        
        w2 += learningRate * (target - output) * x2;

        }
        else {
            console<<std::endl;
            break;
        }
    }
    std::cout<<console.str()<<std::endl;
}