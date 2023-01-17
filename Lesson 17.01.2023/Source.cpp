#include <iostream>
#include <windows.h>
#include <vector>
#include <utility>
#include <unordered_map>

class DataManager {

public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount; 
		for (size_t i = 0; i < _keys.size(); i++) {// ������ �� �������
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 }); //������� �� ������� ���� � �������� ������� �������(������� ���� � ���-�� ������)
			if (!isInserted) {  //���� ������� �� ���������, ��
				auto value = it->second; // �������� ��������
				value++; //����������� ���
				keyAmount[_keys[i]] = value;//���������� ������� �� ������
			}
		}
		std::pair<int, int> key_biggestValue = {0,0}; //���������� ��� ������ ����� ������� �������
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {//���� ����� ������� �������
			if (key_biggestValue.second < it->second) { //�������������� ����
			key_biggestValue = std::make_pair(it->first, it->second);
		}
		}
		return key_biggestValue.first;
	}


private:
	std::vector<int>_keys = { 1, 1, 2, 2, 4, 2, 6, 7, 7, 2 };
};

int divide(int a, int b) {
	if (b == 0) {
		throw "division by zero"; //������ ��������� ������ try, ���� ��������� ������
	}
	return a / b;
}
int errorFunc() {
	throw 0;
	return 1;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//int x = 10, y = 0;
	//try {
	//	errorFunc();
	//	std::cout << divide(x, y) << std::endl;
	//}
	//catch (const char* msg) {
	//	std::cerr << msg << std::endl;// ���������� ������ ��� cout
	//}
	//catch (...) {//catch all(������� ���) ������ ��������
	//	std::cerr << "��������� ������" << std::endl;
	//}
	std::vector<int> v{ 1, 2, 3 };
	try {
		int z = v.at(10);//������ �� ������� 10 .���� ������� �� ���������� ������� ����������
	}
	catch (const std::out_of_range& e) {//����� out_of_range(��� ���������)
		std::cerr << e.what() << std::endl; //��� ��������� �������
	}










	//std::tuple<int, std::string, double, float> t{ 1, "hey", 5.4, 2.3f };
	//const auto& [a, b, c, d] = t;
	//std::tuple <int, int, double> t2;
	//std::cout << a << "  " << b << " " << c << " " << d << std::endl;
	//std::cout << std::get<0>(t) << std::endl;
	//std::vector<std::tuple<int, double, std::string>> vec;
	//vec.push_back({ 1, 2.5, "Bob" });//��������� ������ ����������
	//vec.push_back({ 2, 3.5, "Bobsik" });

	//for(size_t i = 0; i < vec.size(); i++) {
	//	const auto& [x, y, z] = vec[i];//����������� ����� ��������� ����������
	//	std::cout << x << " " << y << " " << z << std::endl;
	//}

	//DataManager dm;
	//std::cout << dm.mostSearchedKey() << std::endl;

	 



}