#ifndef GANALYSE_H
#define GANALYSE_H

#include <fstream>
#include <stack>
#include <iomanip>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>
using namespace std;



struct equation
{
    int num;
    char first;
    string grm;
};

class GAnalyse
{

private:
    string folderpath;
    //ifstream _grammer;
    //ifstream _input;
    //ofstream _firstset; //first集
    //ofstream _follow;   //follow集
    //ofstream _select;  //select集
    //ofstream _procedure;//分析过程

    QFile grammer;
    QFile first;
    QFile follows;
    QFile selects;
    QFile processs;
    QFile strings;


    char G[100][100]; //存文法
    int length[100];   //每行文法的长度
    int number=0;     //文法的行数

    bool handle[26]={0};
    int size=0;

    equation eq[20];

    vector<char> firsts[26]; //first 集
    vector<char> follow[26];
    vector<char> followset[26]; //follow集
    vector<char> followunion[26];
    vector<char> selectset[20]; //select集  从1开始
    map<char,equation> table; //左边非终结符，右边产生式子；
    string istring; //输入串
    string vstring;
    string testi;


public:

    GAnalyse(string path);
    string test();
    int executeGAna();
    int LL1();
    void file_open();
    void file_close();
    void getGrammer();
    void getFirst();
    void writeFirst();
    void getFollowSet();
    void writeFollowSet();
    void getSelectSet();
    void writeSelectSet();
    int getProcess();
    bool check(int i,int j);
    bool checkfollow(int i,int j);
    void findfirst(int i);
    bool isEmpty(int i);
    void init();
    bool judge_LL1();
    bool isIn(char temp,int i);
    void findfollow(int i);



};

#endif // GANALYSE_H
