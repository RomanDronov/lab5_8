#include <iostream>
#include <conio.h>
#include <cstdio>
#include <fstream>//���������� ��� ������ � �������
using std::cin;
using std::cout;
using std::endl;
//��������� ���� ��� � ����� ������ �� ����� �������, �� ���� ��������� ��� ������� � ��� �������� � ������� 
//� ���� � ��� ������ � ������ ����� ������� ��������� ����� ������ ������ ��� ��� ����� ����� ���������� ��������
struct city {
	char Name[50]; //������ �������� ������ ��������, ��� ��� ��� ��� ������ ��������� ������ ���� ������ ����� ������ ����� ������� ��� ��������
	int population;
};
void ByName(city*cities, int size);//���������� ������� ��� ���������� ���� � ������������ � ����������� ������� � ������� ���������
int main() {
	int size;
	cout << " Welcome!I will help u with sorting cities that you will type here" << endl;
	cout << "I can sort cities by the size of population and also by lenght of the name. Good luck!" << endl;
	size = 0;
	city *cities = new city[100];//���������� ������� �������� ��� 100 ���������� �������� �� � ��� ����� �������� ������ ������
	//� ������� 100 ������ � ������� �����������
	std::ifstream file("data.txt");//��������� ������� �������������� ���� ��� ������ � ��������� ���������� ��� ������ � ������ 
	if (!file.is_open()) cout << "Can not open teh file!";//���� ���� �� ������� ������� ������
	else {
		int i = 0;//��� ��� ���������� ������ � ����� �� ���������� �������� ���������� �������� ����� ��������� ������ �������� � 0
		while(file){ //���� ������ ����, ���� �� ������ �� ��� �����


				file >> cities[i].Name;//���������� � ������� ����������� ���������� ������ �� ����� � ���� ��� ������ �� ��������
			file >> cities[i].population;//���������� �����
			size++;//��� ��� ���������� ������ ����������, ���� ������� ������� ����� ������� ������� �������� � ������� ���������
			//��� �� ����������
			i++;
		}
		file.close();//��������� ����
	}

	ByName(cities, size);//�������� ������ � �������


	for (int i = 0; i < size-1; i++) {//������� �� ����� ���������
		cout << cities[i].Name << endl;
		cout << cities[i].population << endl;
	}
	delete[] cities;
	system("pause");
	return 0;
}

void ByName(city * cities, int size)
{
	city min = cities[0];//������������ ��� � ������ ��������� ��������� ���� ����� ��������
	city max = cities[0];//������������ ��� � ������ ��������� ��������� ���� ����� ������� � ��������� ���������� ���� ���������
	city tmp;
	int min_idx = 0;//���� ��������� ������ ��������� ��� ����� ������� �������� ������ � ������ ���������� ��� ����� �������
	int max_idx = 0;
	
	for (int i = 0; i < size-1; i++) {
		if (strlen(min.Name) > strlen(cities[i].Name)) {//������� ������ ���������� ����� ������
			//���� ���� ����������� ���������� ����� � ���������� � ������� ������������ ��� ���� ������������� ������� ������ �
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
			tmp = cities[max_idx]; //����� ��������� � ����������� � ������������ ��������� ������
			cities[max_idx] = cities[min_idx];
			cities[min_idx] = tmp;
	}
