#include <iostream>
#include <map>
#define F false
#define M true
using namespace std;

int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int oneDay = 86400;

struct stu {
    bool gender;
    int score;
    int showTimes;
    int runTimes;
    string level;
    void getRes() {
        if (runTimes >= 21)
            score += 10;
        else if (runTimes >= 19)
            score += 9;
        else if (runTimes >= 17)
            score += 8;
        else if (runTimes >= 14)
            score += 7;
        else if (runTimes >= 11)
            score += 6;
        else if (runTimes >= 7)
            score += 4;
        else if (runTimes >= 3)
            score += 2;
        showTimes += runTimes;
        if (showTimes >= 18)
            score += 5;
        else if (showTimes >= 15)
            score += 4;
        else if (showTimes >= 12)
            score += 3;
        else if (showTimes >= 9)
            score += 2;
        else if (showTimes >= 6)
            score += 1;
        
        if (score >= 95)
            level = "A";
        else if (score >= 90)
            level = "A-";
        else if (score >= 85)
            level = "B+";
        else if (score >= 80)
            level = "B";
        else if (score >= 77)
            level = "B-";
        else if (score >= 73)
            level = "C+";
        else if (score >= 70)
            level = "C";
        else if (score >= 67)
            level = "C-";
        else if (score >= 63)
            level = "D+";
        else if (score >= 60)
            level = "D";
        else 
            level = "F";
    }
};

map<string, stu> student;

int timeToSecond(const string &s) {
    int i = 0;
    int minute = 0;
    int second = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '\'') {
            second = stoi(s.substr(i + 1, s.size() - 1 - (i + 1)));
            break;
        }
        minute *= 10;
        minute += s[i] - '0';
    }
    second += minute * 60;
    return second;
}

int yearToDay(const string &t) {
    return (stoi(t.substr(0, 4)) - 1) * 365 + month[stoi(t.substr(4, 2))] + stoi(t.substr(6));
}

int hourToSecond(const string &t) {
    return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6));
}

int getRunScore(const string &id, const string &s) {
    int second = timeToSecond(s);
    bool gender = student[id].gender;
    if (gender == F) {
        if (second <= 400)
            return 20;
        if (second <= 417)
            return 18;
        if (second <= 434)
            return 16;
        if (second <= 451)
            return 14;
        if (second <= 470)
            return 12;
        if (second <= 485)
            return 10;
        if (second <= 500)
            return 8;
        if (second <= 515)
            return 6;
        if (second <= 530)
            return 4;
        if (second <= 540)
            return 2;
        return 0;
    }
    if (gender == M) {
        if (second <= 750)
            return 20;
        if (second <= 780)
            return 18;
        if (second <= 810)
            return 16;
        if (second <= 840)
            return 14;
        if (second <= 870)
            return 12;
        if (second <= 910)
            return 10;
        if (second <= 950)
            return 8;
        if (second <= 990)
            return 6;
        if (second <= 1030)
            return 4;
        if (second <= 1080)
            return 2;
        return 0;
    }
}

int main() {
    freopen("模测/a.in", "r", stdin);
    freopen("模测/a.out", "w", stdout);
    int n, m;
    cin >> n;
    int f;
    char passOrNot, sex;
    string t, id;
    for (int i = 1; i <= n; i++) {
        cin >> id;
        student[id].score = 0;
        student[id].runTimes = 0;
        cin >> sex >> student[id].score >> t >> passOrNot >> f >> student[id].showTimes;
        student[id].gender = (sex == 'F' ? F : M);
        student[id].score += (getRunScore(id, t) + f + (passOrNot == 'P' ? 10 : 0));
    }

    // deal with run times
    cin >> m;
    int preDay = 0, day, start, preEnd = 0, end, steps, pauseSecond;
    float distance;
    string t1, t2, t3;
    for (int i = 0; i < m; i++) {
        cin >> t >> id >> t1 >> t2 >> distance >> t3 >> steps; 
        distance *= 1000.0;
        day = yearToDay(t);
        start = hourToSecond(t1);
        end = hourToSecond(t2);
        pauseSecond = timeToSecond(t3);
        if (student[id].gender == F && distance < 1500)
            continue;
        if (student[id].gender == M && distance < 3000)
            continue;
        float avg = distance / (end - start);
        if (avg < 2 || avg > 5)
            continue;
        if (pauseSecond > 270)
            continue;
        if (distance / steps > 1.5)
            continue;
        if (((day - preDay) * oneDay + start - preEnd < 21600) && preEnd != 0)
            continue;
        ++student[id].runTimes;
        preDay = day;
        preEnd = end;
    }
    for (auto &p : student) {
        p.second.getRes();
        cout << p.first << ' ' << p.second.score << ' ' << p.second.level << endl;
    }

    return 0;
}