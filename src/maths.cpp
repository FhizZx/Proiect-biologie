#include <maths.h>


float add(float x, float y) {
    return x+y;
}

float substract(float x, float y){
    return x-y;
}

float multiply(float x, float y){
    return x*y;
}

float divide(float x, float y){
    if (y != 0)
        return x/y;
    else {
        printf("Division by 0");
        return -1;
    }

}
float raise(float x, float y) {
    return pow(x, y);
}

float logarithm(float x, float y) {
    return log(x);
}

float sine(float x, float y) {
    return sin(x);
}

float cosine(float x, float y) {
    return cos(x);
}

float tangent(float x, float y) {
    return tan(x);
}

float sqroot(float x, float y) {
    return sqrt(x);
}
