//
// Created by ASUS on 2022/11/9.
//

#include "CsvReader.h"

void CsvReader::readHeader() {
    std::string  str ;
    if(getline(inf,str))
    {
        header = parseContent(str);
    }else
    {
         std::cout<<"it is a empty file."<<std::endl;
        exit(-1);
    }
    initHash();
}

void CsvReader::readRows() {
    std::string  str;
    while(getline(inf,str))
    {
        rows.emplace_back(parseContent(str));
    }
}

std::vector<std::string> CsvReader::getHeader() {
    return header;
}

std::vector<std::vector<std::string>> CsvReader::getRows() {
   return rows;
}


//传入一行带解析的内容
//格式为：content1 ,content2, content3....,contentn
//双指针
std::vector<std::string> CsvReader::parseContent(const std::string &content) {
    if(content.size()==0)
    {
        std::cout<<"invalid string size. string size < 0"<<std::endl;
        exit(-1);
    }
    std::vector<std::string> ret;
    int left =0;
    int right = 0;
    while(right < content.size())
    {
        while(right<content.size() && content[right]!=',')right++;
        if(right==content.size())
        {
            ret.emplace_back(content.substr(left));
            break;
        }
        ret.emplace_back(content.substr(left,right-left));
        left=right+1;
        right++;
    }
    return ret;
}

void CsvReader::initHash() {
    for(int i =0;i<header.size();i++)
    {
        hash[header[i]] = i;
    }
}

CsvReader::CsvReader(std::string filename)
{
    inf.open(filename);
    if(!inf.is_open())
    {
        std::cout<<"open file failed check the file path"<<std::endl;
    }
    readHeader();
    readRows();
    col_size = header.size();
    row_size = 1+rows.size();
}

int CsvReader::colSize() {
    return col_size;
}

int CsvReader::rowSize() {
    return row_size;
}

int CsvReader::getHeaderIndex(const std::string& header) {
    if(hash.count(header)==0)
    {
        std::cout<<"no such header"<<std::endl;
        exit(-1);
    }
    return hash[header];
}
