//
// Created by RobertVoropaev on 15.03.2020.
//

#ifndef DZ04_STRING_H
#define DZ04_STRING_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String {
public:
    String(char const* str = (char*) "");
    String(char c);
    String(char c, size_t n);

    String(const String& obj);
    String& operator=(String const& obj);

    virtual ~String();

    explicit operator bool()            const;
    explicit operator char const*()     const;

    String& operator+=(String const& obj);
    String& operator*=(size_t n);

    char    operator[](size_t i)        const;
    char&   operator[](size_t i);
    size_t  size()                      const;

    friend bool operator==(String const& s1, String const& s2);

    friend ostream& operator<<(ostream& stream, String const& s);
    friend istream& operator>>(istream& stream, String& s);
private:
    char*   data_;
    size_t  size_;
    size_t  max_input_size_ = 1024;
};

String operator+(String s1, String const& s2);
String operator*(String s, size_t n);

bool operator!=(String const& s1, String const& s2);

#endif //DZ04_STRING_H