/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

#define _x first
#define _y second
typedef std::pair<int, int>     Point;
typedef std::pair<Point, Point> Segment;
typedef std::pair<int, int>     Event;
typedef std::vector<Event>      Events;

int segments;
Segment segment[131072];
Events events;
Point ball;

inline
bool onTheLeft(const Point &a, const Point &b, const Point &c)
{
    return 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first) > 0LL;
}

inline
bool above(const int &a, const int &b)
{
    return (onTheLeft(segment[b]._x, segment[b]._y, segment[a]._x) && onTheLeft(segment[b]._x, segment[b]._y, segment[a]._y)) ||
           (!onTheLeft(segment[a]._x, segment[a]._y, segment[b]._x) && !onTheLeft(segment[a]._x, segment[a]._y, segment[b]._y));
}

class iTree
{
    static const int SIZE = 1048576 * 2;
    std::vector<int> data[SIZE * 2];
    bool sorted[SIZE * 2];

    public:
        iTree(void);
        void insert(const int &start, const int &end, const int &sid, const int &iStart = 0, const int &iEnd = SIZE - 1, const int &pos = 1);
        int getTop(const Point &position, const int &iStart = 0, const int &iEnd = SIZE - 1, const int &pos = 1);
};

iTree tree;

int main(void)
{
    scanf("%d", &segments);
    for(int s = 1; s <= segments; ++ s)
    {
        scanf("%d %d %d %d", &segment[s]._x._x, &segment[s]._x._y,
                             &segment[s]._y._x, &segment[s]._y._y);

        segment[s]._x._x += 1000000;
        segment[s]._x._y += 1000000;
        segment[s]._y._x += 1000000;
        segment[s]._y._y += 1000000;

        if(segment[s]._x._x > segment[s]._y._x)
            std::swap(segment[s]._x, segment[s]._y);

        if(segment[s]._y._y > segment[s]._x._y)
        {
            events.push_back(Event(segment[s]._y._y, s));
            events.push_back(Event(segment[s]._x._y, -s));
        }

        else
        {
            events.push_back(Event(segment[s]._x._y, s));
            events.push_back(Event(segment[s]._y._y, -s));
        }
    }

    scanf("%d", &ball._x); ball._x += 1000000; ball._y = 1048576 * 2;
    std::sort(events.begin(), events.end());
    for(int e = 2 * segments - 1; e >= 0; -- e)
    {
        int &s = events[e]._y;
        if(s > 0)
        {
            tree.insert(segment[s]._x._x, segment[s]._y._x, s);
            continue;
        }

        s *= -1;
        if(onTheLeft(segment[s]._x, segment[s]._y, ball) && tree.getTop(ball) == s)
            ball = segment[s]._x._y == events[e]._x ? segment[s]._x : segment[s]._y;
    }

    printf("%d\n", ball._x - 1000000);
    return 0;
}

inline
iTree::iTree(void)
:data()
,sorted()
{
}

inline
void iTree::insert(const int &start, const int &end, const int &sid, const int &iStart/* = 0*/, const int &iEnd/* = SIZE - 1*/, const int &pos/* = 1*/)
{
    if(start == iStart && end == iEnd)
    {
        data[pos].push_back(sid);
        sorted[pos] = false;
        return;
    }

    int iMid = (iStart + iEnd) / 2;
    if(end <= iMid)
        insert(start, end, sid, iStart, iMid, pos * 2);

    else if(start > iMid)
        insert(start, end, sid, iMid + 1, iEnd, pos * 2 + 1);

    else
    {
        insert(start, iMid, sid, iStart, iMid, pos * 2);
        insert(iMid + 1, end, sid, iMid + 1, iEnd, pos * 2 + 1);
    }
}

inline
int iTree::getTop(const Point &position, const int &iStart/* = 0*/, const int &iEnd/* = SIZE - 1*/, const int &pos/* = 1*/)
{
    int current = -1,
        temp = -1;
    if(data[pos].size())
    {
        segment[131071]._x = ball;
        segment[131071]._y = ball;
        if(!sorted[pos])
        {
            sorted[pos] = true;
            std::sort(data[pos].begin(), data[pos].end(), above);
        }

        std::vector<int>::iterator lb = std::lower_bound(data[pos].begin(), data[pos].end(), 131071, above);
        if(lb != data[pos].end())
            current = *lb;
    }

    if(pos >= SIZE)
        return current;

    int iMid = (iStart + iEnd) / 2;
    if(position._x <= iMid)
        temp = getTop(position, iStart, iMid, pos * 2);

    else
        temp = getTop(position, iMid + 1, iEnd, pos * 2 + 1);

    if(temp != -1 && (current == -1 || (above(temp, current) && onTheLeft(segment[temp]._x, segment[temp]._y, ball))))
        current = temp;

    return current;
}
