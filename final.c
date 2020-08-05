#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

struct student {
	int id;
	char fname[50];
	char lname[50];
	char address[50];
	char contact[10];
};

void login();
void menu();
void see();
void create();
void search();
void update();
void del();
void setscreen() {
	system("cls");
    system("color 9a");
}

void main() {
	setscreen();
	
    printf("\t|______________________________________________________|\n");
    printf("\t|                                                      |\n");
    printf("\t|**WELCOME TO C PROGRAM STUDENT INFO'S SYSTEM PROJECT**|\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|   	        DEVELOPED BY NISHANT69                 |\n");
    printf("\t|______________________________________________________|\n");
    sleep(1);
    login();
}

void login() {
	setscreen();
	
	char username[20], password[20];
	printf("\t\t\tLog in\n\n");
	printf("Enter username: ");
	scanf("%s",username);
	printf("Enter password: ");
	scanf("%s",password);
	if (strcmp(username, "Admin") == 0 && strcmp(password, "pass") == 0) {
		printf("\n\n\n\n\n\t\t\tSuccessfully logged in!!!\n");
		sleep(1);
		menu();
	}
	else {
		printf("Access denied\n");
		main();
	}
}

void menu() {
	setscreen();
	
	printf("1.See all students info\n\n");
	printf("2.Add a student's info\n\n");
	printf("3.Search specific student's info\n\n");
	printf("4.Update existing student's info\n\n");
	printf("5.Delete existing student's info\n\n");
	printf("6.Exit\n\n");
	
	A:switch(getch()) {
		case '1': see();break;
		case '2': create();break;
		case '3': search();break;
		case '4': update();break;
		case '5': del();break;
		case '6': exit(0);break;
		default: {
			printf("Invalid input!\n\n");
			goto A;
		}
	}
}

void see() {
	setscreen();
	
	struct student st[100];
		FILE *fp;
		int i=0;
		printf("\n| ID \t| First Name \t| Last Name \t| Address \t| Contact \t|\n");
		fp=fopen("students.txt","r");
		while(!feof(fp)){
			fscanf(fp,"\n%d\t%s\t%s\t%s\t%s\t",&st[i].id,&st[i].fname,&st[i].lname,&st[i].address,st[i].contact);
			printf("\n| %d \t| %s \t| %s \t| %s \t| %s \t|",st[i].id,st[i].fname,st[i].lname,st[i].address,st[i].contact);
			i++;
		}
		fclose(fp);
		
		printf("\n\nPress any key to go back.\n");
		
		getch();
		menu();
}

void create() {
	setscreen();
	
	struct student s;
	printf("id: ");
	scanf("%d",&s.id);
	printf("First name: ");
	scanf("%s",s.fname);
	printf("Last name: ");
	scanf("%s",s.lname);
	printf("Address: ");
	scanf("%s",&s.address);
	printf("Mobile number: ");
	scanf("%s",s.contact);
	FILE *p;
	p=fopen("students.txt","a");
	fprintf(p,"\n%d\t",s.id);
	fprintf(p,"%s\t",s.fname);
	fprintf(p,"%s\t",s.lname);
	fprintf(p,"%s\t",s.address);
	fprintf(p,"%s\t",s.contact);
	fclose(p);
	
	printf("\n\nAdded successfully. Press any key to go back.\n");
	
	getch();
	menu();
}

void search() {
	setscreen();
	
	struct student st[100];
	FILE *search;
	int i=0,j,choice,fnf=0;
	search =  fopen("students.txt","r");
	printf("Enter id to search: ");
	scanf("%d",&choice);
	
	printf("\n| ID \t| First Name \t| Last Name \t| Address \t| Contact \t|\n");
	while(!feof(search)){
		fscanf(search,"\n%d\t%s\t%s\t%s\t%s\t",&st[i].id,&st[i].fname,&st[i].lname,&st[i].address,&st[i].contact);
		i++;
	}
	fclose(search);
	for(j=0;j<i;j++) {
		if(st[j].id == choice) {
			printf("\n| %d \t| %s \t| %s \t| %s \t| %s \t|",st[j].id,st[j].fname,st[j].lname,st[j].address,st[j].contact);
			fnf++;
		}
	}
	
	if(fnf==0) {
		printf("ID not found.");
	}
	
	printf("\n\nPress any key to go back.\n");
	getch();
	menu();
}

void update() {
	setscreen();
	
	struct student st[100];
	FILE *read, *write;
	int i=0,j,choice,fnf=0;
	read =  fopen("students.txt","r");
	printf("Enter id to update: ");
	scanf("%d",&choice);
	
	while(!feof(read)){
		fscanf(read,"\n%d\t%s\t%s\t%s\t%s\t",&st[i].id,&st[i].fname,&st[i].lname,&st[i].address,&st[i].contact);
		i++;
	}
	fclose(read);
	for(j=0;j<i;j++) {
		if(st[j].id == choice) {
			printf("id: ");
			scanf("%d",&st[j].id);
			printf("First name: ");
			scanf("%s",st[j].fname);
			printf("Last name: ");
			scanf("%s",st[j].lname);
			printf("Address: ");
			scanf("%s",&st[j].address);
			printf("Mobile number: ");
			scanf("%s",st[j].contact);
			fnf++;
		}
	}
	
	write =  fopen("students.txt","w");
	for(j=0;j<i;j++){
		fprintf(write,"\n%d\t%s\t%s\t%s\t%s\t",st[j].id,st[j].fname,st[j].lname,st[j].address,st[j].contact);
	}
	fclose(write);
	
	if(fnf==0) {
		printf("ID not found.");
	}
	
	printf("\n\nSuccessfully updated. Press any key to go back.\n");
	getch();
	menu();
}

void del() {
	setscreen();
	
	struct student st[100];
		FILE *read, *write;
		int i=0,j,choice;
		read=fopen("students.txt","r");
		while(!feof(read)){
			fscanf(read,"\n%d\t%s\t%s\t%s\t%s\t",&st[i].id,&st[i].fname,&st[i].lname,&st[i].address,&st[i].contact);
			i++;
		}
		fclose(read);
		
		write =  fopen("students.txt","w");
		printf("Enter id to delete: ");
		scanf("%d",&choice);
		for(j=0;j<i;j++){
		if(st[j].id==choice){
			continue ;
		}
		else {
			fprintf(write,"\n%d\t%s\t%s\t%s\t%s\t",st[j].id,st[j].fname,st[j].lname,st[j].address,st[j].contact);
		}
	}
	fclose(write);
	
	printf("\n\nSuccessfully deleted. Press any key to go back.\n");
	getch();
	menu();
}
