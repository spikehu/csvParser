# csvParser
一个读和写csv文件的库


读取操作，返回的是字符串
~~~C++
CsvReader csvReader("data.csv");
    std::vector<std::string> headers;
    headers = csvReader.getHeader();
    std::vector<std::vector<std::string>> rows = csvReader.getRows();
    for(int i = 0;i<csvReader.rowSize();i++)
    {
        std::cout<<rows[i][csvReader.getHeaderIndex("h2")]<<" ";
        std::cout<<endl;
    }
    return 0;
~~~

写操作
~~~C++
    CsvWriter csv("data.csv");
    csv.writeHeader({"h1","h2","h3"});
    std::vector<string> strs ={"h1","h2","h3"};
    for(int i =0;i < 1000;i++)
    {
        for(int j =0;j<csv.colSize();j++)
        {
            csv.push_row_data(strs[j],to_string(csv.rowSize()*csv.colSize()+j));
        }
        csv.write_row();
    }
~~~


