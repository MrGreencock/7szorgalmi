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
        string id;
        infile >> id;
        vasarlasok.push_back(sor);
        vasarlasdb++;
    }
    infile.close();

    for (string& t : vasarlasok) {
        cout << t << endl;
    }
    vector<string> termekek = { " csoki", " chips", " tej", " kenyer" };
    vector<string> kombinacio;
    string szoveg;
    for (int i = 0; i < termekek.size(); i++) {
        for (int j = 0; j < termekek.size(); j++) {
            if (termekek[i] != termekek[j]) {
                szoveg = " " + termekek[i] + " " + termekek[j];
                kombinacio.push_back(szoveg);
            }
        }
    }
    for (int i = 0; i < termekek.size(); i++) {
        kombinacio.push_back(termekek[i]);
    }

    for (string& t : kombinacio) {
        cout << t << endl;
    }

    map<string, int> gyakori;

    for (string termek : kombinacio) {
        gyakori[termek] = 0;
    }

    for (string termek : vasarlasok) {
        gyakori[termek]++;
    }
    for (pair<string, int> p : gyakori) {
        cout << p.first << " " << p.second / vasarlasdb * 100 << "%" << endl;
    }

    return 0;
}
