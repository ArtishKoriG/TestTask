# TestTask
Description:
A polyline in 3D is given by the list of nodes’ coordinates. Implement an algorithm that
searches the nearest point on the polyline to any given point. In case of multiple solutions,
output all of them.

FinderNearestPoint:
Class Coordinates: 
Contains the x, y and z coordinates of the point.
getX(), getY(), getZ() - returns the corresponding coordinates of the point.
setX(const double&), setY(const double&), setZ(const double&) - changes the corresponding coordinates of the point.
getDistance(const Coordinates&) - returns the distance between points.

Class Vector:
Builds an object based on coordinates or 2 points.
Contains coordinates of the vector.
setCoord(const Coordinates&) - changes coordinates of the vector.
getCoord() - return coordinates of the vector.
getScalarProduct(const Vector&) - returns a value equal to the scalar product of 2 vectors.
getLen() - return length of the vector.
operator+(const Vector&)
operator+=(const Vector&)
operator*(const double&)
operator*=(const double&)
operator-(const Vector&)
operator-=(const Vector&) - overloading of the corresponding operators

Class SegmentLine:
Contains the coordinates of the start and end points of the segment.
setPoint1(const Coordinates&), setPoint2(const Coordinates&) - changes the coordinates of the start and end points of the segment.
getPoint1() - return coordinates of the start of the segment.
getPoint2() - return coordinates of the end of the segment.

class FinderDistToSegment:
Contains a std::vector of segments and data in form std::multimap, key - distance from target to segment, value number of segment and proection target on segment.
getData() - return data.
clearData() - clear multimap.
findDist(const Coordinates& target) - searches for distances from the target point to each segment.
If A and B are segment points, and E is a target point, then scalar products are considered (AB.AE) and (AB.BE).
We have 3 cases:
![Untitled-Diagram-614](https://github.com/user-attachments/assets/dc9d3d26-57d3-4e81-b968-7e9a37ebc545)
![Untitled-Diagram-515](https://github.com/user-attachments/assets/f1b66364-7a1c-41b6-86b9-2d50fe16200f)
![Untitled-Diagram-5-1-1](https://github.com/user-attachments/assets/95c73b67-3c67-4aa1-84bb-3508c1eafca9)
If (AB.AE) <= 0, then AE is the minimum distance to the segment. If (AB.BE) >= 0, then BE the minimum distance.
Otherwise, we are looking for the projection of the target point onto the segment using the formula
![ПТПР01](https://github.com/user-attachments/assets/642aaee4-305d-4b76-85be-989fa4e0c182)
where r2 is the radius vector to the projection, r1 and s1 are the vector making up the segment, r0 is the vector from the beginning of the segment to the target point

MainProject:
class ILogger - interface for ConsoleLogger.
write(const std::multimap<double, std::pair<size_t, Coordinates>>& data) - write data.

Class Logger - context for strategy.
logData() - return write().
setStratygy() - set strategy for log data.

Class ConsoleLogger - log in console.

Class ParserPoints:
read() - parsing data from txt file.
getPoints() - return data.







