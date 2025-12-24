#ifndef SS_SEGMENT_H
#define SS_SEGMENT_H

#include "common.h"
#include "point.h"

namespace pga
{
class Segment
{
    friend class Point;

public:
    Point P0, P1;  // endpoints
    // Constructors
    Segment() = delete;
    Segment(Point A, Point B);
    Segment(const Segment& seg);
};

}  // namespace pga

#endif  // !SS_SEGMENT_H
