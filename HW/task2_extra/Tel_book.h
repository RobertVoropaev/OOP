//
// Created by RobertVoropaev on 15.05.2016.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;

class Email_not_found : public exception {} email_not_found;

template <typename T>
int find(vector<T>& v, const T& el) {
    return find(v.begin(), v.end(), el) - v.begin();
}

template <typename T>
bool contains(vector<T>& v, const T& el) {
    return find(v.begin(), v.end(), el) != v.end();
}

class Person_data {
public:
    Person_data() {
    }

    Person_data(string phone) {
        phones.push_back(phone);
    }

    friend class Book;

private:
    vector<string> phones;
    string email;
};

class Book {
public:
    void new_person(string fio) {
        if(people.count(fio) != 0)
            throw "thePersonAlreadyExists";
        people[fio] = Person_data();
    }

    void new_person_with_phone(string fio, string phone) {
        if(people.count(fio) != 0)
            throw "thePersonAlreadyExists";
        people[fio] = Person_data(phone);
    }

    void erase_person(string fio) {
        people.at(fio);
        people.erase(fio);
    }

    bool exists(string fio) {
        return people.count(fio);
    }

    vector<string> get_phones(string fio) {
        return people.at(fio).phones;
    }

    void clear() {
        people.clear();
    }

    void print_phones(string fio) {
        vector<string>& phones = people[fio].phones;
        vector<string>::iterator j;
        for(j = phones.begin(); j != phones.end(); ++j) {
            cout << *j << endl;
        }
    }

    void add_phone(string fio, string phone) {
        people.at(fio).phones.push_back(phone);
    }

    int get_phones_number(string fio) {
        return people.at(fio).phones.size();
    }

    void set_phone(string fio, string phone) {
        people.at(fio).phones.clear(); // ???
        people.at(fio).phones.push_back(phone);
    }

    void erase_phone(string fio, int i) {
        vector<string>& phones = people.at(fio).phones;
        phones.at(i);
        phones.erase(phones.begin() + i);
    }

    void erase_phone(string fio, string phone) {
        vector<string>& phones = people.at(fio).phones;
        erase_phone(fio, find(phones, phone));
    }

    void set_email(string fio, string email) {
        people.at(fio).email = email;
    }

    string get_email(string fio) {
        if(people.at(fio).email == "") {
            throw email_not_found;
        }
        return people.at(fio).email;
    }

    string get_fio(string phone) {
        map<string, Person_data>::iterator i;
        for(i = people.begin(); i != people.end(); ++i) {
            if(contains(i->second.phones, phone)) {
                return i->first;
            }
        }
        return "N/A";
    }

    void print_all_fio() {
        map<string, Person_data>::iterator i;
        for(i = people.begin(); i != people.end(); ++i) {
            cout << i->first << endl;
        }
    }

    void print_phones() {
        map<string, Person_data>::iterator i;
        for(i = people.begin(); i != people.end(); ++i) {
            string fio = i->first;
            vector<string>& phones = i->second.phones;
            vector<string>::iterator j;
            for(j = phones.begin(); j != phones.end(); ++j) {
                cout << fio << " : " << *j << endl;
            }
        }
    }

private:
    map<string, Person_data> people;
};

int main() {
    Book b;
    cout << "type 'help' to see all commands\n\n";
    while(true) {
        string s;
        cin >> s;
        if(s == "end") {
            break;
        }
        else if(s == "add_phone") {
            string phone, fio;
            cin >> phone;
            cin.get();
            getline(cin, fio);
            if(!b.exists(fio)) {
                b.new_person_with_phone(fio, phone);
            }
            else {
                cout << fio << " already has phones:\n";
                b.print_phones(fio);
                q:
                cout << "replace_all / add_new / cancel";
                string c;
                cin >> c;
                if(c == "replace_all") {
                    b.set_phone(fio, phone);
                }
                else if(c == "add_new") {
                    b.add_phone(fio, phone);
                }
                else {
                    goto q;
                }
            }
        } else if(s == "delete") {
            string fio;
            cin.get();
            getline(cin, fio);
            try {
                b.erase_person(fio);
                cout << "ok\n";
            } catch(out_of_range&) {
                cout << "fio not found\n";
            }
        } else if(s == "delete_all") {
            b.clear();
            cout << "ok\n";
        } else if(s == "erase_phone") {
            string fio, phone;
            cin >> phone;
            cin.get();
            getline(cin, fio);
            try {
                b.erase_phone(fio, phone);
                cout << "ok\n";
            } catch(out_of_range&) {
                cout << "fio/phone not found\n";
            }
        } else if(s == "print_phones") {
            string fio;
            cin.get();
            getline(cin, fio);
            try {
                b.print_phones(fio);
            } catch(out_of_range&) {
                cout << "fio not found\n";
            }
        } else if(s == "print_person") {
            string fio;
            cin.get();
            getline(cin, fio);
            try {
                b.print_phones(fio);
                string email = b.get_email(fio);
                if(email != "")
                    cout << email << endl;
            } catch(out_of_range&) {
                cout << "fio not found\n";
            }
        } else if(s == "print_all_fio")
            b.print_all_fio();
        else if(s == "print_all_phones")
            b.print_phones();
        else if(s == "who") {
            string phone;
            cin >> phone;
            cout << b.get_fio(phone) << endl;
        } else if(s == "set_email") {
            string fio, email;
            cin >> email;
            cin.get();
            getline(cin, fio);
            try {
                b.set_email(fio, email);
                cout << "ok\n";
            } catch(out_of_range&) {
                cout << "fio not found\n";
            }
        } else if(s == "get_email") {
            string fio;
            cin.get();
            getline(cin, fio);
            try {
                cout << b.get_email(fio);
            } catch(out_of_range&) {
                cout << "fio not found\n";
            } catch(Email_not_found&) {
                cout << "email not found\n";
            }
        } else if(s == "help" || s == "?") {
            cout << "end\n" << "add_phone [phone] [fio]\n" << "delete [fio]\n" << "delete_all\n"
                 << "erase_phone [phone] [fio]\n" << "print_phones [fio]\n" << "print_person [fio]\n"
                 << "print_all_fio\n" << "print_all_phones\n" << "who [phone]\n" << "set_email [email] [fio]\n"
                 << "get_email [fio]\n" << endl;
        } else
            cout << "Unknown command. Type 'help' to see all commands\n";
    }
    return 0;
}