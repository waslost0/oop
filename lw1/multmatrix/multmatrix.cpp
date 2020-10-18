#include <iostream>
#include <vector>

constexpr int MATRIX_SIZE = 3;
using Matrix = float[MATRIX_SIZE][MATRIX_SIZE];


template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	for (size_t i = 1; i < v.size() + 1; ++i) {
		out << i << " ";
	}
	out << "\n";
	out << "    Parents: ";
	for (size_t i = 0; i < v.size(); ++i) {
	/*	if (v[i] == 0) {
			out << "0 ";
		}
		else {*/
			out << v[i] << " ";
		//}
	}
	out << "\n";
	return out;
}
D


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Wrong input.\n"
			"Example: multmatrix.exe <matrixfile1><matrixfile2>" << std::endl;
		return 1;
	}

	std::string urlFile1 = argv[1];
	std::string urlFile2 = argv[2];
	Matrix matrix1;
	Matrix matrix2;

}

