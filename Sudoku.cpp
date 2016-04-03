#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	for(int i=0;i<sudokuSize;i++)
	{
		map[i]=0;
		pos[i]=0;
	}
	p=0;
}
void Sudoku::giveQuestion()
{
	map[1]=1; map[4]=7; map[7]=6; map[9]=9; map[11]=3; map[15]=8; map[17]=7; map[19]=8; map[21]=5; map[23]=4; map[25]=3; map[29]=9; map[30]=9; map[32]=2; map[33]=6; map[36]=4; map[44]=3; map[47]=1; map[48]=7; map[50]=6; map[51]=5; map[55]=3; map[57]=6; map[59]=8; map[61]=7; map[63]=7; map[65]=6; map[69]=2; map[71]=4; map[73]=2; map[76]=5; map[79]=1;
	for(int i=0;i<sudokuSize;i++)
	{
		if(((i+1)%9)==0)
			cout << map[i] << endl;
		else
			cout << map[i] << ' ';
	}
}
void Sudoku::readIn()
{
//	cout << "strat reading..." << endl;
	for(int i=0;i<sudokuSize;i++)
		cin >> map[i];
//	cout << "finish reading" << endl;
}
void Sudoku::solve()
{
	for(int i=0;i<sudokuSize;i++)
	{
		if(map[i]>0)
		{
			if(check(i)==1)
			{
				cout << "0" << endl;
				return;
			}
		}
	}

	int ansNum=0;
	int tmpAns[sudokuSize];
	for(int i=0;i<sudokuSize;i++)
		tmpAns[i]=map[i];
	int sp=getBlank(-1);
	do
	{
		map[sp]++;
		if(map[sp]>9)
		{
			map[sp]=0;
			sp=pop();
		}
		else if(check(sp)==0)
		{
			push(sp);
			sp=getBlank(sp);
			if(sp==sudokuSize)
			{
				for(int i=0;i<sudokuSize;i++)
					tmpAns[i]=map[i];
				ansNum++;
				if(ansNum==2)
				{
					cout << "2" << endl;
					return;
				}
				sp=pop();
			}
		}
	}while(sp>=0 && sp<sudokuSize );

	if(ansNum==0 && sp!=sudokuSize)
		cout << "0" << endl;
	else
	{
		cout << "1" << endl;
		for(int i=0;i<sudokuSize;i++)
		{
			if(((i+1)%9)==0)
				cout << tmpAns[i] << endl;
			else
				cout << tmpAns[i] << ' ';
		}
	}
}
int Sudoku::pop()
{
	if(p<=0)
		return -1;
	else
		return (pos[--p]);
}
void Sudoku::push(int sp)
{
	pos[p++]=sp;
	return;
}
int Sudoku::getBlank(int i)
{
	do
	{
		i++;
	}while(i<sudokuSize && map[i]>0);
	return i;
}
int Sudoku::check(int sp)
{
	if(checkRow(sp))
		return 1;
	if(checkCol(sp))
		return 1;
	if(checkCell(sp))
		return 1;
	return 0;
}
int Sudoku::checkRow(int sp)
{
	for(int r=0;r<9;r++)
	{
		if(map[(sp/9)*9+r]==map[sp] && ((sp/9)*9+r)!=sp)
			return 1;
	}
	return 0;
}
int Sudoku::checkCol(int sp)
{
	for(int c=0;c<9;c++)
	{
		if(map[(sp%9)+c*9]==map[sp] && ((sp%9)+c*9)!=sp)
			return 1;
	}
	return 0;
}
int Sudoku::checkCell(int sp)
{
	int num;
	for(int cRow=0;cRow<3;cRow++)
	{
		for(int cCol=0;cCol<3;cCol++)
		{
			num=((sp/9)/3)*27+cRow*9+((sp%9)/3)*3+cCol;
			if(map[num]==map[sp] && num!=sp)
				return 1;
		}
	}
	return 0;
}
void Sudoku::changeNum(int a,int b)
{
//	cout << "cNum " << a << " " << b << endl;
	int temp[sudokuSize];
	for(int i=0;i<sudokuSize;i++)
	{
		if(map[i]==a)
			temp[i]=b;
		else if(map[i]==b)
			temp[i]=a;
		else
			temp[i]=map[i];
	}
	for(int i=0;i<sudokuSize;i++)
		map[i]=temp[i];
}
void Sudoku::changeRow(int a,int b)
{
//	cout << "cRow " << a << " " << b << endl;
	int temp[sudokuSize];
	int n=27;
	for(int i=0;i<=54;i+=n)
	{
		if(i==(a*n))
		{
			for(int j=0;j<n;j++)
				temp[(b*n)+j]=map[i+j];
		}
		else if(i==(b*n))
		{
			for(int k=0;k<n;k++)
				temp[(a*n)+k]=map[i+k];
		}
		else
		{
			for(int r=0;r<n;r++)
				temp[i+r]=map[i+r];
		}
	}
	for(int i=0;i<sudokuSize;i++)
		map[i]=temp[i];
}
void Sudoku::changeCol(int a,int b)
{
//	cout << "cCol " << a << " " << b << endl;
	int temp[sudokuSize];
	int n=3;
	for(int i=0;i<=6;i+=n)
	{
		if(i==(a*n))
		{
			for(int c=0;c<3;c++)
			{
				for(int j=0;j<9;j++)
					temp[(b*n)+j*9+c]=map[i+j*9+c];
			}
		}
		else if(i==(b*n))
		{
			for(int l=0;l<3;l++)
			{
				for(int k=0;k<9;k++)
					temp[(a*n)+k*9+l]=map[i+k*9+l];
			}
		}
		else
		{
			for(int o=0;o<3;o++)
			{
				for(int r=0;r<9;r++)
					temp[i+r*9+o]=map[i+r*9+o];
			}
		}
	}
	for(int i=0;i<sudokuSize;i++)
		map[i]=temp[i];
}
void Sudoku::rotate(int n)
{
//	cout << "rotate " << n << endl;
	int temp[sudokuSize];
	if(n%4==1)
	{
		for(int r=0;r<9;r++)
		{
			for(int c=0;c<9;c++)
			{
				temp[(9*r)+(8-c)]=map[r+c*9];
			}
		}
	}
	else if(n%4==2)
	{
		for(int r=0;r<9;r++)
		{
			for(int c=0;c<9;c++)
			{
				temp[(80-r)-(c*9)]=map[r+c*9];
			}
		}
	}
	else if(n%4==3)
	{
		for(int r=0;r<9;r++)
		{
			for(int c=0;c<9;c++)
			{
				temp[72-(r*9)+c]=map[r+c*9];
			}
		}
	}
	else
	{
		for(int i=0;i<sudokuSize;i++)
			temp[i]=map[i];
	}
	for(int i=0;i<sudokuSize;i++)
		map[i]=temp[i];
}
void Sudoku::flip(int n)
{
//	cout << "flip " << n << endl;
	int temp[sudokuSize];
	if(n==0)
	{
		for(int i=0;i<9;i++)
		{
			for(int c=0;c<9;c++)
				temp[(8-i)+c*9]=map[i+c*9];
		}
	}
	else
	{
		for(int j=0;j<9;j++)
		{
			for(int r=0;r<9;r++)
				temp[(8-j)*9+r]=map[j*9+r];
		}
	}
	for(int i=0;i<sudokuSize;i++)
		map[i]=temp[i];
}
void Sudoku::transform()
{
	srand(time(NULL));
	changeNum((rand()%9)+1,(rand()%9)+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for(int i=0;i<sudokuSize;i++)
	{
		if(((i+1)%9)==0)
			cout << map[i] << endl;
		else
			cout << map[i] << ' ';
	}
}
