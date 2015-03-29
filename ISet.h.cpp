#pragma once

template <class T> class ISet {
public:
	// добавить элемент    
	virtual void add(const T& elem) = 0;
	// удалить элемент    
	virtual void remove(const T& elem) = 0;
	// содержится ли элемент    
	virtual bool contains(const T& elem) const = 0;
	// узнать размер множества    
	virtual int size() const = 0;
};
