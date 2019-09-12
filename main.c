#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>         //basically for uint8_t

#define     ADMIN_PASS      "1234"


char system_panel(void);
char admin_mode(void);
char user_mode(void);
char ask_for_password(void);
char admin_panel(void);
char user_panel(void);


void view_patient_record(int ID);
void view_all_records(void);
void add_patient_record(void);
void edit_patient_record(void);
void view_reservations(void);
void reserve_slot(void);
void cancel_reserve(void);


int main()
{
    // admin, user or exit
    while(system_panel());

    return 0;
}


char system_panel(void){
    uint8_t select;
    printf("\n\n");
    printf("Choose your access mode: \n");
    printf("1: Admin \n");
    printf("2: User \n");
    printf("3: Exit \n");

    printf("select[1~3]: ");
    fflush(stdin);
    scanf("%d", &select);
    printf("\n\n");

    switch(select){
        case 1:
            admin_mode();
            break;

        case 2:
            user_mode();
            break;

        case 3:
            return 0;       // exit indication
            break;

        default:
            printf("wrong selection :( \n");
    }
    return 1;               //he didn't exit
}

char admin_mode(void){
    // check password
    if (ask_for_password()) printf("Success \n\n");
    else {
        printf("Failed \n\n");
        return 1 ;          // 1 means failed login
    }

    // show admin what he can do
    // and wait until he chooeses to EXIT
    while(admin_panel());
    return 0 ;
}

char user_mode(void){
    // show user what he can do
    // and wait until he chooeses to EXIT
    while(user_panel());

}


char ask_for_password(void){
    char counter = 0 ;
    char password[100] ;

    while(counter < 3){
        printf("Enter password: ");
        scanf("%s", password);
        if( !strcmp(ADMIN_PASS , password ) ) return 1 ;    //strcmp returns 0 if strings match
        counter++ ;
    }
    return 0 ;
}

char admin_panel(){
    uint8_t select;
    int ID ;

    printf("\n\n");
    printf("what do you want to do ? \n");
    printf("1: view patient records \n");
    printf("2: Add new patient record \n");
    printf("3: Edit patient record \n");
    printf("4: Reserve a slot with the doctor \n");
    printf("5: Cancel reservation \n");
    printf("6: Log out \n");

    printf("select[1~6]: ");
    fflush(stdin);
    scanf("%d", &select);
    printf("\n\n");

    switch(select){
        case 1:
            view_all_records();
            break;

        case 2:
            add_patient_record();
            break;

        case 3:
            printf("Enter patient ID: ");
            fflush(stdin);
            scanf("%d", &ID);
            edit_patient_record();
            break;

        case 4:
            reserve_slot();
            break;

        case 5:
            cancel_reserve();
            break;

        case 6:
            return 0;       // exit indication

        default:
            printf("wrong selection :( \n");
    }
    return 1;               //he didn't exit
}



char user_panel(void){
    uint8_t select;
    int ID ;

    printf("\n\n");
    printf("what do you want to do ? \n");
    printf("1: View patient record \n");
    printf("2: View today's reservations \n");
    printf("3: Log out \n");

    printf("select[1~3]: ");
    fflush(stdin);
    scanf("%d", &select);
    printf("\n\n");

    switch(select){
        case 1:
            printf("Enter patient ID: ");
            fflush(stdin);
            scanf("%d", &ID);
            view_patient_record(ID);
            break;

        case 2:
            view_reservations();
            break;

        case 3:
            return 0;       // exit indication

        default:
            printf("wrong selection :( \n");
    }
    return 1;               //he didn't exit
}




void view_patient_record(int ID){
    printf("viewing patient record of ID %d \n", ID);
}

void view_all_records(void){
    printf("viewing all records \n");
}

void add_patient_record(void){
    printf("patient record added \n");
}


void edit_patient_record(void){
    printf("patient record editted \n");
}

void view_reservations(void){
    printf("viewing reservations \n");
}

void reserve_slot(void){
    printf("slot reserved \n");
}

void cancel_reserve(void){
    printf("reservation cancelled \n");
}
