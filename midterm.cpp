

#include <iostream>
#include <vector>
using namespace std;
#include "animal.h"
#include "virus.h"
int main()
{
	int choise;
	bool hasVirus=false;
	vector<animal> animals;
	vector<virus> allVirus;
	do {
		cout << "\n\n*****************";
		cout << "\n1.new animal";
		cout << "\n2.print animal";
		cout << "\n3.create DNA from input string";
		cout << "\n4.small mutate a gene";
		cout << "\n5.big mutate a gene";
		cout << "\n6.reverse mutate a gene";
		cout << "\n7.cell die";
		cout << "\n8.big mutate a cell";
		cout << "\n9.small mutate a cell";
		cout << "\n10.reverse mutate a cell";
		cout << "\n11.all palindroms in cromosome";
		cout << "\n12.Similarity Percentage in two animals";
		cout << "\n13.check equalness in two animals";
		cout << "\n14.reproduction --- tolid mesle geir jensi";
		cout << "\n15.reproduction --- tolid mesle  jensi";
		cout << "\n16.animal cell die";
		cout << "\n17.new virus";
		cout << "\n18.Check Harmful virus";
		cout << "\n19.exit";
		cout << "\nenter your choise: ";
		cin >> choise;
		//new animal
		if (choise == 1)
		{
			animal a;
			a.newAnimal();
			animals.push_back(a);
		}
		//print animal
		else if (choise == 2)
		{
			if (animals.size() == 0)
				cout << "\n\tFirst select new animal menue..";
			else
			{
				for (unsigned int i = 0; i < animals.size(); i++)
				{
					cout << "\n\tAnimal " << i + 1 << ": ";
					animals[i].print();
				}
			}
		}
		//create DNA from input string
		else if (choise == 3)
		{
			cout << "\tEnter rna:";
			string rna;
			cin >> rna;
			genome g;
			g.createDnaFromRna(rna);
		}
		//small mutate a gene
		else if (choise == 4)
		{
			int n;
			char a, c;
			genome g;
			string rna;

			cout << "\tenter cromosome : ";
			cin >> rna;
			g.getGene(rna);

			cout << "\tEnter from nekloid:";
			cin >> a;
			cout << "\tEnter to nekloid:";
			cin >> c;
			cout << "\tEnter chnge nekloid quantity:";
			cin >> n;

			g.smallMutateRnaDna(a, c, n);
			cout << "\n\tAfter small mutate: ";
			g.print();
		}
		//big mutate a gene
		else if (choise == 5)
		{
			genome g;
			string rna, st1, st2;

			cout << "\tenter cromosome : ";
			cin >> rna;
			g.getGene(rna);
			cout << "\tEnter from sub string:";
			cin >> st1;
			cout << "\tEnter to sub string:";
			cin >> st2;
			g.bigMutate(st1, st2);
			cout << "\n\tAfter big mutate: ";
			g.print();
		}
		//reverse mutate a gene

		//______________________________cell functions

		else if (choise == 6)
		{
			genome g;
			string rna, st1;

			cout << "\tenter cromosome : ";
			cin >> rna;
			g.getGene(rna);
			cout << "\tEnter sub string to reverse:";
			cin >> st1;
			g.reverseMutate(st1);
			cout << "\n\tAfter reverse mutate: ";
			g.print();
		}
		//cell die
		else if (choise == 7)
		{
			cell c;
			c.getCromozome(1);
			string rna, st1;
			c.cellDie();
		}
		//big mutate a cell
		else if (choise == 8)
		{
			int n, m;
			string st1, st2;
			animal a;
			a.newAnimal();
			cout << "\tenter first cromosome number : ";
			cin >> n;
			cout << "\tenter second cromosome number : ";
			cin >> m;
			cout << "\tEnter from sub string:";
			cin >> st1;
			cout << "\tEnter to sub string:";
			cin >> st2;
			cout << "\n\tAfter cell big mutate: ";
			a.bigMutate(st1, n, st2, m);
			a.print();
		}
		//small mutate a cell
		else if (choise == 9)
		{
			char a, c;
			int n, m;
			animal an;
			an.newAnimal();
			cout << "\tenter first cromosome number : ";
			cin >> n;
			cout << "\tenter second cromosome number : ";
			cin >> m;
			cout << "\tEnter from nekloid:";
			cin >> a;
			cout << "\tEnter to nekloid:";
			cin >> c;

			an.smallMutate(a, c, n, m);
			cout << "\n\tAfter cell small mutate: ";
			an.print();
		}
		//reverse mutate a cell
		else if (choise == 10)
		{
			int n;
			string s1;
			animal a;
			a.newAnimal();
			cout << "\tenter cromosome number : ";
			cin >> n;
			cout << "\tEnter sub string to reverse:";
			cin >> s1;
			a.reverseMutate(s1, n);
			cout << "\n\tAfter cell reverse mutate: ";
			a.print();
		}
		//all palindroms in cromosome
		else if (choise == 11)
		{
			cell c;
			c.getCromozome(1);
			c.printPalindrom();
		}

		//______________________________animal functions
		
		//SimilarityPercentage
		else if (choise == 12)
		{
			if (animals.size() < 2)
				cout << "\n\tfirst enter at least two animal";
			else {
				int a1, a2;
				cout << "\tenter animal number1 : ";
				cin >> a1;
				cout << "\tenter animal number2 : ";
				cin >> a2;
				cout<<"\n\n\ttotal similarity is: "<<animals[a1 - 1].SimilarityPercentage(animals[a2 - 1]);
			}
		}
		//check equalness in two animals
		else if (choise == 13)
		{
			if (animals.size() < 2)
				cout << "\n\tfirst enter at least two animal";
			else 
			{
			int a1, a2;
			cout << "\tenter animal number1 : ";
			cin >> a1;
			cout << "\tenter animal number2 : ";
			cin >> a2;
			if (animals[a1 - 1] == animals[a2 - 1])
				cout << "\n\ttwo animals are equal...";
			else
				cout << "\n\ttwo animals are not equal...";
			}
		}
		//reproduction --- tolid mesle geir jensi
		else if (choise == 14)
		{
			if (animals.size() < 1)
				cout << "\n\tfirst enter at least one animal";
			else {
				animal child;
				int a1;
				cout << "\tenter animal number1 : ";
				cin >> a1;
				child=animals[a1 - 1].reproduction();
				cout << "\n\tparent animal is: ";
				animals[a1 - 1].print();
				cout << "\n\tnew produced child animal is: ";
				child.print();
			}
		}
		//reproduction --- tolid mesle  jensi
		else if (choise == 15)
		{
			if (animals.size() < 2)
			cout << "\n\tfirst enter at least two animal";
			else 
			{
				int a1, a2;
				cout << "\tenter animal number1 : ";
				cin >> a1;
				cout << "\tenter animal number2 : ";
				cin >> a2;
				animal child;
				child = animals[a1 - 1] + animals[a2 - 1];
				if (child.getCromozomeCount() == 0)
				{
					cout << "\n\t cromosome count is odd...child not created..";
				}
				else {
					cout << "\n\tparent animal 1 is: ";
					animals[a1 - 1].print();
					cout << "\n\tparent animal 2 is: ";
					animals[a2 - 1].print();
				}
			}
		}
		//animal cell die
		else if (choise == 16)
		{
		if (animals.size() < 1)
			cout << "\n\tfirst enter at least one animal";
		else {
			int a1;
			cout << "\tenter animal number : ";
			cin >> a1;
			animals[a1 - 1].cellDie();
			cout << "\n\tafter cell die animal is: ";
			animals[a1 - 1].print();
			}
		}
		//_________________________virus functions
		
		//new virus
		else if (choise == 17)
		{
			virus newVirus;
			allVirus.push_back(newVirus);
		}
		//Check Harmful Virus
		else if (choise == 18)
		{
			if (allVirus.size() < 1)
				cout << "\n\tfirst enter at least one virus";
			else
			{
				int v1;
				cout << "\tenter virus number : ";
				cin >> v1;
				if (allVirus[v1 - 1].CheckHarmfulVirus() == true)
				{
					cout << "\n\tthis virus is harmful..";
					allVirus[v1 - 1].print();
				}
			}
		}


		//otherwise
		else {
			cout << "\ninvalid select..";
		}

	} while (choise != 19);
}
