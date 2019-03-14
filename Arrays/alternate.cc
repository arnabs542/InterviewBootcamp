#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void alternate(vector<int>& array)
{
	for (int i =0; i < array.size(); ++i)
	{
		for (int j = 0; j + 2< array.size(); ++j )
		{
			vector<int> signs(3, 0);
			for (int k = 0; k <= 2; ++k)
			{
				signs[k] = array[j+k] >= 0 ? 0 : 1;
			}

			if (signs[0] == signs[1] && signs[1] != signs[2])
				swap(array[j+1], array[j+2]);
		}
	}

}

int main() {
	vector<int> array = {2,3,-4,-9,-1,-7,1,-5,-6};
	alternate(array);
	for (auto v : array)
		cout << v << " ";
	cout << endl;
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
