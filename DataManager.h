//
// Created by yechen on 2020/03/27.
//

#ifndef MINECRAFTTEXTMODIFIER_DATAMANAGER_H
#define MINECRAFTTEXTMODIFIER_DATAMANAGER_H

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

class DataManager {
public:
    using DataType = map<string, vector<pair<string,string>>>;
    DataType data;

    void getDataFromFile(const string& filename);
    static tuple<string,string,string> analyzeLine(string& line);
    string count();

    void print();
    void outputFiles(const string& path);
    void outputResult(const string& path);

    void updateText(const DataManager& rightText);
    void checkNew(const DataManager& newText);





};


#endif //MINECRAFTTEXTMODIFIER_DATAMANAGER_H
