//
// Created by ASUS on 2022/11/9.
//
/**
 * 实现一个读取csv文件的解析器
 * 类似python的这行代码
 * f_csv = csv.reader(f);
 * headers = next(f_csv);
 * for row in f_csv
 *  print(row)
 *  如果是大文件 可能不能一次性加载到内存中 需要处理完一部分再读取下一部分
 */

#ifndef CSVPARSER_CSVREADER_H
#define CSVPARSER_CSVREADER_H
#include <iostream>
#include <vector>
#include <fstream>
#include<unordered_map>

class CsvReader {
public:
    //初始化文件流
    CsvReader(std::string filename);


    std::vector<std::string> parseContent(const std::string& content);//解析一行的内容
    void   readHeader();
    void readRows();
    std::vector<std::string> getHeader();
    std::vector<std::vector<std::string>> getRows();
    void initHash();
    int colSize();
    int rowSize();
    int getHeaderIndex(const std::string& header);


private:
    std::ifstream  inf;
    std::vector<std::string> header;
    std::vector<std::vector<std::string>> rows;
    std::unordered_map<std::string,int> hash;//记录头部的各个值所在列

    int col_size;
    int row_size;


};


#endif //CSVPARSER_CSVREADER_H
