#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <string>

using namespace std;

string requestString();

int analyseString(string text);

void stringToAngle(string text, int &angle);

void stringToAngle(string &text, float &angle);

void computeCosSin(int angle, float &cosValue, float &sinValue);

void computeCosSin(float angle, float &cosValue, float &sinValue);

#endif