#include <iostream>
#include <windows.h>
#include <vector>
#include <utility>
#include <unordered_map>

class DataManager {

public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount; 
		for (size_t i = 0; i < _keys.size(); i++) {// прошли по вектору
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 }); //достаем из вектора ключ и пытаемс€ сделать вставку(вложили ключ и кол-во встреч)
			if (!isInserted) {  //если вставка не произошла, то
				auto value = it->second; // достанем значение
				value++; //увеличиваем его
				keyAmount[_keys[i]] = value;//складываем обратно по адресу
			}
		}
		std::pair<int, int> key_biggestValue = {0,0}; //переменна€ где храним самый большой элемент
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {//ищем самый большой элемент
			if (key_biggestValue.second < it->second) { //переопредел€ем пару
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
		throw "division by zero"; //должен находитс€ внутри try, троу формирует объект
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
	//	std::cerr << msg << std::endl;// дискриптор ошибок как cout
	//}
	//catch (...) {//catch all(поймать все) плоха€ практика
	//	std::cerr << "ѕроизошла ошибка" << std::endl;
	//}
	std::vector<int> v{ 1, 2, 3 };
	try {
		int z = v.at(10);//доступ по индексу 10 .если элемент не существует бросает исключение
	}
	catch (const std::out_of_range& e) {//класс out_of_range(вне диапазона)
		std::cerr << e.what() << std::endl; //что произошло выведет
	}










	//std::tuple<int, std::string, double, float> t{ 1, "hey", 5.4, 2.3f };
	//const auto& [a, b, c, d] = t;
	//std::tuple <int, int, double> t2;
	//std::cout << a << "  " << b << " " << c << " " << d << std::endl;
	//std::cout << std::get<0>(t) << std::endl;
	//std::vector<std::tuple<int, double, std::string>> vec;
	//vec.push_back({ 1, 2.5, "Bob" });//заполнили вектор значени€ми
	//vec.push_back({ 2, 3.5, "Bobsik" });

	//for(size_t i = 0; i < vec.size(); i++) {
	//	const auto& [x, y, z] = vec[i];//присваиваем нашим значени€м переменные
	//	std::cout << x << " " << y << " " << z << std::endl;
	//}

	//DataManager dm;
	//std::cout << dm.mostSearchedKey() << std::endl;

	 



}