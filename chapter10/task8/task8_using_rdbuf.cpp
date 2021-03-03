



#include "std_lib_facilities.h"

void cat_files(const string & output_f,const string &src1_file, const string& src2_file)
//cat_file file what w ; src_file fila what will be added to cat_file
{
	std::ofstream main(output_f, ios_base::binary|ios_base::app);
	ifstream src(src1_file, ios_base::binary);
	ifstream src2(src2_file, ios_base::binary);
	if (src.is_open() && main.is_open()&& src2.is_open())
	{
        //just puts intu main buffer of src and src2 files
		main << src.rdbuf()<< src2.rdbuf();
	}
	else
	{
		error("buffer is now associated with stream");//better error handling
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
		cout << "input output file name \n";
		cin >> output_f_name;
		if (!cin)
		{
			error("no output file name file provided");
		}
		
		cat_files(output_f_name,input_file_name_one, input_f_two);
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	return 0;
};

