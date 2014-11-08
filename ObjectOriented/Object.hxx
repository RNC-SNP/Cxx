#ifndef OBJECT_HXX
#define OBJECT_HXX

class Object {
public:
	Object() = default;
	//declare a pure virtual function. So 'Object' is a abstract class.
	virtual void print() const = 0;
	virtual ~Object() = default;//Base class usually has a virtual destructor.
};

#endif