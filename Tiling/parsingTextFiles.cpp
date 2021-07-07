//#include<string>
//#include<fstream>
//#include<iostream>
//
//#undef main
//
//int main() {
//	std::fstream newFile;
//	newFile.open("../assets/tileMaps/map.txt", std::ios::in);
//	if (newFile.is_open()) {
//		std::string map;
//		while (std::getline(newFile, map)) {
//			std::cout << map << "\n";
//		}
//		newFile.close();
//	}
//	return 0;
//}