#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if((a>0 && b>0)&&(a+b<0)){throw std::overflow_error("AddOverflow");}
    if((a<0 && b<0)&&(a+b>0)){throw std::overflow_error("AddUnderflow");}
    return a+b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if((a>0 && b<0)&&(a-b<0)){throw std::overflow_error("SubOverflow");}
    if((a<0 && b>0)&&(a-b>0)){throw std::overflow_error("SubUnderflow");}
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if(a==0||b==0){return a*b;}
    if((a==INT_MIN && b==-1)||(a==-1 && b==INT_MIN))
    {
        throw std::overflow_error("MulOverflow");
    }
    if(a>0)
    {
        if(b>0 && a>INT_MAX/b){throw std::overflow_error("MulOverflow");}
        else if(b<0 && b<INT_MIN/a){throw std::overflow_error("MulUnderflow");}
    }
    else
    {
        if(b>0 && a<INT_MIN/b){throw std::overflow_error("MulUnderflow");}
        else if(b<0 && a<INT_MAX/b){throw std::overflow_error("MulOverflow");}
    }
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if(b==0){throw std::invalid_argument("Division by zero");}
    if(b==-1 && a==std::numeric_limits<int>::min())
    {
        throw std::overflow_error("DivOverflow");
    }
    return a/b;
}