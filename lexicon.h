#ifndef LEXICON_H
#define LEXICON_H

#include <iostream>
#include <process.h>

#define MAX_WORD_LEN 20

class letter{
	private:
		char let;
		letter *next, *prev;
		
	public:
		letter();
		letter( char character );
		void operator = ( char character );
		void operator = ( letter character );
		void CopySettings( letter &character );
		char operator + ( int number );
		char operator - ( int number );
		letter operator ++ ();
		letter operator ++ ( int );
		letter operator -- ();
		letter operator -- ( int );
		friend std::ostream& operator << ( std::ostream &out, letter &cur );
		void SetNext( letter* next_pointer );
		void SetPrev( letter* prev_pointer );
		letter* RetNext();
		letter* RetPrev();
		bool operator == ( letter &character );
		bool operator == ( char character );
		bool operator != ( letter &character );
		bool operator != ( char character );
		operator char();
};

class String {
	private:
		letter *l;
		int s_pos;
		void ClrStr();
		void CreateNextLetter();
	public:
		String();
		void operator = ( String& word );
		String& operator + ( char character );
		void operator += ( char character );
		char& operator [] ( int pos );
		void operator () ( int pos );
		void operator = ( const char word[] );
		String& operator + ( const char word[] );
		void operator += ( const char word[] );
		friend std::ostream& operator << ( std::ostream &out, String &word );
		friend std::istream& operator >> ( std::istream &in, String &word );
		std::istream& getline( std::istream &in, unsigned int max_len, char ender );
		std::istream& getline( unsigned int max_len, char ender );
		
		int strlen();
		operator char*();
};

//	<----- Class letter ----->

// constructor for initial value
letter::letter() {
	let = '\0';
	next = NULL;	prev = NULL;
	return;
}

// constructor which also assigns value to current_object->let
letter::letter( char character ) {
	letter();
	this->let = character;
	return;
}

void	// assignong value to current_object->let from a char
letter::operator = ( char character ) {
	this->let = character;
	return;
}

void	// assigning value to current_object->let from another object
letter::operator = ( letter character ) {
	this->let = character.let;
	return;
}

void	// copy location values from one object to cur_obj
letter::CopySettings( letter &character ) {
	this->SetNext( character.RetNext() );
	this->SetPrev( character.RetPrev() );
	return;
}

char	// addition of an integer to current_object->let
letter::operator + ( int number ) {
	return this->let + ( char )number;
}

char	// subtraction of an integer from current_object->let
letter::operator - ( int number ) {
	return this->let - ( char )number;
}

letter	// prefix ++ operator acting on current_objet->let
letter::operator ++ () {
	this->let = this->let + 1;
	return letter( this->let );
}

letter	// postfix ++ operator acting on current_objet->let
letter::operator ++ ( int ) {
	this->let = this->let + 1;
	return letter( this->let - 1 );
}

letter	// prefix -- operator acting on current_objet->let
letter::operator -- () {
	this->let = this->let - 1;
	return letter( this->let );
}

letter	// postfix -- operator acting on current_objet->let
letter::operator -- ( int ) {
	this->let = this->let - 1;
	return letter( this->let + 1 );
}

std::ostream&	// cascading operators to output curretn_object->let
operator << ( std::ostream &out, letter &cur ) {
	out.put( cur.let );
	return out;
}

void	// set the value in the cur_obj->next pointer
letter::SetNext( letter* next_pointer ) {
	next = next_pointer;
	return;
}

void	// set the value in the cur_obj->prev pointer
letter::SetPrev( letter* prev_pointer ) {
	prev = prev_pointer;
	return;
}

letter*	// return the value in the cur_onb->next pointer 
letter::RetNext() {
	return next;
}

letter*	// return the value in the cur_obj->prev pointer
letter::RetPrev() {
	return prev;
}

bool	// compare values of cur_obj->let and another_obj->let for equality
letter::operator == ( letter &character ) {
	if( this->let == character.let )	return true;
	else	return false;
}

bool	// compare values of cur_obj->let and a char for equality
letter::operator == ( char character ) {
	if( this->let == character )	return true;
	else	return false;
}

bool	// compare values of cur_obj->let and another_obj->let for inequality
letter::operator != ( letter &character ) {
	if( this->let != character.let )	return true;
	else	return false;
}

bool	// compare values of cur_obj->let and a char for inequality
letter::operator != ( char character ) {
	if( this->let != character )	return true;
	else	return false;
}

// conversion to char
letter::operator char() {
	return this->let;
}

//	<-----Class String----->

// constructor
String::String() {
	l = NULL;
	CreateNextLetter();
	s_pos = -1;
}

void	// clean the characters stored in the string
String::ClrStr() {
	this->operator()( 0 );
	letter *ptr;
	do {
		ptr = l->RetNext();
		delete l;
		l = ptr;
	} while( ptr != NULL );
	CreateNextLetter();
	this->s_pos = -1;
	return;
}

void	// Create next letter block
String::CreateNextLetter() {
	letter *ptr;
	ptr = NULL;
	ptr = new letter;
	ptr->SetNext( NULL );
	if( this->l != NULL ) {
		ptr->SetPrev( this->l );
		this->l->SetNext( ptr );
	}
	this->l = ptr;
	if( l == NULL ) {
		std::cerr << "Overflow!\nAborting Session\n\n";	exit( 1 );
	}
	return;
}

void	// moving obj cursor to specified position
String::operator () ( int pos ) {
	int len = this->strlen();
	int counter = 0;
	if( pos < 0 )	pos = 0;
	if( pos <= len ) {
		while( this->l->RetPrev() != NULL )	this->l = this->l->RetPrev();
		while( counter != pos ) {
			this->l = this->l->RetNext();
			counter++;
		}
		this->s_pos = pos;
	}
	return;
}

char&	// returning character ( and location ) stored in a specific position
String::operator [] ( int pos ) {
	int len = this->strlen();	int s_pos_orig = s_pos;
	letter *ptr;
	ptr = new letter;
	if( !( pos > len || pos < 0 ) ) {
		this->operator()( pos );
		ptr = this->l;
		this->operator()( s_pos_orig );
		return (char&)*ptr;
	}
	else {
		std::cerr << "Invalid position is given for String!\nAborting Session\n\n";	exit( 2 );
	}
}

void	// addition of another obj into cur_obj
String::operator = ( String& word ) {
	char* word_c;
	const int len = word.strlen();
	word_c = new char[len + 1];
	word_c = word;
	*this = word_c;
	return;
}

String&	// addition of a single character into another object (returned)
String::operator + ( char character ) {
	if( this->s_pos == -1 )	this->s_pos = this->strlen();
	letter *temp;
	temp = new letter;
	*temp = character;
	String *ret;
	ret = new String;
	*ret = *this;
	ret->operator()( this->s_pos );
	if( this->s_pos != 0 ) {
		temp->SetNext( ret->l );
		temp->SetPrev( ret->l->RetPrev() );
		ret->l->SetPrev( temp );
		ret->l = temp->RetPrev();
		ret->l->SetNext( temp );
	}
	else {
		temp->SetPrev( NULL );
		temp->SetNext( ret->l );
		ret->l->SetPrev( temp );
	}
	ret->operator()( this->s_pos );
	return *ret;
}

void	// addition of single character to the cur_obj
String::operator += ( char character ) {
	*this = *this + character;
	return;
}

void	// assigning information to cur_obj->l from a const char string
String::operator = ( const char word[] ) {
	this->ClrStr();
	int i = 0;
	while( word[i] != '\0' ) {
		*this->l = word[i];
		this->CreateNextLetter();
		i++;
	}
	this->operator()( 0 );	this->s_pos = -1;
	return;
}

String&	// addition of a char string constant to another object and returned
String::operator + ( const char word[] ) {
	int counter = 0;
	while( word[counter + 1] != '\0' )	counter++;
	String *ret;
	ret = new String;
	*ret = *this;
	for(; counter >= 0; counter-- )	*ret += word[counter];
	return *ret;
}

void	// addition of a char string constant to cur_obj
String::operator += ( const char word[] ) {
	*this = *this + word;
	return;
}

std::ostream&	// output the value saved in cur_obj->l
operator << ( std::ostream &out, String &word ) {
	word( 0 );
	while( !( word.l->RetNext() == NULL ) ) {
		out << *word.l;
		word.l = word.l->RetNext();
	}
	word( 0 );
	word.s_pos = -1;
	return out;
}

std::istream&	// save input ( word by word ) in cut_obj->l
operator >> ( std::istream &in, String &word ) {
	char *temp;
	temp = new char[MAX_WORD_LEN];
	in >> temp;
	word.ClrStr();
	word = temp;
	delete temp;
	return in;
}

std::istream&	// get data from a stream
String::getline( std::istream &in, unsigned int max_len, char ender = '\n' ) {
	char* word;
	word = new char[max_len + 1];
	in.getline( word, max_len + 1, ender );
	this->ClrStr();
	*this = word;
	delete word;
	return in;
}

std::istream&	// get data from a cin stream ( default )
String::getline( unsigned int max_len, char ender = '\n' ) {
	return this->getline( std::cin, max_len, ender );
}

int	// return the length of the saved string
String::strlen() {
	int counter = 0;
	if( this->l != NULL ) {
		while( this->l->RetPrev() != NULL )	this->l = this->l->RetPrev();
		while( l->RetNext() != NULL ) {
			l = l->RetNext();
			counter++;
		}
		while( this->l->RetPrev() != NULL )	this->l = this->l->RetPrev();
	}
	return counter;
}


// conversion to char*
String::operator char*() {
	char* word;
	const int len = this->strlen();
	word = new char[len + 1];
	this->operator()( 0 );
	for( int i = 0; i <= len; i++ ) {
		word[i] = *this->l;
		this->l = this->l->RetNext();
	}
	return word;
}
#endif
