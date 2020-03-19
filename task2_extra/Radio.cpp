//
// Created by RobertVoropaev on 15.05.2016.
//

#include "Radio.h"

Radio::Radio() {
    id_to_score.insert(pair<int, int>(1, 0));
    score_to_id.insert(pair<int, int>(0, 1));
}

int Radio::track_score(const string& ip, unsigned int track_id, int score, unsigned int time) {
    auto p = ip_to_time.find(ip);
    bool this_ip_can_vote;

    if(p == ip_to_time.end()) {
        ip_to_time.insert(pair<string, int>(ip, time));
        this_ip_can_vote = true;
    }
    else {
        if((time - p->second) < 600) {
            this_ip_can_vote = false;
        }
        else {
            this_ip_can_vote = true;
            p->second = time;
        }
    }

    auto d = id_to_score.find(track_id);
    if(d == id_to_score.end()) {
        if(score == 0 || !this_ip_can_vote) {
            return 0;
        }
        else {
            id_to_score.insert(pair<int, int>(track_id, score));
            score_to_id.insert(pair<int, int>(score, track_id));
            d = id_to_score.find(track_id);
        }
    }
    else {
        if(this_ip_can_vote) {
            auto s = score_to_id.find(d->second);

            while(s->second != d->first)
                s++;
            score_to_id.erase(s);
            d->second += score;

            if(d->second == 0) {
                id_to_score.erase(d);
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
    auto EndSearch = score_to_id.end();
    EndSearch--;
    auto BeginSearch = score_to_id.find(EndSearch->first), MinId = BeginSearch;

    while(BeginSearch != score_to_id.end()) {
        if(BeginSearch->second < MinId->second) {
            MinId = BeginSearch;
        }
        BeginSearch++;
    }

    auto p = id_to_score.find(MinId->second);
    auto Res = p;

    if((Res->second) >= 0) {
        cout << Res->first << " " << Res->second << endl;
        p->second = -1;
        score_to_id.erase(MinId);
        score_to_id.insert(pair<int, int>(p->second, p->first));
    }
    else {
        int i = 1;
        while(id_to_score.find(i) != id_to_score.end()) {
            i++;
        }
        cout << i << " " << 0 << endl;
        id_to_score.insert(pair<int, int>(i, -1));
        score_to_id.insert(pair<int, int>(-1, i));
    }
}