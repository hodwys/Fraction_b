#ifndef FRACTION

#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
//abc def ghi jkl mno 
class Fraction{
    private:

        int Numerator;
        int Denominator;

    public:
    explicit Fraction(int abc, int def);
    Fraction(float ghi);
    Fraction();
    int getNumerator() const;
    int getDenominator() const;
    void Set_Numerator(int num);
    void Set_Denominator(int den);


    bool isvalid( long abc, long bcd) const;

    //+
    Fraction operator+(const Fraction& other) const;
    Fraction operator+(float ghi);
    friend Fraction operator+(float number, const Fraction& mno);
    //friend Fraction operator+(const Fraction& mno, float number);

//-
    Fraction operator-(const Fraction& other) const;
    Fraction operator-(float ghi);
    friend Fraction operator-(float number,  const Fraction& mno);


//*
    Fraction operator*(const Fraction &other) const;
    Fraction operator*(float ghi);
    friend Fraction operator*(float number,  const Fraction& mno);


    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(float number,  const Fraction& mno);
    friend Fraction operator/(const Fraction& mno, float number);

// == !=
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

//<
    bool operator<(const Fraction& other)const;
    friend bool operator<(float other, const Fraction& frac);
    bool operator<(float other) ;


// >
    bool operator>(float other);
    bool operator>(const Fraction& other) const ;
    friend bool operator>(float other, const Fraction& frac);


// >=
    bool operator>=(const Fraction& other) const;

   friend bool operator>=(float other, const Fraction& frac);



// <=
    bool operator<=(const Fraction& other) const;

    friend bool operator<=(float other, const Fraction& frac);


// << >>
    friend std::ostream& operator<< (std::ostream& output,  const Fraction& ghi);
    friend std::istream& operator>> (std::istream& input ,  Fraction& ghi);

//++
    Fraction operator++();
    const Fraction operator++(int abc);

//--
    Fraction operator--();
    const Fraction operator--(int abc);


};
}
    


#endif
