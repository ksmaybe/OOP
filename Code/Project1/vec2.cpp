#include "std_lib_facilities.h"

class vect
{
	int sz;
	double* elem;
public:
	vect(const vect& arg);
	vect & operator=(const vect& a);
	vect(int s)
		:sz{ s }, elem{ new double[s] } {
		for (int i = 0; i < sz; ++i) elem[i] = 0.0;
	   }
	   vect(initializer_list<double> lst)
	   :sz{static_cast<int>(lst.size())},elem{new double[sz]}
	   {
	   copy(lst.begin(), lst.end(), elem);
	   }
	   double& operator[](int n) { return elem[n]; }
	~vect()
	{
		delete[] elem;
	}
	double get(int i);
	void set(int i, double d);
};

double vect::get(int i)
{
	return elem[i];
}

void vect::set(int i, double d)
{
	elem[i] = d;
}

vect::vect(const vect& arg)
	:sz{arg.sz},elem{new double[arg.sz]}
{
	copy(arg.elem,arg.elem+arg.sz,elem);
}

vect& vect::operator=(const vect& a)
{
	double* p = new double[a.sz];
	copy(a.elem, a.elem+a.sz, p);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

void f(int n)
{
	cout << n << endl;
	vect v(n);
	v[2]=2.2;
	vect v2 = v;
	v[1]=9.9;
	v2[0]= 8.8;
	cout << v.get(0) << '\t' << v.get(1) << '\t' << v.get(2) << endl;
	cout << v2.get(0) << '\t' << v2.get(1) << '\t' << v2.get(2) << endl;

}

int main()
{
	for (int i = 4; i <= 10000;i++) (f(i));
	keep_window_open();
	return 0;
}