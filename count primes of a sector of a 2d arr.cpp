//*12_homework_8_answer.cpp
#include<iostream>
using namespace std;

int main() {
	bool is_prime[100][100] = { 0 };
	int n, m, val;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> val;

			// let's compute is prime once NOT with every query. Also no need for main array
			if (val <= 1)
				continue;
			/*
			it's just a case of true or false not a case of saving the values of the primes (we just see (and at the specific position) the gotten value
			 if it's prime then we set 1 to that position to indicate this fact (we'll use this 1 later on)
			else it's not prime so put zero
			*/
			//----------this block checks----
			is_prime[i][j] = 1;
			for (int k = 2; k < val; ++k)
			{
				if (val % k == 0)
				{
					is_prime[i][j] = 0;
					break;
				}
			}
			//-------------------------------
		}

	int  rs, cls, q ;///(rs is row size & cls is col size)
	cin >> q;
	//----------- I changed it
	int  TLx, TLy;
	

	while (q--) {
		cin >> TLx >> TLy >> rs >> cls;
		int cnt = 0;

		for (int i = TLx; i <= TLx + rs - 1; ++i)
			for (int j = TLy; j <= TLy + cls - 1; ++j)
				cnt += is_prime[i][j];

		cout << cnt << "\n";
	}
	//----------- I changed it
	return 0;
}
/**

 3 4
8 2 9 5
3 2 27 6
7 8 29 22
 2
 1 0 2 2
3
0 1 2 3
3

 int  si, sj;


	while (q--) {
		cin >> si >> sj >> rs >> cls;
		int cnt = 0;

		for (int i = si; i <= si + rs - 1; ++i)
			for (int j = sj; j <= sj + cls - 1; ++j)
				cnt += is_prime[i][j];

		cout << cnt << "\n";
	}

 */
