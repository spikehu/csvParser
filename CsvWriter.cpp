//
// Created by ASUS on 2022/11/8.
//

#include "CsvWriter.h"

CsvWriter::CsvWriter(const std::string &fileName): col_size(0), row_size(0), push_item_sz(0) {
    of.open(fileName,std::ofstream::app);
    if(!of.is_open())
    {
        std::cout<<"open file failed";
        exit(-1) ;
    }
}

//write header
//传入的是字符串数组
//写入格式为: header1,header2,...headern
//return : 返回header的个数
int CsvWriter::writeHeader(const std::vector<std::string> &headers) {
    int sz = headers.size();
    col_size = sz;
    initHash(headers);
    writeData(headers);
    row_size = headers.size();
    items.resize(col_size);
    return sz;
}

void CsvWriter::push_row_data(const std::string &header, const std::string &item) {
    if(index_hash.count(header)==0)
    {
        for (auto it : index_hash)
        {
            std::cout<<it.first<<std::endl;
        }
        std::cout<<"no such header"<<std::endl;
        exit(-1);
    }
    items[index_hash[header]] = item;
    push_item_sz++;
}

int CsvWriter::write_row() {
    if(push_item_sz != col_size)
        {
            std::cout<<push_item_sz<<","<<col_size<<std::endl;
            std::cout<<"数据数量不一致"<<std::endl;
            exit(-1);
        }
    //    //将items中的数据写入csv文件
    writeData(items);
    //push_item_sz置为0
    push_item_sz=0;
    row_size++;
    return 0;
}

void CsvWriter::writeData(const std::vector<std::string> &content) {
    for(int i =0; i < content.size() - 1; i++)
    {
        of << content[i] << ',';
    }
    of << content.back() << '\n';
}

void CsvWriter::initHash(const std::vector<std::string> &headers) {
        for(int i =0;i<headers.size();i++)
        {
            index_hash[headers[i]] = i;
        }
}

int CsvWriter::colSize() {
    return col_size;

}

int CsvWriter::rowSize() {
    return row_size;
}

