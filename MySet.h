#pragma once

#include "ISet.h"

template <class T> class MySet : public ISet < T > {
private:
	//Харнилище данных
	T* data;
	//текущий размер
	int size1;
	//Максимальная вместимость
	int capacity;

public:
	//Конструктор
	MySet(){
		capacity = 10;
		size1 = 0;
		data = new T[capacity];
	}

	//Конструктор копирования
	MySet(const MySet &copy){
		size1 = copy.size1;
		capacity = copy.capacity;
		data = new T[capacity];
		for (int i = 0; i < size1; ++i){
			data[i] = copy.data[i];
		}
	}

	// Оператор присваивания
	MySet& operator = (const MySet& copy){
		size1 = copy.size1;
		capacity = copy.capacity;
		data = new T[capacity];
		for (int i = 0; i < size1; ++i){
			data[i] = copy.data[i];
		}
		return *this;
	}

	//Деструктор
	~MySet(){
		delete[] data;
	}

	// узнать размер множества    
	virtual int size() const {
		return size1;
	}

	// содержится ли элемент    
	virtual bool contains(const T& elem) const {
		for (int i = 0; i < size1; ++i) {
			if (data[i] == elem) { return true; }
		}
		return false;
	}

	// удалить элемент    
	virtual void remove(const T& elem) {	
		for (int i = 0; i < size1; ++i) {
			if (data[i] == elem) {
				for (int j = i + 1; j < size1; ++j) {
					data[j - 1] = data[j];
				}
				size1--;
			}
		}
	}

	// добавить элемент    
	virtual void add(const T& elem) {
		data[size1++] = elem;
		//увеличение размера массива по мере заполнения
		if (size1 == capacity) {
			capacity = capacity * 2;
			T* data1 = new T[capacity];
			for (int i = 0; i < size1; ++i) {
				data1[i] = data[i];
			}
			std::swap(data1, data);
			delete[] data1;
		}
	}
};
