#include "virus.h"
bool virus::CheckHarmfulVirus() {
	return false;
}
void virus::print() {
	cout << "\n\tRNA: " << RNA;
}
virus::virus()
{
	cout << "\n\tenter virus RNA: ";
	cin >> RNA;
}