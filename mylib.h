#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>
#include <regex>
#include <omp.h>
#include <execution>
#include <list>
#include <deque>

using namespace std::chrono;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::isdigit;
using std::min;
using std::numeric_limits;
using std::streamsize;
using std::vector;
using std::size_t;
using std::sort;
using std::accumulate;
using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::stoi;
using std::getline;
using std::smatch;
using std::regex;
using std::regex_search;
using std::exit;
using std::fixed;
using std::invalid_argument;
using std::out_of_range;
using std::exception;
using std::runtime_error;
using std::to_string;
using std::find_if;
using std::distance;
using std::partition;
using std::sort;
using std::list;
using std::deque;
using std::next;
using std::back_inserter;
using std::move;
using std::merge;
using std::stable_sort;
using std::remove_if;
using std::copy_if;
using std::istream;
using std::ostream;


// struct studentas {
//     string vardas = "", pavarde = "";
//     double galutinisVid = 0, galutinisMed = 0;
//     vector<int> paz_vec;
// };

class Studentas {
private:
    string mVardas;
    string mPavarde;
    double mGalutinisVid;
    double mGalutinisMed;

public:
    Studentas() : mGalutinisVid(0), mGalutinisMed(0) {}
    Studentas(const string& vardas, const string& pavarde, vector<int>& pazVec, const int& egzaminas) :
        mVardas(vardas), mPavarde(pavarde) {
        skaiciuotiGalutinius(pazVec, egzaminas);
    }
    
    void setVardas(const string& vardas) { mVardas = vardas; }
    void setPavarde(const string& pavarde) { mPavarde = pavarde; }
    void setGalutiniai(vector<int>& pazVec, const int& egzaminas) {
        skaiciuotiGalutinius(pazVec, egzaminas); }

    string getVardas() const { return mVardas; }
    string getPavarde() const { return mPavarde; }
    double getGalutinisVid() const { return mGalutinisVid; }
    double getGalutinisMed() const { return mGalutinisMed; }

    void skaiciuotiGalutinius(vector<int>& pazVec, const int& egzaminas) {
        int size = pazVec.size();

        mGalutinisVid = (0.4 * accumulate(pazVec.begin(), pazVec.end(), 0) / size) + (0.6 * egzaminas);

        sort(pazVec.begin(), pazVec.end());
        if (size % 2 == 0) {
            mGalutinisMed = (0.4 * (double)((pazVec[size/2 - 1] + pazVec[size/2]) / 2) + 0.6 * egzaminas);
        }
        else {
            mGalutinisMed = (0.4 * pazVec[size / 2]) + (0.6 * egzaminas);
        }

        pazVec.clear();
    }

    static bool varduPalyginimas(const Studentas& a, const Studentas& b) {
        if (a.getPavarde() == b.getPavarde())
            return a.getVardas() < b.getVardas();
        else
            return a.getPavarde() < b.getPavarde();
    }

    friend ostream& operator<<(ostream& output, const Studentas& s) {
        output << left << setw(15) << s.mVardas << setw(21) << s.mPavarde
            << setw(19) << fixed << setprecision(2) << s.mGalutinisVid
            << setw(20) << fixed << setprecision(2) << s.mGalutinisMed << "\n";
        return output;
    }
};
