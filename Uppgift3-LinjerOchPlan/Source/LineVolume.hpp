#pragma once
template<class T>
class LineVolume
{
	// Default constructor: empty LineVolume.
	LineVolume();
	// Constructor taking a list of Line that makes up the LineVolume.
	LineVolume(const std::vector<Line<T>>& aLineList);
	// Add a Line to the LineVolume.
	void AddLine(const Line<T>& aLine);
	// Returns whether a point is inside the LineVolume: it is inside when the point is
	// on the line or on the side the normal is pointing away from for all the lines in
	// the LineVolume.
	bool IsInside(const Vector2<T>& aPosition);
};