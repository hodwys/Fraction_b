#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Fraction.hpp"
namespace ariel{

// 240999
Fraction :: Fraction(int abc, int def){
    if(def == 0){
        throw std ::invalid_argument ("Division_by_0");
    }
    this-> Numerator = abc;
    this-> Denominator = def;
}

Fraction :: Fraction(float def){

}


//Fraction();

int Fraction::getNumerator() const{
    return this-> Numerator;
}

int Fraction:: getDenominator() const{
    return this-> Denominator;
}

void Fraction:: Set_Numerator(int num){
    this->Numerator = num;
}

void Fraction:: Set_Denominator(int den){
     if(den == 0){
        throw std :: invalid_argument("Division_by_0");
     }
    this->Denominator = den;
}


Fraction Fraction::operator+( const Fraction& other) const{

    Fraction temp(0,1); 
    int den = ((this->Denominator) * (other.Denominator));
    int num = ((this->Numerator * other.Denominator) + (this->Denominator * other.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;

}


Fraction Fraction:: operator-(const Fraction& other)const {
    Fraction temp(0,1); 
    int den = (this->Denominator * other.Denominator);
    int num = ((this->Numerator * other.Denominator) - (this->Denominator * other.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;
}

Fraction Fraction:: operator*(const Fraction& other)const{
    Fraction temp(0,1); 
    int den = (this->Denominator * other.Denominator);
    int num = (this->Numerator * other.Numerator);
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;
}

Fraction Fraction:: operator/( const Fraction& other) const{
    Fraction temp(0,1); 
    int den = this->Denominator * other.Numerator;
    int num = (this->Numerator * other.Denominator);
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;   
}
Fraction Fraction:: operator+(float jkl){
    Fraction temp(0,1); 
    Fraction floa(jkl*1000,1000);
    int den =  ((this->Denominator) * (floa.getDenominator()));
    int num = ((this->Numerator * floa.getDenominator()) + (this->Denominator * floa.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}

Fraction Fraction:: operator-(float jkl){
    Fraction temp(0,1); 
    Fraction floa(jkl*1000,1000);
    int den =  ((this->Denominator) * (floa.getDenominator()));
    int num = ((this->Numerator * floa.getDenominator()) - (this->Denominator * floa.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}

Fraction Fraction:: operator*(float jkl){
    Fraction temp(0,1); 
    Fraction floa(jkl*1000,1000);
    int den = (this->Denominator * floa.getDenominator());
    int num = (this->Numerator * floa.getNumerator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}


bool Fraction:: operator==(const Fraction& other){

    int gcd1 = std::__gcd(this->Denominator , (this->Numerator));
    this->Numerator =(this->Numerator / gcd1);
    this->Set_Denominator(this->Denominator/ gcd1);

    int gcd2 = std::__gcd(other.Denominator , (other.Numerator));
    other.Set_Numerator(other.Numerator / gcd2);
    other.Set_Denominator(other.Denominator/ gcd2);

    bool den = other.Denominator == this->Denominator;
    bool num = other.Numerator == this->Numerator;
    return den && num;
}

bool Fraction:: operator<(const Fraction& other)const {
 
   int other_den = other.Denominator;
   int  this_den = this->Denominator;

   other.Set_Denominator(other_den* this_den);
   this->Set_Denominator(other_den* this_den);

    int other_num = other.Numerator;
    int this_num = this->Numerator;

    other.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_les = (this->Numerator < other.Numerator);

    return this_les;
}


bool Fraction:: operator<(float other){
 
    Fraction temp(other*1000,1000); 
    int other_den = temp.getDenominator();
    int  this_den = this->Denominator;

    temp.Set_Denominator(other_den* this_den);
    this->Set_Denominator(other_den* this_den);

    int other_num = temp.getNumerator();
    int this_num = this->Numerator;

    temp.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_les = (this->Numerator < temp.getNumerator());

    return this_les;

}


bool Fraction:: operator>(const Fraction& other)const {
 
   int other_den = other.Denominator;
   int  this_den = this->Denominator;

   other.Set_Denominator(other_den* this_den);
   this->Set_Denominator(other_den* this_den);

    int other_num = other.Numerator;
    int this_num = this->Numerator;

    other.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_big = (this->Numerator > other.Numerator);

    return this_big;

}


bool Fraction:: operator>(float other){
 
    Fraction temp(other*1000,1000); 
    int other_den = temp.getDenominator();
    int  this_den = this->Denominator;

    temp.Set_Denominator(other_den* this_den);
    this->Set_Denominator(other_den* this_den);

    int other_num = temp.getNumerator();
    int this_num = this->Numerator;

    temp.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_big = (this->Numerator > temp.getNumerator());

    return this_big;

}

bool Fraction:: operator>=(Fraction& other){
     
   int other_den = other.getDenominator();
   int  this_den = this->Denominator;

   other.Set_Denominator(other_den* this_den);
   this->Set_Denominator(other_den* this_den);

    int other_num = other.getNumerator();
    int this_num = this->Numerator;

    other.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_bieq = (this->Numerator >= other.getNumerator());

    return this_bieq;

}

bool Fraction:: operator<=(Fraction& other){
 
   int other_den = other.getDenominator();
   int  this_den = this->Denominator;

   other.Set_Denominator(other_den* this_den);
   this->Set_Denominator(other_den* this_den);

    int other_num = other.getNumerator();
    int this_num = this->Numerator;

    other.Set_Numerator(other_num * this_den);
    this->Set_Numerator(this_num * other_den);

    bool this_leeq = (this->Numerator <= other.getNumerator());

    return this_leeq;
}

Fraction Fraction:: operator++(){ 
   // Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator + this->Denominator);
    Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

Fraction Fraction:: operator++(int abc){
    Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator + this->Denominator);
    //Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

Fraction Fraction:: operator--(){
    this->Set_Numerator(this->Numerator - this->Denominator);
    Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

Fraction Fraction:: operator--(int abc){
    Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator - this->Denominator);
    return temp;
}



// Fraction Fraction:: operator*(const float other){
//     return Fraction(1,2);
// }

Fraction operator+(float number, const Fraction& mno){ 
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    int den =  ((mno.Denominator) * (floa.getDenominator()));
    int num = ((mno.Numerator * floa.getDenominator()) + (mno.Denominator * floa.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}
Fraction operator-(float number, const Fraction& mno){
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    int den =  ((mno.Denominator) * (floa.getDenominator()));
    int num = ((mno.Numerator * floa.getDenominator()) - (mno.Denominator * floa.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}


Fraction operator*(float number, const Fraction& mno){
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    int den = (mno.Denominator * floa.getDenominator());
    int num = (mno.Numerator * floa.getNumerator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
}


Fraction operator/(float number, const Fraction& mno){
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    int den = mno.Denominator * floa.getNumerator();
    int num = (mno.Numerator * floa.getDenominator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;   
}


std::ostream& operator<< (std::ostream& output, const Fraction& ghi){
  output << ghi.Numerator << "/" << ghi.Denominator;
  return output;
}


// std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
//         output << fraction.numerator << "/" << fraction.denominator;
//         return output;



std::istream& operator>> (std::istream& input ,  Fraction& ghi){

    int num, denom;
    char slash;

    // Read the numerator
    input >> num;

    // Read the slash character
    input >> slash;

    // Read the denominator
    input >> denom;

    // Check for input errors
    if (input.fail() || slash != '/') {
        // Input error, set the failbit of the input stream
        input.setstate(std::ios_base::failbit);
    } else {
        // Update the Fraction object
        ghi.Numerator = num;
        ghi.Denominator = denom;
        Fraction temp(num,denom); 

        int gcd = std::__gcd((num) , (denom) );
        ghi.Numerator = (num / gcd);
        ghi.Denominator = (denom / gcd);






       // ghi.reduce(); // reduce the fraction to lowest terms
    }

    return input;
}


}
