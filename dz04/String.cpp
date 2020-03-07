#include "String.h"

#include <cstring>

String::String(char const* str) {
    size_ = strlen(str);
    data_ = new char[size_ + 1];
    strncpy(data_, str, size_ + 1);
}

String::String(char c) {
    size_ = 1;
    data_ = new char[size_ + 1];
    data_[0] = c;
    data_[size_] = 0;
}

String::String(char c, size_t n) {
    size_ = n;
    data_ = new char[size_ + 1];
    for(int i = 0; i < size_; i++) {
        data_[i] = c;
    }
    data_[size_] = 0;
}

String::String(const String& obj) {
    size_ = strlen(obj.data_);
    data_ = new char[size_ + 1];
    strncpy(data_, obj.data_, size_ + 1);
}

String::~String() {
    delete[] data_;
}

String& String::operator=(String const& obj) {
    if(this != &obj) {
        delete[] data_;
        size_ = obj.size_;
        data_ = new char[size_ + 1];
        strncpy(data_, obj.data_, size_ + 1);
    }
    return *this;
}

String::operator bool() const {
    return size_ != 0;
}

String::operator char const*() const {
    if(*this) {
        return data_;
    }
    return "";
}

String& String::operator+=(String const& obj) {
    char* old_data = data_;
    size_t old_size = size_;

    size_ = strlen(data_) + strlen(obj.data_) + 1;
    data_ = new char[size_];

    strncpy(data_, old_data, old_size);
    delete[] old_data;

    strncat(data_, obj.data_, obj.size_);
    return *this;
}

String operator+(String s1, String const& s2) {
    return s1 += s2;
}

String& String::operator*=(size_t n) {
    size_t old_size = size_;
    char* old_data = data_;

    size_ = old_size * n;
    data_ = new char[size_ + 1];
    data_[0] = 0;

    for(int i = 0; i < n; i++) {
        strncat(data_, old_data, old_size);
    }

    delete old_data;
    return *this;
}

String operator*(String s, size_t n) {
    return s *= n;
}


char String::operator[](size_t i) const {
    return data_[i];
}

char& String::operator[](size_t i) {
    return data_[i];
}

bool operator==(String const& s1, String const& s2) {
    return strcmp(s1.data_, s2.data_) == 0;
}

bool operator!=(String const& s1, String const& s2) {
    return !(s1 == s2);
}

size_t String::size() const{
    return size_;
}

ostream& operator<<(ostream& stream, String const& s) {
    stream << s.data_;
    return stream;
}

istream& operator>>(istream& stream, String& s) {
    char new_data[s.max_input_size_];
    delete[] s.data_;

    stream >> new_data;
    s.size_ = strlen(new_data) + 1;

    s.data_ = new char[s.size_];
    strncpy(s.data_, new_data, s.size_);
    return stream;
}