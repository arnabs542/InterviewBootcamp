/*
Comments :
*/

#include <iostream>
#include <stack>

using namespace std;

void printState(stack<int>& a, stack<int>& b, stack<int>& c, int disks)
{
  stack<int> tmp_a, tmp_b, tmp_c;

  while (!a.empty())
  {
    tmp_a.push(a.top()); a.pop();
  }
  while (!b.empty())
  {
    tmp_b.push(b.top()); b.pop();
  }
  while (!c.empty())
  {
    tmp_c.push(c.top()); c.pop();
  }

  cout << "printing state for disks: " << disks << endl;
  while(!tmp_a.empty() || !tmp_b.empty() || !tmp_c.empty())
  {
    if (!tmp_a.empty()) {
      cout << tmp_a.top() << " |" ;
      a.push(tmp_a.top()); tmp_a.pop();
    } else {
      cout << "  |";
    }

    if (!tmp_b.empty()) {
      cout << tmp_b.top() << " |";;
      b.push(tmp_b.top()); tmp_b.pop();
    } else {
      cout << "  |";
    }
    
    if (!tmp_c.empty()) {
      cout << tmp_c.top() << " |";;
      c.push(tmp_c.top()); tmp_c.pop();
    } else {
      cout << "  |";
    }
    cout << endl;
  }
}

void towerOfHanoiRec(stack<int>& from, stack<int>& tmp, stack<int>& to, int
                     disks)
{
  if (disks==0)
    return;

  towerOfHanoiRec(from, to, tmp, disks-1);
  //printState(from,tmp,to);
  to.push(from.top()); from.pop();
  printState(from,tmp,to, disks);
  towerOfHanoiRec(tmp, from, to, disks-1);
  //printState(from,tmp,to);
}

void towerOfHanoi(int diskCount)
{
  stack<int> a,b,c;

  for (auto i = 1; i <= diskCount; ++i)
    a.push(i);
  towerOfHanoiRec(a,b,c, diskCount);
}

int main(int argc, char** argv)
{
  cout << "Invoked with disk count: " << atoi(argv[1]) << endl;
  towerOfHanoi(atoi(argv[1]));
  return 0;
}

