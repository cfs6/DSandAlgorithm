//1003 Emergency
//Dijkstra
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<limits>
using namespace std;

#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
const int N = 502;
const int inf = numeric_limits<int>::max();
bool mark[N];
int citynum, roadnum;
int loc, dst;
vector<int> roadLength(N);                         //cost
vector<int> road(N);                               //way  最短路条数
//vector<int> road2;      

vector<int> teamnum(N);                            //b      在x处有多少人
vector<int> resTeamNum(N);                         //num    最终携带的人数

vector<vector<int>> city(N, vector<int>(N));       


void Dijkstra(int s) {
	for (int i = 0; i < citynum; ++i) {
		mark[i] = false;
		roadLength[i] = inf;
		resTeamNum[i] = road[i] = 0;
	}
	
	resTeamNum[s] = teamnum[s];
	road[s] = 1;
	roadLength[s] = 0;


	for (int i = 0; i < citynum; ++i) {

		int index = -1;
		for (int j = 0; j < citynum; ++j) {
			if ((mark[j] == false) && ((index<0)||(roadLength[j] < roadLength[index])))
				index = j;
		}
		mark[index] = true;
		for (int j = 0; j < citynum; ++j) {
			if ((!mark[j]) && (city[index][j] < inf)) {

				int temp = roadLength[index] + city[index][j];
				if (temp < roadLength[j]) {
					roadLength[j] = temp;
					resTeamNum[j] = resTeamNum[index] + teamnum[j];
					road[j] = road[index];
				}
				else if (temp == roadLength[j]) {
					resTeamNum[j] = MAX(resTeamNum[j], resTeamNum[index] + teamnum[j]);
					road[j] += road[index];
				}
			}
			
		}
	}

}


int main() {
	
	
	
	
	string s, s2;
	getline(cin, s);
	stringstream ss(s);
	ss >> citynum;
	ss >> roadnum;
	ss >> loc;
	ss >> dst;
	int num;
	for (int i = 0; i < citynum; ++i) {
		cin >> num;
		teamnum[i] = num;
	}

	for (int i = 0; i < citynum; ++i) {
		for (int j = 0; j < citynum; ++j) {
			city[i][j] = inf;
		}
	}
	int count = 0;
	
	while(count != roadnum) {
		int x, y, z;
		cin >> x >> y >> z;
		city[x][y] = city[y][x] = MIN(city[x][y], z);
		count++;
	}

	Dijkstra(loc);
	cout << road[dst] << " " << resTeamNum[dst];


	system("pause");
	return 0;
}