//
// Created by yechen on 2020/03/27.
//

#include "DataManager.h"

void DataManager::getDataFromFile(const string& filename){
    ifstream reader{filename};
    if(reader.is_open()){
        string line;
        for(;!reader.eof();){
            getline(reader, line);
            if(line.length()>2 && line[0]!=' ' && line[1]!='#' && line[2]!='#' && line[3]!='#'){
                auto [kind,en,zh] = analyzeLine(line);
                data[kind].push_back(pair{en,zh});
            }
        }
    }else {
        cout << "请确认 " << filename << " 的位置" << endl;
    }
}

tuple<string,string,string> DataManager::analyzeLine(string& line){
    int index0 = line.find_first_of('.');
    int index1 = line.find_first_of('=');
    int index2 = line.find_first_of('#');
    string kind;
    if(index0>0){
        kind = line.substr(0, index0);
    }else{
        kind = line.substr(0, index1);
    }
    string en = line.substr(0, index1);
    string zh = line.substr(index1+1, index2-index1-1);
    tuple<string,string,string> re{kind,en,zh};
    return re;
}

string DataManager::count(){
    int re = 0;
    for(const auto& [kind,v] : data){
        re += v.size();
    }
    return to_string(re)+"条目（1.14应有7936条目）";
}

void DataManager::print(){
    for(const auto& [kind,v] : data){
        for(const auto& [en,zh] : v){
            cout << en << "=" << zh << endl;
        }
    }
}

void DataManager::outputFiles(const string& path){
    for(const auto& [kind,v] : data){
        string filename = path+kind+".txt";
        ofstream writer{filename};
        for(const auto& [en,zh] : v){
            writer << en << "=" << zh << endl;
        }
        writer.close();
    }
}

void DataManager::outputResult(const string& path){
    ofstream writer{path+"result.lang"};
    for(const auto& [kind,v] : data){
        for(const auto& [en,zh] : v){
            writer << en << "=" << zh << endl;
        }
    }
    writer.close();
}



void DataManager::updateText(const DataManager& rightText){
    for(const auto& [kind,v] : rightText.data){
        if(data.count(kind)==0) continue;
        for(const auto& [en,zh] : v){

            for(auto & item : data[kind]){
                if(item.first==en){
                    item.second = zh;
                    break;
                }
            }

        }
    }
}

void DataManager::checkNew(const DataManager& newText){
    DataType newData;
    for(const auto& [kind,v] : newText.data){
        if(data.count(kind)==0){
            newData[kind] = v;
            continue;
        }
        for(const auto& [en,zh] : v){

            set<string> s;
            for(const auto& item : data[kind]){
                s.insert(item.first);
            }
            if(s.find(en)==s.end()){
                newData[kind].push_back(pair{en,zh});
            }

        }
    }
    ofstream writer{"newItems.txt"};
    if(newData.empty()){
        writer << "### 未检测到新的数据" << endl;
    }else{
        for(const auto& [kind,v] : newData){
            for(const auto& [en,zh] : v){
                writer << en << "=" << zh << endl;
            }
        }
    }
    writer.close();
}










