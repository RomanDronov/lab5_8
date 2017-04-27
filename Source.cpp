#include <iostream>
#include <conio.h>
#include <cstdio>
#include <fstream>//библиотека для работы с файлами
using std::cin;
using std::cout;
using std::endl;
//структура тоже что и класс только не имеет функции, по сути стурктуры это предмет и его свойства к примеру 
//и стол и его ширина и высота можно создать множество таких столов однако все они будут иметь одинаковые свойства
struct city {
	char Name[50]; //массив символов внутри стуктуры, так как чар тип данных принимает только один символ нужен массив чтобы хранить его название
	int population;
};
void ByName(city*cities, int size);//объявление функции для нахождения поля с максимальной и минимальной длинной в массиве струтктур
int main() {
	int size;
	cout << " Welcome!I will help u with sorting cities that you will type here" << endl;
	cout << "I can sort cities by the size of population and also by lenght of the name. Good luck!" << endl;
	size = 0;
	city *cities = new city[100];//объявление массива структур это 100 одинаковых структур но в них можно записать разные данные
	//к примеру 100 столов с разными параметрами
	std::ifstream file("data.txt");//открываем заранее подготовленный файл для вывода и объявляем переменную для работы с файлом 
	if (!file.is_open()) cout << "Can not open teh file!";//если файл не удалось открыть ошибка
	else {
		int i = 0;//так как количество данных в файле на неизвестно объявлем переменную котоорая будет заполнять массив струкутр с 0
		while(file){ //пока открыт файл, пока не дойдем до его конца


				file >> cities[i].Name;//записываем с помощью обЪялвенной переменной данные из файла в поле имя каждой из структур
			file >> cities[i].population;//записываем числа
			size++;//так как количество данных неизвестно, есть счетчик который будет считать сколько структур в массиве заполнено
			//для их сортировки
			i++;
		}
		file.close();//закрываем файл
	}

	ByName(cities, size);//передаем данные в функцию


	for (int i = 0; i < size-1; i++) {//выводим на экран результат
		cout << cities[i].Name << endl;
		cout << cities[i].population << endl;
	}
	delete[] cities;
	system("pause");
	return 0;
}

void ByName(city * cities, int size)
{
	city min = cities[0];//прдеполагаем что у первой структуры текстовое поле самое короткое
	city max = cities[0];//прдеполагаем что у первой структуры текстовое поле самое длинное и объявляем переменную типа структуры
	city tmp;
	int min_idx = 0;//сюда запищется индекс структуры где самое корткое название города в нижнюю переменную где самое длинное
	int max_idx = 0;
	
	for (int i = 0; i < size-1; i++) {
		if (strlen(min.Name) > strlen(cities[i].Name)) {//функция стрлен определяет длину строки
			//если цикл выполняется происходит обмен и переменной в которую записывается мин знач присваивается текузий индекс и
			min = cities[i];
			min_idx = i;
		}
	}
		for (int j = 0; j < size-1; j++) {
			if (strlen(max.Name) < strlen(cities[j].Name)) {
				max = cities[j];
				max_idx = j;
			}
		}
			tmp = cities[max_idx]; //обмен структуры с минимальной и максимальной величиной строки
			cities[max_idx] = cities[min_idx];
			cities[min_idx] = tmp;
	}
