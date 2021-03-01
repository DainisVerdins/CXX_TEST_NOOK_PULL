



#include "std_lib_facilities.h"

struct Point {
	int x;
	int y;
	Point() { x = 0; y = 0; };
	Point(int xx, int yy) :x(xx), y(yy) {
		
	}
};
istream& operator>>(istream& is, Point& p) {

	int x = -1;
	int y=-1;
	char ch1;
	is >> x >> ch1 >> y;
	if (ch1!=',')
	{
		is.clear(ios_base::failbit);
		return is;
	}
	if (x<0||y<0)
	{
		error("negative cordinates");
		return is;
	}
	p = Point(x, y);
	return is;
}



void show_vector(const vector<Point>& v) {
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i].x << "," << v[i].y << endl;
	}
}

bool compare_two(const vector<Point>& first, const vector<Point>& second) {

	if (first.size()!=second.size())
	{
		return false;
	}
	for (size_t i = 0; i < first.size(); i++)
	{
		if (first[i].x!=second[i].x|| first[i].y != second[i].y)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<Point>original_points;
	int user_input_count = 2;
	try
	{
		Point p;	
		
		for (size_t i = 0; i < user_input_count; i++)
		{
			cout << "enter new point in 'x,y' manner,left inputs are " << user_input_count-i << "\n";
			cin >> p;
			if (!cin)
			{
				break;
			}
			original_points.push_back(p);
		}

		
		//PROMPT
		string file_name = "mydata.txt";
		ofstream ost(file_name);
		if (!ost)
		{
			error("cannot ooen file");
		}
		for (size_t i = 0; i < original_points.size(); i++)
		{
			ost << original_points[i].x << "," << original_points[i].y << '\n';
		}
		ost.close();
		ifstream ist(file_name);
		if (!ist)
		{
			error("cannot ooen file");
		}
		vector<Point>processed_points;

		Point pp;
		while (ist>>pp)
		{
			processed_points.push_back(pp);
		}
		show_vector(original_points);
		cout << "new vect now" << endl;
		show_vector(processed_points);

		if (compare_two(original_points, processed_points)!=true)
		{
			cout << "shit!" << endl;
		}

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

