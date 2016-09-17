/*
Author: Leonardo Mazuran
Course: cs2700 OOS
this assignment is to write a basic local binary pattern machine that input a basic bmp file and writes it into a text file in binary code.
<include CImage library
*/
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//calling Cimage library
#include "../lib/CImg.h"

using namespace cimg_library;

int main() {
	string local;
	//system color green
	system("color 2");
	//get image file location
	string pathway;
	// pathway file choose a bmp from the sample image
	//all of them are going to be 60X74 if you choose a bigger file, change Larry[][] at line 38
	pathway = "../sampleIMages/53.bmp";
	const char *pathwayChars = pathway.c_str();
	CImg<unsigned char> image(pathwayChars);
	ofstream test;
	test.open("..\\results\\facegallery.txt", ofstream::out | ofstream::app);
     test << endl << "This binary below came from " << pathway;
	test.close();
	//get image width and height 
	
   int wid = image.width();
	 int hei = image.height();
	
	//width and height in array
	
	string Larray[60][74];

	
	//for loop to every pixel set 3x3

	for (int b = 0; b < hei; b++) {


		for (int a = 0; a < wid; a++) {

			// center a,b get center number to calculate 3x3
			int number = image(a, b, 0, 0);

			//top left pixel
			if (number >= (int)image(a - 1, b - 1, 0, 0))
			{
				local.append("1");
			}
			
			{
				local.append("0");
			}
			//top center
			if (number >= (int)image(a, b - 1, 0, 0))
			{
				local.append("1");
			}
	
			{ 
				local.append("0"); 
			}
			//top right
			if (number >= (int)image(a + 1, b - 1, 0, 0))
			{
				local.append("1");
			}
			
			{ local.append("0"); }
			//center right
			if (number >= (int)image(a + 1, b, 0, 0))
			{
				local.append("1");
			}
			 { local.append("0"); }
			//bottom right 
			if (number >= (int)image(a + 1, b + 1, 0, 0))
			{
				local.append("1");
			}
			
			{ local.append("0"); }
			//bottom center
			if (number >= (int)image(a, b + 1, 0, 0))
			{
				local.append("1");
			}
			
			{ local.append("0"); }
			//bottom left
			if (number >= (int)image(a - 1, b + 1, 0, 0))
			{
				local.append("1");
			}
			
			{ local.append("0"); }
			//center left
			if (number >= (int)image(a - 1, b, 0, 0))
			{
				local.append("1");
			}
			
			{ local.append("0"); }
			Larray[a][b] = local;
			local = "";// 1 or 0 input

		}
	}
	//start file transfer
	ofstream ofs;
	//remove faceprobe if exist.
	remove("..\\results\\faceprobe.txt");
	//add starting line to face gallery
	ofs.open("..\\results\\facegallery.txt", ofstream::out | ofstream::app);
	ofs << endl << "Begin of new image" << endl;
	ofs.close();
	//loop lbp of until both hieght and width are done.
	int h = sizeof(Larray);
	int w = sizeof(Larray[0]);

	for (int j = 0; j < h; ++j)
	{
		for (int i = 0; i < w; ++i)
		{
			//display progress on terminal
			cout << Larray[j][i];
			ofstream ofs;
			// recreate file and insert results.
			
			ofs.open("..\\results\\faceprobe.txt", ofstream::out | ofstream::app);

			ofs << Larray[j][i];


			ofs.close();
			
			//input data to facegallery without over writing previous data
			ofs.open("..\\results\\facegallery.txt", ofstream::out | ofstream::app);

			ofs << Larray[j][i];


			ofs.close();






		}
		// add ending message to facegallery input.
		ofstream ofs;

		ofs.open("..\\results\\facegallery.txt", ofstream::out | ofstream::app);
		ofs << endl << "End of LBP image";
		ofs.close();

		system("pause");
		system("cls");
		system("color 21");
		string input;
		cout << endl << endl << endl << "\t" << "THE CONVERSION IS NOW COMPLETE!!!!" << endl;
		cout << "would you like to view your input files? "<<endl;
		cin >> input;
		if (input == "yes" || input == "y")
		{
			system("start ..\\results");

		}
		if (input == "no" || input == "n")
		{
			cout << endl << "                                                " << "Good Bye";
			cin.get();
		}
		
		break;
		system("pause");


	}

	return 0;
}