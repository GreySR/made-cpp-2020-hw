#pragma once
#include <vector>
#include <iostream>

namespace task{	
	const double EPSILON = 1e-7;

	std::vector<double> operator+ (const std::vector<double> &a, const std::vector<double> &b){
		std::vector<double> c;
		for (size_t i = 0; i < a.size(); ++i){
			c.push_back(a[i] + b[i]);
		}
		return c;
	}
	
	std::vector<double> operator+ (const std::vector<double> &a){
		return a;
	}

	std::vector<double> operator- (const std::vector<double> &a){
		std::vector<double> b;
		for (size_t i = 0; i < a.size(); ++i){
			b.push_back(-a[i]);
		}
		return b;
	}

	std::vector<double> operator- (const std::vector<double> &a, const std::vector<double> &b){
		std::vector<double> c;
		for (size_t i = 0; i < a.size(); ++i){
			c.push_back(a[i] - b[i]);
		}
		return c;
	}

	double operator* (const std::vector<double> &a, const std::vector<double> &b){
		double sum = 0;
		for (size_t i = 0; i < a.size(); ++i){
			sum += a[i] * b[i];
		}
		return sum;
	}

	std::vector<double> operator% (const std::vector<double> &a, const std::vector<double> &b){
		std::vector<double> c;
		c.push_back(a[1] * b[2] - a[2] * b[1]);
		c.push_back(a[2] * b[0] - a[0] * b[2]);
		c.push_back(a[0] * b[1] - a[1] * b[0]);
		return c;
	}

	std::ostream &operator<< (std::ostream &os, const std::vector<double> &a){
		for (size_t i = 0; i < a.size(); ++i) os << a[i] << " ";
		os << '\n';
		return os;
	}

	std::istream &operator>> (std::istream &is, std::vector<double> &a){
		size_t n = 0;
		is >> n;
		a.resize(n);
		double x;
		for (size_t i = 0; i < n; ++i){
			is >> x;
			a[i] = x;
		}
		return is;
	}

	bool operator|| (const std::vector<double> &a, const std::vector<double> &b){
		double d1 = 0., d2 = 0.;
		for (size_t i = 0; i < a.size(); ++i){
			d1 += a[i] * a[i];
			d2 += b[i] * b[i];
		}
		d1 = sqrt(d1);
		d2 = sqrt(d2);		
		if ((1. - (a * b) / (d1 * d2) < EPSILON) || (1. + (a * b) / (d1 * d2) < EPSILON))
		       	return true;
		return false;
	}	
	
	bool operator&& (const std::vector<double> &a, const std::vector<double> &b){
		return (a * b > 0) && (a || b);
	}

	void reverse (std::vector<double> &a){
		size_t n = a.size() / 2;
		for (size_t i = 0; i < n; ++i) std::swap(a[i], a[a.size() - 1 - i]);
	}
	
	std::vector<int> operator| (const std::vector<int> &a, const std::vector<int> &b){
		std::vector<int> c;
		for (size_t i = 0; i < a.size(); ++i){
			c.push_back(a[i] | b[i]);
		}
		return c;	
	}	

	std::vector<int> operator& (const std::vector<int> &a, const std::vector<int> &b){
		std::vector<int> c;
		for (size_t i = 0; i < a.size(); ++i){
			c.push_back(a[i] & b[i]);
		}
		return c;	
	}	
}  
