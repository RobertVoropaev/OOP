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
Radio::Radio() {
	id_to_score.insert(pair<int, int>(1, 0));
	score_to_id.insert(pair<int, int>(0, 1));
}
int Radio::track_score(string ip, unsigned int track_id, int score, unsigned int time) {
	map <string, int>::iterator p = ip_to_time.find(ip);
	bool this_ip_can_vote;
	if (p == ip_to_time.end()) {//���� ���� ip ��� �� ���� �� ���������, �� �������� ��� � ���� ������������ 
		ip_to_time.insert(pair<string, int>(ip, time));
		this_ip_can_vote = true;
	}
	else { //���� ���� ip ��������� ������, �� ���������� ��� �����, ��������� � �o�������� �����������
		if ((time - p->second) < 600) {//������ ������ 10 �����
			this_ip_can_vote = false;
		}
		else {//������ ������ 10 �����
			this_ip_can_vote = true;
			p->second = time;
		}
	}
	map <int, int>::iterator d = id_to_score.find(track_id);
	if (d == id_to_score.end()) {//����� ��� � ���� (��� ������� ����� ����)
		if (score == 0 || !this_ip_can_vote) {
			return 0;
		}
		else if (this_ip_can_vote) {
			id_to_score.insert(pair<int, int>(track_id, score));
			score_to_id.insert(pair<int, int>(score, track_id));
			d = id_to_score.find(track_id);
		}
	}
	else {//���� ���� � ����
		if (this_ip_can_vote) { //���� ip ����� ����������
			multimap <int, int>::iterator s = score_to_id.find(d->second);
			while (s->second != d->first)
				s++;
			score_to_id.erase(s);
			d->second += score;
			if (d->second == 0) {
				id_to_score.erase(d);//����� � ������� ��������� �� �������
				return 0;
			}
			else {
				score_to_id.insert(pair<int, int>(d->second, d->first));
				s = score_to_id.find(d->second);
			}
		}
	}
	return d->second;
}
void Radio::get() {
	multimap <int, int>::iterator EndSearch = score_to_id.end();
	EndSearch--;//��������� ������� � ������������ ���������
	multimap <int, int>::iterator BeginSearch = score_to_id.find(EndSearch->first), MinId = BeginSearch;//������ ������� � ������������ ���������
	while (BeginSearch != score_to_id.end()) {//����� �������� � ����������� id
		if (BeginSearch->second < MinId->second) {
			MinId = BeginSearch;
		}
		BeginSearch++;
	}
	map<int, int>::iterator p = id_to_score.find(MinId->second);
	map<int, int>::iterator Res = p;
	if ((Res->second) >= 0) {
		cout << Res->first << " " << Res->second << endl;
		p->second = -1;//���������� 
		score_to_id.erase(MinId);
		score_to_id.insert(pair<int, int>(p->second, p->first));
	}
	else {
		int i = 1;
		while (id_to_score.find(i) != id_to_score.end()) {
			i++;
		}
		cout << i << " " << 0 << endl;
		id_to_score.insert(pair<int, int>(i, -1));
		score_to_id.insert(pair<int, int>(-1, i));
	}
}
int main() {
	Radio MyRadio;
	string enter, ip;
	map <int, int>::iterator Get;
	unsigned int track_id, time;
	int score;
	for (;;) {
		cin >> enter;
		if (enter == "GET") {
			MyRadio.get();
		}
		else if (enter == "VOTE") {
			cin >> ip >> track_id >> score >> time;
			cout << MyRadio.track_score(ip, track_id, score, time) << endl;
		}
		else break;
	}
	cout << "OK";
	return 0;
}