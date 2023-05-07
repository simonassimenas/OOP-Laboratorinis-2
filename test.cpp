#define CATCH_CONFIG_MAIN

#include "library.h"
#include "catch.hpp"


TEST_CASE("Studentas constructor with valid input") {
    std::vector<int> pazymiai = {10, 8, 9};
    Studentas s("Petras", "Petraitis", pazymiai, 7);

    REQUIRE(s.getVardas() == "Petras");
    REQUIRE(s.getPavarde() == "Petraitis");
    REQUIRE(s.getGalutinisVid() == 8.67);
    REQUIRE(s.getGalutinisMed() == 9);
}

TEST_CASE("Studentas copy constructor") {
    std::vector<int> pazymiai = {6, 7, 8};
    Studentas s1("Tomas", "Tomaitis", pazymiai, 9);
    Studentas s2(s1);

    REQUIRE(s2.getVardas() == "Tomas");
    REQUIRE(s2.getPavarde() == "Tomaitis");
    REQUIRE(s2.getGalutinisVid() == 7);
    REQUIRE(s2.getGalutinisMed() == 7);
}

TEST_CASE("Studentas move constructor") {
    std::vector<int> pazymiai = {5, 6, 7};
    Studentas s1("Antanas", "Antanaitis", pazymiai, 8);
    Studentas s2(std::move(s1));

    REQUIRE(s2.getVardas() == "Antanas");
    REQUIRE(s2.getPavarde() == "Antanaitis");
    REQUIRE(s2.getGalutinisVid() == 6);
    REQUIRE(s2.getGalutinisMed() == 6);
    REQUIRE(s1.getVardas() == "");
    REQUIRE(s1.getPavarde() == "");
    REQUIRE(s1.getGalutinisVid() == 0);
    REQUIRE(s1.getGalutinisMed() == 0);
}
