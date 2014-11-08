#ifndef OBJECT_HXX
#define OBJECT_HXX

class Object {
public:
	Object() = default;
	//declare a pure virtual function. So 'Object' is a abstract class.
	virtual void print() const = 0;
	//virtual destructor needed if a base pointer pointing to a derived object is deleted.
	virtual ~Object() = default;//dynamic binding for the destructor
};

#endif