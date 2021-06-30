#include <array>
#include <initializer_list>
#include <cstddef>

template<typename T, size_t N>
class Vector : public std::array<T, N>
{
public:
	Vector();
	Vector(const std::initializer_list<T>& other);
	Vector(const Vector& other);
	T& operator[](size_t index);
	Vector(Vector&& other);


	Vector& operator=(const std::initializer_list<T>& other);
	Vector& operator=(const Vector& other);

	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator*(const Vector& other) const;
	Vector operator/(const Vector& other) const;

	Vector operator+(const float& other) const;
	Vector operator-(const float& other) const;
	Vector operator*(const float& other) const;
	Vector operator/(const float& other) const;

	
};



