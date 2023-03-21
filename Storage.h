#pragma once
#include <iostream>

template <class T> class Storage
{
protected:
	int size;	//������
	T* mas;	//��������� �� ������
public:
	Storage()	//����������� ��� ����������
	{
		size = 1;
		mas = new T[size];
	}
	Storage(int size)//����������� � �����������
	{
		this->size = size;
		mas = new T[this.size];
	}
	Storage(const Storage& storage)	//����������� ����������� � ����������-�������� �����
	{
		size = storage.size;
		mas = new T[size];
		for (int i = 0; i < size; ++i)
		{
			mas[i] = storage.mas[i];
		}
	}
	~Storage()	//����������
	{
		delete[]mas;
	}

	void PushObject(int index, T* value)	//��������� ������ � ���������
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

	void SetObject(int index, T* value)	//�������� ������ � ���������� �� �����
	{
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;
		mas[index] = *value;
	}

	T* DelObject(int index)	//������� ������ �� ����������
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

	T* GetObject(int index)	//�������� ������ �� ���������� ��� ��������
	{
		if (size == 0)
			return nullptr;
		if (index >= size) index = size - 1;
		if (index < 0) index = 0;
		return &mas[index];
	}

	int GetSize()	//�������� ������ ����������
	{
		return size;
	}
};