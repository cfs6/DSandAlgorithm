//N Queen
#include<vector>
#include<iostream>;
using namespace std;
std::vector<int> NQueen(int n) {
	std::vector<int> pArray(n);
	for(int i = 0; i < n; ++i) {
		pArray.push_back(i);
	}
	std::vector<std::vector<int>> res;
	std::vector<std::vector<int>> resV;
	resV = permutation(0, pArray, res);

}

std::vector<std::vector<int>> permutation(int a, std::vector<int> pArray, std::vector<std::vector<int>> &res) {
	int aLength = pArray.size();
	bool isProper = true;
	if (a == aLength)
		return res;
	for (int i = a; i < aLength; ++i) {
		int temp = pArray[a];
		pArray[a] = pArray[i];
		pArray[i] = temp;
		for (int i = 0; i < aLength; ++i) {
			for (int j = 0; j < aLength; ++j) {
				if (pArray[i] - pArray[j] == (i - j))
					isProper = false;
			}
		}
		if (isProper)
			res.push_back(pArray);
		permutation(a + 1, pArray, res);

		temp = pArray[a];
		pArray[a] = pArray[i];
		pArray[i] = temp;
	}
	
}

