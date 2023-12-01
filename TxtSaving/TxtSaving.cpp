#include <iostream>
#include <fstream>

using namespace std;

string read(string filename)
{
	ifstream reader;
	string loadedFile;
	reader.open(filename, ios::in);

	if (reader)
	{
		while (!reader.eof())
		{
			string tmp;
			reader >> tmp;
			loadedFile += tmp + " ";
		}
		reader.close();
		return loadedFile;
	}
}

void write(string filename, string content)
{
	ofstream writer;
	writer.open(filename, ios::out);

	if (writer)
	{
		writer << content;
		writer.close();
	}
}

int main()
{
	string filename = "C:/Users/Tobias.Schaelte/Desktop/TxtTest.txt";
	string content = read(filename);
	if (content == "") content = "Hello World!";
	cout << content << endl;
	write(filename, content + " " + content);
}