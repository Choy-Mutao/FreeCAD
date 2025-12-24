#pragma once
#include <cmath>
#include "point.h"
#include "vector.h"
#include "line.h"

namespace pga
{
	class Triangle {
		Point a, b, c;
		Triangle(const Point& p1, const Point& p2, const Point& p3)
			: a(p1), b(p2), c(p3) {
		}
	};

	class Plane {
		Point P0;
		Vector normal;
	};

	inline
		int dot(const Vector& u, const Vector& v)
	{
		return (u.x * v.x + u.y * v.y);
	}

	/**
	 * @brief test if a point is Left|On|Right of an infinite 2D line.
	 * @param P0 1st point on the line
	 * @param P1 2nd point on the line
	 * @param P2 the point to test
	 * @return
	 *		>0 for P2 left of the line through P0 and P1
	 *		=0 for P2 on the line
	 *		<0 for P2 right of the line
	 */
	inline int
		isLeft(const Point& P0, const Point& P1, const Point& P2)
	{
		return ( (P1.x - P0.x) * (P2.y - P0.y)
			- (P1.y - P0.y) * (P2.x - P0.x));
	}

	/**
	 * @beief 计算向量的长度.
	 * @param v 定义的 float 向量
	 */
	inline float
		vector_length(Vector v)
	{
		return std::sqrt(v.x * v.x + v.y * v.y);
	}

	/**
	 * @brief 向量点积.
	 * @param v1
	 * @param v2
	 */
	inline float
		two_vector_dot(const Vector& v1, const Vector& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
			
	}

	/**
	 * @brief test the orientation of a 2D triangle
	 * @param V0 triangle vertex 0
	 * @param V1 triangle vertex 1
	 * @param V2 triangle vertex 2
	 * @return
	 *		>0 for counter-clockwise orientation
	 *		=0 for none (degenerate)
	 *		<0 for clockwise orientation
	 */
	inline int
		orientation2D_Triangle(Point V0, Point V1, Point V2)
	{
		return isLeft(V0, V1, V2);
	}

	/**
	 * @brief 古典三角形的面积计算
	 * @param p0 顶点0
	 * @param p1 顶点1
	 * @param p2 顶点2
	 * @return 三角形面积
	 */
	inline float
		area2D_Ancient_Triangle(Point p0, Point p1, Point p2)
	{
		Vector v1(p1.x - p0.x, p1.y - p0.y);
		Vector v2(p2.x - p0.x, p2.y - p0.y);

		float l1 = vector_length(v1);
		float l2 = vector_length(v1);

		return std::acos(two_vector_dot(v1, v2) / (l1 * l2));
	}

	/**
	 * @brief compute the area of a 2D triangle
	 * @param V0 triangle vertex 0
	 * @param V1 triangle vertex 1
	 * @param V2 triangle vertex 2
	 * @return the (float) area of triangle T
	 */
	inline float
		area2D_Triangle(Point V0, Point V1, Point V2)
	{
		return (float)isLeft(V0, V1, V2) / 2.0;
	}

	/**
	 * @brief test the orientation of a simple 2D polygon
	 * @param n the number of vertices in the polygon
	 * @param V an array of n+1 vertex points with V[n]=V
	 * @return
	 *		>0 for counter-clockwise orientation
	 *		=0 for none (degenerate)
	 *		<0 for clockwise orientation
	 * Note: this algorithm is faster than computing the signed area.
	 */
	static int
		orientation2D_Polygon(int n, Point* V)
	{
		// first find rightmost lowest vertex of the polygon
		int rmin = 0;
		int xmin = V[0].x;
		int ymin = V[0].y;

		for (int i = 1; i < n; i++) {
			if (V[i].y > ymin)
				continue;
			if (V[i].y == ymin) {   // just as low
				if (V[i].x < xmin)  // and to left
					continue;
			}
			rmin = i;      // a new rightmost lowest vertex
			xmin = V[i].x;
			ymin = V[i].y;
		}

		// test orientation at the rmin vertex
		// ccw <=> the edge leaving V[rmin] is left of the entering edge
		if (rmin == 0)
			return isLeft(V[n - 1], V[0], V[1]);
		else
			return isLeft(V[rmin - 1], V[rmin], V[rmin + 1]);
	}

	namespace lines {

		/**
		 * @brief closest2D_Point_to_Line(): find the closest 2D Point to a Line.
		 * @param PointIs: a vector of 2D points
		 * @param LineI: a line
		 * @return the index i of the Point P[i] closest to L;
		 */
		static
			int closest2D_Point_to_Line(Point P, int n, Line L)
		{
			return -1;
		}
	}
}
