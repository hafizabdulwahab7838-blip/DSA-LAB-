
#include<iostream>
using namespace std;
class course {
    virtual void duration() = 0;
};
class onlinecourse : public course {
    int week;
    int hoursperweek;

public:
    onlinecourse(int w, int hp) {
        week = w;
        hoursperweek = hp;
    }

    void duration() override {
        cout << "Online Course" << endl;
        cout << "Weeks: " << week << endl;
        cout << "Hours per week: " << hoursperweek << endl;
        cout << "Total study hours: "
            << week * hoursperweek << endl;
    }
};

class offlinecourse : public course {
    int months;
    int hoursperday;

public:
    offlinecourse(int m, int hpday) {
        months = m;
        hoursperday = hpday;
    }

    void duration() override {
        cout << "Offline Course" << endl;
        cout << "Months: " << months << endl;
        cout << "Hours per day: " << hoursperday << endl;
        cout << "Total study hours: "
            << months * 30 * hoursperday << endl;
    }
};

int main() {
    onlinecourse c1(7, 9);
    c1.duration();

    cout << endl;

    offlinecourse c2(8, 10);
    c2.duration();

    return 0;
}