#pragma once
#include <string>
#include <map>

enum key
{
    ANZAHL_KARTONS,
    ANZAHL_KILOMETER,
    GEWICHT,
    BERECHNETES_GEWICHT,
    FRACHTKOSTEN,
    NETTOUMSATZ,
    GESAMTUMSATZ,
    RABATT,
    ZIELPREIS
};

int calculateBerechnetesGewicht(int gewicht);
double calculateRabatt(double nettoumsatz);
void print(std::string key = "", std::string value = "", bool endline = true);
void printAll(std::map<key, double>& angaben);