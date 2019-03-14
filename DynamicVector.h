//#pragma once
//#include "Dog.h"
//template <typename T>
//
//class DynamicVector
//{
//private:
//	T * elems;
//	int size;
//	int capacity;
//
//public:
//	DynamicVector(int capacity = 10);
//
//	DynamicVector(const DynamicVector& v);
//	~DynamicVector();
//
//	DynamicVector& operator=(const DynamicVector& v);
//	DynamicVector& operator-(const T& d);
//
//	int add(const T& e);
//	int getCapacity() const { return capacity; }
//
//	int getSize() const;
//	T* getAllElems() const;
//	int deleteDog(const int pos);
//	int updateDog(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight);
//private:
//	void resize(int factor = 2);
//};
//
//template<typename T>
//DynamicVector<T>::DynamicVector(int capacity)
//{
//	/*
//	We create a dynamic vector
//	*/
//	this->size = 0;
//	this->capacity = capacity;
//	this->elems = new T[capacity];
//}
//
//template<typename T>
//DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
//{
//	/*
//	We copy a dynamic vector
//	*/
//	this->size = v.size;
//	this->capacity = v.capacity;
//	this->elems = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//}
//
//template<typename T>
//DynamicVector<T>::~DynamicVector()
//{
//	/*
//	We delete the dynamic vector
//	*/
//	delete[] this->elems;
//}
//
//template<typename T>
//DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
//{
//	/*
//	We overload the = operator
//	*/
//	if (this == &v)
//		return *this;
//
//	this->size = v.size;
//	this->capacity = v.capacity;
//
//	delete[] this->elems;
//	this->elems = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//
//	return *this;
//}
//
//template<typename T>
//DynamicVector<T>& DynamicVector<T>::operator-(const T & d)
//{
//	int pos = -1;
//	for (int i = 0; i < this->getSize(); i++)
//		if (this->elems[i] == d)
//			pos = i;
//	this->deleteDog(pos);
//	return *this;
//}
//
//template<typename T>
//int DynamicVector<T>::add(const T& e)
//{
//	/*
//	We add a dog to the repo. if the dog exists,we return 0
//	*/
//	for (int i = 0; i < this->size; i++)
//		if (this->elems[i] == e)
//			return 0;
//	if (this->size == this->capacity)
//		this->resize();
//	this->elems[this->size] = e;
//	this->size++;
//	return 1;
//}
//
//template<typename T>
//void DynamicVector<T>::resize(int factor)
//{
//	/*
//	We resize the vector if the capacity is equal to the size
//	*/
//	this->capacity *= factor;
//
//	T* els = new T[this->capacity];
//	for (int i = 0; i < this->size; i++)
//		els[i] = this->elems[i];
//
//	delete[] this->elems;
//	this->elems = els;
//}
//
//template<typename T>
//int DynamicVector<T>::deleteDog(const int pos)
//{
//	/*
//	We delete a dog. if the position is invalid,we return 0
//	*/
//	if (pos < 0 || pos >= this->size)
//		return 0;
//	for (int i = pos; i < this->size - 1; i++)
//		this->elems[i] = this->elems[i + 1];
//	this->size--;
//	return 1;
//}
//
//template<typename T>
//int DynamicVector<T>::updateDog(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight)
//{
//	/*
//	We update the dog
//	*/
//	if (pos < 0 || pos >= this->size)
//		return 0;
//	T d = T{ breed,name,age,photo,weight};
//	this->elems[pos] = d;
//	return 1;
//}
//
//template<typename T>
//T* DynamicVector<T>::getAllElems() const
//{
//	/*
//	We get all the elements
//	*/
//	return this->elems;
//}
//
//template<typename T>
//int DynamicVector<T>::getSize() const
//{
//	/*
//	We get the size of the vector
//	*/
//	return this->size;
//}
