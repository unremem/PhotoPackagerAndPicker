#ifndef CSVREADER_H
#define CSVREADER_H
#include <string>
#include <vector>

class CSVReader
{
    std::string fileName;
	std::string delimeter;

public:
	CSVReader(std::string filename, std::string delm = ",") :
			fileName(filename), delimeter(delm)
	{ }

	// Function to fetch data from a CSV File
	std::vector<std::string> getData();
};

#endif // CSVREADER_H
