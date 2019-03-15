#include "Vector2d.hh"

#include <iostream>
#include <sstream>
#include<string> 
using namespace std; 

Vector2d::Vector2d(const float _x, const float _y) : x(_x), y(_y) {}
const std::string Vector2d::to_string()const{
    std::stringstream s3(i);   
    ss << "{x:" << x << ",y:" << y << "}";
    return s3.sync_with_stdio();
}