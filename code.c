#include <stdio.h>
#include <string.h>

void copier();
void scanner();

int main()
{   
    //After receiving the approved documents, then I take actions what to do with it.//
    char choice[30];
    printf("\n\n===============================================\n\n");
    printf("\n\tCOPIER\n");
    printf("\n\tSCANNER\n");
    printf("\n\tEXIT\n");
    printf("\n\tEnter your choice : ");
    scanf("%s", choice);
    if (strcmp(choice, "COPIER") == 0){
        copier();
    }
    else if (strcmp(choice, "SCANNER") == 0){
        scanner();
    }
    else if (strcmp(choice, "EXIT") == 0){
        printf("\tThanks for using this program.\n\n");
    }
    else {
        printf("\tYou've made a mistake , Try again..\n\n\n");
        main();
    }
}

void copier()
{
    int choice; 
    printf("=================COPIER=================");
    printf("\n\t1. TO BE ROUTE OUT / FILE\n"); //File with Routing Slips//
    printf("\t2. NO NEED TO PHOTOCOPY\n");
    printf("\tEnter your choice : "); /3
    scanf("%d", &choice); 
    switch(choice)
    {
        case 1:
                int pagequantity, copyquantity, starter, copystarter;
                char size[10], type[15], option[20];
                printf("\tPage Quantity : ");
                scanf("%d", &pagequantity);
                printf("\tCopy Quantity : ");
                scanf("%d", &copyquantity);
                printf("\n\t====TYPE====\n");
                printf("\tBlack & White\n");
                printf("\tColored\n");
                getchar();
                printf("\tType : ");
                fgets(type, sizeof(type), stdin);
                printf("\n\t====SIZE====\n");
                printf("\tA4\n");
                printf("\t8 x 13\n");
                printf("\tSize : ");
                getchar();
                fgets(size, sizeof(size), stdin);
                printf("\t====PRINTING SETTING====\n");
                printf("\tOPTION 1 : 1 sided-2 sided: T to T");
                printf("\n\tOPTION 2 : 2 sided-2 sided");
                printf("\n\tOPTION 3 : 1 sided-comb 4 orig");
                printf("\n\tOPTION 4 : 1 sided-Comb 4 orig");
                printf("\n\tOPTION 5 : Create Margin");
                printf("\n\tOPTION 6 : NONE");
                printf("\n\tPrinting Setting : ");
                getchar();
                fgets(option, sizeof(option), stdin);
                starter = 1;
                copystarter = 1;
                if (copyquantity > 1) 
                { 
                    while (copystarter <= copyquantity)
                    {
                    printf("\t====Documents Sorted====\n");
                    starter = 1;
                    while (starter <= pagequantity) 
                    {
                    printf("\tDone Photocopied Page # %d\n", starter);
                    ++starter;
                    }
                    ++copystarter;
                    }
                    printf("\n\n \t====Photocopying is Done!====\n\n");
                    main();
                }
                else if (copyquantity == 1){
                    while(starter <= pagequantity)
                    {
                        printf("\tDone Page # %d\n", starter);
                        ++starter;
                    }
                    printf("\n\n \t====Photocopying is Done!====\n\n\n");
                    main();
                }
                else{
                    printf("\tYou've made a mistake , Try again..\n\n\n");
                    main();
                }
        case 2:
                printf("\tGIVE DIRECTLY TO RELEASING OFFICER OR PUT IT TO FILLING FOLDER\n\n\n");
                main();
        default:
                printf("\tYou've made a mistake , Try again..\n\n\n");
                main();
        }
    
}


void scanner()
{
    printf("\n\tInsert the USB Drive\n");
    FILE *fp;
    fp = fopen("scannedfile.txt", "a");
    int unscan, pagequantity;
    char file_name[40], type[40], papersize[40];
    printf("=================SCANNER=================");
    printf("\n\tFile Name : ");
    getchar();
    fgets(file_name, sizeof(file_name), stdin);
    fprintf(fp, "File Name : %s", file_name);
    fflush(stdin);
    printf("\n\tPage Quantity : ");
    scanf("%d", &pagequantity);
    fprintf(fp, "\tPage Quantity : %d", pagequantity);
    printf("\n\t====TYPE====\n");
    printf("\tBlack & White\n");
    printf("\tColored\n");
    printf("\tType : ");
    getchar();
    fgets(type, sizeof(type), stdin);
    fprintf(fp, "\n\tType : %s", type);
    fflush(stdin);
    printf("\t====SIZE====\n");
    printf("\tA4\n");
    printf("\t8 x 13\n");
    printf("\tSize : ");
    getchar();
    fgets(papersize, sizeof(papersize), stdin);
    fprintf(fp, "\tSize : %s", papersize);
    fflush(stdin);
    unscan = 1;
    while(unscan <= pagequantity)
    {
        printf("\tDone Scanning Page # %d\n", unscan);
        ++unscan;
    }
    printf("\n\n \t====Scanning is Done!====\n\n");
    fclose(fp);
    main();
}
     // Code by : Flores "I'm applying my experience and knowledge about CS 1 & C++ in doing this activity."
     // Members : Alminaza, Cosio, Landa, Paniza //