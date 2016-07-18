#include"test.h"


void test1()
{
	Solution s;
	int arr[3][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 } };

	vector<int> ve;
	vector<vector<int> > ve1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ve.push_back(arr[i][j]);
		}
		ve1.push_back(ve);
		ve.clear();
	}

	cout << s.Find(ve1, 12) << endl;
	cout << s.Find(ve1, 0) << endl;
	cout << s.Find(ve1, 1) << endl;
	cout << s.Find(ve1, 2) << endl;
	cout << s.Find(ve1, 3) << endl;
	cout << s.Find(ve1, 4) << endl;
	cout << s.Find(ve1, 5) << endl;
	cout << s.Find(ve1, 6) << endl;
	cout << s.Find(ve1, 7) << endl;
	cout << s.Find(ve1, 8) << endl;
	cout << s.Find(ve1, 9) << endl;
	cout << s.Find(ve1, 10) << endl;
	cout << s.Find(ve1, 11) << endl;
	cout << s.Find(ve1, 15) << endl;
}

int main()
{
	test1();
	getchar();
	return 0;
}