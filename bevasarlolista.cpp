#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {

    ifstream infile("lista.txt");
    vector <string> vasarlasok;
    string sor;
    double vasarlasdb = 0;
    while (getline(infile, sor)) {
        istringstream iss(sor);
        string id;
        string termek;
        iss >> id;
        while (iss >> termek) {
            vasarlasok.push_back(termek);
        }
        vasarlasdb++;
    }
    infile.close();


    map<string, int> gyakori;

    for (string termek : vasarlasok) {
        gyakori[termek]++;
    }
    for (pair<string, int> p : gyakori) {
        cout << p.first << " " << p.second / vasarlasdb * 100 << "%" << endl;
    }

    return 0;
}
