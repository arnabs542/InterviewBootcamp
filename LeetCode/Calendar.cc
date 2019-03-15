/*
Comments :
Implement a MyCalendar class to store your events. A new event can be added if
adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this
represents a booking on the half open interval [start, end), the range of real
numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie.,
there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be
added to the calendar successfully without causing a double booking. Otherwise,
return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar();
MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already
booked by another event.
The third event can be booked, as the first event takes every time less than 20,
but not including 20.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range
[0, 10^9].
Discuss


*/


#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class MyCalendar {
 public:
	MyCalendar() {

	}

  struct comp {
    bool operator() (const pair<int, int>& r1, const pair<int, int>& r2)
    {
      return r1.second < r2.first;
    }
  };

  bool book(int start, int end) {
    auto ev = make_pair(start, end);
    auto p = equal_range(eventsMap.begin(), eventsMap.end(), ev, comp{});

    bool done = false;
    for (auto it = p.first; !done; ++it)
    {
      if (it == p.second)
        done = true;
      if (it == eventsMap.end())
        break;

      if (!((start >= it->second) || (end <= it->first)))
        return false;
    }
    eventsMap.insert(ev);
    return true;
  }

	set<pair<int, int> > eventsMap;
};

int main(int argc, char** argv)
{
  MyCalendar c;

  vector<pair<int, int> > events =
      {{97,100},{33,51},{89,100},{83,100},{75,92},{76,95},{19,30},{53,63},{8,23},{18,37},{87,100},{83,100},{54,67},{35,48},{58,75},{70,89},{13,32},{44,63},{51,62},{2,15}};

  for (auto const&  e : events)
    cout << c.book(e.first, e.second);
  cout << endl;
  return 0;
}

