#include <string.h>
#include "String.h"

String::String( const char * cstring )
{
    if( cstring == NULL )
        cstring = "";
    strLength = strlen( cstring );
    bufferLength = strLength + 1;
    buffer = new char[ bufferLength ];
    strcpy( buffer, cstring );
}

String::String( const String & str )
{
    strLength = str.length( );
    bufferLength = strLength + 1;
    buffer = new char[ bufferLength ];
    strcpy( buffer,str.buffer );
}

const String& String::operator=( const String& rhs )
{
    if( this != &rhs )
    {
        if( bufferLength < rhs.length() + 1 )
        {
            delete []buffer;
            bufferLength = rhs.length() + 1;
            buffer = new char[ bufferLength ];
        }
        strLength = rhs.length();
        strcpy( buffer, rhs.buffer );
    }
    return *this;
}

const String& String::operator+=( const String & rhs )
{
    if( this == &rhs )
    {
        String copy( rhs );
        return *this += copy;
    }

    int newLength = length( ) + rhs.length( );
    if( newLength >= bufferLength )
    {
        bufferLength = 2 * ( newLength + 1 );

        char *oldBuffer = buffer;
        buffer = new char[ bufferLength ];
        strcpy( buffer, oldBuffer );
        delete [ ] oldBuffer;
    }

    strcpy( buffer + length( ), rhs.buffer );
    strLength = newLength;
    return *this;
}

const String& String::operator+=( const char *str )
{
        String rhs(str);
    int newLength = length( ) + rhs.length();
    if( newLength >= bufferLength )
    {
        bufferLength = 2 * ( newLength + 1 );

        char *oldBuffer = buffer;
        buffer = new char[ bufferLength ];
        strcpy( buffer, oldBuffer );
        delete [ ] oldBuffer;
    }

    strcpy( buffer + length( ), rhs.buffer );
    strLength = newLength;
    return *this;
}

const String operator+( const String & lhs, const String &rhs )
{
        String s(lhs);
        s += rhs;
        return s;
}

char& String::operator[]( int k )
{
    if( k < 0 || k >= strLength )
        throw StringIndexOutOfBounds( );
    return buffer[k];
}

char String::operator[]( int k ) const
{
    if( k < 0 || k >= strLength )
        throw StringIndexOutOfBounds( );
    return buffer[k];
}

std::ostream& operator<<( std::ostream& out, const String& str )
{
    out << str.to_str();
        return out;
}

std::istream& operator>>( std::istream & in, String& str )
{
    char buf[ String::MAX_LENGTH + 1 ];
    in >> buf;
    if( !in.fail( ) )
        str = buf;
    return in;
}

std::istream& getline( std::istream& in, String& str )
{
    char buf[ String::MAX_LENGTH + 1 ];
    in.getline( buf, String::MAX_LENGTH );
    if( !in.fail( ) )
        str = buf;
    return in;
}

bool operator==( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) == 0;
}

bool operator!=( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) != 0;
}

bool operator<( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) < 0;
}

bool operator<=( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) <= 0;
}

bool operator>( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) > 0;
}

bool operator>=( const String& lhs, const String& rhs )
{
    return strcmp( lhs.to_str( ), rhs.to_str( ) ) >= 0;
}
