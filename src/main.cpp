#include <iostream>
#include "flight.h"

using namespace std;

int main() {
	init();
	Vector yAxis(3), xAxis(3);
	yAxis[0] = 0;
	yAxis[1] = 1;
	yAxis[2] = 0;
	xAxis[0] = 1;
	xAxis[1] = 0;
	xAxis[2] = 0;
	Vector v = rotate(yAxis, xAxis, 90);
	for (int i = 0; i < v.size(); i++)  {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}