



#include "std_lib_facilities.h"


vector<string>roman_digit_tbl;
void init_print_tbl(vector<string>& tbl) {
	tbl.push_back("I");
	tbl.push_back("II");
	tbl.push_back("III");
	tbl.push_back("IV");
	tbl.push_back("V");
	tbl.push_back("VI");
	tbl.push_back("VII");
	tbl.push_back("VIII");
	tbl.push_back("IX");
}

class Roman_int
{
public:
	enum  Romans {
		I = 0, II, III, IV, V, VI, VII, VIII, IX
	};
	Roman_int():digit(Roman_int::I) {}; //default digit is one
	Roman_int(Romans a_digit);
	int as_int();
	string& get_digit() const {
		return roman_digit_tbl[digit];
	}
private:
	Romans digit;
};

Roman_int::Roman_int(Romans a_digit)
	:digit(a_digit)
{
	
}

int Roman_int::as_int() {
	
	//plus one because romands do not have zero so first digit is one
	return digit+1;
}

ostream& operator <<(ostream& os, const Roman_int& ri) {
	return os << ri.get_digit();
}

istream& operator >>(istream& is, Roman_int& ri) {
	string roman;
	is >> roman;
	for (size_t i = 0; i < roman_digit_tbl.size(); i++)
	{
		if (roman== roman_digit_tbl[i])
		{
			ri = Roman_int(Roman_int::Romans(i));
			return is;
		}
	}
	return is;
}

int main()
{
	try
	{
		init_print_tbl(roman_digit_tbl);


		Roman_int r(Roman_int::V);
		cout <<"Roman "<< r <<" equels "<< r.as_int()<<" "<<endl;
		Roman_int rr;
		cin >> rr;
		cout << "Roman " << rr << " equels " << rr.as_int() << " " << endl;
	}
	catch (const std::exception& e) {

	}

	return 0;
};

