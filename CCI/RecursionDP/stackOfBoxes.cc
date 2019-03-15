#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

typedef tuple<int, int, int> Dimension;  //Width, Height, Depth
typedef vector<Dimension> Dimensions;

struct MySort
{
  bool operator()(const Dimension& d1, const Dimension& d2)
  {
    return get<0>(d1) < get<0>(d2);
  }
}increasing;

int width(const Dimension& d)
{
  return get<0>(d);
}

int height(const Dimension& d)
{
  return get<1>(d);
}

int depth(const Dimension& d)
{
  return get<2>(d);
}

void print(const Dimensions& d)
{
  for (int i=0; i < d.size(); ++i)
    cout << width(d[i]) << "," << height(d[i]) << "," << depth(d[i]) << endl;
}

int maxHeight(Dimensions& dimensions)
{
  sort(dimensions.begin(), dimensions.end(), increasing); // Sort by width nlog(n)

  vector<int> dp(dimensions.size() + 1, 0);

  dp[1] = height(dimensions[0]);


  for (int i=2; i <= dimensions.size(); ++i)
  {
    dp[i] = height(dimensions[i-1]);
    int maxHt = dp[i];
    
    for (int j=1; j < i; ++j)
    {
      if ((depth(dimensions[j-1]) < depth(dimensions[i-1])) && (height(dimensions[j-1]) < height(dimensions[i-1])))
        maxHt = max(maxHt, dp[i] + dp[j]);
    }
    dp[i] = maxHt;
  }

  return dp[dimensions.size()];

}

int main()
{
  Dimensions d = {{3,3,2}, {2,2,2,}, {1,1,3,}};

  cout << maxHeight(d) << endl;

  return 0;
}
