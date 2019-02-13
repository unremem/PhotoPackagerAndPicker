#include <iostream>
#include <fstream>

#include "CSVWriter.h"

void CSVWriter::writeData( std::vector<std::string> data )
{
	std::ofstream file;
	file.open(fileName.c_str());
	std::cout<< "Trying to open: " << fileName.c_str() << std::endl;
	if( !file.is_open() )
    {
        std::cout<< "Error Opening File!" << std::endl;
        return;
    }

	for( int i = 0; i < data.size(); i++ )
    {
        file << data[i] << delimeter;
    }
	// Close the File
	file.close();
}
