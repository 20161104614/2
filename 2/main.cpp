//
//  main.cpp
//  2
//
//  Created by 20161104612 on 18/6/26.
//  Copyright © 2018年 20161104612. All rights reserved.
//


/*#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

int main()
{
    ifstream fin("scoresheet.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout <<"原表字符串："<< line << endl; //整行输出
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
    }
    return EXIT_SUCCESS;
}*/

#include<iostream>
#include<fstream>

using namespace std;

struct student{
    int age;
    char name[15];
    float score;
};

int main()
{
    struct student *pst;
    struct student tst;
    int i,j,m,n;
    int lin;
    
    cout<<"请输入学生的个数：";
    scanf("%d",&lin);
    pst=(struct student *)malloc(lin * sizeof(struct student));
    for(i = 0; i<lin; i++)
    {
        cout<<"请输入第"<<i+1<<"个学生的信息"<<endl;
        
        cout<<"name = ";
        cin>>pst[i].name;
        
       printf("age = ");
       scanf("%d", &pst[i].age);
        
        
        printf("score = ");
        scanf("%f", &pst[i].score);
    }
    
    //按分数从小到大进行排序
    for(m=0; m<lin; m++)
    {
        for(n = 0; n<lin-1-m;n++)
            if(pst[n].score > pst[n+1].score)
            {
                tst = pst[n];
                pst[n] = pst[n+1];
                pst[n+1] = tst;
            }
    }
    
    printf("\n==========学生信息输出============\n\n");
    
    for(j = 0; j<lin; j++)
    {
        printf("输出第%d个学生的信息：\n", (j+1));
        
        printf("name = ");
        printf("%s\n", pst[j].name);
        
        printf("age = ");
        printf("%d\n",pst[j].age);
        
        printf("score = ");
        printf("%f\n", pst[j].score);
    }
    return 0;
}
