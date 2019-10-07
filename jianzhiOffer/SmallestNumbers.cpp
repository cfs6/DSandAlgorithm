//Smallest numbers
//Using multiset
#include<set>
#include<vector>
std::vector<int> GetSmallestNumber(std::vector<int> data, int k) {
	std::multiset<int> resSet;
	std::vector<int> res;
	if (data.size() == 0 || k <= 0)
		return res;
	std::vector<int>::iterator data_it = data.begin();
	for (; data_it != data.end(); ++data_it) {
		if (resSet.size() < k) {
			resSet.insert(*data_it);
		}
		else {
			std::multiset<int>::iterator it_set = resSet.begin();
			if (*data_it < *it_set) {
				resSet.erase(*it_set);
				resSet.insert(*data_it);
			}
		}
	}
	std::multiset<int>::iterator tra_set = resSet.begin();
	for (; tra_set != resSet.end(); ++tra_set) {
		res.push_back(*tra_set);
	}
	return res;
}