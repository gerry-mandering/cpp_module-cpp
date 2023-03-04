#include <iostream>
#include <cmath>

class Point {
	public:
		int	x, y;

		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}

		void	PrintPoint() const {
			std::cout << "x : " << x << " y : " << y << std::endl;
		}
};

class Geometry {
	private:
		Point*	point_array[100];
		int		num_points;

		double	GetDistance(const Point &point_a, const Point &point_b);

	public:
		Geometry() {
			num_points = 0;
		}

		void	AddPoint(const Point &point) {
			point_array[num_points++] = new Point(point.x, point.y);
		}

		void	PrintDistance();
};

double	Geometry::GetDistance(const Point &point_a, const Point &point_b) {
	double	distance;

	distance = sqrt(pow(point_a.x - point_b.x, 2) + pow(point_a.y - point_b.y, 2));
	return distance;
}

void	Geometry::PrintDistance() {
	for (int i = 0; i < this->num_points; i++) {
		for (int j = i + 1; j < this->num_points; j++) {
			std::cout << "Point " << i << " to "
					  << "Point " << j << " is "
					  << GetDistance(*this->point_array[i], *this->point_array[j]) << "distance" << std::endl;
		}
	}
}

int	main(void) {
	Geometry	geometry;

	geometry.AddPoint(Point(1, 1));
	geometry.AddPoint(Point(2, 2));
	geometry.AddPoint(Point(3, 3));
	geometry.AddPoint(Point(4, 4));
	geometry.AddPoint(Point(5, 5));

	geometry.PrintDistance();
}
