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

  //  Fraction();

    Fraction(int abc, int def);
    Fraction(float ghi);
    int getNumerator() const;
    int getDenominator() const;
    void Set_Numerator(int num);
    void Set_Denominator(int den);



    Fraction operator+(const Fraction& other) const;

    Fraction operator-(const Fraction& other) const;

    Fraction operator*(const Fraction& other) const;

   // Fraction operator*(Fraction& other);

    Fraction operator/(const Fraction& other) const;



    Fraction operator+(float ghi);

    Fraction operator-(float ghi);

    Fraction operator*(float ghi);

    
    friend Fraction operator+(float number, const Fraction& mno);
    friend Fraction operator-(float number,  const Fraction& mno);
    friend Fraction operator*(float number,  const Fraction& mno);
    friend Fraction operator/(float number,  const Fraction& mno);


    bool operator==(const Fraction& other);

    bool operator<(const Fraction& other);

    bool operator<(float other);

    bool operator>(float other);

    bool operator>(const Fraction& other);

    bool operator>=(const Fraction& other) ;

    bool operator<=(const Fraction& other) ;



    friend std::ostream& operator<< (std::ostream& output,  const Fraction& ghi);
    friend std::istream& operator>> (std::istream& input ,  Fraction& ghi);


    Fraction operator++();

    Fraction operator++(int abc);

    Fraction operator--();

    Fraction operator--(int abc);





    

};
}
    


#endif






  

    // Fraction& operator--();
