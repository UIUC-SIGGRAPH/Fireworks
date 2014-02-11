
#ifndef _UTILS_HPP_
#define _UTILS_HPP_


class Point
{
	public:
		Point(float x_, float y_, float z_);
		~Point();
		float x;
		float y;
		float z;
	private:
};

class Vec
{
	public:
		Vec(float x_, float y_, float z_);
		~Vec();
		float x;
		float y;
		float z;
	private:
};

#endif