#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>



int matris[9][9] ={    {1,2,3,4,5,6,7,8,9},//Creating Matrix List for 
                       {4,5,6,7,8,9,1,2,3},//the random Sudoku Table
                       {7,8,9,1,2,3,4,5,6},
                                          
                       {2,3,4,5,6,7,8,9,1},
                       {5,6,7,8,9,1,2,3,4},
                       {8,9,1,2,3,4,5,6,7},
                                          
                       {3,4,5,6,7,8,9,1,2},
                       {6,7,8,9,1,2,3,4,5},
                       {9,1,2,3,4,5,6,7,8}};
                       

                       
int sudokuTable[9][9]={{0}};//The Sudoku Table That will be used
//to being filled my declared matrix randomly we assigned to empty list
bool matriscontrol( int _matris[9][9], int newvalue, int i, int j); // A function named kontrol created as bool

void mix( void ); //Karistir Function was designed to mix the elemant of the matrix

int main()
{
                                         
    srand( time(NULL) );//To generate random-like numbers srand initilized
    
    int mix_num;//A variable to detect how much mixing is happened
    
    mix_num = rand() % 50 + 5; //Between 1-49 numbers is produced 
    //matrix going to be mixed
    
    for(int i=0;i<mix_num;i++)
    {
      mix();//Calling mix function
     }
    
   
    
    for(int j=0;j<9;j++)//In this section some numbers will be shown 
    {                   //in the matrix
                        //Which are different in each other

    
            int showrows[3];//Gosterileceksatir is used 
                                        //to show the row that was selected
                                        //at the first time
   
            do
            {
                showrows[0] = rand() % 9; //Creating random integers between 0-8
                showrows[1] = rand() % 9;
                showrows[2] = rand() % 9;
        
            }while( showrows[0] == showrows[1] ||
                    showrows[1] == showrows[2] ||
                    showrows[0] == showrows[2] );
            
            
            for(int i=0;i<9;i++)
            {
              sudokuTable[j][ showrows[0] ] = matris[j][ showrows[0] ];// Rows that will be shown
              
              sudokuTable[j][ showrows[1] ] = matris[j][ showrows[1] ];
              sudokuTable[j][ showrows[2] ] = matris[j][ showrows[2] ];
             }  
    }     
    
 
    while(1)
    {
    int x=0,y=0,nummer=0;  
            
    printf("       0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
    printf("------------------------------------------\n");//Giving sudoku-like shape. 
    
    for(int i=0;i<9;i++)
    {
            printf("%d -> | ", i);
            
            for(int j=0;j<9;j++)
            {
                    if( sudokuTable[i][j] != 0 )
                    {
                        printf("%d | ",sudokuTable[i][j]); // In table 3 rows are visible.
                    }
                    else
                    {
                        printf("  | "); // Zeros was not printed spaces was.
                    }
            }
        
            printf("\n------------------------------------------\n");//Giving sudoku-like shape 
    }
    
    printf("Enter the coordinates(x y):");
    scanf("%d %d",&x, &y);
    
    if( x == 10 )//When 10 is written in coordinates it will give error.
    {
        for(int i=0;i<9;i++)
        {
                for(int j=0;j<9;j++)
                {
                        sudokuTable[i][j] = matris[i][j];//Showing sudoku .
                }
        }
        system("cls");//When 10 is given then real sudoku will be shown
                      //Unsolved sudoku will be vanished  
        printf("Thats you got the solution!!:\n");
    }
    else
    {
        printf("\nEnter a number:");
        scanf("%d", &nummer);
        if( matriscontrol( sudokuTable, nummer, x, y) && nummer < 10 && nummer > 0 )//To see real solution when 10 is written
        {
            system("cls");
            printf("You've entered the number!\n\n\n");
            sudokuTable[x][y] = nummer;
        
        }
        else
        {
            system("cls");
            printf("This cannot be given\n\n\n");
        }
    }
    
    
    printf("\n");
    
    }
    
    system("pause");
    return 0;
}

void mix( void )
{
     int newMatris[9][9];
     
     for(int i=0;i<9;i++)
     {
              newMatris[0][i] = matris[2][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[0][i] = matris[2][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[1][i] = matris[1][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[2][i] = matris[0][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[3][i] = matris[5][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[4][i] = matris[4][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[5][i] = matris[3][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[6][i] = matris[8][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[7][i] = matris[7][i];
     }
     
      for(int i=0;i<9;i++)
     {
     newMatris[8][i] = matris[6][i];
     }
     
    
     for(int i=0;i<9;i++)
     {
              for(int j=0;j<9;j++)
              {
                      matris[i][j] = newMatris[i][j];
              }
     }
     
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][0] = matris[i][2]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][1] = matris[i][1]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][2] = matris[i][0]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][3] = matris[i][5]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][4] = matris[i][4]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][5] = matris[i][3]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][6] = matris[i][8]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][7] = matris[i][7]; 
     }
     
     for(int i=0;i<9;i++)
     {
             newMatris[i][8] = matris[i][6]; 
     }
     
     for(int i=0;i<9;i++)
     {
              for(int j=0;j<9;j++)
              {
                      matris[i][j] = newMatris[i][j];
              }
     }
     
     
}

bool matriscontrol( int _matris[9][9], int newvalue, int i, int j)
{
   
     
     if( _matris[i][j] != 0 )
     {
         //If the given coordinate was not empty
         printf("*Full*");
         return false;
     } 
     
     
     for(int k=0;k<9;k++) 
     {
            
             
             if( _matris[i][k] == newvalue ) 
             {
                 //If new given y-value was the same with previous value in coordinate
                 printf("*y-axis already full*");
                 return false;
               
             }
     }
     for(int k=0;k<9;k++) 
     {
            
             if( _matris[k][j] == newvalue )
             {
                 //If new given x-value was the same with previous value in coordinate

                 printf("*x-axis already full*");
                 return false;
             }
     }
     
     int littlei = i % 3;  
     int littlek = j % 3;
     
     int kmatrisX = floor( i / 3 ); 
     int kmatrisY = floor( j / 3 );
     
     
     int kmatris[3][3];//Little Matris
     
     int little_pos_x = kmatrisX * 3;
     int little_pos_y = kmatrisY * 3;
     
     for(int k=0;k<3;k++)
     {
             for(int m=0;m<3;m++)// To move rows and coulums
             {
                    
                    if(_matris[little_pos_x + k][little_pos_y + m] == newvalue)//Comparing whether rows and coulumns are identitcal
                    {
                        printf("*3x3 is failed*");//If moved position in
                                                //little matris(kmatris) equall the new value   
                        return false;           //returning false
                    }

             }
     }
   
     
      
     return true;
     
  

}
