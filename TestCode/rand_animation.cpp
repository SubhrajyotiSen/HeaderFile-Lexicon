//dver = 1

#include <iostream>
#include "robot 4.h"
using namespace std;

int main() {
	char message[5000];
	cout << "\t  ";
	strcpy( message, ascii_heading( "Tic Tac Toe" ) );
	rand_animation( message, 't', 2000 );
	getch();
	return 0;
}
