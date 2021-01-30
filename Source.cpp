#include <iostream>
#include <fstream> 
#include <sstream>
#include <string> 

using namespace std;
//ofstream ofs("idealimage9.txt");        //used for storing ideal arrays

void printNormally(char** map, int rows, int columns) {
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++) // row = height. column = width
		{
			cout << map[x][y] << " ";
			//ofs << map[x][y] << " ";   //used for storing ideal arrays
		}
		cout << endl;
		//ofs << endl;					 //used for storing ideal arrays
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
			to[x][y] = from[x][y];
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

char** getCleared(char** map, int& width, int& height)
{
	char** transponated = getTransponated(map, width, height);
	map = transponated;

	int newWidth = height;
	int newHeight = width;

	while (true)
	{
		bool isRowEmpty = true;
		bool isColumnEmpty = true;

		for (int x = 0; x < newWidth; x++)
		{
			if (map[x][0] != '0')
			{
				isColumnEmpty = false;
				break;
			}
		}

		for (int y = 0; y < newHeight; y++)
		{
			if (map[0][y] != '0')
			{
				isRowEmpty = false;
				break;
			}
		}

		if (isRowEmpty)
		{
			char** newMap = decreaseRows(--newWidth, newHeight);
			fillArrForDecreasedRow(map, newMap, newWidth, newHeight);
			map = newMap;
		}
		else if (isColumnEmpty)
		{
			char** newMap = decreaseColumns(newWidth, --newHeight);
			fillArrForDecreasedColumn(map, newMap, newWidth, newHeight);
			map = newMap;
		}

		if (!isRowEmpty && !isColumnEmpty)
			break;
	}

	while (true)
	{
		bool isRowEmpty = true;
		bool isColumnEmpty = true;

		for (int x = 0; x < newWidth; x++)
		{
			if (map[x][newHeight - 1] != '0')
			{
				isColumnEmpty = false;
				break;
			}
		}

		for (int y = 0; y < newHeight; y++)
		{
			if (map[newWidth - 1][y] != '0')
			{
				isRowEmpty = false;
				break;
			}
		}

		if (isRowEmpty)
		{
			char** newMap = decreaseRows(--newWidth, newHeight);
			fillArrForDecreasedRowInverted(map, newMap, newWidth, newHeight);
			map = newMap;
		}
		else if (isColumnEmpty)
		{
			char** newMap = decreaseColumns(newWidth, --newHeight);
			fillArrForDecreasedColumnInverted(map, newMap, newWidth, newHeight);
			map = newMap;
		}

		if (!isRowEmpty && !isColumnEmpty)
			break;
	}


	width = newWidth;
	height = newHeight;
	return map;
}

void getIdealDimensions(string pictureSrc, int& rows, int& columns)
{
	ifstream stream(pictureSrc);
	string line;


	while (getline(stream, line))
	{
		columns = line.size() / 2;
		rows++;
	}

	stream.close();
}

char** populateIdealArray(char** idArr, string pictureSrc)
{
	int rows = 0, columns = 0;
	getIdealDimensions(pictureSrc, rows, columns);

	idArr = new char* [rows];
	for (int i = 0; i < rows; i++)
		idArr[i] = new char[columns];

	ifstream stream(pictureSrc);

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			stream >> idArr[x][y];
		}
	}



	stream.close();

	return idArr;
}




int main(int argc, char* argv[])
{
	int size = 0, pixels_adress = 0, width = 0, height = 0;
	//char i1[60][50], i3[60][50], i4[60][50], i5[60][50], i6[60][50], i7[60][50], i8[60][50], i9[60][50];
	char** i1 = new char* [1], ** i2 = new char* [1], ** i3 = new char* [1], ** i4 = new char* [1], ** i5 = new char* [1], ** i6 = new char* [1],
		** i7 = new char* [1], ** i8 = new char* [1], ** i9 = new char* [1];

	i1 = populateIdealArray(i1, "idealimage1.txt");
	i2 = populateIdealArray(i2, "idealimage2.txt");
	i3 = populateIdealArray(i3, "idealimage3.txt");
	i4 = populateIdealArray(i4, "idealimage4.txt");
	i5 = populateIdealArray(i5, "idealimage5.txt");
	i6 = populateIdealArray(i6, "idealimage6.txt");
	i7 = populateIdealArray(i7, "idealimage7.txt");
	i8 = populateIdealArray(i8, "idealimage8.txt");
	i9 = populateIdealArray(i9, "idealimage9.txt");

	/*int rows = 0, columns = 0;
	getIdealDimensions("idealimage1.txt", rows, columns);
	printNormally(i1, rows, columns);*/ // INPUT ORIGINAL


	/////////////
	short int bits_per_pixel = 0;
	if (argc >= 2)
		cout << "Your file is: " << argv[1] << endl;
	else
	{
		cout << "Please drag and drop .bmp file on the .exe" << endl;
		system("PAUSE");
		return 0;
	}
	ifstream file(argv[1], ios::in | ios::binary);

	file.seekg(2, ios::beg);

	file.read((char*)& size, sizeof(int));
	////////////////////////////////////////////////////
	file.seekg(10, ios::beg);

	file.read((char*)& pixels_adress, sizeof(int));
	//////////////////////////////////////////////////////
	file.seekg(18, ios::beg);

	file.read((char*)& width, sizeof(int));

	file.read((char*)& height, sizeof(int));
	///////////////////////////////////////////////////

	///////////////////////////////////////////////ideal arrays created and file streams closed
	if (width != 60 && height != 50)
	{
		cout << "Sorry, but your image needs to be 60x50 pixels" << endl;
		system("PAUSE");
		return 0;
	}

	file.seekg(28, ios::beg);

	file.read((char*)& bits_per_pixel, sizeof(short int));
	///////////////////////////////////////////////////////////
	file.seekg(pixels_adress, ios::beg);


	cout << "Size: " << size << endl;
	cout << "pixels_adress: " << pixels_adress << endl;
	cout << "bits per pixel: " << bits_per_pixel << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;


	char** map;

	map = new char* [width];
	for (int i = 0; i < width; i++)
		map[i] = new char[height];

	if (bits_per_pixel == 24)
	{
		unsigned int bgr = 0;

		for (int y = height - 1; y >= 0; y--)
		{
			for (int x = 0; x < width; x++)
			{
				file.read((char*)& bgr, 3);

				//cout << bgr << endl;

				if (bgr == 0xFFFFFF)
					map[x][y] = '0';
				else
					map[x][y] = '1';

				bgr = 0;
			}
		}
	}
	else
	{
		cout << "Sorry, but your image needs to have 24 bits per pixel" << endl;
		system("PAUSE");
		return 0;
	}


	map = getCleared(map, width, height);
	printNormally(map, width, height);
















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
