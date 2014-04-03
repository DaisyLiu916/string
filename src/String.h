#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class StringIndexOutOfBounds { };

class String
{
  public:
    String( const char *cstring = "" );     // Constructor 
    String( const String & str );           // Copy constructor
    ~String( )  {                            // Destructor
				delete []buffer; 
		}

    const String& operator=( const String& rhs );  // Copy s = s1 
    const String& operator+=( const String& rhs );  // Append // s += s1
		const String& operator+=( const char *str);  // s += "Hello"

		friend String operator+(const String &lhs, const String &rhs); // s = s1 + s2
		friend String operator+(const String &lhs, const char *str); // s = s1 + "hello"
		friend String operator+(const char *str, const String &rhs); // s = "hello" + s1

		/* conversion function */
    const char *to_str() const        // Return C-style string
      { return buffer; }
    int length() const               // Return string length
      { return strLength; }

    char  operator[]( int k ) const; // Accessor operator[] x = s[2]
    char& operator[]( int k );       // Mutator  operator[] s[2] = 'x'

    enum { MAX_LENGTH = 1024 };  // Maximum length for input string

		friend bool operator==( const String & lhs, const String & rhs );    // Compare ==
		friend bool operator!=( const String & lhs, const String & rhs );    // Compare !=
		friend bool operator< ( const String & lhs, const String & rhs );    // Compare <
		friend bool operator<=( const String & lhs, const String & rhs );    // Compare <=
		friend bool operator> ( const String & lhs, const String & rhs );    // Compare >
		friend bool operator>=( const String & lhs, const String & rhs );    // Compare >=

		friend std::ostream& operator<<( std::ostream& out, const String& str );    // Output   cout << s << endl;
		friend std::istream& operator>>( std::istream& in, String& str );           // Input		 cin >> s
		friend std::istream& getline( std::istream& in, String& str );              // Read line  getline(cin, s)
  private:
    char *buffer;                  // storage for characters
    int strLength;                 // length of string (# of characters)
    int bufferLength;              // capacity of buffer
};



#endif
