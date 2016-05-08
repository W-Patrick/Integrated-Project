#include <iostream> //required for a user interface
#include <fstream> //required for reading and writing files
#include <string> //required for strings
#include <cmath> //required to use trigonometry & powers

using namespace std;

bool proper_proportions(float, float, float); //initializing proper_proportions(float, float, float)
bool fits_in_container(float, float, float); //initializing fits_in_container(float, float, float)
int main()
{
	string filename; 
	float w, x, y, z; 
	cout<<"Please input the name of the file you would like to analyze: ";
	cin>>filename; //Takes in the name of the file the user wants to analyze

	ifstream infile; //file that the user wants to analyze is set as the variable infile
	ofstream outfile; //file that will be created is set as the variable outfile
	infile.open(filename.c_str()); //opening the file that the user wanted
	outfile.open("Data_For_Matlab.txt"); //opened the file that will be created and named it "Data_For_Matlab.txt"
	
	while(infile>>w>>x>>y>>z) //loops through every row of the input file
	{
		if (proper_proportions(x, y, z)  and fits_in_container(x, y, z)) //if the batch fits in the container and has the proper proportions
		{
		outfile<<w<<" "<<x<<" "<<y<<" "<<z<<endl; //then include it in the output file
	    }
	}
	infile.close(); //closes input file
	outfile.close(); //closes output file
	
	ifstream infile2;
	infile2.open("Data_For_Matlab.txt"); //reopens "Data_For_Matlab.txt" to make sure that the file was created successfully 
	if (!infile2) //if it does not open 
	{
		cout<<"There was an error in creating the file. Try again!"<<endl; //let the user know
		system("pause");
		exit(0); //quit the program
	}
	else
	{
		cout<<"File created successfully!"<<endl; //otherwise, let the user know that the file was successfully created
	}
	infile2.close(); //close the file after checking it 
	system("pause"); //pause the program 
	return 0; //end the program
}

bool proper_proportions(float a, float b, float c) 
{
	bool answer; //initialize answer as a boolean
	float total, min;
	total = a + b + c; //total amount of objects in the batch 
	min = total * 0.1; //assigns 10% of the total amount as the min
	if (a >= min and b >= min and c >= min) //if the amount of each item is greater than the min
		answer = true; //then set answer equal to true 
	else
		answer = false; //otherwise set answer equal to false	
	return answer;	//return answer 
}

bool fits_in_container(float a, float b, float c)
{
	bool answer; //initialize answer as a boolean
	float total_volume, cans_volume, blanket_volume, med_volume, total_space, can_space, blanket_space, med_space;
	total_volume = 10 * 11 * 16 * .9; //total volume in the container, accounting for the expected 10% of wiggle room
	cans_volume = pow(1.5, 2.0) * 3.14 * 4; //volume of one can of food
	blanket_volume = 1.75 * 1.75 * 3; //volume of one blanket box
	med_volume = 1 * 1 * 4; //volume of one med kit box
	
	can_space = a * cans_volume; //total volume taken up by the cans of food
	blanket_space = b * blanket_volume; //total volume taken up by the blanket boxes
	med_space = c * med_volume; //total volume taken up by the med kit boxes
	total_space = can_space + blanket_space + med_space; //total space taken up by the items
	
	if (total_space <= total_volume) //if the total space taken up by the items is less than or equal to the maximum volume allowed in the container 
		answer = true; //then set answer equal to true
	else 
		answer = false; //otherwise set answer equal to false
	return answer; //return answer
}


