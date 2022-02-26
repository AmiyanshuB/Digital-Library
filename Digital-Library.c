#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>

#define MAX_NO_OF_BOOKS 5000
#define MAX_AUTHOR_OF_A_BOOK 20
#define MAX_CHAR_IN_NAME 100
//Giving A Name To The File
#define FILE_NAME "Digital Library.bin"
int numberOfBooks = 0;
int notReady = 0;
//Declaring Structure Book
typedef struct
{
    long long int ISBN;
    char Name[MAX_CHAR_IN_NAME];
    int numberOfAuthors;//contains the information of number of authors as number of authors will be different for different books
    char author[MAX_CHAR_IN_NAME][MAX_AUTHOR_OF_A_BOOK];
    char publisher[MAX_CHAR_IN_NAME];
    int year;
}BOOK;
//Calculated the number of spaces and decided whether to print the message
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
//Printing The header of the program
void headMessage(const char *message)
{
    system("cls");
    char ch;
    FILE*fp = fopen("headmsg.txt","r");
    if(!fp)
    {
        printf("Memory Error!!");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);

    Message(message);
}
//Printing welcome messages
void welcomeMessage()
{
    printf("\n\n\n");
    char ch;
    FILE*fp = fopen("welcome.txt","r");//File from where the fxn reading the data
    if(!fp)
    {
        printf("Memory Error!!!");
        exit(0);
    }
    printf("\t\t\t");
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}
//Display function Basically to display all the books: Sorted and All the books
void viewFxn(BOOK* b)
{
    printf("\nSr.No\t\tISBN No\t\t\tYear Of Publication\t\tName of the Book\t\t Author\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < numberOfBooks; i++)
    {
            printf("  %d.\t\t%lld\t\t\t%d\t\t\t%s\t",i+1,b[i].ISBN,b[i].year,b[i].Name);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
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
            printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}
//Not found ASCII Message
void errorASCII(void)
{
    char ch;
    FILE*fp = fopen("error.txt","r");
    if(!fp)
    {
        printf("Memory error");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
//Success Message
void successASCII(void)
{
    char ch;
    FILE*fp = fopen("Success.txt","r");
    if(fp == NULL)
    {
        errorASCII();
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
//Message when a particular book is found
void found(void)
{
    char ch;
    FILE*fp = fopen("found.txt","r");
    if(!fp)
    {
        printf("Memory error");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
void empty(void)
{
    char ch;
    FILE*fp = fopen("empty.txt","r");
    if(!fp)
    {
        printf("Memory error");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
void error1(void)
{
    char ch;
    FILE*fp = fopen("error1.txt","r");
    if(!fp)
    {
        printf("Memory error");
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
}
//Kind of Display function which display only some selected books
void findViewFxn(BOOK* b, int counter)
{
     printf("\nSr.No\t\tISBN No\t\t\tYear Of Publication\t\tName of the Book\t\t Author\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < counter; i++)
    {
            printf("  %d.\t\t%lld\t\t\t%d\t\t\t%s\t",i+1,b[i].ISBN,b[i].year,b[i].Name);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
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
            printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}
///WE HAVE USED "ab+" AND "rb" INSTEAS OF a AND r BECAUSE I AM USING A BINARY FILE RATHER THEN ANY READABLE FILE AND ab+ and rb ARE USED FOR A BINARY FILE//
///FUNCTIONALITY OF THESE MODES ARE SAME AS a and r MODES//
///"ab+" - APPAND AT THE END OF THE BINARY FILE//
///"rb" - READ FROM THE BINARY FILE//
//Function to inser inside a data base/ file
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
    successASCII();
}
//This function Fetches Data form the file
BOOK *readingFromaDataBase()
{
    BOOK Book;//Declaring a book buffer!!
    int i = 0;
    int k = i;
    BOOK*temp = malloc(sizeof(BOOK)*MAX_NO_OF_BOOKS);//declaring a array dynamically
    FILE*fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        return NULL;
    }
    if(fseek(fp, 0 ,SEEK_SET) != 0)//Bringing the file pointer to the starting of the file and then  checking whether it is empty or not//
    {
        printf("The File is still not created");
        return NULL;
    }
    while(fread(&Book, sizeof(BOOK), 1,fp))//Reading the file by putting the data inside the book buffer and then storing it into a array temp.....
    {
        temp[i] = Book;
        i++;
    }
    numberOfBooks = i;

    return temp;

}
int booksInBetweenGivernYears(BOOK *temp,int year1, int year2)
{
    BOOK b[numberOfBooks];
    int counter = 0;
    if(year2 < year1)
    {
        printf("\n\t\t\tPlease enter valid year!!!");
        error1();
        printf("\n\t\t\tPress any key to return to main menu.....");
        fflush(stdin);
        getchar();
        return 1;
    }
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(year1 <= temp[i].year && year2 >= temp[i].year)
        {
            b[counter] = temp[i];
            counter++;
        }
    }
    if(counter == 0)
    {
        errorASCII();
    }
    else
    {
        found();
        printf("Library has %d books between the years %d and %d and following is the list of books\n",counter,year1,year2);
        findViewFxn(b,counter);
        printf("\n\n\n\t\t\t Enter any key to return to main menu.....");
    }
        fflush(stdin);
        getchar();
        return counter;

}
//Function to find the book by a given author
void bookByAGivenAuthor(BOOK *b, char authorName[], int n)
{
    BOOK temp[n];
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
              temp[counter] = b[i];
              counter++;
          }

        }
    }
    if(FoundBook == true)
    {
        found();
        printf("\n\n\n\t\t\t\t: ) Yes We Have %d Books By The Author %s  \n",counter,authorName);
        findViewFxn(temp, counter);
        printf("\n\t\t\t\tEnter any key to return to main menu.....");
        fflush(stdin);
        getchar();
    }

    if(FoundBook == false)
    {
        errorASCII();
        printf("\n\t\t\tPress any key to return to main menu.....");
        fflush(stdin);
        getchar();
    }

}
//Sort By Name of the books
void sortByName(BOOK *b,int n)
{
    if(numberOfBooks == 0)
    {
        empty();
        return;
    }
    int k = 0;
    BOOK temp;
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
    if(n == 0)
    {
        errorASCII();
        printf("\n\t\t\tPress any key to return to main menu.....");
        fflush(stdin);
        getchar();
    }
    printf("\n\t\t\t\tBooks in Sorted Oreder:\n");
    viewFxn(b);
}
void sortByISBN(BOOK* b,int n)
{
    if(numberOfBooks == 0)
    {
        empty();
        return;
    }

    int counter=1;
    while(counter < n)
    {
    for(int i=0; i < n - counter; i++)
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
viewFxn(b);
}
void booksInAGivenYear(BOOK* b, int year1)
{
    BOOK temp[numberOfBooks];
    int counter = 0;
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(year1 == b[i].year)
        {
            counter++;
            temp[counter] = b[i];
        }
    }
    if(counter == 0)
    {
            errorASCII();
            return;
    }
    findViewFxn(temp, counter);
}
void record(void)
{
    system("cls");
    char ch;
    FILE*fp = fopen("record.txt","r");
    if(fp == NULL)
    {
        printf("ERROR 404!!!!");
    }
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);

}
void bookByAGivenPublisher(BOOK* temp)
{
    BOOK b[numberOfBooks];
    char publisher[MAX_CHAR_IN_NAME];
    int count = 0;
    printf("\n\t\t\tEnter The Name Of Publisher = ");
    fflush(stdin);
    fgets(publisher,MAX_CHAR_IN_NAME,stdin);
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(strcmp(publisher , temp[i].publisher) == 0)
        {
            b[count] = temp[i];
            count++;
        }
    }
    if(count == 0)
    {
        printf("\n\t\t\t\t: ( No Book By The Publisher\n");
        error1();
        return;
    }
    findViewFxn(b, count);
}
void sortByAuthor(BOOK *b,int n)
{
    if(numberOfBooks == 0)
    {
        empty();
        return;
    }
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
    printf("\n\n\t\t\t\t\tBooks in Sorted Order By The Names Of Authors:\n\n");
    viewFxn(b);
}
void view(BOOK *b)
{
    system("cls");
    record();
    printf("\n\n");
    viewFxn(b);
}
void message(void)
{
    system("cls");
    char ch;
    FILE*fp = fopen("Message.txt","r");
                    if(fp == NULL)
                    {
                    printf("ERROR 404!!!!");
                    return;
                    }
                    while((ch = fgetc(fp)) != EOF)
                    {
                    printf("%c",ch);
                    }
                    fclose(fp);
                    printf("Press any key to go to main menu....");
                    fflush(stdin);
                    getchar();
                    return;
}




int main()
{
    BOOK *temp = malloc(sizeof(BOOK)*MAX_NO_OF_BOOKS);
    int choice = 0,n,year1,year2;
    char author[MAX_CHAR_IN_NAME];
    welcomeMessage();
    while(1)
    {
        temp = readingFromaDataBase();
        jump:
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Book:");
        printf("\n\t\t\t2.Search Books Between Two Given Years: ");
        printf("\n\t\t\t3.Search By Name Of Author:");
        printf("\n\t\t\t4.Sort By Name: ");
        printf("\n\t\t\t5.Sort By ISBN Number:");
        printf("\n\t\t\t6.Search Books In A Given Year:");
        printf("\n\t\t\t7.Search Books By a Given Publisher:");
        printf("\n\t\t\t8.Sort By Author: ");
        printf("\n\t\t\t9.Print The Whole Library:");
        printf("\n\t\t\t10.Credits:");
        printf("\n\t\t\t11.Message!!");
        printf("\n\t\t\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:insertInADataBase();
                temp = readingFromaDataBase();
                printf("\n\t\t\tEnter any key to return to main menu.....");
                fflush(stdin);
                getchar();
                break;
            case 2:headMessage("Find Book In Between Two Given Years");
            if(numberOfBooks == 0)
              {
                empty();
                printf("\n\t\t\tThe Library Is Currently Empty Please Enter 1 To Insert Into The Library");
                printf("\n\t\t\tPress any key to return to main menu.....");
                fflush(stdin);
                getchar();
                break;
              }
                printf("\n\t\t\tYear1:");
                scanf("%d",&year1);
                printf("\n\t\t\tYear2:");
                scanf("%d",&year2);
                int k= booksInBetweenGivernYears(temp,year1,year2);
                break;
            case 3:headMessage("Find Book By Author");
                if(numberOfBooks == 0)
                {
                    empty();
                    printf("\n\t\t\tPress any key to return to main menu.....");
                fflush(stdin);
                getchar();
                break;
                }

                printf("\n\n\t\t\t\t\tAuthor's Name: ");
                scanf("\n%[^\n]s",author);
                printf("\n\t\t\t\t\tBooks By Author:\n\n");
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
            if(numberOfBooks == 0)
            {
                empty();
                printf("Press any key to go to main menu....");
                fflush(stdin);
                getchar();
                break;
            }do{
                printf("\n\t\t\t\tYear:");
                    scanf("%d",&year1);
                }
                while(year1 < 0 || year1 > 2022);
            booksInAGivenYear(temp, year1);
            printf("Press any key to go to main menu....");
            fflush(stdin);
            getchar();
            break;
            case 7:headMessage("Find Book By Publishers Name");
            if(numberOfBooks == 0)
            {
                empty();
                printf("Press any key to go to main menu....");
                fflush(stdin);
                getchar();
                break;
            }
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
            if(numberOfBooks == 0)
            {
                empty();
                printf("Press any key to return to main menu....");
                fflush(stdin);
                getchar();
                break;
            }
            view(temp);
            printf("Press any key to go to main menu....");
            fflush(stdin);
            getchar();
            break;
            case 10: headMessage("CREDITS : ) ");
                    char ch;
                    FILE*fp = fopen("Cradits.txt","r");
                    if(fp == NULL)
                    {
                    printf("ERROR 404!!!!");
                    break;
                    }
                    while((ch = fgetc(fp)) != EOF)
                    {
                    printf("%c",ch);
                    }
                    fclose(fp);
                    printf("Press any key to go to main menu....");
                    fflush(stdin);
                    getchar();
                    break;
            case 11: message();
            break;



        }
    }
}
