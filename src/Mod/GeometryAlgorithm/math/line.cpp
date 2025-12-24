#include "line.h"

namespace pga
{
Line::Line(Point A, Point B)
    : Segment(A, B)
{}

Line::Line(const Segment& seg)
    : Segment(seg)
{}

Line::~Line() = default;

}