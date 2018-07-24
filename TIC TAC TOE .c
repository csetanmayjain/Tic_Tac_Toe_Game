#include <stdio.h>
#include<string.h>
int funct (char [][3],int,char*,char*,char*);
int main()
{
 char fn[50],sn[50],n[50],ch,sec[50],a[3][3],*ptr,ask,tp;
 ptr=&ask;
 int q,r,i,j,fp,c,k,cn,coun;
do                                       //do loop,if the player wants to play again
{
      cn=0;coun=0;ask='n';q=1;
       for(i=0;i<3;i++)              //Initialize value . to all the elements
       {
        for(j=0;j<3;j++)
        a[i][j]='.';
       }
     printf("Enter a name for the X player:\n");
     fflush(stdin);
     scanf(" %s",&fn);                         //input first player name
     printf("Enter a name for the O player:\n");
     scanf(" %s",&sn);                        //input second player name
    do
     {
       ch='w';
       printf("Who plays first, %s or %s? \n",fn,sn);
       scanf(" %s",&n);
         if((strcmp(n,fn)==0))
          {
           cn=0;    //compare who play first
       		ch='y';
       		strcpy(sec,sn);
          }
         else if((strcmp(n,sn)==0))
          {
           cn=1;
           ch='y';
           strcpy(sec,fn);
          }
          else
           printf("\n %s is not a registered player.\n",n);
       }while(ch=='w');

    for(i=0;i<3;i++)                  //print the blank game matrix
	 {
      for(j=0;j<3;j++)
      printf(" %c ",a[i][j]);
      printf("\n");
	  }
   coun=1;
    for(k=0;k<=4;k++)               //run cn as a counter so it will update to insert x or o and k is run k+2 as loop will take 2 value at a time
      {
        if(coun<=9)
           {
            printf("\nPlayer of current turn: %s\n",n);
            cn=funct(a,cn,fn,sn,ptr);
             if(((*ptr)=='y')||((*ptr)!='\0'))
                break;
             coun=coun+1;
            }
           if(coun<=9)
           {
            printf("\nPlayer of current turn: %s\n",sec);
            cn=funct(a,cn,fn,cn,ptr);
             if(((*ptr)=='y')||((*ptr)!='\0'))
                break;
            coun=coun+1;
            }
        if(coun>9)
            break;
      }
      tp=(*ptr);
      if(coun>9)
        {
            printf("\nGame is Over\n");
            printf("it is a tie\nWould you like to play again? (Y/N):- ");
            scanf(" %c",ptr);
            tp=(*ptr);
        }
           if((tp!='n')&&(tp!='y'))  // not work on ||, work on &&
            {
             do
              {     ask='\0';
                printf("You Enter A Wrong Choice\nDo You Want To Continue(y/n)?:- ");
                fflush(stdin);
                scanf(" %c",&tp);
                fflush(stdin);
              }while((tp!='n')&&(tp!='y'));
            }
            if((tp=='n')||(tp=='N'))
            {
              printf("\nBye!");
              exit(0);
            }
 free(ptr);
}while((tp=='y')||(tp=='Y'));
 return 0;
}

//Function check the correctness of row and coloumn value and repeat until correct value insert by the player

 int funct(char a[][3],int cn,char* fn,char* sn,char* ptr)
    {
	 int r,c,i,j,q;
     char brk='\0';(*ptr)='\0';
      do
       {
        q=1;
        do                         //  do,if input value of row -r is not valid
         {
            q=1;                    //if r  value not valid then q=0
            printf("\nChoose a row number (O to 2):");
            fflush(stdin);
            r=getchar();
            fflush(stdin);
            //r = (int)r;
           // printf("row selected is %d\n",r);
            if((r<48)||(r>50))
              {
                q=0;
               printf("%c is not a valid row.",r);
	           }
            }while((r<48)||(r>50));
            r = r-48;
       do             //  do,if input value of  c is not valid
         {
            q=1;          //if c  value not valid then q=0
            printf("\nChoose a coloumn number (O to 2):");
            fflush(stdin);
            c=getchar();
            fflush(stdin);
            if((c<48)||(c>50))
            {
              q=0;
              printf("%c is not a valid coloumn.\n",c);
	         }
         }while((c<48)||(c>50));
         c = c-48;
           q=1;
         if (a[r][c]!='.')
         {
          printf("%d %d is already chosen.\n",r,c);
         q=0;
         }
      }while(q==0);
     if((cn%2)==0)
         a[r][c]='x';                       //insertion of element in array
     else
	     a[r][c]='o';
   system("cls");
    j=0;
    brk='\0';
       for(i=0;i<3;i++)
         {
              brk='\0';
                if((a[i][j]==a[i][j+1])&&(a[i][j+1]==a[i][j+2]))
                    {
                        if(a[i][j]=='x')
                          {
                            brk='x';
                             break;
                           }
                         if(a[i][j]=='o')
                           {
                            brk='o';
                            break;
                            }
                     }
            if((a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i]))
                      {
                        if((a[j][i]=='x'))
                          {
                            brk='x';
                             break;
                           }
                         if((a[j][i]=='o'))
                           {
                            brk='o';
                            break;
                            }
                       }
         }
            if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))
                    {
                       if((a[0][0]=='x'))
                          {
                            brk='x';
                           }
                         if((a[0][0]=='o'))
                           {
                            brk='o';
                            }
                    }
          if((a[0][2]==a[1][1])&&(a[1][1]==a[2][0]))
                   {
                      if(a[0][2]=='x')
                          {
                            brk='x';
                         //    break;
                           }
                         if((a[0][2]=='o'))
                           {
                            brk='o';
                    }
                    }

    if(brk=='o')
       printf("\n Game is over: %s player Wins!\n",fn);
  if(brk=='x')
    printf("\n Game is over: %s player Wins!\n",sn);

     for(i=0;i<3;i++)                  //print the blank game matrix
	 {
      for(j=0;j<3;j++)
      printf(" %c ",a[i][j]);
      printf("\n");
	  }

	  if(brk=='o'||brk=='x')
    {
       printf("\n Would you like to play again? (y/n)");
       scanf(" %c",ptr);
    }
  if((*ptr)=='n'||(*ptr)=='N')
          {
              printf("\nBye!");
              exit(0);
          }
    cn++;
  return cn;
}

