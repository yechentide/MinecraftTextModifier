#include <iostream>
#include "DataManager.h"
using namespace std;

int main() {

    DataManager dm;
    dm.getDataFromFile("./src/zh_CN.lang");

    //dm.print();
    //cout << dm.count() << endl;
    //dm.outputFiles("./src/output/");

    /* 将rightText.txt的数据更新进来，并输出结果文件
    DataManager rightText;
    rightText.getDataFromFile("./src/rightText.txt");
    rightText.print();
    dm.updateText(rightText);
    dm.outputResult("./src/");
    */

    /* 对比zh_CN.lang和zh_CN_new.lang，输出新增文本项目
    DataManager newText;
    newText.getDataFromFile("./src/zh_CN_new.lang");
    dm.checkNew(newText);
    */



    return 0;
}



