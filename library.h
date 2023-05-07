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


/// @brief Bazinė Žmogaus klasė.
class Zmogus {
protected:
    string mVardas;
    string mPavarde;

public:
    // ==KONSTRUKTORIUS
    /// @brief Konstruktorius, sukuriantis tuščią Žmogaus objektą.
    Zmogus() : mVardas(""), mPavarde("") {}

    // ==GETTERIAI==
    /// @brief Metodas, gaunantis Žmogaus vardą.
    string getVardas() const { return mVardas; }

    /// @brief Metodas, gaunantis Žmogaus pavardę.
    string getPavarde() const { return mPavarde; }

    // ==SETTERIAI==
    /// @brief Virtualus metodas, nustatantis Žmogaus vardą.
    virtual void setVardas(const string& vardas) = 0;

    /// @brief Virtualus metodas, nustatantis Žmogaus pavardę.
    virtual void setPavarde(const string& pavarde) = 0;

    // ==DESTRUKTORIUS==
    /// @brief Destruktorius, sunaikinantis Žmogaus objektą.
    virtual ~Zmogus() {}
};

/// @brief Išvestinė Studento klasė, išvesta iš Žmogaus bazinės klasės.
class Studentas : public Zmogus {
private:
    double mGalutinisVid;
    double mGalutinisMed;

public:
    // ==KONSTRUKTORIAI==
    /// @brief Konstruktorius, sukuriantis tuščią Studento objektą.
    Studentas() : mGalutinisVid(0), mGalutinisMed(0) {}

    /// @brief Konstruktorius, sukuriantis Studento objektą su perduodamais parametrais.
    Studentas(string vardas, string pavarde, vector<int>& pazVec, int egzaminas) {
        mVardas = vardas;
        mPavarde = pavarde;
        skaiciuotiVidurki(pazVec, egzaminas);
        skaiciuotiMediana(pazVec, egzaminas);
        pazVec.clear();
    }

    // ==COPY KONSTRUKTORIUS==
    /// @brief Konstruktorius, sukuriantis Studento objektą perkopijuodamas duomenis iš jau esamo objekto į naują.
    Studentas(const Studentas& source) {
            mVardas = source.mVardas;
            mPavarde = source.mPavarde;
            mGalutinisVid = source.mGalutinisVid;
            mGalutinisMed = source.mGalutinisMed;
    }
    
    // ==MOVE KONSTRUKTORIUS==
    /// @brief Konstruktorius, sukuriantis Studento objektą perkeldamas duomenis iš jau esamo objekto į naują.
    Studentas(const Studentas&& source) {
        mVardas = std::move(source.mVardas);
        mPavarde = std::move(source.mPavarde);
        mGalutinisVid = std::move(source.mGalutinisVid);
        mGalutinisMed = std::move(source.mGalutinisMed);
    }


    // ==GETTERIAI==
    string getVardas() const { return mVardas; }
    /// @brief Metodas, gaunantis Studento objekto vardą.

    string getPavarde() const { return mPavarde; }
    /// @brief Metodas, gaunantis Studento objekto pavardę.

    double getGalutinisVid() const { return mGalutinisVid; }
    /// @brief Metodas, gaunantis Studento objekto galutinį balą, paskaičiuotą gaunant pažymių vidurkį.

    double getGalutinisMed() const { return mGalutinisMed; }
    /// @brief Metodas, gaunantis Studento objekto galutinį balą, paskaičiuotą gaunant pažymių medianą.

    // ==SETTERIAI==
    void setVardas(const string& vardas) override { mVardas = vardas; }
    /// @brief Metodas, nustatantis Studento objekto vardą.

    void setPavarde(const string& pavarde) override { mPavarde = pavarde; }
    /// @brief Metodas, nustatantis Studento objekto pavardę.

    void setGalutinisVid(const double& galutinisVid) { mGalutinisVid = galutinisVid; }
    /// @brief Metodas, nustatantis Studento objekto galutinį balą, paskaičiuotą gaunant pažymių vidurkį.

    void setGalutinisMed(const double& galutinisMed) { mGalutinisMed = galutinisMed; }
    /// @brief Metodas, nustatantis Studento objekto galutinį balą, paskaičiuotą gaunant pažymių medianą.

    // ==METODAI==
    /// @brief Metodas, suskaičiuojantis studento pažymių vidurkį ir nustatantis galutinį balą. paskaičiuotą gaunant pažymių vidurkį.
    void skaiciuotiVidurki(const vector<int>& pazVec, int& egzaminas) {
        mGalutinisVid = (0.4 * (accumulate(pazVec.begin(), pazVec.end(), 0) / pazVec.size())) + (0.6 * egzaminas);
    }

    /// @brief Metodas, suskaičiuojantis studento pažymių vidurkį ir nustatantis galutinį balą. paskaičiuotą gaunant pažymių medianą.
    void skaiciuotiMediana(vector<int>& pazVec, int& egzaminas) {
        int size = pazVec.size();
        sort(pazVec.begin(), pazVec.end());

        if (size % 2 == 0)
            mGalutinisMed = (0.4 * (double)((pazVec[size/2 - 1] + pazVec[size/2]) / 2) + 0.6 * egzaminas);
        else
            mGalutinisMed = (0.4 * pazVec[size / 2]) + (0.6 * egzaminas);
    }

    // ==IVESTIES OPERATORIUS==
    /// @brief Įvesties operatorius, nuskaitantis duomenis iš failo ir sukuriantis Studento objektą.
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
    /// @brief Išvesties operatorius, išvedantis Studento objekto duomenis į failą.
    friend ostream& operator<<(ostream& output, const Studentas& student) {
        output << left << setw(15) << student.mVardas << setw(21) << student.mPavarde
            << setw(19) << fixed << setprecision(2) << student.mGalutinisVid
            << setw(20) << fixed << setprecision(2) << student.mGalutinisMed << "\n";
        return output;
    }

    // ==COPY ASSIGNMENT OPERATORIUS
    /// @brief Kopijavimo priskirimo operatorius, perkopijuojantis duomenis iš vieno Studento objekto į kitą.
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
    /// @brief Perkelimo priskirimo operatorius, perkeliantis duomenis iš vieno Studento objekto į kitą.
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
    /// @brief Destruktorius, sunaikinantis Studento objektą.
    ~Studentas() {}
};

/// @brief Funkcija, skirta skaityti duomenis iš failo.
void failoSkaitymas(vector<Studentas>& grupe, string filename);

/// @brief Funkcija, skirta išvesti duomenis į du skirtingus failus: "saunuoliai.txt" ir "vargsai.txt".
void failoIrasymas(vector<Studentas>& grupe, int partPoint);

/// @brief Funkcija, skirta atskirti studentus į dvi grupes pagal galutinį balą, gražinanti atskirties tašką.
int partitionIrSort(vector<Studentas>& grupe, bool rusiavimasChoice);

/// @brief Funkcija, skirta rūšiavimui pagal vardus abėcėline tvarka.
bool varduPalyginimas(const Studentas& a, const Studentas& b);

/// @brief Funkcija, gražinanti atsitiktinį skaičių generuojant studentų balus.
int randomSkaicius();

/// @brief Funkcija, skirta sugeneruoti studentų failą su jų duomenimis.
void failoGeneravimas();

/// @brief Funkcija, skirta pasirinkti kokie galutiniai balai bus skaičiuojami ir įvesti studentų duomenis rankomis.
void naudotojoIvestis(vector<Studentas>& grupe);

/// @brief Funkcija, skirta įvesti vieno studento duomenis rankomis.
void pildymas(Studentas& temp);

/// @brief Funkcija, skirta išvesti pirmas dvi eilutes į failą.
void output_template();

/// @brief Funkcija, skirta spausdinti studentų duomenis į failą.
void spausdinimas(Studentas& temp, string outputPasirinkimas);

/// @brief Funkcija, skirta validuoti bool tipo: vienas arba nulis.
bool getBoolInput();

/// @brief Funkcija, skirta validuoti ar įvestis yra skaičius.
bool isNumber(const string& str);

/// @brief Funkcija, skirta validuoti pasirinkimą.
string getChoiceInput();

/// @brief Funkcija, skirta validuoti ar įvestis yra string tipo.
string getStringInput();

/// @brief Funkcija, skirta validuoti pažymių skaičių įvestį.
int gradeInput();

/// @brief Funkcija, skirta validuoti automatiškai generuojamų pažymių skaičiu.
int autoGradeInput();

/// @brief Funkcija, skirta validuoti pasirinkima: vienas, du, trys.
int threeInput();
