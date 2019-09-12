/*************************** INCLUDE ***************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>         //basically for uint8_t
#include <stdbool.h>        //basically for bool

/*************************** DEFINE ***************************/
// system defs
#define     ADMIN_PASS      "1234"

// structure defs
#define     MALE            'm'
#define     FEMALE          'f'
#define     MAX_NUM         100
#define     MAX_NAME        100
#define     NULL_NAME       "NULL"

/************************** STRUCTS ***************************/
typedef struct pat{
  char      name[MAX_NAME] ;
  uint8_t   age ;
  char      gender ;
}patient;

typedef struct pat_rec{
  patient* patients[MAX_NUM];
  int      top ;
}patient_record;


/********************** FUNC. PROTOTYPES **********************/
// system interface
char system_panel(void);
char admin_mode(void);
char user_mode(void);
char ask_for_password(void);
char admin_panel(void);
char user_panel(void);

// structure interface
void     init_record( patient_record* );
patient* fill_patient_info( patient* );
int      add_patient_to_record( patient_record*, patient* );
void     view_all_records(patient_record*);
patient* edit_patient_record_by_ID(patient_record*, int);
void     delete_patient_record_by_ID(patient_record*, int);
void     view_patient_record_by_ID(patient_record*, int);
bool     is_null_by_ID(patient_record*, int);

void view_reservations(void);
void reserve_slot(void);
void cancel_reserve(void);

/*************************** GLOBAL ***************************/
patient_record clinic_record;



/**************************** MAIN ****************************/
int main()
{
    init_record(&clinic_record);

    // admin, user or exit
    while(system_panel());



    view_reservations();
    reserve_slot();
    cancel_reserve();
    return 0;

}

/************************** FUNC. DEF **************************/
// system interface functions
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
    printf("4: Delete patient record \n");
    printf("5: Reserve a slot with the doctor \n");
    printf("6: Cancel reservation \n");
    printf("7: Log out \n");

    printf("select[1~7]: ");
    fflush(stdin);
    scanf("%d", &select);
    printf("\n\n");

    switch(select){
        case 1:
            view_all_records(&clinic_record);
            break;

        case 2:
            add_patient_to_record(&clinic_record , fill_patient_info((patient*)malloc(sizeof(patient))) );
            break;

        case 3:
            printf("Enter patient ID: ");
            fflush(stdin);
            scanf("%d", &ID);
            edit_patient_record_by_ID(&clinic_record, ID);
            break;

        case 4:
            printf("Enter patient ID: ");
            fflush(stdin);
            scanf("%d", &ID);
            delete_patient_record_by_ID(&clinic_record, ID);
            break;

        case 5:
            reserve_slot();
            break;

        case 6:
            cancel_reserve();
            break;

        case 7:
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
            view_patient_record_by_ID( &clinic_record, ID);
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


// structure interface functions

void init_record(patient_record* p_r){
    p_r->top = 0 ;
}

patient* fill_patient_info(patient *patient_ptr){
    printf("\n\n");
    printf("Enter patient name: ");
    fflush(stdin);
    scanf("%[^\n]s", patient_ptr->name);

    printf("Enter patient age: ");
    fflush(stdin);
    scanf("%d", &(patient_ptr->age));

    printf("Enter patient gender (m/f) : ");
    fflush(stdin);
    scanf("%c", &(patient_ptr->gender));
    return patient_ptr;
}

int add_patient_to_record(patient_record *record , patient *patient_ptr){
    int ID = record->top ;
    record->patients[record->top] = patient_ptr;
    record->top++;
    printf("patient record added at ID: %d \n", ID);
    return ID;
}

void view_all_records(patient_record *record){
    int i , num = record->top;
    printf("viewing %d records \n", num);
    printf("%-4s  %-30s  %-4s  %s \n", "ID", "NAME", "AGE", "GENDER");
    for(i = 0; i<num; i++){
        if(is_null_by_ID(record, i))  continue;
        printf("%-4d  %-30s  %-4d  %c \n", i, record->patients[i]->name, record->patients[i]->age, record->patients[i]->gender);
    }
    printf("\n\n");
}

patient* edit_patient_record_by_ID(patient_record *record, int ID){
    if(is_null_by_ID(record, ID)){
        printf("there is not patient with this ID \n");
        return;
    }
    record->patients[ID] = fill_patient_info(record->patients[ID]);
    printf("patient record edited \n");
    return record->patients[ID];
}
void delete_patient_record_by_ID(patient_record *record, int ID){
    if(is_null_by_ID(record, ID)){
        printf("there is not patient with this ID \n");
        return;
    }
    strncpy(record->patients[ID]->name , NULL_NAME , MAX_NAME);
}

void view_patient_record_by_ID(patient_record *record, int ID){
    if(is_null_by_ID(record, ID)){
        printf("there is not patient with this ID \n");
        return;
    }
    printf("viewing patient record of ID %d \n", ID);
    printf("%-4s  %-30s  %-4s  %s \n", "ID", "NAME", "AGE", "GENDER");
    printf("%-4d  %-30s  %-4d  %c \n", ID, record->patients[ID]->name, record->patients[ID]->age, record->patients[ID]->gender);
}

bool is_null_by_ID(patient_record *record, int ID){
    return ID >= record->top || !strcmp(NULL_NAME, record->patients[ID]->name );
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
