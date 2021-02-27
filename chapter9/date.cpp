


#include "std_lib_facilities.h"


//------------------------------------------------------------------------------

//Month operator++(Month& m) {
//
//	m = (m == Month::dec) ? Month::jan : Month(m + 1);
//	return m;
//}



class Date
{
public:
	enum  Month { jan = 1, feb, mar, may, jun, jul, aug, sep, oct, nov, dec };

	class Invalid {};//used like exception
	Date(int yy, Month mm, int dd);//have check on date
	
	Date();
	void add_day(int n);
	int day() const { return d; }
	int month() { return m; }
	int year() { return y; }
	~Date();

private:
	int y;
	Month m;
	int d;
	bool check();//if date correct returns true
};
Date& default_date() {
	static Date dd(2001, Date::jan, 1);
	return dd;
}


Date::Date(int yy, Month mm, int dd)
	:y(yy),  m(mm), d(dd)
{
	if (!check())
	{
		throw Invalid();
	}
}



void Date::add_day(int n)
{
}

Date::~Date()
{
}

bool Date::check()
{
	if (m < 1 || 12 < m)return false;
}


void f(int x, int y) {
	try
	{
		Date dxy(2009, Date::dec, y);
		//cout << dxy << '\n';
		dxy.add_day(2);
	}
	catch (Date::Invalid)
	{
		error("invalid date");
	}

}
void foo(Date& d, const Date& start_t) {

	int a = d.day();
	int b = start_t.day();


}

int main()
{

	//327
	return 0;
};