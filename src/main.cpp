#include "make_data.h"
char to_lower(char c)
{
  if (c >= 'A' && c <= 'Z')
  {
    c = c + 32;
  }
  return c;
}

int main(int argc, char* argv[])
{
  if(argc <= 2)
  {
    cerr<<"======usage======\n"
          "./make-data 5 \"i0 sequence(1), i1 int, v varchar(11), dc decimal(7,2), db double, ts timestamp\" >> x.del \n";
    return 1;
  }
  srand(time(NULL));
  cout.fill('0');
  int row_num = atoi(argv[1]);
  char* p = argv[2];
  char delima = 15;
  transform(p, p+strlen(p), p, to_lower);
  vector<string> vs;
  str2vec(p, vs);
  for (int i = 0; i < row_num; i++)
  {
    parseVector(cout, vs, delima, i);
    cout<<"\n";
  }
  return 0;
}
