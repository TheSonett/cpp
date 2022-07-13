#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
	std::priority_queue<std::pair<int, int>> pq{};
	std::vector<int> indexes{};
	std::vector<int> result{};

	for (int i = 0; i < nums.size(); i++) {
		pq.push({ nums[i], i });
	}

	while (k--) {
		indexes.push_back(pq.top().second);
		pq.pop();
	}

	std::sort(indexes.begin(), indexes.end());

	for (int i = 0; i < indexes.size(); i++) {
		result.push_back(nums[indexes[i]]);
	}
	return result;
}

int lastStoneWeight(std::vector<int>& stones) {

	if (stones.size() == 0) {
		return 0;
	}

	std::priority_queue<int> pq(stones.begin(), stones.end());
	while (pq.size() > 1) {
		int x = pq.top();
		pq.pop();

		int y = pq.top();
		pq.pop();

		if (x == y) {
			continue;
		}
		else if (x != y) {
			pq.push((x - y));
		}
	}

	if (pq.empty()) {
		return 0;
	}

	return pq.top();
}

int main()
{
	/*std::vector<int> nums{ 2, 1, 3, 3 };
	int k = 2;

	std::vector<int> result = maxSubsequence(nums, k);
	std::for_each(result.begin(), result.end(), [](int x) {
		std::cout << x << " ";
	});*/

	std::vector<int> stones{ 2,7,4,1,8,1 };
	std::cout << lastStoneWeight(stones);

	std::cin.get();
}