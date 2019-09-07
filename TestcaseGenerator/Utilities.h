#pragma once

#define LC 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
#define UC 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'


#include<stdarg.h>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

template<typename T>
T GetRandom(const T ll, const T ul) {
	return ll + static_cast <T> ( rand() ) / ( static_cast <T> ( RAND_MAX / ( ul - ll ) ) + 1 );
}

std::string GetString(const int len, const int n, ...) {
	std::ostringstream oss;
	char* arr = new char[n];
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
		arr[i] = va_arg(args, char);
	va_end(args);
	for (int i = 0; i < len; i++)
		oss << arr[GetRandom<int>(0, n)];
	delete[] arr;
	return oss.str();
}
class NumSys {

private:
	std::vector<char> digits;
	long long int decimal;

public:
	NumSys(const NumSys &n) :digits(n.digits), decimal(n.decimal) {}
	NumSys(const long long int n, ...) {
		char temp;
		va_list args;
		va_start(args, n);
		for (int i = 0; i < n; i++) {
			temp = va_arg(args, char);
			digits.push_back(temp);
		}
		va_end(args);
		digits.resize(std::distance(digits.begin(), std::unique(digits.begin(), digits.end())));
		decimal = 0;
	}

	void ToLexo() {
		std::sort(digits.begin(), digits.end());
	}

	std::string GenRandomString(const int len) {
		std::ostringstream oss;
		for (int i = 0; i < len; i++)
			oss << digits[GetRandom<int>(0, digits.size())];
		return oss.str();
	}

	std::string GetCurrent(const int length = 0) {
		std::ostringstream oss;
		auto iter = decimal;
		if (!length) {
			if (!decimal) {
				oss << digits[0];
				return oss.str();
			}
			while (iter) {
				oss << digits[iter%digits.size()];
				iter /= digits.size();
			}
		} else {
			for (int i = 0; i < length; i++) {
				oss << digits[iter%digits.size()];
				iter /= digits.size();
			}
		}
		std::string result = oss.str();
		reverse(result.begin(), result.end());
		return result;
	}

	std::string GetEqui(const long long int value, const int length = 0) {
		std::ostringstream oss;
		auto iter = value;
		if (!length) {
			if (!value) {
				oss << digits[0];
				return oss.str();
			}
			while (iter) {
				oss << digits[iter%digits.size()];
				iter /= digits.size();
			}
		} else {
			for (int i = 0; i < length; i++) {
				oss << digits[iter%digits.size()];
				iter /= digits.size();
			}
		}
		std::string result = oss.str();
		reverse(result.begin(), result.end());
		return result;
	}

	long long int CheckCurrent() { return decimal; }

	NumSys operator ++ (int) {
		decimal++;
		return *this;
	}

};