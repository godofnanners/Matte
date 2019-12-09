#pragma once
template <class T>
class Line
{
	// Default constructor: there is no line, the normal is the zero vector.
	Line();
	// Copy constructor.
	Line(const Line <T>& aLine);
	// Constructor that takes two points that define the line, the direction is aPoint1 -aPoint0.
	Line(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1);
	// Init the line with two points, the same as the constructor above.
	void InitWith2Points(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1);
	// Init the line with a point and a direction.
	void InitWithPointAndDirection(const Vector2<T>& aPoint, const Vector2<T>&
		aDirection);
	// Returns whether a point is inside the line: it is inside when the point is on the
	line or on the side the normal is pointing away from.
		bool IsInside(const Vector2<T> & aPosition) const;
	// Returns the direction of the line.
	const Vector2<T>& GetDirection() const;
	// Returns the normal of the line, which is (-direction.y, direction.x).
	const Vector2<T>& GetNormal() const;
};