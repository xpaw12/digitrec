#include <iostream>
#include <fstream> 
#include <string> 

using namespace std;

void print(char** map, int width, int height) {
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
}

void printNormally(char** map, int width, int height) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			char r = map[x][y];
			if (r != '0')
			{
				int a = 5;
			}
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
}

char** decreaseRows(int newRowsCount, int columnsCount) {
	char** map;

	map = new char* [newRowsCount];
	for (int i = 0; i < newRowsCount; i++)
		map[i] = new char[columnsCount];

	return map;
}

char** decreaseColumns(int rowsCount, int newColumnsCount) {
	char** map;

	map = new char* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
		map[i] = new char[newColumnsCount];

	return map;
}

/*

1 0 1 0
1 1 1 1
0 0 0 0

X X X X
X X X X
// [0][0]

*/
void fillArrForDecreasedRow(char** from, char** to, int width, int height) { // [5][5] -> [4][5]

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			to[x][y] = from[x + 1][y];
		}
	}
}

// width 2 . height 4
void fillArrForDecreasedRowInverted(char** from, char** to, int width, int height) { // [3][4] -> [2][4]

	for (int x = width - 1; x >= 0; x--)
	{
		for (int y = 0; y < height; y++)
		{
			to[x][y] = from[x][y];
		}
	}
}

void fillArrForDecreasedColumn(char** from, char** to, int width, int height) { // [5][5] -> [4][5]

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			to[x][y] = from[x][y + 1];
		}
	}
}


void fillArrForDecreasedColumnInverted(char** from, char** to, int width, int height) { // [5][5] -> [4][5]

	for (int x = 0; x < width; x++)
	{
		for (int y = height - 1; y >= 0; y--)
		{
			to[x][y] = from[x][y - 1];
		}
	}
}

char** getTransponated(char** map, int width, int height) {
	char** newMap = new char* [height];
	for (int i = 0; i < height; i++)
		newMap[i] = new char[width];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			newMap[y][x] = map[x][y];
		}
	}

	return newMap;
}

int main(int argc, char* argv[])
{
	int size = 0, pixels_adress = 0, width = 0, height = 0;
	char i1[60][50], i3[60][50], i4[60][50], i5[60][50], i6[60][50], i7[60][50], i8[60][50], i9[60][50];
	char** i2;
	width = 60;
	height = 50;
	i2 = new char* [width];
	for (int i = 0; i < width; i++)
		i2[i] = new char[height];

	//arrays for ideal arrays
	ifstream id1("idealimage1.txt");
	ifstream id2("idealimage2.txt");
	ifstream id3("idealimage3.txt");
	ifstream id4("idealimage4.txt");
	ifstream id5("idealimage5.txt");
	ifstream id6("idealimage6.txt");
	ifstream id7("idealimage7.txt");
	ifstream id8("idealimage8.txt");
	ifstream id9("idealimage9.txt");
	/////////////
	short int bits_per_pixel = 0;
	//ofstream ofs("idealimage9.txt");    //used for storing ideal arrays
	/*if (argc >= 2)
		cout << "Your file is: " << argv[1] << endl;
	else
	{
		cout << "Please drag and drop .bmp file on the .exe" << endl;
		system("PAUSE");
		return 0;
	}*/
	//ifstream file(argv[1], ios::in | ios::binary);

	//file.seekg(2, ios::beg);

	//file.read((char*)& size, sizeof(int));
	//////////////////////////////////////////////////////
	//file.seekg(10, ios::beg);

	//file.read((char*)& pixels_adress, sizeof(int));
	////////////////////////////////////////////////////////
	//file.seekg(18, ios::beg);

	//file.read((char*)& width, sizeof(int));

	//file.read((char*)& height, sizeof(int));
	/////////////////////////////////////////////////////
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id1 >> i1[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char a = (char)i2[x][y];
			id2 >> i2[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id3 >> i3[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id4 >> i4[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id5 >> i5[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id6 >> i6[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id7 >> i7[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id8 >> i8[x][y];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			id9 >> i9[x][y];
		}
	}
	id1.close();
	id2.close();
	id3.close();
	id4.close();
	id5.close();
	id6.close();
	id7.close();
	id8.close();
	id9.close();
	///////////////////////////////////////////////ideal arrays created and file streams closed
	/*if (width != 60 && height != 50)
	{
		cout << "Sorry, but your image needs to be 60x50 pixels" << endl;
		system("PAUSE");
		return 0;
	}*/

	//file.seekg(28, ios::beg);

	//file.read((char*)& bits_per_pixel, sizeof(short int));
	///////////////////////////////////////////////////////////
	//file.seekg(pixels_adress, ios::beg);


	cout << "Size: " << size << endl;
	cout << "pixels_adress: " << pixels_adress << endl;
	cout << "bits per pixel: " << bits_per_pixel << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;


	//char map[60][50];
	char** map;

	map = new char* [width];
	for (int i = 0; i < width; i++)
		map[i] = new char[height];

	map = i2;
	//if (bits_per_pixel == 24)
	//{
	//	unsigned int bgr = 0;

	//	for (int y = height - 1; y >= 0; y--)
	//	{
	//		for (int x = 0; x < width; x++)
	//		{
	//			file.read((char*)& bgr, 3);

	//			//cout << bgr << endl;

	//			if (bgr == 0xFFFFFF)
	//				map[x][y] = '0';
	//			else
	//				map[x][y] = '1';

	//			bgr = 0;
	//		}
	//	}
	//}
	//else
	//{
	//	cout << "Sorry, but your image needs to have 24 bits per pixel" << endl;
	//	system("PAUSE");
	//	return 0;
	//}
	////////////////////////////////// cutting down extra zeroes
	/*int zero = 0;
	for (int row = 0; row < width; row++)
	{
		for (int col = 0; col < height; col++)
		{
			if (map[row][col] != '0')
			{
				zero++;
			}

		}
		if (zero == 0)
		{
			delete[] map[row];
		}
		zero = 0;
	}*/
	//////////////////////////////////////////////
	//print(map, height, width);
	//cout << endl << endl << endl << endl;
	//printNormally(map, height, width);

	char** transponated = getTransponated(map, width, height);
	map = transponated;



	/*cout << endl << endl << endl << endl;
	printNormally(transponated, height, width);
	return 0;
	cout << endl << endl << endl;*/
	/*map = new char* [3];
	for (int i = 0; i < 3; i++)
		map[i] = new char[3];

	map[0][0] = '0';
	map[0][1] = '0';
	map[0][2] = '0';

	map[1][0] = '1';
	map[1][1] = '0';
	map[1][2] = '1';

	map[2][0] = '0';
	map[2][1] = '0';
	map[2][2] = '0';
*/

	int newWidth = height;
	int newHeight = width;

	/*for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			if (map[x][y] != '0')
			{
				int k = 10;
			}
		}
	}

	for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			char r = map[x][y];
			if (r != '0')
			{
				int a = 5;
			}
			cout << map[x][y] << " ";
		}
		cout << endl;
	}*/

	printNormally(map, newWidth, newHeight);
	while (true)
	{
		bool isRowEmpty = true;
		//bool isColumnEmpty = true;

		/*for (int x = 0; x < newHeight; x++)
		{
			for (int y = 0; y < newWidth; y++)
			{
				if (map[x][y] != '0')
				{
					isColumnEmpty = false;
					break;
				}
			}
		}*/

		cout << endl << endl;
		for (int x = 0; x < newWidth; x++)
		{
			for (int y = 0; y < newHeight; y++)
			{
				if (map[x][y] != '0')
				{
					isRowEmpty = false;
					break;
				}
			}

			break;
		}

		if (isRowEmpty)
		{
			char** newMap = decreaseRows(--newWidth, newHeight);
			fillArrForDecreasedRow(map, newMap, newWidth, newHeight);
			map = newMap;
		}
		/*else if (isColumnEmpty)
		{
			char** newMap = decreaseColumns(newWidth, --newHeight);
			fillArr(map, newMap, newWidth, newHeight);
			map = newMap;
		}*/

		/*if (!isRowEmpty && !isColumnEmpty)
			break;*/

		printNormally(map, newWidth, newHeight);
		cout << endl << endl;
		if (!isRowEmpty)
			break;
	}

	while (true)
	{
		bool isRowEmpty = true;
		//bool isColumnEmpty = true;

		/*for (int x = 0; x < newHeight; x++)
		{
			for (int y = 0; y < newWidth; y++)
			{
				if (map[x][y] != '0')
				{
					isColumnEmpty = false;
					break;
				}
			}
		}*/

		cout << endl << endl;
		for (int x = newWidth - 1; x >= 0; x--)
		{
			for (int y = 0; y < newHeight; y++)
			{
				if (map[x][y] != '0')
				{
					isRowEmpty = false;
					break;
				}
			}

			break;
		}

		if (isRowEmpty)
		{
			char** newMap = decreaseRows(--newWidth, newHeight);
			fillArrForDecreasedRowInverted(map, newMap, newWidth, newHeight);
			map = newMap;
		}
		/*else if (isColumnEmpty)
		{
			char** newMap = decreaseColumns(newWidth, --newHeight);
			fillArr(map, newMap, newWidth, newHeight);
			map = newMap;
		}*/

		/*if (!isRowEmpty && !isColumnEmpty)
			break;*/

		printNormally(map, newWidth, newHeight);
		cout << endl << endl;
		if (!isRowEmpty)
			break;
	}

	//print(map, newHeight, newWidth);

	//for (int y = 0; y < height; y++)         
	//{
	//	for (int x = 0; x < width; x++)
	//	{
	//		cout << i5[x][y] << " ";
	//		//ofs << map[x][y] << " ";
	//	}
	//	cout << endl;
	//}
	/*int i1sim = 0, i2sim = 0, i3sim = 0, i4sim = 0, i5sim = 0, i6sim = 0, i7sim = 0, i8sim = 0, i9sim = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i1[x][y] && map[x][y] != '0')
			{
				i1sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i2[x][y] && map[x][y] != '0')
			{
				i2sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i3[x][y] && map[x][y] != '0')
			{
				i3sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i4[x][y] && map[x][y] != '0')
			{
				i4sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i5[x][y] && map[x][y] != '0')
			{
				i5sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i6[x][y] && map[x][y] != '0')
			{
				i6sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i7[x][y] && map[x][y] != '0')
			{
				i7sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i8[x][y] && map[x][y] != '0')
			{
				i8sim++;
			}
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y] == i9[x][y] && map[x][y] != '0')
			{
				i9sim++;
			}
		}
	}*/
	/*cout << "similar to 1 : " << i1sim / 30 << "%" << endl;
	cout << "similar to 2 : " << i2sim / 30 << "%" << endl;
	cout << "similar to 3 : " << i3sim / 30 << "%" << endl;
	cout << "similar to 4 : " << i4sim / 30 << "%" << endl;
	cout << "similar to 5 : " << i5sim / 30 << "%" << endl;
	cout << "similar to 6 : " << i6sim / 30 << "%" << endl;
	cout << "similar to 7 : " << i7sim / 30 << "%" << endl;
	cout << "similar to 8 : " << i8sim / 30 << "%" << endl;
	cout << "similar to 9 : " << i9sim / 30 << "%" << endl;*/
	//total pixels in bmp is equal to 3000.by dividing by 30 we get percentage
	//file.close();
	system("pause");
}
