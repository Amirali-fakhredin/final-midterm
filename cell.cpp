#include <iostream>
using namespace std;
#include "cell.h"
void cell::getCromozome(int cromozomes) {
	cromozomeCount = cromozomes;
	gene = new genome[cromozomeCount];
	string rna;
	cout << "\tenter cromosome value:\n";
	for (int i = 0; i < cromozomeCount; i++)
	{
		cout << "\t\tcromosome "<<i+1<<" : ";
		cin >> rna;
		gene[i].getGene(rna);
	}
}
void cell::cellDie() {
	for (int j = 0; j < cromozomeCount; j++){
		string DNA0 = gene[j].readGeneDNA0();
		string DNA1 = gene[j].readGeneDNA1();
		int point = 0, AT = 0, GC = 0;
		for (int i = 0; i < DNA[0].length(); i++){
			if (
			(DNA0[i] == 'A' && DNA1[i] != 'T')
			||
			(DNA0[i] == 'T' && DNA1[i] != 'A')
			||
			(DNA0[i] == 'G' && DNA1[i] != 'C')
			||
			(DNA0[i] == 'C' && DNA1[i] != 'G')
			)
				point++;

			if ((DNA0[i] == 'A' && DNA1[i] == 'T')
			||
			(DNA0[i] == 'T' && DNA1[i] == 'A'))
				AT++;

			if ((DNA0[i] == 'G' && DNA1[i] == 'C')
			||
			(DNA0[i] == 'C' && DNA1[i] == 'G'))
				GC++;
		}
	}
	
	if (point > 5 || AT > 3 * GC)
	{
		cout << "\n\tCell died..";
		delete this;//????
		break;
	}
	else
	{
		cout << "\n\tCell not died..";
		print();
	}
}

void cell::bigMutate(string str1, int n, string str2, int m) {
	string s1, s2;
	s1 = gene[n-1].readGeneRNA();
	s2 = gene[m-1].readGeneRNA();

	replaceSubStr(s1, str1, str2);
	replaceSubStr(s2, str2, str1);

	gene[n-1].getGene(s1);
	gene[m-1].getGene(s2);
}
void cell::smallMutate(char a, char c, int n, int m) {
	string s2 = gene[m - 1].readGeneRNA();
    for(int i = 0; i < n; i++){
        int f = s2.find("a");
        s2[f] = 'c'; 
    }
    gene[m - 1].getGene(s2);
}
void cell::reverseMutate(string st1, int n) {
	string s1;
	s1 = gene[n - 1].readGeneRNA();

	string st2 = st1;
	int len = st1.length();
	for (int i = 0; i < len; i++)
		st2[i] = st1[len - i - 1];
	replaceSubStr(s1, st1, st2);
	gene[n - 1].getGene(s1);
}
int palindromSubStr(const string& input, int j, int k) {
	int count = 0;
	for (; j >= 0 && k < input.length(); --j, ++k) {
		if ((input[j] == 'A' && input[k] != 'T') || (input[j] == 'T' && input[k] != 'A') || (input[j] == 'G' && input[k] != 'C') || (input[j] == 'C' && input[k] != 'G'))
			break;
		if (input.substr(j, k - j + 1).length() % 2 == 0 && input.substr(j, k - j + 1).length() > 2)
		{
			cout << "\t\t" << input.substr(j, k - j + 1) << endl;
			++count;
		}
	}
	return count;
}
void cell::printPalindrom() {
	string input = gene[0].readGeneRNA();
	int count = 0;
	cout << "\n\tchecking palindrom substrings...\n";
	for (auto i = 0; i < input.length(); ++i) {
		count+= palindromSubStr(input, i - 1, i + 1);
		count+= palindromSubStr(input, i, i + 1);
	}
	cout << "\ttotal: " << count << " palindrom substring found..";
}
void cell::print() {
	cout << "\n\tThis animal cromosomes Count is " << cromozomeCount;
	cout << "\n\tRNAs and DNAs are: ";
	for (auto i = 0; i < cromozomeCount; i++)
	{
		gene[i].print();
	}
}
int cell::getCromozomeCount() {
	return cromozomeCount;
}
