#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int v);
		Fixed(const float v);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		bool operator>(Fixed &other) const;
		bool operator<(Fixed &other) const;
		bool operator>=(Fixed &other) const;
		bool operator<=(Fixed &other) const;
		bool operator==(Fixed &other) const;
		bool operator!=(Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};
std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif
