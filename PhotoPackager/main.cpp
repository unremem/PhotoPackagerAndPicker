#include <cstdio>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <windows.h>

#include "CSVReader.h"

using namespace std;

int main()
{
    CSVReader TestRead( "PhotoSet.csv" );
    vector<string> FileNames = TestRead.getData();
    if( FileNames.size() == 0 ) return 0;

    cout << "Creating: PhotoSet" << endl;
    if ( !CreateDirectory("PhotoSet" ,NULL) &&
    ERROR_ALREADY_EXISTS != GetLastError() )
        cerr << "Error :  " << strerror(errno) << endl;

    else
        cout << "Directory created" << endl;

    for( int i = 0; i < FileNames.size(); i++ )
    {
        string fileName = FileNames[i] + ".*";
        //cout << fileName << endl;

        vector< string > all_matching_files;

        WIN32_FIND_DATA data;
        HANDLE hFind = FindFirstFile(fileName.c_str(), &data);      // DIRECTORY

        if ( hFind != INVALID_HANDLE_VALUE ) {
            do {
                string newFileName ( data.cFileName );
                string newString = "PhotoSet\\" + newFileName;
                if(CopyFile(data.cFileName, newString.c_str(), FALSE) < 0)
                {
                    std::cout << strerror(errno) << '\n';
                }
                else
                {
                    std::cout << "Copying " << data.cFileName << std::endl;
                }
            } while (FindNextFile(hFind, &data));
            FindClose(hFind);
        }
        else
        {
            cout << "File " << fileName << " Not Found!" << endl;
        }
    }

    cout << "DONE! Press ENTER to exit. " << endl;
    cin.ignore();

    return 0;
}
