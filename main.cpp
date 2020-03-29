#include <iostream>
#include "DataManager.h"
using namespace std;

int main() {

    DataManager dm;
    dm.getDataFromFile("./src/zh_CN.lang");
    int code = 6;

    while(code!=0){
        cout << "\n你想做什么？" << endl;
        cout << "更新正确翻译，输入1。 ";
        cout << "确认新增文本，输入2。 ";
        cout << "输入0结束" << endl;

        cin >> code;

        if(code==0){
            exit(0);
        }else if(code==1){
            /* 将rightText.txt的数据更新进来，并输出结果文件 */
            DataManager rightText;
            rightText.getDataFromFile("./src/rightText.txt");
            rightText.print();
            dm.updateText(rightText);
            dm.outputResult("./src/");
        }else if(code==2){
            /* 对比zh_CN.lang和zh_CN_new.lang，输出新增文本项目 */
            DataManager newText;
            newText.getDataFromFile("./src/zh_CN_new.lang");
            dm.checkNew(newText);
        }else{
            cout << "请输入正确数字" << endl;
        }

    }

    //dm.print();
    //cout << dm.count() << endl;
    //dm.outputFiles("./src/output/");



    return 0;
}



