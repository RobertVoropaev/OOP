//
// Created by RobertVoropaev on 15.05.2016.
//

#ifndef TASK2_EXTRA_RADIO_H
#define TASK2_EXTRA_RADIO_H

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Radio {
public:
    Radio();
    int track_score(const string& ip, unsigned int track_id, int score, unsigned int time);
    void get();
private:
    map<int, int> id_to_score;
    multimap<int, int> score_to_id;
    map<string, int> ip_to_time;
};

#endif //TASK2_EXTRA_RADIO_H
