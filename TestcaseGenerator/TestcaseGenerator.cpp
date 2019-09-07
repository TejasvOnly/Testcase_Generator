#include<bits/stdc++.h>
#include"Utilities.h"
using namespace std;

int main() {
	ofstream out("generated.txt");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
	//Sample code to generate ternary numbers upto decimal equivalent of 5000 where characters are A,B and C
	NumSys test(3,'A','B','C');
	for (long int i = 0; i < 5000; i++) {
		cout << test.GetCurrent() << endl;
		printf("%ld\n", i);
		test++;
	}
}