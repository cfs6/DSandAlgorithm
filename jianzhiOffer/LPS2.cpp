//LongestPalindromicString by dp
#include<vector>
#include<string>
#include<iostream>

std::string LPSdp(std::string s) {
	int sLength = s.length();
//	bool** isP = new bool[sLength][sLength]; //[i][j] : i: start  j: end
	std::vector<std::vector<bool>> isPS(sLength, std::vector<bool>(sLength));
//	bool isPS[sLength][sLength] = { false };
	if (sLength == 0)
		return "";
	if (sLength == 1)
		return s;
	std::string res;
	
	for (int i = 0; i < sLength-1; ++i) {
		isPS[i][i] = true;
		isPS[i][i + 1] = (s[i] == s[i + 1]);
	}
	
	for (int i = sLength-3; i >= 0; --i) {  //dp
		for (int j = i+2; j < sLength; ++j) {
			isPS[i][j] = (s[i]==s[j])&&(isPS[i + 1][j-1]);
		}
	}
	
	int max = 0;
	for (int i = 0; i < sLength; ++i) {
		for (int j = i; j < sLength; ++j) {
			if (isPS[i][j] == true) {
				if (max < j - i + 1) {
					max = j - i + 1;
					res.assign(s, i, j-i+1);
				}
			}
		}
	}
	return res;

}
/*
int main() {
//	std::string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	std::string s = "ccc";
	std::string resS;
	resS = LPSdp(s);
	std::cout << resS << std::endl;
	system("pause");
	return 0;
}
*/