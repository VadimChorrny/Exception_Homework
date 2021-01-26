#include <iostream>
#include <string>
using namespace std;

// can build exception hierarchy
//double triangle(const double& first_side,const double& second_side,const double& third_side)
//{
//	if (first_side <= 0)
//		throw first_side;
//	if (first_side >= second_side + third_side)
//		throw string("Side " + to_string(first_side));
//}

class Exception
{
public:
	Exception(const string& errMessage = "Unknow error!") : errMessage{ errMessage } {}
	virtual const string& what() const {};
private:
	string errMessage;
};
class WrongLengthException : public Exception
{
public:
	WrongLengthException(const string& errMessage = "error with length!") : Exception(errMessage) {}
};
class WrongDepthException : public Exception
{
public:
	WrongDepthException(const string& errMessage = "error with depth") : Exception(errMessage) {}
};
class WrongWidthException : public Exception
{
public:
	WrongWidthException(const string& errMessage = "error width!!!") : Exception(errMessage) {}
};
class WrongTypeException : public Exception
{
public:
	WrongTypeException(const string& errMessage = "error with type!!!") : Exception(errMessage) {}
};

class Water
{
public:
	enum  typeWater { LAKE, RIVER, SEA, UNDEFINED };
	Water(const size_t& length,const size_t& width,const size_t& depth,typeWater type)
	{
		setLengthWater(length);
		setWidthWater(width);
		setDepthWater(depth);
		setTypeWater(type);
	}

	void setLengthWater(const size_t& length)
	{
		if (length <= MAX_LENGTH)
			this->length = length;
		else
			throw WrongLengthException("");
	}
	void setWidthWater(const size_t& width)
	{
		if (width <= MAX_WIDTH)
			this->width = width;
		else
			throw WrongWidthException("");
	}
	void setDepthWater(const size_t& depth)
	{
		if (depth <= MAX_DEPTH)
			this->depth = depth;
		else
			throw WrongDepthException("");
	}
	void setTypeWater(typeWater type)
	{
		if (!typeWater::UNDEFINED)
			this->type = type;
		else
			throw WrongTypeException("");
	}
private:
	typeWater type;
	size_t length,width,depth;
	size_t MAX_LENGTH = 18000, MAX_WIDTH = 7000, MAX_DEPTH = 5000; // its information - false
};

void main()
{
	//try
	//{
	//	triangle(0, 0,0);
	//}
	//catch (double errMessage)
	//{
	//	cout << "Error : " << errMessage << endl;
	//}
	////catch (...) { cout << " Default (...) worked! " << endl; }



}


