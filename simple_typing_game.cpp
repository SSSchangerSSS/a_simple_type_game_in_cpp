#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#define row 24 
#define column 80 

int typed = 0;
int level = 0;
using namespace std;


void menu();
void update_screen(char c[row][column]);
void update2_screen(char c[row][column], int p[row][5]);
void check_screen(char ch , char a[row][column]);

void init(char c[row][column]);
void set_values_for_row(int p[row][5] , char c[row][column], int selected_row);
void print_screen(char c[row][column]);
void swap22(char a[row][column],int row1,int row2);
void screen_go_to_next_line(char a[row][column]);
void swap11(int a[row][5],int row1,int row2);
void screen_go_to_next_line_pointers(int a[row][5]);









int main(){
	
int p [row][5];
char c [row][column];
int time;
int easy = 4;
int normal = 3;
int hard = 2;
bool easy_b = false;
bool normal_b = false;
bool hard_b = false;
char ch;
	
int choice;		
	
while(true){
	
	
	menu();
	cout<<time;
	cin>>choice;
	
	if(choice == 1){
easy_b = true;
normal_b = false;
hard_b = false;
}
else if(choice == 2){
easy_b = false;
normal_b = true;
hard_b = false;		
}
else if(choice == 3){
easy_b = false;
normal_b = false;
hard_b = true;		
}
else if(choice == 4){
break;
}
else{
cout<<"\nselected option does not exist!";	
continue;	
}

level = 0;
typed = 0;

init(c);
set_values_for_row(p,c,0);
print_screen(c);

clock_t shoro = clock();

if(easy_b)
time = easy;
else if(normal_b)
time = normal;
else if(hard_b)
time = hard;

while(level < 100){

if(((clock() - shoro)/CLOCKS_PER_SEC) >= time){
update2_screen(c,p);
shoro = clock();	
}
else{
	
if(kbhit()){
ch = getch();
check_screen(ch,c);
update_screen(c);
}
	
}
	
}


//set first row empty and print the screen again
for(int j =0;j<column;j++)
c[0][j] = ' ';
update_screen(c);
//cause one more level is assumed we should calculate time of last


cout<<"\nyou have typed : "<<typed<<" characters";
cout<<"\nyou have missed : "<<level*5 - typed<<"characters";
cout<<"\nyour score : "<<typed - (level*5 - typed);


}
	
return 0;	
	
}

















//functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void menu(){
cout<<"\n\n\n";
cout<<"###***TYPE_GAME***###";
cout<<"\n1.easy";
cout<<"\n2.normal";
cout<<"\n3.hard";
cout<<"\n4.exit";	
cout<<"\nplease select the option you prefer\n";
}




void init(char c[row][column]){
	
	for(int i = 0;i< row;i++)
	for(int j =0;j<column;j++)
	c[i][j] = ' ';
	
}

void set_values_for_row(int p[row][5] , char c[row][column], int selected_row){
	
int randoms[5] = {0};

// number of characters a line support = 80

randoms[0] = rand() % 80;//az 0 ta 79

randoms[1] = rand() % 80;
while(randoms[1] == randoms[0])
randoms[1] = rand() % 80;

randoms[2] = rand() % 80;
while(randoms[2] == randoms[1] or randoms[2] == randoms[0])
randoms[2] = rand() % 80;

randoms[3] = rand() % 80;
while(randoms[3] == randoms[2] or randoms[3] == randoms[1] or randoms[3] == randoms[0])
randoms[3] = rand() % 80;

randoms[4] = rand() % 80;
while(randoms[4] == randoms[3] or randoms[4] == randoms[2] or randoms[4] == randoms[1] or randoms[4] == randoms[0])
randoms[4] = rand() % 80;


for(int i = 0;i < 5;i++)
p[selected_row][i] = randoms[i]; 	//set position


//  asci code : a = 97 and z = 122

randoms[0] = rand() % 26 + 97;//from 97 ta 122

randoms[1] = rand() % 26 + 97;
while(randoms[1] == randoms[0])
randoms[1] = rand() % 26 + 97;

randoms[2] = rand() % 26 + 97;
while(randoms[2] == randoms[1] or randoms[2] == randoms[0])
randoms[2] = rand() % 26 + 97;

randoms[3] = rand() % 26 + 97;
while(randoms[3] == randoms[2] or randoms[3] == randoms[1] or randoms[3] == randoms[0])
randoms[3] = rand() % 26 + 97;

randoms[4] = rand() % 26 + 97;
while(randoms[4] == randoms[3] or randoms[4] == randoms[2] or randoms[4] == randoms[1] or randoms[4] == randoms[0])
randoms[4] = rand() % 26 + 97;

for(int i = 0;i < 5;i++){
int pos = p[selected_row][i];
c[selected_row][pos] = randoms[i]; 	//set character
}
}





void print_screen(char c[row][column]){
	
	for(int i = 0; i < row;i++)
	for(int j = 0; j < column;j++)
    cout<<c[i][j];

}




void swap22(char a[row][column],int row1,int row2){
	
	
	char temp [column] = {' '};
	
	for(int i = 0;i < column;i++)
	temp [i] = a[row1][i];
	
	for(int i = 0;i < column;i++)
	a[row1][i] = a[row2][i];
	
	for(int i = 0;i < column;i++)
	a[row2][i] = temp[i];
	
	
}


void screen_go_to_next_line(char a[row][column]){
	
	for(int i = row-2; i >= 0 ; i--)
	swap22(a,i,i+1);
	
		for(int i = 0;i<column;i++)
        	a[0][i] = ' ';
}




void swap11(int a[row][5],int row1,int row2){
	
	
	char temp [5] = {0};
	
	for(int i = 0;i < 5;i++)
	temp [i] = a[row1][i];
	
	for(int i = 0;i < 5;i++)
	a[row1][i] = a[row2][i];
	
	for(int i = 0;i < 5;i++)
	a[row2][i] = temp[i];
	
	
}


void screen_go_to_next_line_pointers(int a[row][5]){
	
	for(int i = row-2; i > 0 ; i--)
	swap11(a,i,i+1);

	swap11(a,0,1);
	
		for(int i = 0;i<5;i++)
        	a[0][i] = 0;
}






void check_screen(char ch , char a[row][column]){

bool s = false;
int check = ch;

if(check >= 97 and check<=122){
for(int i = row-1; i >= 0;i--){
for(int j = 0; j < column;j--){	
if (a[i][j] == ch){
a[i][j] = ' ';
s = true;
break;	
}
}
if (s == true)
break;
}
}

typed += s;


}



void update_screen(char c[row][column]){
for(int i = 0; i < 100; i++)
cout<<"\n\n\n";
print_screen(c);
}


void update2_screen(char c[row][column], int p[row][5]){
screen_go_to_next_line(c);
screen_go_to_next_line_pointers(p);
set_values_for_row(p,c,0);
update_screen(c);
level += 1;
}




