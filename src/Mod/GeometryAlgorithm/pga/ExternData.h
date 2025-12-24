#ifndef SS_EXTERN_DATA
#define SS_EXTERN_DATA
#include <vector>
#include <gp_XYZ.hxx>

struct EdgeDiscreateData
{
	int index;		// edge index
	int degree;
	bool bDegenerated;
	double length;
	std::vector<gp_Pnt> uniformPolygon;
	std::vector<double> pointsParam3d;
	std::vector<gp_XYZ> segmentCenters;
	std::vector<gp_XYZ> segmentTans;
	std::vector<gp_XYZ> segmentRefered;
	
};
#endif // !SS_EXTERN_DATA
