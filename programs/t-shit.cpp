#include <iostream>

int main()
{
	// your code goes here
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, a, b, count = 0, count1 = 0;
		std::cin >> n >> a >> b;
		std::string s;
		std::cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
				count++;
			else
				count1++;
		}

		int res = 0;
		res = (a * count) + (b * count1);
		std::cout << res << std::endl;
	}
	return 0;
}
