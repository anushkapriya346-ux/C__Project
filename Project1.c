#include<stdio.h>
#include<string.h>
#define MAX 100
char names[MAX][100];
char phones[MAX][15];
int count = 0;

void trimNewline(char*str){
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1 ] = '\0';

}

// add new contact feature
int isValidphone(const char*phone){
    int len = strlen(phone);
    if (phone[len-1] == '\n')len--;
    if (len < 7 || len > 14)
    return 0;
    for ( int i = 0 ; i < len ; i++){
        if(phone[i]<'0' || phone[i]>'9')
        return 0;

    }
    return 1;


}
// add new contact 
void addcontact(){
    if ( count >= MAX){
        printf("Contact is full.\n");
        return ;

    }
    printf("Enter name: ");
    fgets(names[count],sizeof(names[count]),stdin);
    trimNewline(names[count]);

    while(1){
        printf("Enter your phone number: ");
        fgets(phones[count],sizeof(phones[count]),stdin);
        trimNewline(phones[count]);
        
        if (isValidphone(phones[count])){
            break; 
        }
        else{
            printf("Invalid phone number. Phone number must be b/w 7 and 14 and contains only numbers.\n");

        }
       
    }
    printf("Contacts added successfully.\n");
    count++;

}
// displaying all contacts.
void displayContacts(){
    if ( count == 0 ){
        printf("No contacts.\n");
        return;
    }
    printf("\n -- Contact list -- \n");
    for (int i = 0 ; i < count ; i++){
        printf("%d Name: %s Phone: %s\n",i+1,names[i],phones[i]);

    }
}
// search by name 
int searchbyName(int index, const char*query){
    if (index == count ){
        return -1;
    }
    if(strcasecmp(names[index],query)==0)
        return index;
    return searchbyName(index+1,query);

}
// search by phone
int searchbyPhone(int index , const char *query){
    if (index == count ){
        return -1;   
    }
    if (strcmp(phones[index],query)==0)
        return index;
    return searchbyPhone(index+1,query);

}
// Delete contact by list
void deleteContact(){
    char query[100];
    int index;
    printf("Enter name to delete: ");
    fgets(query,sizeof(query),stdin);
    trimNewline(query);

    index = searchbyName(0,query);
    if(index == -1){
        printf("Contact Not found \n");
        return ;

    }
    if (index == count -1){
        count--;
    }
    else{
        strcpy(names[index],names[count-1]);
        strcpy(phones[index],phones[count-1]);
        count --;

    }
    printf("Contact deleted successfully .\n");


}
// dashboard
int main(){
    int choice;
    char query[100];
    int index;
    
    while(1){
        printf("\n -- WELCOME TO CONTACT BOOK --\n");
        printf("1. ADD CONTACT\n");
        printf("2. Search by Name\n");
        printf("3. Search by Phone\n");
        printf("4. Display all contacts\n ");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Hey! Enter your choice : ");
        scanf("%d",&choice);
        getchar();


    
        switch(choice){
        case 1:
        addcontact();
        break;

        case 2:
        printf("Enter name to search: ");
        fgets(query,sizeof(query),stdin);
        trimNewline(query);
        index = searchbyName(0,query);
        if (index == -1)
        printf("Contact NOT found.\n");
        else{
            printf("Found: Name: %s Number: %s\n",names[index],phones[index]);

        }
        break;

        case 3:
        printf("Enter Phone number to search : ");
        fgets(query,sizeof(query),stdin);
        trimNewline(query);
        index = searchbyPhone(0,query);
        if ( index == -1){
            printf("Contact NOT found .\n");

        }
        else{
            printf("Found: Name: %s Number: %s\n",names[index],phones[index]);

        }
        break;
         
        case 4:
        printf(" Displaying all contacts \n ");
        displayContacts();
        break;

        case 5:
        deleteContact();
        break;

        case 6:
        printf("Exiting contact book . ThankYou AYUSh!\n");
        return 0;
        
        default:
        printf("Invalid choice . TRY AGAIN.");





     }
    }
}

