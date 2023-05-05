#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Fraction.hpp"
#include <limits.h>


namespace ariel{


int a = INT_MAX;
int b = INT_MIN;
 Fraction :: Fraction(int abc, int def){
    if(def == 0){
        throw std ::invalid_argument ("Division_by_0");
    }
    if(def<0 ){
        abc = -abc;
        def = -def;
    }
    long c = (long) (abc);
    long d =(long)(def);

    if(!(isvalid(c,d))){
        throw std:: overflow_error("invalid input");
    }
    this-> Numerator = abc;
    this-> Denominator = def;


}

Fraction :: Fraction(float def){

    Set_Numerator(int(def*1000));
    Set_Denominator(1000);
}

Fraction :: Fraction(){
    Fraction temp(0,1);
}


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

bool Fraction::isvalid( long a, long b)const{
    if(a > INT_MAX || b > INT_MAX || a < INT_MIN || b < INT_MIN){
        return false;
    }
    return true;
}


// Fraction Fraction::reduction(){

// }

Fraction Fraction::operator+(const Fraction& other) const{


    if(other.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }

    Fraction eror(other.getNumerator(), other.getDenominator());
    Fraction temp(0,1); 

    long c = long(this->Numerator * other.getDenominator()) + (this->Denominator * other.getNumerator());
    long d = long((this->Denominator) * (other.getDenominator()));
   
    // long d =();
    if(!( isvalid(c,d))){
        throw std:: overflow_error("invalid input");
    }

    int den = ((this->Denominator) * (other.getDenominator()));
    int num = ((this->Numerator * other.getDenominator()) + (this->Denominator * other.getNumerator()));
    int gcd = std::__gcd((num) , (den) );

    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;

}


Fraction Fraction:: operator+(float jkl){

    Fraction temp(this->Numerator, this->Denominator); 
    Fraction floa(jkl);
    return floa + temp; 
}


Fraction operator+(float number, const Fraction& mno){ 
 
    Fraction floa(number);

    return mno + floa;
}



Fraction Fraction:: operator-(const Fraction& other)const {

    if(other.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }

    long c = (long)((this->Numerator * other.getDenominator())) - (long)(this->Denominator * other.getNumerator());
    long d =(long)(this->Denominator * other.getDenominator());

    if(!(isvalid(c,d))){
        throw std:: overflow_error("invalid input");
    }
    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp(0,1); 
    int den = (this->Denominator * other.getDenominator());
    int num = ((this->Numerator * other.getDenominator()) - (this->Denominator * other.getNumerator()));

    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);


    return temp;

}

Fraction Fraction:: operator-(float jkl){
    Fraction temp(this->Numerator, this-> Denominator); 
    Fraction floa(jkl);
    return temp - floa; 
}



Fraction operator-(float number, const Fraction& mno){
    // Fraction temp(mno.getNumerator(),mno.getDenominator()); 
    Fraction floa(number);
    return floa - mno; 
}



Fraction Fraction:: operator*(const Fraction& other)const{


    if(other.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }

    Fraction temp1(this->Numerator, this->Denominator);

    Fraction temp2(other.getNumerator(),other.getDenominator());
    int num1 = this->Numerator;
    int num2 = other.getNumerator();
    int den1 = this->Denominator;
    int den2 =  other.getDenominator();
    int gcd1 = std::__gcd((num1) , (den1) );
    int gcd2 = std::__gcd((num2) , (den2) );
    temp1.Set_Numerator(num1/ gcd1);
    temp1.Set_Denominator(den1/ gcd1);
    temp2.Set_Denominator(den2/gcd2);
    temp2.Set_Numerator(num2/gcd2 );

    long c = (long)temp1.getNumerator() * temp2.getNumerator();
    long d = (long)temp1.getDenominator() * temp2.getDenominator();
   
    if(!( isvalid(c,d))){
        throw std:: overflow_error("invalid input");
    }
    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp(0,1); 
    int den = (this->Denominator * other.getDenominator());
    int num = (this->Numerator * other.getNumerator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
       
    return temp;
}

Fraction Fraction:: operator*(float jkl){
Fraction temp(this->Numerator,this->Denominator); 
Fraction floa(jkl);

return floa*temp; 
}


Fraction operator*(float number, const Fraction& mno){
    Fraction floa(number);
    return mno*floa; 
}



Fraction Fraction:: operator/( const Fraction& other) const{

   if(other.getNumerator()==0 || this->Denominator==0){

        throw std:: runtime_error("div by 0");
    }

    Fraction temp1(this->Numerator, this->Denominator);

    Fraction temp2(other.getNumerator(),other.getDenominator());
    int num1 = this->Numerator;
    int num2 = other.getNumerator();
    int den1 = this->Denominator;
    int den2 =  other.getDenominator();
    int gcd1 = std::__gcd((num1) , (den1) );
    int gcd2 = std::__gcd((num2) , (den2) );
    temp1.Set_Numerator(num1/ gcd1);
    temp1.Set_Denominator(den1/ gcd1);
    temp2.Set_Denominator(den2/gcd2);
    temp2.Set_Numerator(num2/gcd2 );

    long c = (long)temp1.getNumerator() * temp2.getNumerator();
    long d = (long)temp1.getDenominator() * temp2.getDenominator();
   
    if(!(isvalid(c,d))){
        throw std:: overflow_error("invalid input");
    }

    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp(0,1); 
    int den = this->Denominator * other.getNumerator();
    int num = (this->Numerator * other.getDenominator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;   
}

Fraction operator/(float number, const Fraction& mno){

    Fraction floa(number);
    return floa/mno;   
}

Fraction operator/(const Fraction& mno , float number){
    Fraction floa(number);
    return mno/floa;   
}



bool Fraction::operator==(const Fraction &other) const
{

    const float epsilon = 1000.0;
    int num1 = (int)(((float)Numerator / (float)Denominator) * epsilon);
    int num2 = (int)(((float)other.Numerator / (float)other.Denominator) * epsilon);

    return (num1 == num2);
}

bool operator==(float floa, const Fraction &other)
{
    Fraction temp(floa);
    return temp== other;
}


bool Fraction::operator!=(const Fraction &other) const
{
    Fraction floa(this->Numerator, this->Denominator);
     return !(floa ==other);
}




  bool operator!=(float floa, const Fraction &other)
  {
    return !(floa ==other);
  }


bool Fraction:: operator<(const Fraction& other)const {

    Fraction eror(other.getNumerator(), other.getDenominator());

    if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
        throw std:: overflow_error("invalid input");
    }    
   int other_den = other.Denominator;
   int  this_den = this->Denominator;

    Fraction temp_other(other.Numerator, other.Denominator);
    Fraction temp_this(this->Numerator, this->Denominator);

   temp_other.Set_Denominator(other_den* this_den);
   temp_this.Set_Denominator(other_den* this_den);

    int other_num = temp_other.getNumerator();
    int this_num = temp_this.getNumerator();

    temp_other.Set_Numerator(other_num * this_den);
   temp_this.Set_Numerator(this_num * other_den);

    bool this_les = (temp_this.getNumerator() < temp_other.getNumerator());
    return this_les;

}




bool operator<(float other ,const Fraction& frac){

    Fraction temp(other);
    return (temp < frac);
}




bool Fraction:: operator<(float other) {
 
    Fraction temp(other); 
    Fraction temp_this(this->Numerator, this->Denominator);
    return (temp_this < temp);
}


bool Fraction:: operator>(const Fraction& other)const {
 
    Fraction eror(other.getNumerator(), other.getDenominator());

   int other_den = other.Denominator;
   int  this_den = this->Denominator;

   
    Fraction temp_other(other.Numerator, other.Denominator);
    Fraction temp_this(this->Numerator, this->Denominator);

  temp_other.Set_Denominator(other_den* this_den);
   temp_this.Set_Denominator(other_den* this_den);

    int other_num = temp_other.getNumerator();
    int this_num = temp_this.getNumerator();

   temp_other.Set_Numerator(other_num * this_den);
   temp_this.Set_Numerator(this_num * other_den);

    bool this_big = (temp_this.getNumerator() >temp_other.getNumerator());

    return this_big;

}


bool Fraction:: operator>(float other) { 

    Fraction temp(other*1000,1000); 
    Fraction temp_this(this->Numerator, this->Denominator);
    return (temp_this > temp);
}

bool operator>(float other, const Fraction& frac){

    Fraction temp(other); 
    return (temp > frac);
}


bool Fraction:: operator>=( const Fraction& other) const {

    Fraction eror(other.getNumerator(), other.getDenominator());

     
    int other_den = other.getDenominator();
    int  this_den = this->Denominator;

    Fraction temp_other(other.Numerator, other.Denominator);
    Fraction temp_this(this->Numerator, this->Denominator);

    temp_other.Set_Denominator(other_den* this_den);
   temp_this.Set_Denominator(other_den* this_den);

    int other_num = temp_other.getNumerator();
    int this_num = temp_this.getNumerator();

    temp_other.Set_Numerator(other_num * this_den);
   temp_this.Set_Numerator(this_num * other_den);

    bool this_bieq = (temp_this.getNumerator() >= temp_other.getNumerator());

    return this_bieq;

}



bool operator>=(float other, const Fraction& frac){

    Fraction temp(other);
    return (temp >= frac);
}


bool Fraction:: operator<=(const Fraction& other) const {
 
    Fraction eror(other.getNumerator(), other.getDenominator());

   int other_den = other.getDenominator();
   int  this_den = this->Denominator;

    Fraction temp_other(other.Numerator, other.Denominator);
    Fraction temp_this(this->Numerator, this->Denominator);


   temp_other.Set_Denominator(other_den* this_den);
   temp_this.Set_Denominator(other_den* this_den);

    int other_num = other.getNumerator();
    int this_num = this->Numerator;

    temp_other.Set_Numerator(other_num * this_den);
    temp_this.Set_Numerator(this_num * other_den);

    bool this_leeq = (temp_this.getNumerator() <= temp_other.getNumerator());

    return this_leeq;
}

bool operator<=(float floa, const Fraction& other){

    Fraction temp_this(floa);
    return (temp_this <= other);
}


Fraction Fraction:: operator++(){ 
    this->Set_Numerator(this->Numerator + this->Denominator);
    Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

const Fraction Fraction:: operator++(int abc){
    Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator + this->Denominator);
    return temp;
}

Fraction Fraction:: operator--(){
    this->Set_Numerator(this->Numerator - this->Denominator);
    Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

const Fraction Fraction:: operator--(int abc){
    Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator - this->Denominator);
    return temp;
}


std::ostream& operator<< (std::ostream& output, const Fraction& ghi){

    int num = ghi.getNumerator();
    int denom = ghi.getDenominator();
    int gcd = std::__gcd(num,denom);
    int numb =num /gcd;
    int deno = denom/gcd;
    Fraction temp(numb , deno);
 
  output << temp.getNumerator() << "/" << temp.getDenominator();
  return output;
}


std::istream& operator>> (std::istream& input ,  Fraction& ghi){

    int num, denom;
    if ( (input >> num >> denom) && denom!=0 ) {
        
        int gcd = std::__gcd(num,denom);
        ghi.Set_Numerator(num / gcd);
        ghi.Set_Denominator(denom / gcd);
         //std::cin >> ghi;
            
    } else {
        throw std:: runtime_error("input 1");  
    } 
    return input;
}
}



