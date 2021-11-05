#include "complex.h"
#include <iostream>
// You will add function definitons to this file
// See TODOs in complex.h

//// things to be added for part 2 ////
// TODO: operator<<

std::ostream& operator<<(std::ostream& os, const Complex& c){
  os<< c.rel << " + " <<c.img <<"i"<<std::endl;
  return os;
}

//// things to be added for part 3 ////
// TODO: copy constructor

Complex::Complex(const Complex& rhs){
  rel = rhs.rel;
  img = rhs.img;
}

// TODO: assignment operator

void Complex::operator=(const Complex& rhs){
  rel = rhs.rel;
  img = rhs.img;
}

// TODO: add operator
Complex Complex::operator+(const Complex& rhs){
  Complex a(rel+rhs.rel,img + rhs.img);
  return a;
}  

// TODO: minus operator
Complex Complex::operator-(const Complex& rhs){
  Complex a(rel-rhs.rel,img - rhs.img);
  return a;
}

// TODO: times operator
Complex Complex::operator*(const Complex& rhs){
  float real = rel*rhs.rel - img*rhs.img;
  float imag = rel*rhs.img + img*rhs.rel;
  Complex a(real, imag);
  return a;
}

// TODO: times operator (float)
Complex Complex::operator*(const float& rhs){
  Complex a(rel*rhs,img*rhs);
  return a;
}

// TODO: divide operator
Complex Complex::operator/(const Complex& rhs){
  Complex a((rel*rhs.rel + img*rhs.img)/(rhs.rel*rhs.rel+img*rhs.img),(img*rhs.rel-rel*rhs.img)/(rhs.rel*rhs.rel+rhs.img*rhs.img));
  return a;
}

//// things to be added for part 4 ////
// TODO: times operator for float times complex


