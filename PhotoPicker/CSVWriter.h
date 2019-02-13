#ifndef CSVREADER_H
#define CSVREADER_H
#include <string>
#include <vector>

class CSVWriter
{
    std::string fileName;
	std::string delimeter;

public:
	CSVWriter(std::string filename, std::string delm = ",") :
			fileName(filename), delimeter(delm)
	{ }

	// Function to fetch data from a CSV File
	void writeData( std::vector<std::string> data );
};

#endif // CSVREADER_H
