



#include "std_lib_facilities.h"

void cat_files(ofstream& main_file, ifstream& src_file)
//cat_file file what w ; src_file fila what will be added to cat_file
{
	string line;
	//if (!cat_file.is_open())error("Error file is not opened and asociated with stream");
	if (src_file.is_open() &&main_file.is_open())
	{
		main_file << '\n';
		while (getline(src_file,line) ){
			main_file << line<<'\n';
		}
		src_file.close();
		main_file.close();
	}
}

int main()
{
	try
	{
		string input_f_two;
		string output_f_name;
		string input_file_name_one;//this will be cantantinated
		cout << "input first file name \n";
		cin >> input_file_name_one;
		if (!cin)
		{
			error("no input file provided");
		}
		cout << "input second file name \n";
		cin >> input_f_two;
		if (!cin)
		{
			error("no input file provided");
		}
		/*cout << "ouotput file name \n";
		cin >> output_f_name;
		if (!cin)
		{
			error("no input file provided");
		}*/
		ofstream ofs(input_file_name_one, ios::out | ios::app);
		ifstream ifs(input_f_two);
		
		cat_files(ofs, ifs);
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	return 0;
};

