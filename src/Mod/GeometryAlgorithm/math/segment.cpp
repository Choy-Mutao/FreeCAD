#include "segment.h"

namespace pga
{
Segment::Segment(Point A, Point B)
    : P0(A)
    , P1(B)
{}

Segment::Segment(const Segment& seg)
    : P0(seg.P0)
    , P1(seg.P1)
{}
}  // namespace pga
