/**
* @ProgramName: Program-1
* @Author: Logan Wheeler
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 02 - 08 - 18
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/

struct rgb{
	int r;
	int g;
	int b;
	rgb(){
		r = 0;
		g = 0;
		b = 0;
	}
};

/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void grayScale(rgb** image, int width, int height){
	int r, g, b, gray;
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			r = image[i][j].r;
			g = image[i][j].g;
			b = image[i][j].b;

			gray = (r + g + b) / 3;

			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}

/**
* @FunctionName: removeRed
* @Description:
*     Loops through a 2D array and turns every R value to 0.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void removeRed(rgb** image, int width, int height){

	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			image[i][j].r = 0;
		}
	}
}

/**
* @FunctionName: flipHorizontal
* @Description:
*     Loops through a 2D array and flips rgb values till image is horizontally flipped.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorizontal(rgb** image, int width, int height){
	int x;
	rgb temp;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width / 2; j++){
			x = (width - 1) - j;
			temp = image[i][j];
			image[i][j] = image[i][x];
			image[i][x] = temp;

		}
	}

}

/**
* @FunctionName: flipVertical
* @Description:
*     Loops through a 2D array and flips rgb values till image is vertically flipped.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVertical(rgb** image, int width, int height){
	int x;
	rgb temp;
	for (int j = 0; j < width; j++){
		for (int i = 0; i < height / 2; i++){
			x = (height - 1) - i;
			temp = image[i][j];
			image[i][j] = image[x][j];
			image[x][j] = temp;
		}
	}

}


int main(){
	ifstream infile;          //Input / output files
	ofstream outfile;
	infile.open("bot.txt");
	outfile.open("bot2.txt");
	int r, g, b, gray;

	int width;               //width of image
	int height;              //height of image
	int choice;

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	infile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.

	imgArray = new rgb*[height];   //This array points to every row

	for (int i = 0; i<height; i++){
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

										//Read the color data in from our txt file
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			infile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	//We could make any changes we want to the color image here

	cout << "Enter the number with what action you'd like to perform" << endl
		<< "1. Gray Scale." << endl << "2. Red Removal." << endl << "3. Flip Horizontal" << endl
		<< "4. Flip Vertical" << endl;
		cin >> choice;

	// If else statements for the user to decide what they want to do with it

	if (choice == 1){
			cout << "Gray Scale done" << endl;
			grayScale(imgArray, width, height);
		}
	if (choice == 2){
			cout << "Red removed" << endl;
			removeRed(imgArray, width, height);
		}
	if (choice == 3){
			cout << "Flipped horizontally" << endl;
			flipHorizontal(imgArray, width, height);
		}
	if (choice == 4){
			cout << "Flipped vertically" << endl;
			flipVertical(imgArray, width, height);
		}

	//Write out our color data to a new file
	outfile << width << "  " << height << endl;
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			outfile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		outfile << endl;
	}


	return 0;
}

