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
#include <omp.h>
#include <execution>
#include <list>
#include <deque>

using namespace std::chrono;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
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
using std::ios;


class Zmogus {
protected:
    string mVardas;
    string mPavarde;

public:
    // ==KONSTRUKTORIUS
    Zmogus() : mVardas(""), mPavarde("") {}

    // ==GETTERIAI==
    string getVardas() const { return mVardas; }
    string getPavarde() const { return mPavarde; }

    // ==SETTERIAI==
    virtual void setVardas(const string& vardas) = 0;
    virtual void setPavarde(const string& pavarde) = 0;

    // ==DESTRUKTORIUS==
    virtual ~Zmogus() {}
};

class Studentas : public Zmogus {
private:
    double mGalutinisVid;
    double mGalutinisMed;

public:
    // ==KONSTRUKTORIAI
    Studentas() : mGalutinisVid(0), mGalutinisMed(0) {}
    Studentas(string vardas, string pavarde, vector<int>& pazVec, int egzaminas) {
        mVardas = vardas;
        mPavarde = pavarde;
        skaiciuotiVidurki(pazVec, egzaminas);
        skaiciuotiMediana(pazVec, egzaminas);
        pazVec.clear();
    }

    // ==COPY KONSTRUKTORIUS==
    Studentas(const Studentas& source) {
            mVardas = source.mVardas;
            mPavarde = source.mPavarde;
            mGalutinisVid = source.mGalutinisVid;
            mGalutinisMed = source.mGalutinisMed;
    }
    
    // ==MOVE KONSTRUKTORIUS==
    Studentas(const Studentas&& source) {
        mVardas = std::move(source.mVardas);
        mPavarde = std::move(source.mPavarde);
        mGalutinisVid = std::move(source.mGalutinisVid);
        mGalutinisMed = std::move(source.mGalutinisMed);
    }


    // ==GETTERIAI==
    string getVardas() const { return mVardas; }
    string getPavarde() const { return mPavarde; }
    double getGalutinisVid() const { return mGalutinisVid; }
    double getGalutinisMed() const { return mGalutinisMed; }
    

    // ==SETTERIAI==
    void setVardas(const string& vardas) override { mVardas = vardas; }
    void setPavarde(const string& pavarde) override { mPavarde = pavarde; }
    void setGalutinisVid(const double& galutinisVid) { mGalutinisVid = galutinisVid; }
    void setGalutinisMed(const double& galutinisMed) { mGalutinisMed = galutinisMed; }


    // ==METODAI==
    void skaiciuotiVidurki(const vector<int>& pazVec, int& egzaminas) {
        mGalutinisVid = (0.4 * (accumulate(pazVec.begin(), pazVec.end(), 0) / pazVec.size())) + (0.6 * egzaminas);
    }


    void skaiciuotiMediana(vector<int>& pazVec, int& egzaminas) {
        int size = pazVec.size();
        sort(pazVec.begin(), pazVec.end());

        if (size % 2 == 0)
            mGalutinisMed = (0.4 * (double)((pazVec[size/2 - 1] + pazVec[size/2]) / 2) + 0.6 * egzaminas);
        else
            mGalutinisMed = (0.4 * pazVec[size / 2]) + (0.6 * egzaminas);
    }

    // ==IVESTIES OPERATORIUS==
    friend istream& operator>>(istream& input, vector<Studentas>& group) {
        string vardas, pavarde, line;
        vector<int> pazVec;
        int pazymys;

        getline(input, line);
        if (input.fail()) {
            return input;
        }
        stringstream ss(line);

        ss >> vardas >> pavarde;

        while (ss >> pazymys) {
            pazVec.push_back(pazymys);
        }

        int egzaminas = pazVec.back();
        pazVec.pop_back();

        group.emplace_back(vardas, pavarde, pazVec, egzaminas);

        return input;
    }

    // ==ISVESTIES OPERATIORIUS==
    friend ostream& operator<<(ostream& output, const Studentas& student) {
        output << left << setw(15) << student.mVardas << setw(21) << student.mPavarde
            << setw(19) << fixed << setprecision(2) << student.mGalutinisVid
            << setw(20) << fixed << setprecision(2) << student.mGalutinisMed << "\n";
        return output;
    }

    // ==COPY ASSIGNMENT OPERATORIUS
    Studentas& operator=(const Studentas& source) {
        if (this == &source)
            return *this;

        mVardas = source.mVardas;
        mPavarde = source.mPavarde;
        mGalutinisVid = source.mGalutinisVid;
        mGalutinisMed = source.mGalutinisMed;
        return *this;
    }

    // ==MOVE ASSIGNMENT OPERATORIUS
    Studentas& operator=(Studentas&& source) {
        if (this == &source)
            return *this;
        
        mVardas = std::move(source.mVardas);
        mPavarde = std::move(source.mPavarde);
        mGalutinisVid = std::move(source.mGalutinisVid);
        mGalutinisMed = std::move(source.mGalutinisMed);
        return *this;
    }

    // ==DESTRUKTORIUS==
    ~Studentas() {}
};


void failoSkaitymas(vector<Studentas>& grupe, string filename);
void failoIrasymas(vector<Studentas>& grupe, int partPoint);
int partitionIrSort(vector<Studentas>& grupe, bool rusiavimasChoice);
bool varduPalyginimas(const Studentas& a, const Studentas& b);
int randomSkaicius();
void failoGeneravimas();
void naudotojoIvestis(vector<Studentas>& grupe);
void pildymas(Studentas& temp);
void output_template();
void spausdinimas(Studentas& temp, string outputPasirinkimas);
bool getBoolInput();
bool isNumber(const string& str);
string getChoiceInput();
string getStringInput();
int gradeInput();
int autoGradeInput();
int threeInput();