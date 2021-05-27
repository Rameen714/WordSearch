#include<cstdlib>
#include<time.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//random genrator decides pattern from these 8  

int WordLength(string& word)
{
	int size=0;
	for(int i=0;word[i]!='\0';i++)
	{
		if(word[i]==32 && word[i+1]=='\0')
		{
			word[i]='\0';
			break;
		}
		if(word[i]==32 )
		{
			word[i]=word[i+1];
			word[i+1]=32;
		}

		size++;
	}
	return size;
}

int LargestOfWords(ifstream& IN)
{
	IN.open("Input.txt");
	int size=0;
	int temp=0;
	while(!IN.eof())
	{
		string a;
		getline(IN,a);
		temp=WordLength(a);
		if(temp>size)
			size=temp;
	}
	IN.close();
	return size;
}

void pattern_1(char** Grid,int size,int row_size,int size2,string Word,int& pattern)
{

		//left to right
		//to generate pattern within the grid
		cout<<"\nleft to right\n";
		int startIndex=rand() % size2 ;
		int endIndex=startIndex+size2;
		//the loop below checks if size by random generator might execed the grid size
		if(endIndex>size)
		{	
			int temp=endIndex-size; 
			startIndex=startIndex-temp;
			endIndex=size2+startIndex;
		}
		int row=rand() % row_size ; 
		int c=0,counter=0;
		//code below checks for the space
		while(c!=2 && counter<21)
		{

			for(int j=startIndex,k=0;j<endIndex;j++,k++)
			{
				if(Grid[row][j]!='*' && Grid[row][j]!=Word[k] && Grid[row][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;						
				}
			}
			//if not found another row is tried
			if(c==1)
				row=rand() % row_size ;
			else if (c==0)
				c=2;
			counter++;
		}
		//other patterns are tried 
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			cout<<"\nI am pattern now: "<<pattern<<endl<<endl;
		}
		//if found space then stored through this
		else if(counter<21)
		{
			for(int j=startIndex,k=0;j<endIndex;j++,k++)
				Grid[row][j]=Word[k];
		}
			
}

void pattern_2(char** Grid,int size,int row_size,int size2,string Word,int& pattern)		
{
		//right to left
		int startIndex=rand() % size2;
		int endIndex=startIndex+size2;
		if(endIndex>size)
		{	
			int temp=endIndex-size;
			startIndex=startIndex-temp;
			endIndex=size2+startIndex;
		}
		int row=rand() % size2 ;
		int c=0,counter=0;
		while(c!=2 	&& counter<21)
		{
			for(int j=endIndex-1,k=0;j>=startIndex;j--,k++)
			{
				if(Grid[row][j]!='*' && Grid[row][j]!=Word[k] && Grid[row][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
				row=rand() % row_size ;
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,size,row_size,size2,Word,pattern);
		}
		else if(counter<21)
		{
			for(int j=endIndex-1,k=0;j>=startIndex;j--,k++)
				Grid[row][j]=Word[k];
		}
			
}

void pattern_3(char** Grid,int size,int col_size,int size2,string Word,int& pattern)
{
		//cout<<"\nup to down\n";
		int startIndex=rand() % size2 ;
		int endIndex=startIndex+size2;
		if(endIndex>size)
		{	
			int temp=endIndex-size;
			startIndex=startIndex-temp;
			endIndex=size2+startIndex;
		}
		int col=rand() % size2 ;
		int c=0,counter=0;
		while(c!=2 && counter<21)
		{	
			for(int i=startIndex,k=0;i<endIndex;i++,k++)
			{
				if(Grid[i][col]!='*'&& Grid[i][col]!=Word[k] && Grid[i][col]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
				col=rand() % col_size ;
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,size,col_size,size2,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,size,col_size,size2,Word,pattern);
		}
		else if(counter<21)
		{
			for(int i=startIndex,k=0;i<endIndex;i++,k++)
				Grid[i][col]=Word[k];
		}
			
}

void pattern_4(char** Grid,int size,int col_size,int size2,string Word,int& pattern)
{
		// down to up
		int startIndex=rand() % size2 ;
		int endIndex=startIndex+size2;
		if(endIndex>size)
		{	
			int temp=endIndex-size;
			startIndex=startIndex-temp;
			endIndex=size2+startIndex;
		}
		int col=rand() % size2 ;
		int c=0,counter=0;
		while(c!=2 && counter<21)
		{	
			for(int i=endIndex-1,k=0;i>=startIndex;i--,k++)
			{
				if(Grid[i][col]!='*'&& Grid[i][col]!=Word[k] && Grid[i][col]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
				col=rand() % col_size ;
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,size,col_size,size2,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,size,col_size,size2,Word,pattern);
			else if(pattern==3)
				pattern_3(Grid,size,col_size,size2,Word,pattern);
		}
		else if(counter<21)
		{
			for(int i=endIndex-1,k=0;i>=startIndex;i--,k++)
				Grid[i][col]=Word[k];
		}
			
}

void pattern_5(char** Grid,int row_size,int col_size,int word_size,string Word,int& pattern)
{

		//diagonal top left to bottom right
		int startIndex=rand() % word_size ;
		int endIndex=startIndex+word_size;
		if(endIndex>col_size )
		{	
			int temp=endIndex-col_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		if(endIndex> row_size)
		{	
			int temp=endIndex-row_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		int col=rand() % word_size ;
		int c=0,counter=0;
		while(c!=2 && counter<21)
		{	
			for(int i=startIndex,j=startIndex,k=0;j<endIndex,i<endIndex;i++,j++,k++)
			{
				if(Grid[i][j]!='*'&& Grid[i][j]!=Word[k] && Grid[i][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
			{	
				startIndex=rand() % word_size ;
				endIndex=startIndex+word_size;
				if(endIndex>row_size)
				{	
					int temp=endIndex-row_size;
					startIndex=startIndex-temp;
					endIndex=row_size+startIndex;
				}
				if(endIndex>col_size)
				{	
					int temp=endIndex-col_size;
					startIndex=startIndex-temp;
					endIndex=col_size+startIndex;
				}	
			}
			if(c==1)
				col=rand() % row_size ;
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,row_size,col_size,word_size,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==3)
				pattern_3(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==4)
				pattern_4(Grid,col_size,row_size,word_size,Word,pattern);
		}
		else if(counter<21)
		{
			for(int i=startIndex,j=startIndex,k=0;j<endIndex,i<endIndex;i++,j++,k++)
				Grid[i][j]=Word[k];
		}

}

void pattern_6(char** Grid,int row_size,int col_size,int word_size,string Word,int& pattern)
{
		//diagonal bottom right to top left
			
		int startIndex=rand() % row_size + 1;
		int endIndex=startIndex+word_size;
		if(endIndex>row_size)
		{	
			int temp=endIndex-row_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		if(endIndex>col_size)
		{	
			int temp=endIndex-col_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		int c=0,counter=0;
		while(c!=2)
		{	
			for(int i=endIndex-1,j=endIndex-1,k=0;j>=startIndex,i>=startIndex;i--,j--,k++)
			{
				if(Grid[i][j]!='*'&& Grid[i][j]!=Word[k] && Grid[i][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
			{	
				startIndex=rand() % row_size ;
				endIndex=startIndex+word_size;
				if(endIndex>row_size)
				{	
					int temp=endIndex-row_size;
					startIndex=startIndex-temp;
					endIndex=word_size+startIndex;
				}	
			}
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,row_size,col_size,word_size,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==3)
				pattern_3(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==4)
				pattern_4(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==5)
				pattern_5(Grid,row_size,col_size,word_size,Word,pattern);
		}
		else if(counter<21)
		{
			for(int i=endIndex-1,j=endIndex-1,k=0;j>=startIndex,i>=startIndex;i--,j--,k++)
				Grid[i][j]=Word[k];
		}			
}

void pattern_7(char** Grid,int row_size,int col_size,int word_size,string Word,int& pattern)
{
		//diagonal top right to bottom left	
			
		int startIndex=rand() % row_size + 1;
		int endIndex=startIndex+word_size;
		if(endIndex>row_size)
		{	
			int temp=endIndex-row_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		if(endIndex>col_size)
		{	
			int temp=endIndex-col_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		int c=0,counter=0;
		while(c!=2)
		{	
			for(int i=endIndex-1,j=startIndex,k=0;i>=endIndex,j<endIndex;i--,j++,k++)
			{
				if(Grid[i][j]!='*'&& Grid[i][j]!=Word[k] && Grid[i][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
			{	
				startIndex=rand() % row_size ;
				endIndex=startIndex+word_size;
				if(endIndex>row_size)
				{	
					int temp=endIndex-row_size;
					startIndex=startIndex-temp;
					endIndex=word_size+startIndex;
				}	
				if(endIndex>col_size)
				{	
					int temp=endIndex-col_size;
					startIndex=startIndex-temp;
					endIndex=word_size+startIndex;
				}	
			}
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,row_size,col_size,word_size,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==3)
				pattern_3(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==4)
				pattern_4(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==5)
				pattern_5(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==6)
				pattern_6(Grid,row_size,col_size,word_size,Word,pattern);
		}
		else if(counter<21)
		{
			for(int i=endIndex-1,j=startIndex,k=0;i>=endIndex,j<endIndex;i--,j++,k++)
				Grid[i][j]=Word[k];
		}	

}

void pattern_8(char** Grid,int row_size,int col_size,int word_size,string Word,int& pattern)
{
		//diagonal top left to bottom right	
			
		int startIndex=rand() % row_size + 1;
		int endIndex=startIndex+word_size;
		if(endIndex>row_size)
		{	
			int temp=endIndex-row_size;
			startIndex=startIndex-temp;
			endIndex=word_size+startIndex;
		}
		if(endIndex>col_size)
		{	
			int temp=endIndex-row_size;
			startIndex=startIndex-temp;
			endIndex=col_size+startIndex;
		}
		int c=0,counter=0;
		while(c!=2)
		{	
			for(int j=endIndex-1,i=startIndex,k=0;j>=endIndex,i<endIndex;j--,i++,k++)
			{

				if(Grid[i][j]!='*'&& Grid[i][j]!=Word[k] && Grid[i][j]>0)
				{
					c=1;
					break;
				}
				else
				{
					c=0;
					continue;		
				}
			}
			if(c==1)
			{	
				startIndex=rand() % row_size ;
				endIndex=startIndex+word_size;
				if(endIndex>row_size)
				{	
					int temp=endIndex-row_size;
					startIndex=startIndex-temp;
					endIndex=word_size+startIndex;
				}	
				if(endIndex>col_size)
				{	
					int temp=endIndex-col_size;
					startIndex=startIndex-temp;
					endIndex=word_size+startIndex;
				}	
			}
			else if (c==0)
				c=2;
			counter++;
		}
		if(counter>=21)
		{
			pattern=rand() % 4 + 1;
			if(pattern==1)
				pattern_1(Grid,row_size,col_size,word_size,Word,pattern);	
			else if(pattern==2)
				pattern_2(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==3)
				pattern_3(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==4)
				pattern_4(Grid,col_size,row_size,word_size,Word,pattern);
			else if(pattern==5)
				pattern_5(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==6)
				pattern_6(Grid,row_size,col_size,word_size,Word,pattern);
			else if(pattern==7)
				pattern_7(Grid,row_size,col_size,word_size,Word,pattern);
		}
		else if(counter<21)
		{
			for(int j=endIndex-1,i=startIndex,k=0;j>=endIndex,i<endIndex;j--,i++,k++)
				Grid[i][j]=Word[k];
		}	

}

bool pattern_1(char** Grid,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string Word)
{
	if(startIndex_j+size>=cols)
		return false;
	for(int j=startIndex_j,k=0;j<startIndex_j+size;j++,k++)
	{
		if(Grid[startIndex_i][j]!=Word[k])
		{
			return false;
		}
		else
		{
			endIndex_j++;
			continue;		
		}
				
	}
	return true;
}

bool pattern_2(char** Grid,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string Word)
{
	if(startIndex_j-size<0)
		return false;	
	for(int j=startIndex_j,k=0;j>startIndex_j-size;j--,k++)
	{
		if(Grid[startIndex_i][j]!=Word[k])
		{
			return false;
		}
		else
		{
			endIndex_j++;
			continue;		
		}
				
	}
	endIndex_j=startIndex_j-endIndex_j+2;
	return true;
}

bool pattern_3(char** Grid,int rows,int startIndex_i,int startIndex_j,int& endIndex_i,int endIndex_j,int size,string Word)
{
	if(startIndex_i+size>=rows)
		return false;
	for(int i=startIndex_i,k=0;i<startIndex_i+size;i++,k++)
	{
		if(Grid[i][startIndex_j]!=Word[k])
		{
			return false;
		}
		else
		{
			endIndex_i++;
			continue;		
		}
				
	}
	return true;
}

bool pattern_4(char** grid,int rows,int startIndex_i,int startIndex_j,int& endIndex_i,int endIndex_j,int size,string word)
{
	if(startIndex_i-size<0)
		return false;
	for(int i=startIndex_i,k=0;i>startIndex_i-size;i--,k++)
	{
		if(grid[i][startIndex_j]!=word[k])
		{
			return false;
		}
		else
		{
			endIndex_i--;
			continue;		
		}
				
	}
	return true;
}

bool pattern_5(char** Grid,int rows,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string Word)
{

	if( startIndex_i+size>rows || startIndex_j+size>cols )
		return false;
	for(int i=startIndex_i,j=startIndex_j,k=0;i<endIndex_i,j<endIndex_j;i++,j++,k++)
	{
		if(Grid[i][j]!=Word[k])
		{
			return false;
		}
		else
		{
			continue;		
		}
				
	}
	return true;
}

bool pattern_6(char** grid,int rows,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string word)
{

	if( startIndex_i-size<0 || startIndex_j-size<0 )
		return false;
	for(int i=startIndex_i,j=startIndex_j,k=0;i>endIndex_i,j>endIndex_j;i--,j--,k++)
	{
		if(grid[i][j]!=word[k])
		{
			return false;
		}
		else
		{
			continue;		
		}
				
	}

	return true;
}

bool pattern_7(char** Grid,int rows,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string Word)
{
	
	if( endIndex_i-size<0 || startIndex_j+size>cols )
		return false;
	for(int i=startIndex_i,j=startIndex_j,k=0;i>endIndex_i,j<endIndex_j;i--,j++,k++)
	{
		if(Grid[i][j]!=Word[k])
		{
			return false;
		}
		else
		{
			continue;		
		}
				
	}
	return true;
}

bool pattern_8(char** Grid,int rows,int cols,int startIndex_i,int startIndex_j,int endIndex_i,int& endIndex_j,int size,string Word)
{

	if( startIndex_i+size>rows || endIndex_j-size<0 )
		return false;
	for(int j=startIndex_j,i=startIndex_i,k=0;j>endIndex_j,i<endIndex_i;j--,i++,k++)
	{
		if(Grid[i][j]!=Word[k])
		{
			return false;
		}
		else
		{
			continue;		
		}
				
	}
	return true;
}

int main()
{
	system("color 05");
	cout<<endl<<"\t\t\tWELCOME!!!"
		<<endl<<"\tPLEASE ENTER YOUR CHOICE FROM MENU"
		<<endl;
	char choice1;
	int choice2=0;
	ifstream InFile;
	ofstream Output;
	//int i=0;
	do{
		do{
			cout<<"\n\n1)Create Grid(C)\n2)Search From Grid(S)\n3)Quit(Q)"<<endl;
			cin>>choice1;
		}
		while(choice1!='C' && choice1!='S' && choice1!='Q' && choice1!='1' && choice1!='2' && choice1!='3');
		
		if(choice1=='C' || choice1=='1')
			choice2=1;
		if(choice1=='S' || choice1=='2')
			choice2=2;
		if(choice1=='Q' || choice1=='3')
			choice2=3;
		switch(choice2)
		{
			case 1:
				if(choice1=='C' || choice2==1)
				{
					cout<<"\n1) Name of the input file where a list of words is available in the format (one word per line)";
					string FileName;
					int row_size=0,col_size=0,no_of_words=0;
					do
					{
						cout<<"Enter File Name";
						cin.clear();
						fflush(stdin);
						getline (cin, FileName);
					}while(FileName.length() == 0);
					cout<<"\n2) Number of words in the file: ";cin>>no_of_words;
					cout<<"\n3) Number of rows in the grid: ";cin>>row_size;
					cout<<"\n4) Number of columns in the grid: ";cin>>col_size;
					cout<<"\n5) Name of the output file where the grid needs to be placed: ";
					do
					{
						cin.clear();
						fflush(stdin);
						getline (cin, FileName);
					}while(FileName.length() == 0);

					srand (time(NULL));
	
					//2D array of character pointers

					char** Grid= new char*[row_size];
					for(int i=0;i<row_size;i++)
					{
						Grid[i]=new char[col_size];
					}

					//Grid is being initialized to " * "
					for(int i=0;i<row_size;i++){
						for(int j=0;j<col_size;j++)
							Grid[i][j]='*';
					}

					//Opening file and reading words
					InFile.open("Input.txt");
					cout<<"These are no of words: "<<no_of_words<<endl;
					int block=0;
					for(int i=0;i<no_of_words;i++)
					{		
						cout<<"\n--------------------------------------------------------------\n";
						//Random pattern generator from 1 to 8
						int pattern=rand() % 8 + 1;							
			
						string Word;
						getline(InFile,Word);
						
						int size2=WordLength(Word);

						if(block==1 && pattern > 4)
							pattern = rand() % 4 +1 ;
			
						if(pattern==1)						
							pattern_1(Grid,col_size,row_size,size2,Word,pattern);	
						
						if(pattern==2)						
							pattern_2(Grid,col_size,row_size,size2,Word,pattern);
						
						if(pattern==3)						
							pattern_3(Grid,row_size,col_size,size2,Word,pattern);		
						
						if(pattern==4)						
							pattern_4(Grid,row_size,col_size,size2,Word,pattern);
						
						if(pattern==5)
						{
							block=1;
							pattern_5(Grid,row_size,col_size,size2,Word,pattern);
						}
						if(pattern==6)
						{
							block=1;
							pattern_6(Grid,row_size,col_size,size2,Word,pattern);
						}
						if(pattern==7)
						{
							block=1;
							pattern_7(Grid,row_size,col_size,size2,Word,pattern);
						}
						if(pattern==8)
						{
							block=1;
							pattern_8(Grid,row_size,col_size,size2,Word,pattern);
						}
					
					}

					cout<<"\n--------------------------------------------------------------\n";
					//Input file is now closed
					InFile.close();

					//for display
					cout<<endl<<"Grid with required words:"<<endl;
					for(int i=0;i<row_size;i++)
					{	
						for(int j=0;j<col_size;j++)
							cout<<" "<<Grid[i][j];
						cout<<endl;
					}
					cout<<"\t\tGRID CREATED SUCCESSFULLY\t\t"<<endl;
					//random number genrator to fill remaining space
					for(int i=0;i<row_size;i++)
					{
						for(int j=0;j<col_size;j++)
						{	
							if(Grid[i][j]==' ' || Grid[i][j]=='*')
								Grid[i][j]=rand() % 25 +65;
						}
					}
					cout<<endl<<"Word Search containing required words"<<endl;
					//for display
					for(int i=0;i<row_size;i++)
					{	
						for(int j=0;j<col_size;j++)
							cout<<" "<<Grid[i][j];
						cout<<endl;
					}
					//stored in output file
					Output.open(FileName);
					for(int i=0;i<row_size;i++){
						for(int j=0;j<col_size;j++)
							Output<<" "<<Grid[i][j];
						Output<<endl;
					}
					Output.close();
				}
				cout<<"Press any key to return to home screen...";
				getchar();
				break;
				//////////////////
			case 2:
				if(choice1=='S')
				{
				string FileName1,FileName2,FileName3;
				cout<<"\n1) Name of the input file which has a grid in it: ";
				do
				{
					cin.clear();
					fflush(stdin);
					getline (cin, FileName1);
				}while(FileName1.length() == 0);
	
				cout<<"\n2) Name of the file with input to be searched: ";
				do
				{
					cin.clear();
					fflush(stdin);
					getline (cin, FileName2);
				}while(FileName2.length() == 0);

				cout<<"\n3) Name of the output file where the results needs to be placed:";
				do
				{
					cin.clear();
					fflush(stdin);
					getline (cin, FileName3);
				}while(FileName3.length() == 0);
				
				InFile.open(FileName2);
				int rows,cols,cases=0;
				InFile>>rows>>cols>>cases;
				InFile.close();
				InFile.open(FileName1);
				char** Grid = new char*[rows];
				for(int i=0;i<rows;i++)
				{
					Grid[i]=new char[cols];
				}
				for(int i=0;i<rows;i++)
					{
						for(int j=0;j<cols;j++)
						{
							InFile>>Grid[i][j];
						}
					}
				InFile.close();
				InFile.open(FileName2);
				InFile.ignore(7);
				Output.open(FileName3);
				cout<<endl<<"\t\t RESULTS ARE:\t\t"<<endl;
				for(int c=0;c<cases;c++)
					{
						string word;
						InFile>>word;

						int size=0;
						size=WordLength(word);

						int i,j,k,a=0,endIndex_i,endIndex_j;
						for(i=0,k=0; i<rows; i++)
						{
							for(j=0; j<cols; j++)
							{
								//starting word is checked in the whole grid and then looked for other letters of word by call of patterns 
								if(Grid[i][j]==word[k])
								{
									endIndex_i=i;
									endIndex_j=0;
									if( pattern_1(Grid,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i<<" , "<<endIndex_j-1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i<<" , "<<endIndex_j-1<<"}"<<endl;
										a=1;
									}
									endIndex_i=i;
									endIndex_j=0;
									if( pattern_2(Grid,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i<<" , "<<endIndex_j-1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i<<" , "<<endIndex_j-1<<"}"<<endl;

										a=1;
									}
									endIndex_j=j;
									endIndex_i=i;
									if( pattern_3(Grid,rows,i,j,endIndex_i,endIndex_j,size,word) == true )
									{	
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j<<"}"<<endl;
										a=1;
									}
									endIndex_j=j;
									endIndex_i=i;
									if( pattern_4(Grid,rows,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j<<"}"<<endl;
										a=1;
									}					
									endIndex_i=i+size;
									endIndex_j=j+size;
									if( pattern_5(Grid,rows,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j-1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j-1<<"}"<<endl;
										a=1;
									}										
									endIndex_j=j-size;
									endIndex_i=i-size;
									if( pattern_6(Grid,rows,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j+1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j+1<<"}"<<endl;

										a=1;
									}
									endIndex_j=j+size;
									endIndex_i=i-size;
									if( pattern_7(Grid,rows,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j-1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i+1<<" , "<<endIndex_j-1<<"}"<<endl;

										a=1;
									}					
									endIndex_j=j-size;
									endIndex_i=i+size;
									if( pattern_8(Grid,rows,cols,i,j,endIndex_i,endIndex_j,size,word) == true )
									{
										Output<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j+1<<"}"<<endl;
										cout<<"{"<<i<<" , "<<j<<"} "<<" {"<<endIndex_i-1<<" , "<<endIndex_j+1<<"}"<<endl;

										a=1;
									}
								}
							}
			
						}
						//if none of the patterns  finds the word in grid this right here ouputs not found
						if(a!=1){
							Output<<"NOT FOUND"<<endl;
							cout<<"NOT FOUND"<<endl;				
						}
				}
				}
				cout<<"Press any key to return to home screen...";
				getchar();
				break;
			case 3: 
				return 0;
			cout<<"Press any key to continue...";
			getchar();
		}

	}while(1);
}