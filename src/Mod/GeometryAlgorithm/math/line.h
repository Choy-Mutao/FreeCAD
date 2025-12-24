#ifndef SS_LINE_H
#define SS_LINE_H

#include "common.h"
#include "segment.h"

namespace pga
{
class Line: public Segment
{
public:
    Line() = delete;
    Line(Point A, Point B);
    Line(const Segment& seg);
    ~Line();

private:
};
}

#endif // !SS_LINE_H
