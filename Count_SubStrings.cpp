// CPP program to count number of substrings of s1 
// present in s2.
#include<iostream>
#include<string>
using namespace std;

int countSubstrs(string s1, string s2)
{
	int ans = 0;

	for (int i = 0; i < s1.length(); i++) {
		
		// s3 stores all substrings of s1
		string s3;
		for (int j = i; j < s1.length(); j++) {
			s3 += s1[j];

			// check the presence of s3 in s2
			if (s2.find(s3) != string::npos) 
				ans++;
		}
	}
	return ans;
}

// Driver code
int main()
{
	string s1 = "aab", s2 = "acacacab";
	cout << countSubstrs(s1, s2);
	return 0;
}
