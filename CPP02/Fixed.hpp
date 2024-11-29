#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int ayhaja;
        int ayhaja1;
        int ayhaja2;
        int ayhaja3;

    public:
        Fixed();
        Fixed(int num);
        Fixed(float num);
        ~Fixed();
        Fixed(const Fixed & copy);
        Fixed &operator=(const Fixed & copy);
        void setAyhaja(int num);
        void setAyhaja1(int num);
        void setAyhaja2(int num);
        void setAyhaja3(int num);

        int getAyhaja(void);
        int getAyhaja1(void);
        int getAyhaja2(void);
        int getAyhaja3(void);

};

std::ostream& operator<<(std::ostream& os,  Fixed& obj);

#endif