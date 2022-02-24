#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>

#define MAX_NO_OF_BOOKS 5000
#define MAX_AUTHOR_OF_A_BOOK 20
#define MAX_CHAR_IN_NAME 100
#define FILE_NAME "Digital Library.bin"
int numberOfBooks = 0;
int notReady = 0;

typedef struct
{
    long long int ISBN;
    char Name[MAX_CHAR_IN_NAME];
    int numberOfAuthors;
    char author[MAX_CHAR_IN_NAME][MAX_AUTHOR_OF_A_BOOK];
    char publisher[MAX_CHAR_IN_NAME];
    int year;
}BOOK;
///Someones
void Message(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    char ch;
    FILE*fp = fopen("headmsg.txt","r");
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);

    Message(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("DSA - ASSIGMENT OF TEAM 13 ");
    printf("\n\n\n");
    char ch;
    FILE*fp = fopen("welcome.txt","r");
    printf("\t\t\t");
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}

void insertInADataBase()
{
    BOOK b;
    int n,j,k = 0;
    FILE *fp = fopen(FILE_NAME, "ab+");
    if(!fp)
    {
        printf("Segmentation Fault!!!");
        exit(1);
    }
    headMessage(": ) ADD BOOK");

    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tISBN NO = ");
    fflush(stdin);
    scanf("%lld",&b.ISBN);
    //Asking for book Name
    printf("\n\t\t\tBook Name  = ");
    fflush(stdin);
    fgets(b.Name,MAX_CHAR_IN_NAME,stdin);
    //Asking for author name
     printf("\n\t\t\tNumber of author's:");
        scanf("%d",&j);
        b.numberOfAuthors = j;
        printf("\n\t\t\tName Of Author/Authors:");
        while( k < j )
        {
            scanf("\n%[^\n]%*c", b.author[k]);
            k++;
        }
    //Asking for publisher
    printf("\n\t\t\tPublisher:");
    fflush(stdin);
    fgets(b.publisher, MAX_CHAR_IN_NAME, stdin);
    //Asking for Year
    printf("\n\t\t\tYear =");
    scanf("%d",&b.year);
    //writing inside a file
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}
BOOK *readingFromaDataBase()
{
    BOOK Book;
    int i = 0;
    int k = i;
    BOOK*temp = malloc(sizeof(BOOK)*MAX_NO_OF_BOOKS);
    FILE*fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        exit(1);
    }
    if(fseek(fp, 0 ,SEEK_SET) != 0)
    {
        exit(1);
    }
    while(fread(&Book, sizeof(BOOK), 1,fp))
    {
        temp[i] = Book;
        i++;
    }
    numberOfBooks = i;

    return temp;

}
int booksInBetweenAGivernYears(BOOK *temp,int year1, int year2)
{
    int counter = 0;
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(year1 <= temp[i].year && year2 >= temp[i].year)
        {
            counter++;
            printf("\n\t\t\t%d.%s\n",counter,temp[i].Name);
        }
    }
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    fflush(stdin);
    getchar();
    return counter;
}
void bookByAGivenAuthor(BOOK *b, char authorName[], int n)
{

    int counter = 0;
    int j = 0;
    bool FoundBook= false;
    for(int i = 0; i < n; i++)
    {

        for(j = 0; j < b[i].numberOfAuthors; j++ )
        {
          if(strcmp(authorName, b[i].author[j]) == 0)
          {
              FoundBook = true;
              counter++;
              printf("\n\t\t\t%d. %s\n",counter,b[i].Name);
          }

        }
    }
    if(true)
    {
        printf("\n\n\n\t\t\t: ) %d Books By The Author %s is Found \n\t\t\tEnter any key to continue.....",counter,authorName);
        fflush(stdin);
        getchar();
    }

    if(FoundBook == false)
    {
        printf(": ( Sorry Don't Found Any Book By the Author");
    }

}
void sortByName(BOOK *b,int n)
{
    int k = 0;
    BOOK smallest,temp;
    for(int i = 0; i < n -1; i++)
    {
            for(int j = i + 1; j < n; j++)
            {
                while(toupper(b[i].Name[k]) == toupper(b[j].Name[k]))
                {
                    k++;
                }
            if(toupper(b[i].Name[k]) > toupper(b[j].Name[k]))
                {
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
                k = 0;
        }

    }
    printf("\n\t\t\t\tBooks in Sorted Oreder:\n");
    for(int i = 0; i < n; i++)
        {
            printf("\n%d.%s",i + 1,b[i].Name);
        }
}
void sortByISBN(BOOK* b,int n)
{

    int counter=1;
    while(counter<n){
    for(int i=0;i<n-counter;i++)
        {
            if(b[i].ISBN>b[i+1].ISBN)
            {
            BOOK temp=b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
            }
        }
counter++;
}

for(int i=0;i<n;i++)
    {
    printf("--NAME--%s\t",b[i].Name);

     printf("---ISBN--:%lli",b[i].ISBN);
     printf("\n");
   }
}
void booksInAGivenYear(BOOK* b, int year1)
{
    int counter = 0;
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(year1 == b[i].year)
        {
            counter++;
            printf("%d.%s",counter, b[i].Name);
        }
    }
    if(counter == 0)
    {
            printf(": ( No Book Found!!!");
    }
}
void bookByAGivenPublisher(BOOK* temp)
{
    char publisher[MAX_CHAR_IN_NAME];
    int count = 0;
    printf("Enter The Name Of Publisher = ");
    fflush(stdin);
    fgets(publisher,MAX_CHAR_IN_NAME,stdin);
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(strcmp(publisher , temp[i].publisher) == 0)
        {
            count++;
            printf("%d.%s",count,temp[i].Name);
        }
    }
    if(count == 0)
    {
        printf(": ( No Book By The Publisher");
    }
}
void sortByAuthor(BOOK *b,int n)
{
    int k = 0;
    BOOK smallest,temp;
    for(int i = 0; i < n -1; i++)
    {
            for(int j = i + 1; j < n; j++)
            {
                while(toupper(b[i].author[0][k]) == toupper(b[j].author[0][k]))
                {
                    k++;
                }
            if(toupper(b[i].author[0][k]) > toupper(b[j].author[0][k]))
                {
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
                k = 0;
        }

    }
    printf("Books in Sorted Oreder By The Names Of Authrs:\n");
    for(int i = 0; i < n; i++)
        {
            printf("\n%d.%s",i + 1,b[i].Name);
        }
}
void view(BOOK *b)
{
    printf("\nSr.No\tName Of The Book\tYear Of Publication\t\t\tISBN No\t\t Author\n");
    printf("--------------------------------------------------------------------------\n");
    for(int i = 0; i < numberOfBooks; i++)
    {
            printf("%d.\t%lld\t\t\t\t\t%d\t\t\t\t%s\t\t",i+1,b[i].ISBN,b[i].year,b[i].Name);
            for(int j = 0; j < b[i].numberOfAuthors; j++)
            {
                if(b[i].numberOfAuthors == 1)
                {
                    printf("%s",b[i].author[j]);

                }
                else
                {
                        printf("%s,",b[i].author[j]);
                }
            }
             printf("\n");
    }

}



int main()
{
    BOOK *temp = malloc(sizeof(BOOK)*MAX_NO_OF_BOOKS);
    int choice = 0,n,year1,year2;
    char author[MAX_CHAR_IN_NAME];
    welcomeMessage();
    while(1)
    {
        //temp = readingFromaDataBase();
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Book:");
        printf("\n\t\t\t2.Search Books Between Two Given Years: ");
        printf("\n\t\t\t3.Search By Name Of Author:");
        printf("\n\t\t\t4.Sort By Name: ");
        printf("\n\t\t\t5.Sort By ISBN Number:");
        printf("\n\t\t\t6.Search Books In A Given Year:");
        printf("\n\t\t\t7.Search Books By a Given Publisher:");
        printf("\n\t\t\t8.Sort By Author: ");
        printf("\n\t\t\t9.Print The Whole Library");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:insertInADataBase();
                temp = readingFromaDataBase();
                printf("\n\n\n\t\t\t: ) Book Successfully Added Enter any key to continue.....");
                fflush(stdin);
                getchar();
                break;
            case 2:headMessage("Find Book In Between Two Given Years");
                printf("\n\t\t\tYear1:");
                scanf("%d",&year1);
                printf("\n\t\t\tYear2:");
                scanf("%d",&year2);
                int k= booksInBetweenAGivernYears(temp,year1,year2);
                break;
            case 3:if(numberOfBooks == 0)
                {
                printf("\n\t\t\t: ( There is no book in the library!!");
                break;
                }
                headMessage("Find Book By Author");
                printf("\n\t\t\tAuthor's Name: ");
                scanf("\n%[^\n]s",author);
                printf("\n\t\t\tBooks By Author:");
                bookByAGivenAuthor(temp, author, numberOfBooks);

            break;
            case 4:headMessage("Sorting By Name Of Books");
                sortByName(temp,numberOfBooks);
                printf("Press any key to go to main menu....");
                fflush(stdin);
                getchar();
                    break;
            case 5:
                headMessage("Sorting By ISBN Number");
                sortByISBN(temp,numberOfBooks);
                printf("Press any key to go to main menu....");
                fflush(stdin);
                getchar();
            break;
            case 6:headMessage("List Of Books In A Particular Year");
                printf("Year:");
            scanf("%d",&year1);
            booksInAGivenYear(temp, year1);
            printf("Press any key to go to main menu....");
            fflush(stdin);
            getchar();
            break;
            case 7:headMessage("Find Book By Publishers Name");
                bookByAGivenPublisher(temp);
                printf("Press any key to go to main menu....");
                fflush(stdin);
                getchar();
            break;
            case 8:headMessage("Sort Book By The Name Of Authors");
            sortByAuthor(temp, numberOfBooks);
            printf("Press any key to go to main menu....");
            fflush(stdin);
            getchar();
            break;
            case 9: headMessage("List Of Books In A Particular Year");
            view(temp);
            printf("Press any key to go to main menu....");
            fflush(stdin);
            getchar();
            break;

        }
    }
}
