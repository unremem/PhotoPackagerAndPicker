#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include "CSVReader.h"

/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
std::vector<std::string> CSVReader::getData()
{
    std::vector<std::string> dataList;
	std::ifstream file;
	file.open(fileName.c_str(), std::ios::in);
	std::cout<< "Trying to open: " << fileName.c_str() << std::endl;
	if( !file.is_open() )
    {
        std::cout<< "Error Opening File!" << std::endl;
        return dataList;
    }

	std::string line = "";
	// Iterate through each line and split the content using delimeter
	while (getline(file, line))
	{
		boost::algorithm::split(dataList, line, boost::is_any_of(delimeter));
	}
	// Close the File
	file.close();

	return dataList;
}
