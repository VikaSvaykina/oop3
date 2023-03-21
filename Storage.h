#pragma once
#include <iostream>

template <class T> class Storage
{
protected:
	int size;	//размер
	T* mas;	//указатель на массив
public:
	Storage()	//конструктор без параметров
	{
		size = 1;
		mas = new T[size];
	}
	Storage(int size)//конструктор с параметрами
	{
		this->size = size;
		mas = new T[this.size];
	}
	Storage(const Storage& storage)	//конструктор копирования с параметром-объектом класс
	{
		size = storage.size;
		mas = new T[size];
		for (int i = 0; i < size; ++i)
		{
			mas[i] = storage.mas[i];
		}
	}
	~Storage()	//деструктор
	{
		delete[]mas;
	}

	void PushObject(int index, T* value)	//добавляем объект в контейнер
	{
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;

		T* Nmas = new T[size + 1];
		for (int i = 0; i < index; ++i)
		{
			Nmas[i] = mas[i];
		}
		for (int i = index + 1; i < size - 1; ++i)
		{
			Nmas[i] = mas[i];
		}
		Nmas[index] = *value;

		delete[]mas;
		mas = Nmas;
		++size;
	}

	void SetObject(int index, T* value)	//заменяем объект в контейнере на новый
	{
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;
		mas[index] = *value;
	}

	T* DelObject(int index)	//удаляем объект из контейнера
	{
		if (size == 1)
			return nullptr;
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;

		T* Nmas = new T[size - 1];
		T value = mas[index];
		for (int i = 0; i < index; ++i)
		{
			Nmas[i] = mas[i];
		}
		for (int i = index + 1; i < size - 1; ++i)
		{
			Nmas[i] = mas[i];
		}

		delete[]mas;
		mas = Nmas;
		--size;
		return &value;
	}

	T* GetObject(int index)	//получаем объект из контейнера без удаления
	{
		if (size == 0)
			return nullptr;
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;
		return &mas[index];
	}

	int GetSize()	//получаем размер контейнера
	{
		return size;
	}
};