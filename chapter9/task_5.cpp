



#include "std_lib_facilities.h"

struct ISBN
{
	string code;
	ISBN(int first, int second, int third, char x);
	ISBN(int first, int second, int third, int x);

};
struct Date
{
	int year;
	int month;
	int day;
	Date(int a_year, int a_month, int a_day);
};

class Book {
public:
	Book(string a_title, string author_surn, Date date, ISBN code);
	void show_self();
private:
	string title;
	string author_surname;
	//license_registr_date;
	int year;
	int month;
	int day;
	bool book_on_hands;
	string ISBN_code;
};

int main()
{
	try
	{
		Book mybook("me", "anotherme", Date(1999, 02, 25), ISBN(1, 2, 3, 'K'));
		mybook.show_self();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "hz" << endl;
	}

	return 0;
};

ISBN::ISBN(int first, int second, int third, char x)
{
	code = to_string(first) + "-" + to_string(second) + "-" + to_string(third) + "-" + x;
}

ISBN::ISBN(int first, int second, int third, int x)
{
	code = to_string(first) + "-" + to_string(second) + "-" + to_string(third) + "-" + to_string(x);


}

Date::Date(int a_year, int a_month, int a_day)
:year(a_year),month(a_month),day(a_day)
{
}

Book::Book(string a_title, string author_surn, Date date, ISBN code)
	:title(a_title),author_surname(author_surn)
{
	//from struct to this brrr
	day = date.day; month = date.month; year=date.year;
	ISBN_code = code.code;
}

void Book::show_self()
{
	cout << this->title << " " << this->author_surname<<this->ISBN_code;
}
