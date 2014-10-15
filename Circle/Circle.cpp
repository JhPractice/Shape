#include <iostream>

const float pi = 3.141592;

int main()
{
	const int kRow = 14;
	const int kCullum = 25;

	char buffer[kRow][kCullum];
	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			buffer[i][j] = ' ';
		}
	}
	
	int row = 9, cullum = 5;
	int size = 5;

	for (int i = 0; i < 360; ++i)
	{
		int x = (int)(cos(i * pi / 180) * size + row);
		int y = (int)(sin(i * pi / 180) * size + cullum);

		if (!(x < 0 || y < 0 || x > kCullum || y > kRow))
			buffer[y][x] = '*';
	}

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			std::cout << buffer[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	system("PAUSE");
	return 0;
}