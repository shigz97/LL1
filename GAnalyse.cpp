#include "GAnalyse.h"

void GAnalyse::file_open()
{
    /*string grammer=this->folderpath+"/grammer.txt";
    string first=this->folderpath+"/first.txt";
    string follow=this->folderpath+"/follow.txt";
    string select=this->folderpath+"/select.txt";
    string process=this->folderpath+"/process.txt";
    string intstring=this->folderpath+"/string.txt";*/

    //this->testi=first;

    //_grammer.open(grammer);
    //_input.open(intstring);
    //_firstset.open(first);
    //_follow.open(follow);
    //_select.open(select);
    //_procedure.open(process);

    QString npath=QString::fromStdString(this->folderpath);
    QString ngrammer=npath+"/grammer.txt";
    QString nfirst=npath+"/first.txt";
    QString nfollow=npath+"/follow.txt";
    QString nselect=npath+"/select.txt";
    QString nprocess=npath+"/process.txt";
    QString nstring=npath+"/string.txt";

    this->grammer.setFileName(ngrammer);
    this->first.setFileName(nfirst);
    this->follows.setFileName(nfollow);
    this->selects.setFileName(nselect);
    this->processs.setFileName(nprocess);
    this->strings.setFileName(nstring);
    //qDebug()<<ngrammer;
    //qDebug()<<nfirst;

}

void GAnalyse::file_close()
{
    //_grammer.close();
    //_firstset.close();
    //_follow.close();
    //_select.close();
    //_procedure.close();
    //_input.close();
}

void GAnalyse::getGrammer()
{
    grammer.open(QIODevice::ReadOnly);
    QTextStream _grammer(&grammer);
    _grammer>>number;
    _grammer.readLine();
    for(int i=1;i<=number;i++)
    {
        QString line=_grammer.readLine();
        string lines=line.toStdString();
        //qDebug()<<lines.length();
        G[i][0]=lines[0];
        for(int j=3;j<lines.length()-1;j++){
            G[i][j-2]=lines[j];
        }
        length[i]=lines.length()-3;
    }


}



//用"@"表示空字符
void GAnalyse::getFirst()
{
    for(int i=1;i<=number;i++)
        {
            int j=(int)(G[i][0]-'A');
            if(G[i][1]>='A'&&G[i][1]<='Z')
            {
                follow[j].push_back(G[i][1]);
            }
            else
            {
                firsts[j].push_back(G[i][1]);
            }
        }



        //设置递归
        for(int i=0;i<26;i++)
        {
            findfirst(i);
        }



        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(!follow[i].empty()&&(!follow[j].empty()))
                {
                    if(check(i,j))
                    {
                        firsts[i].insert(firsts[i].end(),firsts[j].begin(),firsts[j].end());
                        firsts[j].insert(firsts[j].end(),firsts[i].begin(),firsts[i].end());

                    }
                }
            }
        }

        for(int i=1;i<=number;i++)
        {
            int j=(int)(G[i][0]-'A');//非终结符
            int t=1;
            if(G[i][t]>='A'&&G[i][t]<='Z')
            {
                while(t<length[i])
                {
                    int k=(int)(G[i][t]-'A');
                    //cout<<k<<" "<<isEmpty(k)<<endl;
                    if(isEmpty(k))
                    {
                        //cout<<k<<endl;
                        t++;
                        firsts[j].insert(firsts[j].end(),firsts[k].begin(),firsts[k].end());
                    }
                    else{
                        t=length[i];
                        firsts[j].insert(firsts[j].end(),firsts[k].begin(),firsts[k].end());
                        handle[(int)(G[i][0]-'A')]=true;
                    }
                }
            }
        }



        //排序去重
        for(int i=0;i<26;i++)
        {
            if(!firsts[i].empty())
            {
                sort(firsts[i].begin(),firsts[i].end());
                vector<char>::iterator iter=unique(firsts[i].begin(),firsts[i].end());
                firsts[i].erase(iter,firsts[i].end());
            }
        }



        for(int i=0;i<26;i++)
        {
            if(handle[i]==1)
            {
                //cout<<i<<endl;
                //firsts[i].erase(firsts[i].begin());
                vector<char>::iterator iter=find(firsts[i].begin(),firsts[i].end(),'@');
                if(iter!=firsts[i].end())
                {
                    firsts[i].erase(iter);
                }
            }
        }
}

void GAnalyse::writeFirst()
{
    if(this->first.open(QIODevice::WriteOnly))
    {
        //qDebug()<<"a";


    QTextStream _firstset(&first);
    for(int i=0;i<26;i++)
        {

            if(!firsts[i].empty())
            {
                _firstset<<"first("<<char(i+65)<<")={";
                for(vector<char>::iterator it=firsts[i].begin();it!=firsts[i].end()-1;it++)
                {
                    //qDebug()<<*it;
                    _firstset<<*it<<",";
                }
                _firstset<<firsts[i].at(firsts[i].size()-1)<<"}"<<endl;
            }
        }
     }
}

void GAnalyse::getFollowSet()
{
    followset[(int)(G[1][0]-'A')].push_back('#');

        //cout<<endl<<endl<<endl;
        for(int i=1;i<=number;i++)
        {
            for(int j=1;j<length[i];j++)
            {
                if(G[i][j]>='A'&&G[i][j]<='Z')
                {
                    int k=(int)(G[i][j]-'A');
                    if(j==length[i]-1)
                    {
                        followunion[k].push_back(G[i][0]);
                    }
                    for(int p=1;p+j<length[i];p++)
                    {
                        if(G[i][j+p]>='A'&&G[i][j+p]<='Z')
                        {
                            int q=(int)(G[i][j+p]-'A');

                            //cout<<G[i][j]<<endl;
                            //cout<<G[i][j+p]<<" "<<isEmpty(q)<<endl;

                            if(isEmpty(q))
                            {
                                vector<char> temp(firsts[q]);
                                vector<char>::iterator iter=find(temp.begin(),temp.end(),'@');
                                if(iter!=temp.end())
                                {
                                    temp.erase(iter);
                                }

                                followset[k].insert(followset[k].end(),temp.begin(),temp.end());


                            }else{
                                followset[k].insert(followset[k].end(),firsts[q].begin(),firsts[q].end());
                                break;
                            }
                            if(p+j==length[i]-1)
                            {
                                //cout<<G[i][0]<<endl;
                                followunion[k].push_back(G[i][0]);
                            }
                        }
                        else{
                            followset[k].push_back(G[i][j+p]);
                            break;
                        }
                    }
                }
            }
        }



        for(int i=0;i<26;i++)
        {
            if(!followunion[i].empty())
            {
                vector<char>::iterator iter=find(followunion[i].begin(),followunion[i].end(),G[1][0]);
                if(iter!=followunion[i].end())
                {
                    followunion[i].erase(iter);
                    followset[i].insert(followset[i].end(),followset[(int)(G[1][0]-'A')].begin(),followset[(int)(G[1][0]-'A')].end());
                }
            }
        }

        for(int i=0;i<26;i++)
        {
            if(!followunion[i].empty())
            {
                findfollow(i);
            }
        }

        //去除重复
        for(int i=0;i<26;i++)
        {
            if(!followset[i].empty())
            {
                sort(followset[i].begin(),followset[i].end());
                vector<char>::iterator iter=unique(followset[i].begin(),followset[i].end());
                followset[i].erase(iter,followset[i].end());
            }
        }
}

void GAnalyse::writeFollowSet()
{

    this->follows.open(QIODevice::WriteOnly);
    QTextStream _follow(&follows);

    for(int i=0;i<26;i++)
        {
            if(!followset[i].empty())
            {
                _follow<<"follow("<<char(i+65)<<")={";
                /*for(int j=0;j<followset[i].size()-1;j++)
                {
                    _follow<<followset[i].at(j)<<",";
                }
                _follow<<followset[i].at(followset[i].size()-1)<<"}"<<endl;*/
                for(vector<char>::iterator it=followset[i].begin();it!=followset[i].end()-1;it++)
                {
                    _follow<<*it<<",";
                }
                _follow<<followset[i].at(followset[i].size()-1)<<"}"<<endl;
            }
    }
}

void GAnalyse::getSelectSet()
{
    bool flag[20]={0};//用于判断是否推出空字符
        for(int i=1;i<=number;i++)
        {
            for(int j=1;j<length[i];j++){
                //cout<<G[i][j]<<endl;
                if(G[i][j]>='A'&&G[i][j]<='Z')
                {
                    int t=(int)(G[i][j]-'A');
                    if(isEmpty(t))
                    {
                        if(j==length[i]-1)
                        {
                            flag[i]=true;
                        }
                    }
                    else{
                        break;
                    }
                }else {
                    if(G[i][j]=='@')
                    {
                        flag[i]=true;
                    }
                    break;
                }
            }
        }


        /*for(int i=1;i<=number;i++)
        {
            cout<<flag[i]<<endl;
        }*/

        for(int i=1;i<=number;i++)
        {
            if(flag[i]){
                int p=(int)(G[i][0]-'A');
                if(G[i][1]=='@')
                {
                    selectset[i].insert(selectset[i].end(),followset[p].begin(),followset[p].end());
                }
                else{
                    for(int j=1;j<length[i];j++)
                    {
                        int p=(int)(G[i][j]-'A');
                        //selectset[i].insert(selectset[i].end(),firsts[p].begin()+1,firsts[p].end());
                        vector<char> temp(firsts[p]);
                        vector<char>::iterator iter=find(temp.begin(),temp.end(),'@');
                        if(iter!=temp.end())
                        {
                            temp.erase(iter);
                        }
                        selectset[i].insert(selectset[i].end(),temp.begin()+1,temp.end());
                    }
                    selectset[i].insert(selectset[i].end(),followset[p].begin(),followset[p].end());
                }
            }
            else{
                for(int j=1;j<length[i];j++)
                {
                    if(G[i][j]>='A'&&G[i][j]<='Z')
                    {
                        int k=(int)(G[i][j]-'A');
                        if(isEmpty(k))
                        {
                            //selectset[i].insert(selectset[i].end(),firsts[k].begin()+1,firsts[k].end());
                            vector<char> temp(firsts[k]);
                            vector<char>::iterator iter=find(temp.begin(),temp.end(),'@');
                            if(iter!=temp.end())
                            {
                                temp.erase(iter);
                            }
                            selectset[i].insert(selectset[i].end(),temp.begin(),temp.end());
                        }else{
                            selectset[i].insert(selectset[i].end(),firsts[k].begin(),firsts[k].end());
                            break;
                        }
                    }else{
                        selectset[i].push_back(G[i][j]);
                        break;
                    }
                }
            }
        }

        for(int i=1;i<=number;i++)
        {
            sort(selectset[i].begin(),selectset[i].end());
            vector<char>::iterator iter=unique(selectset[i].begin(),selectset[i].end());
            followset[i].erase(iter,selectset[i].end());
        }
}

void GAnalyse::writeSelectSet()
{
    selects.open(QIODevice::WriteOnly);
    QTextStream _select(&selects);

    for(int i=1;i<=number;i++){
            _select<<"select("<<G[i][0]<<"->";
            for(int j=1;j<length[i];j++)
            {
                _select<<*(G[i]+j);
            }
            _select<<")={";
            for(vector<char>::iterator it=selectset[i].begin();it!=selectset[i].end()-1;it++)
            {
                _select<<*it<<" "<<",";
            }
            _select<<*(selectset[i].end()-1)<<"}";
            _select<<endl;
        }
}

int GAnalyse::getProcess()
{
    //1 成功 2不是LL1文法 3分析失败

    processs.open(QIODevice::WriteOnly);
    QTextStream _procedure(&processs);

    init();
    if(judge_LL1()){
        _procedure<<QString("分析表")<<qSetFieldWidth(15)<<QString("剩余串")<<qSetFieldWidth(15)<<QString("所用产生式")<<qSetFieldWidth(0)<<endl;
        int n=0; //用于判断循环
        while(istring[0]!='#'||vstring[vstring.length()-1]!='#')
        {

            char tep1=istring[0];
            char tep2=vstring[vstring.length()-1];
            _procedure<<QString::fromStdString(vstring);
            _procedure<<qSetFieldWidth(20)<<QString::fromStdString(istring);
            for(int i=1;i<=number;i++)
            {
                if(eq[i].first==tep2)
                {
                    if(isIn(tep1,i))
                    {
                        string tempp=eq[i].grm;
                        reverse(tempp.begin(),tempp.end());
                        vstring.erase(vstring.end()-1);
                        vstring=vstring+tempp;
                        _procedure<<qSetFieldWidth(20)<<tep2<<qSetFieldWidth(0)<<"->"<<QString::fromStdString(eq[i].grm)<<qSetFieldWidth(0)<<endl;
                        if(tep1==vstring[vstring.length()-1])
                        {
                            _procedure<<QString::fromStdString(vstring)<<qSetFieldWidth(20)<<QString::fromStdString(istring)<<qSetFieldWidth(20)<<tep1<<qSetFieldWidth(0)<<QString("匹配")<<qSetFieldWidth(0)<<endl;
                            istring=istring.substr(1,istring.length()-1);
                            vstring.erase(vstring.end()-1);
                        }
                        else if(vstring[vstring.length()-1]=='@'){
                            vstring.erase(vstring.end()-1);
                        }

                        int m=0;
                        while((!((vstring[vstring.length()-1]>='A')&&(vstring[vstring.length()-1]<='Z')))&&vstring[vstring.length()-1]!='#'){
                            m++;
                            if(m>10)
                            {
                            break;
                            }
                            char tempp=istring[0];
                            if(vstring[vstring.length()-1]==tempp)
                            {

                             _procedure<<QString::fromStdString(vstring)<<qSetFieldWidth(20)<<QString::fromStdString(istring)<<qSetFieldWidth(0)<<tempp<<QString("匹配")<<qSetFieldWidth(0)<<endl;
                             istring=istring.substr(1,istring.length()-1);
                             vstring.erase(vstring.end()-1);
                             }
                       }

                    }
                }
            }
            n++;
            if(n>1000){
                processs.close();
                //ofstream p("process.txt",ios::trunc);//清空
                //p.close();
                //return;
                return 3;
            }
        }
       //cout<<vstring<<setw(22)<<istring<<setw(22)<<"acc"<<endl;
       _procedure<<QString::fromStdString(vstring)<<qSetFieldWidth(20)<<QString::fromStdString(istring)<<qSetFieldWidth(20)<<"acc"<<endl;
        return 1;
    }
    else{
        //cout<<"not LL1"<<endl;
        return 2;  //不是LL文法
    }

}

bool GAnalyse::check(int i, int j)
{
    bool isIinJ=false;
        bool isJinI=false;
        for(vector<char>::iterator it=follow[i].begin();it!=follow[i].end();it++)
        {
            //cout<<*it<<" "<<char(i+65)<<endl;
            if(*it==char(j+65))
            {
                isJinI=true;
                break;
            }

        }
        for(vector<char>::iterator it=follow[j].begin();it!=follow[j].end();it++)
        {
            if(*it==char(i+65)){
                isIinJ=true;
                break;
            }
        }
        if(isIinJ&&isJinI)
        {
            return true;
        }
        else
        {
            return false;
        }
}

bool GAnalyse::checkfollow(int i, int j)
{
    bool isIinJ=false;
        bool isJinI=false;
        for(vector<char>::iterator it=followunion[i].begin();it!=followunion[i].end();it++)
        {
            if(*it==char(j+65))
            {
                isJinI=true;
                break;
            }

        }
        for(vector<char>::iterator it=followunion[j].begin();it!=followunion[j].end();it++)
        {
            if(*it==char(i+65)){
                isIinJ=true;
                break;
            }
        }
        if(isIinJ&&isJinI)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void GAnalyse::findfirst(int i)
{
    if(!(follow[i].empty()&&firsts[i].empty()))
       {
           if(!follow[i].empty())
           {
               for(vector<char>::iterator it=follow[i].begin();it!=follow[i].end();it++)
               {
                   int j=(int)(*it-'A');
                   if(!check(i,j))
                   {
                       findfirst(j);
                   }
                   firsts[i].insert(firsts[i].end(),firsts[j].begin(),firsts[j].end());
               }
           }
       }
    return;
}

bool GAnalyse::isEmpty(int i)
{
    vector<char>::iterator iter=find(firsts[i].begin(),firsts[i].end(),'@');
        if(iter==firsts[i].end())
        {
            return false;
        }
        else
        {
            return true;
        }
}

void GAnalyse::init()
{
    strings.open(QIODevice::ReadOnly);
    QTextStream _input(&strings);
    QString str1;
    _input>>str1;
    //qDebug()<<str1;
    istring=str1.toStdString();
    vstring='#';
    vstring=vstring+G[1][0];
    //ifstream _input;
    //string intstring=this->folderpath+"/string.txt";
    //_input.open(intstring);
    //_input>>istring;
    //istring=str1.toStdString();


    //初始化equation
    for(int i=1;i<=number;i++)
    {
        eq[i].num=i;
        eq[i].first=G[i][0];
        string str=G[i];
        eq[i].grm=str.substr(1,str.length()-1);
       //eq[i].grm=G[i];
    }
}

bool GAnalyse::judge_LL1()
{
    bool isLL1=true;
        for(int i=1;i<=number;i++)
        {
            for(int j=i+1;j<=number;j++)
            {
                if(G[i][0]==G[j][0])
                {
                    //cout<<i<<endl<<j<<endl;
                    //int k=(int)(G[i][0]-'A');
                    //int p=(int)(G[j][0]-'A');
                    for(vector<char>::iterator it=selectset[i].begin();it!=selectset[i].end();it++)
                    {
                        vector<char>::iterator iter=find(selectset[j].begin(),selectset[j].end(),*it);
                        if(iter!=selectset[j].end())
                        {
                            isLL1=false;
                        }
                    }
                }
            }
        }
        return isLL1;
}

bool GAnalyse::isIn(char temp, int i)
{
    bool isin=false;
        for(vector<char>::iterator it=selectset[i].begin();it!=selectset[i].end();it++)
        {
            char tepp=*it;
            if(tepp==temp)
            {
                isin=true;
            }
        }
        return isin;
}

void GAnalyse::findfollow(int i)
{
    if(!(followset[i].empty()&&followunion[i].empty()))
        {
            if(!followunion[i].empty())
            {
                for(vector<char>::iterator it=followunion[i].begin();it!=followunion[i].end();it++)
                {
                    int j=(int)(*it-'A');
                    if(!checkfollow(i,j))
                    {
                        findfollow(j);
                    }
                    followset[i].insert(followset[i].end(),followset[j].begin(),followset[j].end());
                }
            }
        }
}

GAnalyse::GAnalyse(string path)
{
    this->folderpath=path;

}

string GAnalyse::test()
{
    return this->testi;
}

int GAnalyse::executeGAna()
{
    file_open();
    int res=LL1();
    file_close();
    return res;
}

int GAnalyse::LL1()
{
    getGrammer();
    getFirst();
    writeFirst();
    getFollowSet();
    writeFollowSet();
    getSelectSet();
    writeSelectSet();

    return getProcess();
    //return 1;
}
