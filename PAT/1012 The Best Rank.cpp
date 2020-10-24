//1012 The Best Rank
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int id, clanguage, math, english;
	int average;
	vector<vector<int>> score;
	for (int i = 0; i < n; ++i) {
		cin >> id >> clanguage >> math >> english;
		average = (clanguage + math + english) / 3.0;
		vector<int> idScore;
		idScore.push_back(id);
		idScore.push_back(average);
		idScore.push_back(clanguage);
		idScore.push_back(math);
		idScore.push_back(english);
		score.push_back(idScore);
	}
	
	vector<int> query;
	int q;
	for (int i = 0; i < m; i++) {
		cin >> q;
		query.push_back(q);
	}
	
	for (int i = 0; i < score.size(); ++i) {
		for (int j = 0; j < score[i].size(); ++j) {
			cout << score[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	

	//sort
	vector<int> rankRes;
	vector<vector<int>> res;
	for (int i = 0; i < score.size(); i++) {
		rankRes.clear();
		rankRes.push_back(score[i][0]);

		for (int k = 1; k < score[i].size(); ++k) {                       //5
			int rank = 1;
			for (int l = 0; l < score.size(); ++l) {
				if ((l != i)&&(score[i][k]<score[l][k])) {
					rank++;
				}
			}
			rankRes.push_back(rank);
		}
		res.push_back(rankRes);
	}


	for (int i = 0; i <res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;

	}



	for (int i = 0; i < query.size(); ++i) {
		bool match = false;
		for (int k = 0; k < res.size(); ++k) {
			int min = res.size(), index = 1;
			if (query[i] == res[k][0]) {
				match = true;
				for (int l = 1; l < res[k].size(); ++l) {
					if (min > res[k][l]) {
						min = res[k][l];
						index = l;
					}
				}
				switch (index) {
				case 1:
					cout << min << " " << "A" << endl;
					break;
				case 2:
					cout << min << " " << "C" << endl;
					break;
				case 3:
					cout << min << " " << "M" << endl;
					break;
				case 4:
					cout << min << " " << "E" << endl;
					break;
				default:
					break;
				}
			}


		}
		if (match == false) {
			cout << "N/A" << endl;
		}

	}
	/*
	bool lastmatch = false;
	for (int k = 0; k < res.size(); ++k) {
		int min = 1, index = 1;
		if (query[query.size()-1] == res[k][0]) {
			lastmatch = true;
			for (int l = 1; l < res[k].size(); ++l) {
				if (min < res[k][l]) {
					min = res[k][l];
					index = l;
				}
			}
			switch (index) {
			case 1:
				cout << min << " " << "A" << endl;
				break;
			case 2:
				cout << min << " " << "C" << endl;
				break;
			case 3:
				cout << min << " " << "M" << endl;
				break;
			case 4:
				cout << min << " " << "E" << endl;
				break;
			default:
				break;
			}
		}


	}
	if (!lastmatch)
		cout << "N/A";*/

	system("pause");

}