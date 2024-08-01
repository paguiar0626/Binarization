#include<iostream>
#include<math.h>

using namespace std;

double distanceCalculate(double x1, double y1, double x2, double y2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	return dist;
}

int main()
{
	int n;
	int k;
	double x[100];
	double y[100];
	char c[100];
	double valuex;
	double valuey;
	char valuec;

	std::cin >> n;
	std::cin >> k;
	for (int i = 0; i < n; i++){
		std::cin >> valuex;
		std::cin >> valuey;
		std::cin >> valuec;
		x[i] = valuex;
		y[i] = valuey;
		c[i] = valuec;
	}
	std::cin >> x[n];
	std::cin >> y[n];

	if (n == 1){
		std::cout << c[0] << std::endl;
		return 0;
	}
	double d[n];

	for (int i = 0; i < n; i++){
		d[i] = distanceCalculate(x[n], y[n], x[i], y[i]);
	}

	double closest[k];
	char colors[k];

	for (int i = 0; i < k; i++){
		int temp = 0;
		closest[i] = d[0];
		for (int j = 0; j < n; j++){
			if (d[j] < closest[i]){
				closest[i] = d[j];
				//std::cout << closest[i] << std::endl;
				temp = j;
			}
		}
		d[temp] = 286;
		colors[i] = c[temp];
	}

	int R = 0;

	for (int i = 0; i < k; i++){
		if (colors[i] == 'R'){
			R++;
		}
	}

	//std::cout << R << std::endl;

	if ((k-R) > R){
		std::cout << "B\n";
	}
	else{
		std::cout << "R\n";
	}
}