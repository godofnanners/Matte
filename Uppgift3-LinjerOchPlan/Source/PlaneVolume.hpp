#pragma once

template <class T>
class PlaneVolume
{
	// Default constructor: empty PlaneVolume.
	PlaneVolume();
	// Constructor taking a list of Plane that makes up the PlaneVolume.
	PlaneVolume(const std::vector<Plane<T>>& aPlaneList);
	// Add a Plane to the PlaneVolume.
	void AddPlane(const Plane<T>& aPlane);
	// Returns whether a point is inside the PlaneVolume: it is inside when the point is on the
		// plane or on the side the normal is pointing away from for all the planes in the PlaneVolume.
	bool IsInside(const Vector3<T>& aPosition);
};