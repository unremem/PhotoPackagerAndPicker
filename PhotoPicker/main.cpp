#include <iostream>
#include <windows.h>

#include "CSVWriter.h"

using namespace std;

int main()
{
    CSVWriter TestWrite( "PhotoSet.csv" );
    std::vector<std::string> FileNames;
    WIN32_FIND_DATA data;
    HANDLE hFind = FindFirstFile("*", &data);      // DIRECTORY

    if ( hFind != INVALID_HANDLE_VALUE ) {
        do {
            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
            {
                string newFileName ( data.cFileName );
                string newFileExt;

                // remove the extensions
                size_t lastdot = newFileName.find_last_of(".");
                if (lastdot != std::string::npos)
                {
                    newFileExt = newFileName.substr(lastdot);
                    newFileName = newFileName.substr(0, lastdot);
                }

                if( newFileExt == ".dll" || newFileExt == ".exe" || newFileExt == ".csv" ) continue;

                FileNames.push_back( newFileName );
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }

    TestWrite.writeData( FileNames );

    cout << "DONE! Press ENTER to exit. " << endl;
    cin.ignore();

    return 0;
}
