#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

enum PassengerType {
    ADULT, STUDENT, ELDER, CHILD
};

vector<string> stations = {
        "HUA", "SAM", "SIL", "LUM", "KHO", "SIR",
        "SUK", "PET", "RAM", "CUL", "HUI", "SUT",
        "RAT", "LAT", "PHA", "CHA", "KAM", "BAN"
};

map<char, string> passengerMap{{'A', "Adult"},
                               {'S', "Student"},
                               {'E', "Elder"},
                               {'C', "Child"}
};

map<char, vector<int>> rate{
        {'A', {16, 16, 19, 21, 23, 25, 28, 30, 32, 35, 37, 39, 42, 42, 42, 42, 42, 42}},
        {'S', {14, 14, 17, 19, 21, 22, 25, 27, 29, 31, 33, 35, 38, 38, 38, 38, 38, 38}},
        {'E', {8,  8,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 21, 21, 21}},
        {'C', {8,  8,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 21, 21, 21}},
};

string upper(const string s) {
    string dest = "";
    for (const auto &e : s) {
        dest += toupper(e);
    }
    return dest;
}

//template<typename T>
int indexOf(vector<string> haystack, string needle) {
    int pos = find(haystack.begin(), haystack.end(), needle) - haystack.begin();
    return pos < haystack.size() ? pos : -1;
}

void fareTable() {
    vector<char> p{'A', 'S', 'E', 'C'};
    printf("%-8s | ", "stations");
    for (int i = 0; i < 18; ++i) {
        printf("%3d | ", i);
    }
    cout << endl;
    for (auto &&item :p) {
        printf("%-8s | ", passengerMap[item].c_str());
        for (auto &&f :rate[item]) {
            printf("%3d | ", f);
        }
        cout << endl;
    }
}

int travelStation(string fromStation, string toStation) {
    int fromIdx = indexOf(stations, fromStation);
    int toIdx = indexOf(stations, toStation);
    return abs(fromIdx - toIdx);
}

int fare(string fromStation, string toStation, char passengerType) {
    return rate[passengerType][travelStation(fromStation, toStation)];
}

string route(string fromStation, string toStation, string sep = "->") {
    int fromIdx = indexOf(stations, fromStation);
    int toIdx = indexOf(stations, toStation);
    string s = "";
    if (fromIdx < toIdx) {
        for (int i = fromIdx; i < toIdx; ++i) {
            s += stations[i] + sep;
        }
        s += stations[toIdx];
    } else {
        for (int i = fromIdx; i > toIdx; --i) {
            s += stations[i] + "->";
        }
        s += stations[toIdx];
    }
    return s;
}

int main() {
    cout << "stations | " << route(stations.front(), stations.back(), " | ") << " |" << endl;
    fareTable();
    string fromStation;
    string toStation;
    char passengerType;
    cout << "enter from to passengerType (ex. SUK SAM A) ";
    cin >> fromStation >> toStation >> passengerType;
    fromStation = upper(fromStation);
    toStation = upper(toStation);
    cout << travelStation(fromStation, toStation) << " stations" << " " << route(fromStation, toStation) << endl;
    cout << "fare = " << fare(fromStation, toStation, toupper(passengerType)) << " baht" << endl;
    return 0;
}