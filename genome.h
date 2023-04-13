#pragma once
#include <iostream>
using namespace std;
class genome
{
protected:
    string RNA;
    string DNA[2];
public:
    void getGene(string rna);
    void createDnaFromRna(string rna);
    void smallMutateRnaDna(char a, char c, int n);
    void bigMutate(string st1, string st2);
    void reverseMutate(string st1);
    void print();
    string readGeneRNA();
    string readGeneDNA();
    void replaceSubStr(string& s, string s1, string s2);
    string readGeneDNA0();
    string readGeneDNA1();
};

