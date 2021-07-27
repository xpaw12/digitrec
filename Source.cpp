#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <sstream>
#include <string> 
#include <algorithm>
#include <conio.h>

using namespace std;

double getSimilarityRate(char** initial, char** secondary, int rows, int columns)
{
	double equalQuantity = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (initial[i][j] == secondary[i][j])
				equalQuantity++;
		}
	}

	return equalQuantity / ((double)rows * columns) * 100;
}

void HighestSimilarityPrint(double r1, double r2, double r3, double r4, double r5, double r6, double r7, double r8, double r9) 
{
	double arr[] = { r1,r2,r3,r4,r5,r6,r7,r8,r9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout <<"Number on the input picture is: "<< distance(arr, max_element(arr, arr + n))+1<<endl;
}

void printNormally(char** map, int rows, int columns)
{
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
	cout << endl;
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
		columns = (int)line.size() / 2;
		rows++;
	}

	stream.close();
}

char** populateIdealArray(char** idArr, string pictureSrc, int& resRows, int& resColumns)
{
	int rows = 0, columns = 0;
	getIdealDimensions(pictureSrc, rows, columns);
	resRows = rows;
	resColumns = columns;
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

char** getStrechedArr(char** map, int idealRowsN, int idealColumnsN, int inputRows, int inputColumns)
{

	char** stretchedArr = new char* [idealRowsN];
	for (int i = 0; i < idealRowsN; i++)
		stretchedArr[i] = new char[idealColumnsN];
	double rowFactor = idealColumnsN / (double)inputColumns;
	double columnFactor = idealRowsN / (double)inputRows;
	int lastRowIndex = 0;
	int lastColumnIndex = 0;

	//RowStretch *working*
	for (int p = 0; p < inputRows; p++)
	{
		for (int i = 0; i < inputColumns; i++)
		{
			int index0 = (int)(i * rowFactor); //where the next value is stored
			int index1 = (int)((i + 1) * rowFactor); //stretch the value up to here
			for (int j = index0; j < index1; j++)
			{
				stretchedArr[p][j] = map[p][i];
				lastRowIndex = j;
			}
		}
	}
	for (int i = 0; i < inputRows; i++)
	{
		for (++lastRowIndex; lastRowIndex < idealColumnsN; lastRowIndex++)
		{
			//fill last value gap
			stretchedArr[i][lastRowIndex] = map[i][inputColumns - 1];
		}
	}
	//end of RowStretch

	// columnStretch *working*
	for (int p = 0; p < inputColumns; p++)
	{
		for (int i = 0; i < inputRows; i++)
		{
			int index0 = (int)(i * columnFactor); //where the next value is stored
			int index1 = (int)((i + 1) * columnFactor); //stretch the value up to here
			for (int j = index0; j < index1; j++)
			{
				stretchedArr[j][p] = map[i][p];
				lastRowIndex = j;
			}
		}
	}
	for (int i = 0; i < inputColumns; i++)
	{
		for (++lastColumnIndex; lastColumnIndex < idealRowsN; lastColumnIndex++)
		{
			//fill last value gap
			stretchedArr[lastColumnIndex][i] = map[inputRows - 1][i];
		}
	}

	//checking for empty spaces
	for (int i = 0; i < idealRowsN; i++)
	{
		for (int j = 0; j < idealColumnsN; j++)
		{
			if (stretchedArr[i][j] != '0' && stretchedArr[i][j] != '1')
				stretchedArr[i][j] = '0';
		}
	}

	//end of columnStretch


	//stretched Array output
	for (int i = 0; i < idealRowsN; i++)
	{
		for (int j = 0; j < idealColumnsN; j++)
		{
			cout << stretchedArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return stretchedArr;
}

int main(int argc, char* argv[])
{
	int size = 0, pixels_adress = 0, width = 0, height = 0;
	char** i1 = new char* [1], ** i2 = new char* [1], ** i3 = new char* [1], ** i4 = new char* [1], ** i5 = new char* [1], ** i6 = new char* [1],
		** i7 = new char* [1], ** i8 = new char* [1], ** i9 = new char* [1];

	int rows1 = 35, columns1 = 17;
	int rows2 = 35, columns2 = 23;
	int rows3 = 40, columns3 = 23;
	int rows4 = 34, columns4 = 25;
	int rows5 = 34, columns5 = 23;
	int rows6 = 35, columns6 = 24;
	int rows7 = 33, columns7 = 23;
	int rows8 = 35, columns8 = 23;
	int rows9 = 35, columns9 = 23;

	i1 = populateIdealArray(i1, "idealimage1.txt", rows1, columns1);
	i2 = populateIdealArray(i2, "idealimage2.txt", rows2, columns2);
	i3 = populateIdealArray(i3, "idealimage3.txt", rows3, columns3);
	i4 = populateIdealArray(i4, "idealimage4.txt", rows4, columns4);
	i5 = populateIdealArray(i5, "idealimage5.txt", rows5, columns5);
	i6 = populateIdealArray(i6, "idealimage6.txt", rows6, columns6);
	i7 = populateIdealArray(i7, "idealimage7.txt", rows7, columns7);
	i8 = populateIdealArray(i8, "idealimage8.txt", rows8, columns8);
	i9 = populateIdealArray(i9, "idealimage9.txt", rows9, columns9);



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

	file.read((char*)&size, sizeof(int));
	////////////////////////////////////////////////////
	file.seekg(10, ios::beg);

	file.read((char*)&pixels_adress, sizeof(int));
	//////////////////////////////////////////////////////
	file.seekg(18, ios::beg);

	file.read((char*)&width, sizeof(int));

	file.read((char*)&height, sizeof(int));
	///////////////////////////////////////////////////

	///////////////////////////////////////////////ideal arrays created and file streams closed
	if (width != 60 && height != 50)
	{
		cout << "Sorry, but your image needs to be 60x50 pixels" << endl;
		system("PAUSE");
		return 0;
	}

	file.seekg(28, ios::beg);

	file.read((char*)&bits_per_pixel, sizeof(short int));
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
				file.read((char*)&bgr, 3);


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
	file.clear();
	file.close();
	map = getCleared(map, width, height);
	printNormally(map, width, height);

	//stretching

	int inputRows = width;
	int inputColumns = height;

	char** map1 = new char* [rows1];
	for (int i = 0; i < rows1; i++)
		map1[i] = new char[columns1];

	char** map2 = new char* [rows2];
	for (int i = 0; i < rows2; i++)
		map2[i] = new char[columns2];

	char** map3 = new char* [rows3];
	for (int i = 0; i < rows3; i++)
		map3[i] = new char[columns3];

	char** map4 = new char* [rows4];
	for (int i = 0; i < rows4; i++)
		map4[i] = new char[columns4];

	char** map5 = new char* [rows5];
	for (int i = 0; i < rows5; i++)
		map5[i] = new char[columns5];

	char** map6 = new char* [rows6];
	for (int i = 0; i < rows6; i++)
		map6[i] = new char[columns6];

	char** map7 = new char* [rows7];
	for (int i = 0; i < rows7; i++)
		map7[i] = new char[columns7];

	char** map8 = new char* [rows8];
	for (int i = 0; i < rows8; i++)
		map8[i] = new char[columns8];

	char** map9 = new char* [rows9];
	for (int i = 0; i < rows9; i++)
		map9[i] = new char[columns9];


	map1 = getStrechedArr(map, rows1, columns1, inputRows, inputColumns);
	map2 = getStrechedArr(map, rows2, columns2, inputRows, inputColumns);
	map3 = getStrechedArr(map, rows3, columns3, inputRows, inputColumns);
	map4 = getStrechedArr(map, rows4, columns4, inputRows, inputColumns);
	map5 = getStrechedArr(map, rows5, columns5, inputRows, inputColumns);
	map6 = getStrechedArr(map, rows6, columns6, inputRows, inputColumns);
	map7 = getStrechedArr(map, rows7, columns7, inputRows, inputColumns);
	map8 = getStrechedArr(map, rows8, columns8, inputRows, inputColumns);
	map9 = getStrechedArr(map, rows9, columns9, inputRows, inputColumns);

	double rate1 = getSimilarityRate(i1, map1, rows1, columns1);
	double rate2 = getSimilarityRate(i2, map2, rows2, columns2);
	double rate3 = getSimilarityRate(i3, map3, rows3, columns3);
	double rate4 = getSimilarityRate(i4, map4, rows4, columns4);
	double rate5 = getSimilarityRate(i5, map5, rows5, columns5);
	double rate6 = getSimilarityRate(i6, map6, rows6, columns6);
	double rate7 = getSimilarityRate(i7, map7, rows7, columns7);
	double rate8 = getSimilarityRate(i8, map8, rows8, columns8);
	double rate9 = getSimilarityRate(i9, map9, rows9, columns9);

	cout << "Rate 1: " << rate1 << endl;
	cout << "Rate 2: " << rate2 << endl;
	cout << "Rate 3: " << rate3 << endl;
	cout << "Rate 4: " << rate4 << endl;
	cout << "Rate 5: " << rate5 << endl;
	cout << "Rate 6: " << rate6 << endl;
	cout << "Rate 7: " << rate7 << endl;
	cout << "Rate 8: " << rate8 << endl;
	cout << "Rate 9: " << rate9 << endl;

	HighestSimilarityPrint(rate1, rate2, rate3, rate4, rate5, rate6, rate7, rate8, rate9);

	_getch();
}
