#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Fraction.hpp"
#include <limits.h>

// #include <cmath>
// #include <climits>
// #include <cstdlib>

namespace ariel{

//int max = max_int;
int a = INT_MAX;
int b = INT_MIN;

// 240999
Fraction :: Fraction(int abc, int def){
    if(def == 0){
        throw std ::invalid_argument ("Division_by_0");
    }
    if(def<0 ){
        abc = -abc;
        def = -def;
    }


   // int gcd = std::__gcd((abc) , (def) );

    
    this-> Numerator = abc;
    this-> Denominator = def;
}

Fraction :: Fraction(float def){

    Set_Numerator(int(def*1000));
    Set_Denominator(1000);

    // return def2;
}

Fraction :: Fraction(){
    Fraction temp(0,1);
    // return def2;
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

bool Fraction::isvalid( long a, long b)const{
    if(a> INT_MAX || b>INT_MAX || a<INT_MIN || b<INT_MIN){
        return false;
    }
    return true;
}


Fraction Fraction::operator+( const Fraction& other) const{


    if(other.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }
    // if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
    //     throw std:: overflow_error("invalid input");
    // }
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


Fraction Fraction:: operator*(const Fraction& other)const{


    if(other.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }

    // long check1 = long(this->Numerator) * other.getNumerator();
    // long check2 = long(this->Denominator) * other.getDenominator();
    // if (check1 > INT_MAX || check2 > INT_MAX ||  check1 < INT_MIN || check2 < INT_MIN){
    // throw std::overflow_error (" Note we're using INTEGERS");
    // }
    long c = long((this->Numerator)) * other.getNumerator();
    long d = long(this->Denominator) * other.getDenominator();
   
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

Fraction Fraction:: operator/( const Fraction& other) const{


    if(other.getNumerator()==0 || this->Denominator==0){

        throw std:: runtime_error("div by 0");
    }

    long c = long(this->Denominator) * other.getNumerator();
    long d = long(this->Numerator) * other.getDenominator();
   
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


Fraction Fraction:: operator+(float jkl){

    Fraction temp(0,1); 
    Fraction floa(jkl*1000,1000);
    if(floa.getDenominator()== 0 ){
    throw std:: runtime_error("div by 0");
    }

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

    if(floa.getDenominator()== 0 ){
        throw std:: runtime_error("div by 0");
    }


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

bool Fraction::operator==(const Fraction &other) const
{

    const float epsilon = 1000.0;
    int num1 = (int)(((float)Numerator / (float)Denominator) * epsilon);
    int num2 = (int)(((float)other.Numerator / (float)other.Denominator) * epsilon);

    return (num1 == num2);
  }

bool Fraction::operator!=(const Fraction &other) const
{
    if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
        throw std:: overflow_error("invalid input");
    }
    const float epsilon = 1000.0;
    int num1 = (int)(((float)Numerator / (float)Denominator) * epsilon);
    int num2 = (int)(((float)other.Numerator / (float)other.Denominator) * epsilon);

    return (!(num1 == num2));
}
  bool operator==(float floa, const Fraction &other)
  {

    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp_other(other.getNumerator(), other.getDenominator());
    Fraction temp_this(floa * 1000, 1000);
    int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
    temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
    temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

    int gcd2 = std::__gcd(other.getDenominator(), (other.getNumerator()));
    int a = (other.getNumerator() / gcd2);
    temp_other.Set_Numerator(a);
    int b = other.getDenominator() / gcd2;
    temp_other.Set_Denominator(b);

    bool den = temp_other.getDenominator() == temp_this.getDenominator();
    bool num = temp_other.getNumerator() == temp_this.getNumerator();
    return den && num;
  }


  bool operator!=(float floa, const Fraction &other)
  {
    if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
        throw std:: overflow_error("invalid input");
    }

    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp_other(other.getNumerator(), other.getDenominator());
    Fraction temp_this(floa * 1000, 1000);
    int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
    temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
    temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

    int gcd2 = std::__gcd(other.getDenominator(), (other.getNumerator()));
    int a = (other.getNumerator() / gcd2);
    temp_other.Set_Numerator(a);
    int b = other.getDenominator() / gcd2;
    temp_other.Set_Denominator(b);

    bool den = temp_other.getDenominator() == temp_this.getDenominator();
    bool num = temp_other.getNumerator() == temp_this.getNumerator();
    return !(den && num);
  }




  bool operator==(const Fraction &other, float floa)
  {

    if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
        throw std:: overflow_error("invalid input");
    }
    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp_other(other.getNumerator(), other.getDenominator());
    Fraction temp_this(floa * 1000, 1000);
    int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
    temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
    temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

    int gcd2 = std::__gcd(other.getDenominator(), (other.getNumerator()));
    int a = (other.getNumerator() / gcd2);
    temp_other.Set_Numerator(a);
    int b = other.getDenominator() / gcd2;
    temp_other.Set_Denominator(b);

    bool den = temp_other.getDenominator() == temp_this.getDenominator();
    bool num = temp_other.getNumerator() == temp_this.getNumerator();
    return den && num;
  }





    bool operator!=(const Fraction &other, float floa)
  {
    if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
        throw std:: overflow_error("invalid input");
    }
 
    Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp_other(other.getNumerator(), other.getDenominator());
    Fraction temp_this(floa * 1000, 1000);
    int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
    temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
    temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

    int gcd2 = std::__gcd(other.getDenominator(), (other.getNumerator()));
    int a = (other.getNumerator() / gcd2);
    temp_other.Set_Numerator(a);
    int b = other.getDenominator() / gcd2;
    temp_other.Set_Denominator(b);

    bool den = temp_other.getDenominator() == temp_this.getDenominator();
    bool num = temp_other.getNumerator() == temp_this.getNumerator();
    return !(den && num);
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



bool operator<(const Fraction& frac , float other){
    // if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
    //     throw std:: runtime_error("invalid input");
    // }
    Fraction eror(frac.getNumerator(), frac.getDenominator());

 cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;
    Fraction temp(other*1000,1000); 
    Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
    int other_den = temp.getDenominator();
    int  frac_den = frac.getDenominator();

    temp.Set_Denominator(other_den* frac_den);
    temp_frac.Set_Denominator(other_den* frac_den);
    cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;

    int other_num = temp.getNumerator();
    int frac_num = temp_frac.getNumerator();

    temp.Set_Numerator(other_num * frac_den);
    temp_frac.Set_Numerator(frac_num * other_den);

    bool frac_les = ((temp_frac.getNumerator() < temp.getNumerator()));
    cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;

   return frac_les;
 //  return frac<temp;

}


bool operator<(float other ,const Fraction& frac){
    // if(other.getDenominator()> a || other.getNumerator()>a ||other.getDenominator()< b || other.getNumerator()<b){
    //     throw std:: runtime_error("invalid input");
    // }
    Fraction eror(frac.getNumerator(), frac.getDenominator());


    cout << "acaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    Fraction temp(other*1000,1000); 
    Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
    int other_den = temp.getDenominator();
    int  frac_den = frac.getDenominator();

    temp.Set_Denominator(other_den* frac_den);
    temp_frac.Set_Denominator(other_den* frac_den);
    cout << "acaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;

    int other_num = temp.getNumerator();
    int frac_num = temp_frac.getNumerator();

    temp.Set_Numerator(other_num * frac_den);
    temp_frac.Set_Numerator(frac_num * other_den);

    bool other_les = (temp.getNumerator() < temp_frac.getNumerator());

    return other_les;
    //return temp < frac;

}




bool Fraction:: operator<(float other) {
 
   // Fraction eror(other.getNumerator(), other.getDenominator());

    Fraction temp(other*1000,1000); 
    Fraction temp_this(this->Numerator, this->Denominator);
    int other_den = temp.getDenominator();
    int  this_den = this->Denominator;

    temp.Set_Denominator(other_den* this_den);
    temp_this.Set_Denominator(other_den* this_den);

    int other_num = temp.getNumerator();
    int this_num = -temp_this.getNumerator();

    temp.Set_Numerator(other_num * this_den);
    temp_this.Set_Numerator(this_num * other_den);

    bool this_les = (temp_this.getNumerator() < temp.getNumerator());

    return this_les;

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

  //  Fraction eror(other.getNumerator(), other.getDenominator());

 
    Fraction temp(other*1000,1000); 
    Fraction temp_this(this->Numerator, this->Denominator);
    int other_den = temp.getDenominator();
    int this_den = this->Denominator;

    temp.Set_Denominator(other_den* this_den);
    temp_this.Set_Denominator(other_den* this_den);

    int other_num = temp.getNumerator();
    int this_num = temp_this.getNumerator();

    temp.Set_Numerator(other_num * this_den);
    temp_this.Set_Numerator(this_num * other_den);

    bool this_big = (temp_this.getNumerator() > temp.getNumerator());

    return this_big;

}



bool operator>(float other, const Fraction& frac){

    Fraction eror(frac.getNumerator(), frac.getDenominator());


    Fraction temp(other*1000,1000); 
    int other_den = temp.getDenominator();
    Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
    int  frac_den = temp_frac.getDenominator();

    temp.Set_Denominator(other_den* frac_den);
    temp_frac.Set_Denominator(other_den* frac_den);

    int other_num = temp.getNumerator();
    int this_num = temp_frac.getNumerator();

    temp.Set_Numerator(other_num * frac_den);
    temp_frac.Set_Numerator(this_num * other_den);

    bool this_big = (temp_frac.getNumerator() < temp.getNumerator());

    return this_big;
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

    Fraction eror(frac.getNumerator(), frac.getDenominator());

    Fraction temp(other*1000,1000); 
    Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
    int other_den = temp.getDenominator();
    int  frac_den = frac.getDenominator();

    temp.Set_Denominator(other_den* frac_den);
    temp_frac.Set_Denominator(other_den* frac_den);

    int other_num = temp.getNumerator();
    int frac_num = temp_frac.getNumerator();

    temp.Set_Numerator(other_num * frac_den);
    temp_frac.Set_Numerator(frac_num * other_den);

    bool frac_les = ((temp_frac.getNumerator()) < (temp.getNumerator()));

    return frac_les;
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
     
    Fraction eror(other.getNumerator(), other.getDenominator());

   int other_den = other.getDenominator();
  

    Fraction temp_other(other.Numerator, other.Denominator);
    Fraction temp_this(floa*1000,1000);
    int  this_den = temp_this.getDenominator();


   temp_other.Set_Denominator(other_den* this_den);
   temp_this.Set_Denominator(other_den* this_den);

    int other_num = other.getNumerator();
    int this_num =temp_this.getNumerator();

    temp_other.Set_Numerator(other_num * this_den);
    temp_this.Set_Numerator(this_num * other_den);

    bool this_leeq = (temp_this.getNumerator() <= temp_other.getNumerator());

    return this_leeq;
}


Fraction Fraction:: operator++(){ 
   // Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator + this->Denominator);
    Fraction temp(this->Numerator, this->Denominator);
    return temp;
}

const Fraction Fraction:: operator++(int abc){
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

const Fraction Fraction:: operator--(int abc){
    Fraction temp(this->Numerator, this->Denominator);
    this->Set_Numerator(this->Numerator - this->Denominator);
    return temp;
}



// Fraction Fraction:: operator*(const float other){
//     return Fraction(1,2);
// }

Fraction operator+(float number, const Fraction& mno){ 
    // Fraction temp(0,1); 
     Fraction floa(number*1000,1000);
    // int den =  ((mno.Denominator) * (floa.getDenominator()));
    // int num = ((mno.Numerator * floa.getDenominator()) + (mno.Denominator * floa.getNumerator()));
    // int gcd = std::__gcd((num) , (den) );
    // temp.Set_Numerator(num / gcd);
    // temp.Set_Denominator(den / gcd);
    // return temp; 
    return mno+ floa;
}


Fraction operator+(const Fraction& mno, float number){ 

    Fraction floa(number*1000,1000);
   return floa + mno;

}


Fraction operator-(float number, const Fraction& mno){
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    long c = -((mno.Numerator * floa.getDenominator()) - (mno.Denominator * floa.getNumerator()));
    long d =((mno.Denominator) * (floa.getDenominator()));

    if(c > INT_MAX || d>INT_MAX || c< INT_MIN || d< INT_MIN){
        throw std:: overflow_error("invalid input");
    }

    
    int den =  ((mno.Denominator) * (floa.getDenominator()));
    int num = -((mno.Numerator * floa.getDenominator()) - (mno.Denominator * floa.getNumerator()));
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp; 
       //return floa + mno;
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
    if(mno.getDenominator()==0){
        throw std:: runtime_error("div by 0");
    }
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    int den = mno.Numerator * floa.getDenominator();
    int num = (mno.Denominator * floa.getNumerator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
    return temp;   
}



Fraction operator/(const Fraction& mno , float number){
    Fraction temp(0,1); 
    Fraction floa(number*1000,1000);
    if(floa.getNumerator()==0){
        throw std:: runtime_error("div by 0");
    }
    int den = mno.Denominator * floa.getNumerator();
    int num = (mno.Numerator * floa.getDenominator());
    int gcd = std::__gcd((num) , (den) );
    temp.Set_Numerator(num / gcd);
    temp.Set_Denominator(den / gcd);
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


// std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
//         output << fraction.numerator << "/" << fraction.denominator;
//         return output;



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
//        num = ghi.getNumerator();
        // denom = ghi.getDenominator();
        // input >> num >> denom;














//         #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// #include <algorithm>
// #include <limits>
// using namespace std;

// #include "Fraction.hpp"
// namespace ariel
// {

//   // 240999
//   Fraction ::Fraction(int abc, int def)
//   {
//     if (def == 0)
//     {
//       throw std ::invalid_argument("Division_by_0");
//     }
//     if (def < 0)
//     {
//       abc = -abc;
//       def = -def;
//     }

//     // int gcd = std::__gcd((abc) , (def) );

//     this->Numerator = abc;
//     this->Denominator = def;
//   }

//   Fraction ::Fraction(float def) : Fraction((int)(def * 1000), 1000)
//   {
//   }

//   Fraction ::Fraction() : Numerator(0), Denominator(1)
//   {
//   }

//   // TODO for overflow
//   void check_overflow(long long a, long long b)
//   {
//     constexpr long long max_int = std::numeric_limits<int>::max();
//     constexpr long long min_int = std::numeric_limits<int>::min();

//     if (a > max_int || b > max_int || a < min_int || b < min_int)
//     {
//       throw std::overflow_error("");
//     }
//   }

//   // Fraction();

//   int Fraction::getNumerator() const
//   {
//     return this->Numerator;
//   }

//   int Fraction::getDenominator() const
//   {
//     return this->Denominator;
//   }

//   void Fraction::Set_Numerator(int num)
//   {
//     this->Numerator = num;
//   }

//   void Fraction::Set_Denominator(int den)
//   {

//     if (den == 0)
//     {
//       throw std ::invalid_argument("Division_by_0");
//     }
//     this->Denominator = den;
//   }

//   Fraction Fraction::operator+(const Fraction &other) const
//   {
//     if (other.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }
//     Fraction eror(other.getNumerator(), other.getDenominator());
//     Fraction temp(0, 1);
//     int den = ((this->Denominator) * (other.getDenominator()));
//     int num = ((this->Numerator * other.getDenominator()) + (this->Denominator * other.getNumerator()));

//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);

//     return temp;
//   }

//   Fraction Fraction::operator-(const Fraction &other) const
//   {

//     if (other.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }
//     Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp(0, 1);
//     int den = (this->Denominator * other.Denominator);
//     // cout <<this->Denominator << endl;
//     // cout << this->Numerator << endl;
//     // cout <<  other.Denominator << endl;
//     // cout << other.Numerator << endl;
//     int num = ((this->Numerator * other.Denominator) - (this->Denominator * other.getNumerator()));

//     // int num = ((this->Denominator * other.getNumerator() - (this->Numerator * other.Denominator) ));

//     // cout << num << endl;
//     // cout << num2 << endl;

//     if (num < 0)
//     {
//       int gcd = std::__gcd((num), (den));
//       temp.Set_Numerator(num / gcd);

//       temp.Set_Denominator(den / gcd);
//     }
//     else
//     {
//       int gcd = std::__gcd((num), (den));
//       temp.Set_Numerator(num / gcd);
//       temp.Set_Denominator(den / gcd);
//     }

//     return temp;
//   }

//   Fraction Fraction::operator*(const Fraction &other) const
//   {

//     if (other.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp(0, 1);
//     int den = (this->Denominator * other.Denominator);

//     int num = (this->Numerator * other.Numerator);

//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   Fraction Fraction::operator/(const Fraction &other) const
//   {

//     if (other.getNumerator() == 0 || this->Denominator == 0)
//     {

//       throw std::runtime_error("div by 0");
//     }
//     Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp(0, 1);
//     int den = this->Denominator * other.Numerator;
//     int num = (this->Numerator * other.Denominator);

//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   Fraction Fraction::operator+(float jkl)
//   {

//     Fraction temp(0, 1);
//     Fraction floa(jkl * 1000, 1000);
//     if (floa.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }

//     int den = ((this->Denominator) * (floa.getDenominator()));
//     int num = ((this->Numerator * floa.getDenominator()) + (this->Denominator * floa.getNumerator()));

//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   // Fraction operator+( const Fraction& other, float jkl){

//   //     Fraction temp(0,1);
//   //     int den = ((this->Denominator) * (other.Denominator));
//   //     int num = ((this->Numerator * other.Denominator) + (this->Denominator * other.getNumerator()));
//   //     int gcd = std::__gcd((num) , (den) );
//   //     temp.Set_Numerator(num / gcd);
//   //     temp.Set_Denominator(den / gcd);
//   //     return temp;

//   // }

//   Fraction Fraction::operator-(float jkl)
//   {
//     Fraction temp(0, 1);
//     Fraction floa(jkl * 1000, 1000);

//     if (floa.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }

//     int den = ((this->Denominator) * (floa.getDenominator()));
//     int num = ((this->Numerator * floa.getDenominator()) - (this->Denominator * floa.getNumerator()));
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   Fraction Fraction::operator*(float jkl)
//   {
//     Fraction temp(0, 1);
//     Fraction floa(jkl * 1000, 1000);
//     int den = (this->Denominator * floa.getDenominator());
//     int num = (this->Numerator * floa.getNumerator());
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   bool Fraction::operator==(const Fraction &other) const
//   {
//     const float epsilon = 1000.0;
//     int num1 = (int)(((float)Numerator / (float)Denominator) * epsilon);
//     int num2 = (int)(((float)other.Numerator / (float)other.Denominator) * epsilon);

//     return (num1 == num2);
//   }
//   bool operator==(float floa, const Fraction &other)
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(floa * 1000, 1000);
//     int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
//     temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
//     temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

//     int gcd2 = std::__gcd(other.Denominator, (other.Numerator));
//     int a = (other.Numerator / gcd2);
//     temp_other.Set_Numerator(a);
//     int b = other.Denominator / gcd2;
//     temp_other.Set_Denominator(b);

//     bool den = temp_other.getDenominator() == temp_this.getDenominator();
//     bool num = temp_other.getNumerator() == temp_this.getNumerator();
//     return den && num;
//   }

//   bool operator==(const Fraction &other, float floa)
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(floa * 1000, 1000);
//     int gcd1 = std::__gcd(temp_this.getDenominator(), (temp_this.getNumerator()));
//     temp_this.Set_Numerator(temp_this.getNumerator() / gcd1);
//     temp_this.Set_Denominator(temp_this.getDenominator() / gcd1);

//     int gcd2 = std::__gcd(other.Denominator, (other.Numerator));
//     int a = (other.Numerator / gcd2);
//     temp_other.Set_Numerator(a);
//     int b = other.Denominator / gcd2;
//     temp_other.Set_Denominator(b);

//     bool den = temp_other.getDenominator() == temp_this.getDenominator();
//     bool num = temp_other.getNumerator() == temp_this.getNumerator();
//     return den && num;
//   }

//   // bool operator==(int a, float floa ){

//   //     floa =
//   //     return den && num;
//   // }

//   bool Fraction::operator<(const Fraction &other) const
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     int other_den = other.Denominator;
//     int this_den = this->Denominator;

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(this->Numerator, this->Denominator);

//     temp_other.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = temp_other.getNumerator();
//     int this_num = temp_this.getNumerator();

//     temp_other.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_les = (temp_this.getNumerator() < temp_other.getNumerator());

//     return this_les;
//   }

//   bool operator<(const Fraction &frac, float other)
//   {

//     Fraction eror(frac.getNumerator(), frac.getDenominator());

//     cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;
//     Fraction temp(other * 1000, 1000);
//     Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
//     int other_den = temp.getDenominator();
//     int frac_den = frac.getDenominator();

//     temp.Set_Denominator(other_den * frac_den);
//     temp_frac.Set_Denominator(other_den * frac_den);
//     cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;

//     int other_num = temp.getNumerator();
//     int frac_num = temp_frac.getNumerator();

//     temp.Set_Numerator(other_num * frac_den);
//     temp_frac.Set_Numerator(frac_num * other_den);

//     bool frac_les = ((temp_frac.getNumerator() < temp.getNumerator()));
//     cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;

//     return frac_les;
//     //  return frac<temp;
//   }

//   bool operator<(float other, const Fraction &frac)
//   {

//     Fraction eror(frac.getNumerator(), frac.getDenominator());

//     cout << "acaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
//     Fraction temp(other * 1000, 1000);
//     Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
//     int other_den = temp.getDenominator();
//     int frac_den = frac.getDenominator();

//     temp.Set_Denominator(other_den * frac_den);
//     temp_frac.Set_Denominator(other_den * frac_den);
//     cout << "acaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;

//     int other_num = temp.getNumerator();
//     int frac_num = temp_frac.getNumerator();

//     temp.Set_Numerator(other_num * frac_den);
//     temp_frac.Set_Numerator(frac_num * other_den);

//     bool other_les = (temp.getNumerator() < temp_frac.getNumerator());

//     return other_les;
//     // return temp < frac;
//   }

//   bool Fraction::operator<(float other)
//   {

//     // Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp(other * 1000, 1000);
//     Fraction temp_this(this->Numerator, this->Denominator);
//     int other_den = temp.getDenominator();
//     int this_den = this->Denominator;

//     temp.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = temp.getNumerator();
//     int this_num = -temp_this.getNumerator();

//     temp.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_les = (temp_this.getNumerator() < temp.getNumerator());

//     return this_les;
//   }

//   bool Fraction::operator>(const Fraction &other) const
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     int other_den = other.Denominator;
//     int this_den = this->Denominator;

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(this->Numerator, this->Denominator);

//     temp_other.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = temp_other.getNumerator();
//     int this_num = temp_this.getNumerator();

//     temp_other.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_big = (temp_this.getNumerator() > temp_other.getNumerator());

//     return this_big;
//   }

//   bool Fraction::operator>(float other)
//   {

//     //  Fraction eror(other.getNumerator(), other.getDenominator());

//     Fraction temp(other * 1000, 1000);
//     Fraction temp_this(this->Numerator, this->Denominator);
//     int other_den = temp.getDenominator();
//     int this_den = this->Denominator;

//     temp.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = temp.getNumerator();
//     int this_num = temp_this.getNumerator();

//     temp.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_big = (temp_this.getNumerator() > temp.getNumerator());

//     return this_big;
//   }

//   bool operator>(float other, const Fraction &frac)
//   {

//     Fraction eror(frac.getNumerator(), frac.getDenominator());

//     Fraction temp(other * 1000, 1000);
//     int other_den = temp.getDenominator();
//     Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
//     int frac_den = temp_frac.getDenominator();

//     temp.Set_Denominator(other_den * frac_den);
//     temp_frac.Set_Denominator(other_den * frac_den);

//     int other_num = temp.getNumerator();
//     int this_num = temp_frac.getNumerator();

//     temp.Set_Numerator(other_num * frac_den);
//     temp_frac.Set_Numerator(this_num * other_den);

//     bool this_big = (temp_frac.getNumerator() < temp.getNumerator());

//     return this_big;
//   }

//   bool Fraction::operator>=(const Fraction &other) const
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     int other_den = other.getDenominator();
//     int this_den = this->Denominator;

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(this->Numerator, this->Denominator);

//     temp_other.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = temp_other.getNumerator();
//     int this_num = temp_this.getNumerator();

//     temp_other.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_bieq = (temp_this.getNumerator() >= temp_other.getNumerator());

//     return this_bieq;
//   }

//   bool operator>=(float other, const Fraction &frac)
//   {

//     Fraction eror(frac.getNumerator(), frac.getDenominator());

//     Fraction temp(other * 1000, 1000);
//     Fraction temp_frac(frac.getNumerator(), frac.getDenominator());
//     int other_den = temp.getDenominator();
//     int frac_den = frac.getDenominator();

//     temp.Set_Denominator(other_den * frac_den);
//     temp_frac.Set_Denominator(other_den * frac_den);

//     int other_num = temp.getNumerator();
//     int frac_num = temp_frac.getNumerator();

//     temp.Set_Numerator(other_num * frac_den);
//     temp_frac.Set_Numerator(frac_num * other_den);

//     bool frac_les = ((temp_frac.getNumerator()) < (temp.getNumerator()));

//     return frac_les;
//   }

//   bool Fraction::operator<=(const Fraction &other) const
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     int other_den = other.getDenominator();
//     int this_den = this->Denominator;

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(this->Numerator, this->Denominator);

//     temp_other.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = other.getNumerator();
//     int this_num = this->Numerator;

//     temp_other.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_leeq = (temp_this.getNumerator() <= temp_other.getNumerator());

//     return this_leeq;
//   }

//   bool operator<=(float floa, const Fraction &other)
//   {

//     Fraction eror(other.getNumerator(), other.getDenominator());

//     int other_den = other.getDenominator();

//     Fraction temp_other(other.Numerator, other.Denominator);
//     Fraction temp_this(floa * 1000, 1000);
//     int this_den = temp_this.getDenominator();

//     temp_other.Set_Denominator(other_den * this_den);
//     temp_this.Set_Denominator(other_den * this_den);

//     int other_num = other.getNumerator();
//     int this_num = temp_this.getNumerator();

//     temp_other.Set_Numerator(other_num * this_den);
//     temp_this.Set_Numerator(this_num * other_den);

//     bool this_leeq = (temp_this.getNumerator() <= temp_other.getNumerator());

//     return this_leeq;
//   }

//   Fraction Fraction::operator++()
//   {
//     // Fraction temp(this->Numerator, this->Denominator);
//     this->Set_Numerator(this->Numerator + this->Denominator);
//     Fraction temp(this->Numerator, this->Denominator);
//     return temp;
//   }

//   const Fraction Fraction::operator++(int abc)
//   {
//     Fraction temp(this->Numerator, this->Denominator);
//     this->Set_Numerator(this->Numerator + this->Denominator);
//     // Fraction temp(this->Numerator, this->Denominator);
//     return temp;
//   }

//   Fraction Fraction::operator--()
//   {
//     this->Set_Numerator(this->Numerator - this->Denominator);
//     Fraction temp(this->Numerator, this->Denominator);
//     return temp;
//   }

//   const Fraction Fraction::operator--(int abc)
//   {
//     Fraction temp(this->Numerator, this->Denominator);
//     this->Set_Numerator(this->Numerator - this->Denominator);
//     return temp;
//   }

//   // Fraction Fraction:: operator*(const float other){
//   //     return Fraction(1,2);
//   // }

//   Fraction operator+(float number, const Fraction &mno)
//   {
//     // Fraction temp(0,1);
//     Fraction floa(number * 1000, 1000);
//     // int den =  ((mno.Denominator) * (floa.getDenominator()));
//     // int num = ((mno.Numerator * floa.getDenominator()) + (mno.Denominator * floa.getNumerator()));
//     // int gcd = std::__gcd((num) , (den) );
//     // temp.Set_Numerator(num / gcd);
//     // temp.Set_Denominator(den / gcd);
//     // return temp;
//     return mno + floa;
//   }

//   Fraction operator+(const Fraction &mno, float number)
//   {

//     Fraction floa(number * 1000, 1000);
//     return floa + mno;
//   }

//   Fraction operator-(float number, const Fraction &mno)
//   {
//     Fraction temp(0, 1);
//     Fraction floa(number * 1000, 1000);
//     int den = ((mno.Denominator) * (floa.getDenominator()));
//     int num = -((mno.Numerator * floa.getDenominator()) - (mno.Denominator * floa.getNumerator()));
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//     // return floa + mno;
//   }

//   Fraction operator*(float number, const Fraction &mno)
//   {
//     Fraction temp(0, 1);
//     Fraction floa(number * 1000, 1000);
//     int den = (mno.Denominator * floa.getDenominator());
//     int num = (mno.Numerator * floa.getNumerator());
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   Fraction operator/(float number, const Fraction &mno)
//   {
//     if (mno.getDenominator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }
//     Fraction temp(0, 1);
//     Fraction floa(number * 1000, 1000);
//     int den = mno.Numerator * floa.getDenominator();
//     int num = (mno.Denominator * floa.getNumerator());
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   Fraction operator/(const Fraction &mno, float number)
//   {
//     Fraction temp(0, 1);
//     Fraction floa(number * 1000, 1000);
//     if (floa.getNumerator() == 0)
//     {
//       throw std::runtime_error("div by 0");
//     }
//     int den = mno.Denominator * floa.getNumerator();
//     int num = (mno.Numerator * floa.getDenominator());
//     int gcd = std::__gcd((num), (den));
//     temp.Set_Numerator(num / gcd);
//     temp.Set_Denominator(den / gcd);
//     return temp;
//   }

//   std::ostream &operator<<(std::ostream &output, const Fraction &ghi)
//   {

//     int num = ghi.getNumerator();
//     int denom = ghi.getDenominator();
//     int gcd = std::__gcd(num, denom);
//     int numb = num / gcd;
//     int deno = denom / gcd;
//     Fraction temp(numb, deno);

//     output << temp.getNumerator() << "/" << temp.getDenominator();
//     return output;
//   }

//   // std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
//   //         output << fraction.numerator << "/" << fraction.denominator;
//   //         return output;

//   std::istream &operator>>(std::istream &input, Fraction &ghi)
//   {

//     int num, denom;
//     if ((input >> num >> denom) && denom != 0)
//     {

//       int gcd = std::__gcd(num, denom);
//       ghi.Set_Numerator(num / gcd);
//       ghi.Set_Denominator(denom / gcd);
//       // std::cin >> ghi;
//     }
//     else
//     {
//       throw std::runtime_error("input 1");
//     }
//     return input;
//   }
// }