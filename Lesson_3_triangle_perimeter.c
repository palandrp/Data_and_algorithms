#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main(int argc, char *argv[]) {
	double x1 = 0,
		y1 = 0,
		x2,
		y2,
		x3 = 0,
		y3;

	printf("Input x2: ");
	scanf("%lf", &x2);

	printf("Input y2: ");
	scanf("%lf", &y2);

	printf("Input y3: ");
	scanf("%lf", &y3);

	double l1 = distance(x1, y1, x2, y2);
	double l2 = distance(x1, y1, x3, y3);
	double l3 = distance(x2, y2, x3, y3);

	printf("Perimetr: %lf\n", l1 + l2 + l3);

	return 0;
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}