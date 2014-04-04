#include <cstdio>
#include "String.h"
using namespace std;

int main( )
{
    /* Simple constructor String(const char *str) */
    String a = "this";
    String b = "that";

    /* operator==(const String &lhs, const String &rhs) */
    if ( a == b )
      cout << a <<" "<< b <<" same string. " << endl;
    else
      cout << a <<" "<< b <<" different string. " << endl;

    /* operator+=(const String &rhs) */
    a += a;
    cout <<"a : " << a << endl;

    /* operator+(String &lhs, String &rhs) */
    String s = a + b;
    cout <<"s : " << s << endl;

    /* Copy constructor String(const String &rhs) */
    String c = a;
    /* operator +=(const char *str) */
    c += "then";

    /* default constructor String(const char *str = NULL) */
    String d;
    for( int i = 0; i < 300000; i++ )
        d += "a";
    cout << d.length( ) << "\n";

    cout << "Enter a String\n" ;
    String e;
    cin >> e;
    e += "";
    /* operator=(const String &rhs) */
    d = e;
    /* operator << (ostream &out, const String &str) */
    cout << d << endl;
    cin.ignore();

    /* getline(instream &in, String &s) */
    getline(cin, e);
    /* operator << (ostream &out, const String &str) */
    cout << e << endl;
    /* operator[](const int index) */
    e[1] = 'a';

    /* operator[](const int index) const  */
    char x = e[1];
    cout << x << endl;
    return 0;
}
