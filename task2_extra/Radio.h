#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
class Radio {
	map<int, int> id_to_score;
	multimap<int, int> score_to_id;
	map<string, int> ip_to_time;
public:
	Radio();
	int track_score(string ip, unsigned int track_id, int score, unsigned int time);
	void get();
};
