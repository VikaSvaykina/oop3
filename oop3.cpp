#include "Storage.h"
#include <iostream>
#include <time.h>

using namespace std;

class Test	//родительский класс для тестирования
{
protected:
	int object;
public:
	Test()
	{
		object = 0;
	}
	void Setobject(int object)	//метод сеттер объекта
	{
		this->object = object;
	}
	int Getobject()	//метод геттер объекта
	{
		return object;
	}
};

class DaughterTest : public Test	//дочерний класс для тестирования
{
public:
	DaughterTest() : Test()
	{
		object = 1;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(0));
	int count = 100;
	Storage<Test> storage;
	while (count <= 10000)	//цикл для тестирования
	{
		long double time = 0;
		clock_t start = clock();
		for (int i = 0; i < count; ++i)
		{
			switch (rand() % 3)	//случайный выбор действия
			{
			case 0:
				storage.PushObject(rand() % count, new DaughterTest);	//добавляем объект в контейнер
				break;
			case 1:
				storage.DelObject(rand() % count);	//удаляем оъект из контейнера
				break;
			case 2:
				int setget = rand() % 2;
				if (setget == 0) storage.GetObject(rand() % count)->Getobject();	//геттер объекта
				else storage.GetObject(rand() % count)->Setobject(rand() % 100);	//сеттер объекта
				break;
			}
		}
		clock_t end = clock();
		time += (long double)(end - start) / CLOCKS_PER_SEC;	//время
		cout << count << " случайных действий: " << time << " секунд" << endl;
		count *= 10;
	}
}