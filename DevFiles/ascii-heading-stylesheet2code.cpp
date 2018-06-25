#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
	char line[200];
	fstream fin, fout;
	int i = 0, j = 0;
	
	fin.open( "ascii-heading-stylesheet.txt", ios::in );
	fout.open( "ascii-heading-switch-code.txt", ios::out | ios::trunc );
	
	// adding case for space
	
	fout << "\t				case \' \':" << endl;
	fout << "\t					switch( x ) {" << endl;
	fout << "\t						case 0:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t						case 1:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t						case 2:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t						case 3:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t						case 4:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t						case 5:" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							var[m] = \' \'; m++;" << endl;
	fout << "\t							break;" << endl;
	fout << "\t					}						" << endl;
	fout << "\t					break;" << endl;


	
	// ending special case
	while( fin.getline( line, 200 ) ) {
		fout << "\t\t\t\t\t";
		fout << "case \'" << char( 'A' + i ) << "\':" << endl;
		fout << "\t\t\t\t\t\t";
		fout << "switch( x ) {" << endl;
		
		while( strlen( line ) != 0 ) {
			fout << "\t\t\t\t\t\t\t";
			fout << "case " << j <<":" << endl;
			for( int k = 0; k < strlen( line ); k++ ) {
				fout << "\t\t\t\t\t\t\t\t";
				if( line[k] == '\\' ) {
					fout << "var[m] = \'\\\\\';";
				}
				else if( line[k] == '\'' ) {
					fout << "var[m] = \'\\\'\';";
				}
				else {
					fout << "var[m] = \'" << line[k] << "\';";
				}
				fout << " m++;" << endl;
			}
			fout << "\t\t\t\t\t\t\t\t";
			fout << "break;" << endl;
			fin.getline( line, 200 );
			j++;
		}
		fout << "\t\t\t\t\t\t";
		fout << "}" << endl;
		fout << "\t\t\t\t\t\t";
		fout << "break;" << endl;
		j = 0;
		i++;
	}
	
	return 0;
}
