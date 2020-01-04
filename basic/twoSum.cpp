#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) 
		{
			vector<int> result;
			for (auto i = 0; i < nums.size(); ++i)
			{
				for (auto j = i + 1; j < nums.size(); ++j)
				{
					if (nums[i] + nums[j] == target)
					{
						result.push_back(i);
						result.push_back(j);
						return result;
					}
				}
			}
			return result;
		}
};

int main()
{
	vector<int> n = { 2, 3, 4, 5, 6 };
	int target = 5;
	vector<int> r = Solution().twoSum(n, target);

	for (auto i = 0; i < r.size(); ++i)
	{
		cout << r[i] << endl;
	}
	return 0;
}

