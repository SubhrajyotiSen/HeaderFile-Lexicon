#include <iostream>
#include "robot_2.1.h"
#include <stdlib.h>
using namespace std;

int main() {
	int number = 26;
	char msg[] = {"Hello"};
	char message[500];
	int clear_len = 0;
	
	//cout << message << endl;
	
	COORD pos_start;
	pos_start.X = getX();
	pos_start.Y = getY();
	
	for( int i = 0; i < strlen( msg ); i++ ) {
		if( islower( msg[i] ) ) {
			msg[i] = toupper( msg[i] );
		}
	}
	
	char temp_msg[ strlen( msg ) ];
	for( int i = 0; i <= strlen( msg ); i++ ) {
		temp_msg[i] = '\0';
	}
	
	for( int j = 0; j <= number; j++ ) {
		clean_slate( pos_start.X, pos_start.Y );
		for( int i = 0; i <= strlen( msg ); i++ ) {
			message[i] = '\0';
		}
		gotoXY( pos_start.X, pos_start.Y, 0 );
		for( int i = 0; i < strlen( msg ); i++ ) {
			if( ( ( msg[i] - ( number - j ) ) >= 'A' ) ) {
				temp_msg[i] = msg[i] - ( number - j );
			}
			else {
				temp_msg[i] = msg[i] - ( number - j ) + 26;
			}
		}
		strcpy( message, ascii_heading( temp_msg ) );
		center_align( message );
		Sleep( 50 );
	}
	
	return 0;
}
