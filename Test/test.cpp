#define CATCH_CONFIG_MAIN

#include "../library.h"
#include "../functions.cpp"
#include "catch.hpp"


TEST_CASE("Studentas constructor with valid input works correctly") {
    std::vector<int> pazymiai = {10, 8, 9};
    Studentas s("Petras", "Petraitis", pazymiai, 7);

    REQUIRE(s.getVardas() == "Petras");
    REQUIRE(s.getPavarde() == "Petraitis");
    REQUIRE(s.getGalutinisVid() != 0);
    REQUIRE(s.getGalutinisMed() != 0);
}

TEST_CASE("Studentas copy constructor works correctly") {
    std::vector<int> pazymiai = {6, 7, 8};
    Studentas s1("Tomas", "Tomaitis", pazymiai, 9);
    Studentas s2(s1);

    REQUIRE(s2.getVardas() == "Tomas");
    REQUIRE(s2.getPavarde() == "Tomaitis");
    REQUIRE(s2.getGalutinisVid() == 8.2);
    REQUIRE(s2.getGalutinisMed() == 8.2);
}

TEST_CASE("Studentas move constructor works correctly") {
    std::vector<int> pazymiai = {6, 6, 6};
    Studentas s1("Antanas", "Antanaitis", pazymiai, 6);
    Studentas s2(std::move(s1));

    REQUIRE(s2.getVardas() == "Antanas");
    REQUIRE(s2.getPavarde() == "Antanaitis");
    REQUIRE(s2.getGalutinisVid() == 6);
    REQUIRE(s2.getGalutinisMed() == 6);
}

TEST_CASE("File reading function reads data correctly from file") {
    vector<Studentas> grupe;
    string filename = "studentai1000.txt";
    REQUIRE_NOTHROW(failoSkaitymas(grupe, filename));
}

TEST_CASE("File reading function throws an exception if file not found") {
    vector<Studentas> grupe;
    string filename = "non_existing_file.txt";
    REQUIRE_THROWS(failoSkaitymas(grupe, filename));
}

TEST_CASE("isNumber returns correct boolean value") {
    REQUIRE(isNumber("12345") == true);
    REQUIRE(isNumber("124bde") == false);
}
