//
// Created by ASUS on 2022/11/8.
//

#ifndef CSVPARSER_CSVPARSER_H
#define CSVPARSER_CSVPARSER_H


#include <vector>
#include <fstream>
#include<unordered_map>
#include <vector>
#include <iostream>


class CsvParser {
public:
    //构造函数 传入文件的路径
    CsvParser(const std::string &fileName);


    int writeHeader(const std::vector<std::string>& headers);
    void push_row_data(const std::string& header,const std::string& item);
    int write_row();
    void writeData(const std::vector<std::string> &content);
    void  initHash(const std::vector<std::string> &headers);

private:
    std::ofstream of;
    std::unordered_map<std::string ,int > index_hash;//记录hash所在的列 列从1开始
    int col_size; //列数
    int row_size; //行数
    int push_item_sz; // 表示装入vector元素的个数
    std::vector<std::string> items;//将所有元素装入一个vector之后再进行写入

};



#endif //CSVPARSER_CSVPARSER_H
