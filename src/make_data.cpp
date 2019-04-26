#include "make_data.h"
void str2vec(char *str, vector<string> &v)
{
  const char *delim = " ,()";
  char *p = strtok(str, delim);
  //while (p != NULL)
  for (int flag = 0,i = 0; p; )
  {
    if (i & 1 || flag > 0)
    {
      string s(p);
      v.push_back(s);
      if (s == "char" || s == "varchar" || s == "sequence")
      {
        i = 1;
        flag = 1;
      }
      else if (s == "decimal")
      {
        i = 2;
        flag = 2;
      }
      else if (s == "int" || s == "double" || s == "timestamp")
      {
        i = 0;
      }
      else
      {
        //cout<<s<<endl;
        i--;
        flag--;
      }
    }
    else
    {
      i = 1;
    }
    p = strtok(NULL, delim);
  }
}

void parseVector(ostream &ost, vector<string> & vs, char delima, int row)
{
  int c = vs.size();
  for (int i = 0; i < c; i++)
  {
    if (i > 0) ost<<delima;
    if (vs[i] == "int")
    {
      ost<<rand();
    }
    else if (vs[i] == "sequence")
    {
      int l = atoi(vs[++i].c_str());
      ost<<l+row;
    }
    else if (vs[i] == "char" || vs[i] == "varchar")
    {
      int l = atoi(vs[++i].c_str());
      for (int j = 0; j < l; j++)
      {
        //ost<<rand()%26+'A';
        ost<<char('A'+rand()%26);
      }
    }
    else if (vs[i] == "decimal" || vs[i] == "double")
    {
      int p,s;
      if (vs[i] == "decimal")
      {
        p = atoi(vs[++i].c_str());
        s = atoi(vs[++i].c_str());
      }
      else
      {
        s = rand()%6+1;
        p = s+rand()%6+1;
      }
      for (int j = 0; j < p; j++)
      {
        ost<<rand()%10;
        if (j == p-s-1) ost<<".";
      }
    }
    else if (vs[i] == "timestamp" || vs[i] == "time" || vs[i] == "date")
    {
      if (vs[i] == "timestamp" || vs[i] == "date")
      {
        ost<<rand()%100+2000<<"-";
        ost.width(2);
        ost<<rand()%12+1<<"-";
        ost.width(2);
        ost<<rand()%28+1;

      }
      if (vs[i] == "timestamp")
      {
        ost<<" ";
      }
      if (vs[i] == "timestamp" || vs[i] == "time")
      {
        ost.width(2);
        ost<<rand()%24+1<<":";
        ost.width(2);
        ost<<rand()%60+1<<":";
        ost.width(2);
        ost<<rand()%60+1;
      }
    }
    else
    {
      ost<<"ERROR TYEP！\n";
      exit(1);
    }
  }
}
