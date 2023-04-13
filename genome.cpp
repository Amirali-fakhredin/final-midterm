#include <iostream>
using namespace std;
#include "genome.h"

void genome::getGene(string rna) { //get gen
	DNA[0] = rna;
	DNA[1] = rna;
	RNA = rna;
	for (unsigned int i = 0; i < rna.size(); i++) //compilite
	{
		if (rna[i] == 'T')
			DNA[1][i] = 'A';
		else if (rna[i] == 'A')
			DNA[1][i] = 'T';
		else if (rna[i] == 'C')
			DNA[1][i] = 'G';
		else if (rna[i] == 'G')
			DNA[1][i] = 'C';
	}
}
void genome::createDnaFromRna(string rna) { //create DNA from RNA
	string dna[2];
	dna[0] = rna;
	dna[1] = rna;
	RNA = rna;
	for (unsigned int i = 0; i < rna.size(); i++)
	{
		if (rna[i] == 'T')
			dna[1][i] = 'A';
		else if (rna[i] == 'A')
			dna[1][i] = 'T';
		else if (rna[i] == 'C')
			dna[1][i] = 'G';
		else if (rna[i] == 'G')
			dna[1][i] = 'C';
	}
	cout << "\tnew created DNA is: " << dna[0] << " " << dna[1];
}
void genome::smallMutateRnaDna(char a, char c, int n) { //small mutate
	int nCount = 0;
	for (unsigned int i = 0; i < RNA.size()&& nCount<n; i++)
	{
		if (RNA[i] == a)
		{
			RNA[i] = c;
			nCount++;
		}
	}
	nCount = 0;
	for (unsigned int i = 0; i < DNA[0].size()&& nCount < n; i++)
	{
		if (DNA[0][i] == a)
		{
			DNA[0][i] = c;
			nCount++;

			if (DNA[0][i] == 'T')
				DNA[1][i] = 'A';
			else if (DNA[0][i] == 'A')
				DNA[1][i] = 'T';
			else if (DNA[0][i] == 'C')
				DNA[1][i] = 'G';
			else if (DNA[0][i] == 'G')
				DNA[1][i] = 'C';			
		}
	}	
}
void genome::replaceSubStr(string& s, string s1, string s2) //replace substr
{
	bool replaced = false;
	string ans = "";
	for (unsigned int i = 0; i < s.length(); i++) {
		unsigned int k = 0;
		if (s[i] == s1[k] && i + s1.length() <= s.length()) {// first character matches 
			unsigned int j;
			for (j = i; j < i + s1.length(); j++) {//complete string matches or not
				if (s[j] != s1[k])
					break;
				else
					k = k + 1;
			}
			if (j == i + s1.length() && replaced == false) {// If complete string matches >> replace it with s2
				ans.append(s2);
				i = j - 1;
				replaced = true;
			}
			else
				ans.push_back(s[i]);
			
		}
		else
			ans.push_back(s[i]);
	}
	s = ans;
}
void genome::bigMutate(string st1, string st2) { //big mutate
	replaceSubStr(RNA, st1, st2);
	DNA[0] = RNA;
	DNA[1] = RNA;
	for (unsigned int i = 0; i < RNA.size(); i++)
	{
		if (RNA[i] == 'T')
			DNA[1][i] = 'A';
		else if (RNA[i] == 'A')
			DNA[1][i] = 'T';
		else if (RNA[i] == 'C')
			DNA[1][i] = 'G';
		else if (RNA[i] == 'G')
			DNA[1][i] = 'C';
	}
}
void genome::reverseMutate(string st1) { //reverse
	string st2 = st1;
	int len = st1.length();
	for (int i = 0; i < len; i++)
		st2[i] = st1[len - i - 1];
	replaceSubStr(RNA, st1, st2);

	DNA[0] = RNA;
	DNA[1] = RNA;
	for (unsigned int i = 0; i < RNA.size(); i++)
	{
		if (RNA[i] == 'T')
			DNA[1][i] = 'A';
		else if (RNA[i] == 'A')
			DNA[1][i] = 'T';
		else if (RNA[i] == 'C')
			DNA[1][i] = 'G';
		else if (RNA[i] == 'G')
			DNA[1][i] = 'C';
	}
}
void genome::print() {
	cout <<"\n\t\t"<<"RNA: "<<RNA<< "\tDNA: "<< DNA[0] << " " << DNA[1];
}
string genome::readGeneRNA()
{
	return RNA;
}
string genome::readGeneDNA()
{
	return DNA[0]+DNA[1];
}
string genome::readGeneDNA0()
{
	return DNA[0] ;
}
string genome::readGeneDNA1()
{
	return DNA[1];
}
