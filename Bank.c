#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<conio.h>
struct user {
	char name[30];
	char username[30];
	char ac[30];
	char password[30];
	int age;
	float balance;
};
COORD coord= {0,0};
void gotoxy(int x,int y) {
	coord.X=x;
	coord.Y=y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, coord);
}

FILE *fp;
static struct user usr,usr1;
static char filename[30];
void welCome();
void welcomeUser();
void frameset();
void loginoption();
void transaction();
void currentBalance();
void depositBalance(float amnt);
void withdrawBalance(float amnt);
void transferamountresult(float amnt,char usernam[50],char filena[50]);
void changepassword(char passs[30]);
void changephone(char pho[30]);
void registeruser(char pass[30]);
//void choiceGraphs();


int main() {

	system("color 4");

	int choice,continu,bal_choice;
	char cont,cho_sec;
	char username1[30];
	char ac1[30];
	char password1[30];
	time_t now;
	time(&now);

first:
	system("cls");
	welCome();
	frameset();
	gotoxy(40,8);
	loginoption();

	printf("  \nYour Choice : ");
	scanf("%d",&choice);

	if(choice==1) {

		system("cls");
		welCome();
		frameset();

		// Frame Set ends

		gotoxy(50,10);
		printf("Enter Username : ");
		gotoxy(80,10);
		scanf("%s",username1);
		gotoxy(50,11);
		printf("Enter Phone No : ");
		gotoxy(80,11);
		scanf("%s",ac1);
		gotoxy(50,12);
		printf("Enter Password : ");
		gotoxy(80,12);
		scanf("%s",password1);


		strcpy(filename,username1);
		fp=fopen(strcat(filename,".dat"),"r+");
		fread(&usr,sizeof(struct user),1,fp);

		if(fp==NULL) {
			system("cls");
			printf("\n Something Went Wrong On this \n Please try again later");
			printf("\n Do you want to retry once again?(y/n)");
			fflush(stdin);
			scanf("%c",&continu);
			if(continu=='y') {
				system("cls");

				goto first;
			} else {

				exit(0);
			}
			fclose(fp);

		} else if(!strcmp(usr.username,username1)) {
			if(!strcmp(usr.ac,ac1)) {
				if(!strcmp(usr.password,password1)) {
Login:
					fp=fopen(strcat(filename,".dat"),"r+");
					system("cls");
					int bal_choice;
					char cont='y';
					char continu='y';
					char username2[30];
					int cho_sec;
					welcomeUser();
					gotoxy(56,3);
					printf("WELCOME %s",username1);
					gotoxy(50,4);
					printf("%s",ctime(&now));




					frameset();
					transaction();
					printf("\n Your Choice : ");
					scanf("%d",&bal_choice);
					if(bal_choice==1) {
						frameset();



						currentBalance();
						fclose(fp);
						gotoxy(50,13);
						printf("Do you want to continue the transcation?(y/n)");
						fflush(stdin);
						scanf("%c",&continu);
						if(continu=='y') {
							system("cls");

							goto Login;
						} else {

							exit(0);
						}

					} else if(bal_choice==2) {
						float amount;
						char nn[30],acn[30];
						gotoxy(50,11);
						printf("Your name : ");
						scanf("%s",nn);
						gotoxy(50,12);
						printf("Your Phone : ");
						scanf("%s",acn);
						gotoxy(50,13);
						printf("Enter Amount : ");
						scanf("%f",&amount);

						fp=fopen(strcat(nn,".dat"),"r+");


						if(amount>0) {
							fread(&usr,sizeof(struct user),1,fp);
							if(!strcmp(acn,usr.ac)) {
								depositBalance(amount);
							} else {
								printf("\n account number not matched...");
							}
							fclose(fp);


							gotoxy(50,14);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;

							} else {
								fclose(fp);
								exit(0);
							}
						} else {
							gotoxy(50,14);
							printf("Your Money Cannot Be Deposited  ");
							gotoxy(50,15);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;
							} else {
								fclose(fp);
								exit(0);
							}
						}
					} else if(bal_choice==3) {
						float amount;
						char nn[30],acn[30];
						gotoxy(50,11);
						printf("Your name : ");
						scanf("%s",nn);

						gotoxy(50,12);
						printf("Your Ac No : ");
						scanf("%s",acn);

						gotoxy(50,13);
						printf("Enter Amount : ");
						scanf("%f",&amount);


						fp=fopen(strcat(nn,".dat"),"r+");



						if(usr.balance>amount) {

							fread(&usr,sizeof(struct user),1,fp);
							if(!strcmp(acn,usr.ac)) {
								withdrawBalance(amount);
							} else {
								printf("\n account number not matched...");
							}
							fclose(fp);


							gotoxy(50,15);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;

							} else {
								fclose(fp);
								exit(0);
							}
						} else if(amount<10) {
							gotoxy(50,12);
							printf("Minimum Withdrawn value is 10 ");
							gotoxy(50,35);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;
							} else {
								fclose(fp);
								exit(0);
							}
						} else {
							gotoxy(50,12);
							printf("Your Money Cannot Be Withdrawed  ");
							gotoxy(50,15);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;
							} else {
								fclose(fp);
								exit(0);
							}
						}
						fclose(fp);
					}

					else if(bal_choice==4) {
						char username2[30],acn[30];
						float amount;



						gotoxy(50,11);
						printf("Enter Username:\t");
						scanf("%s",username2);
						
						gotoxy(50,12);
						printf("Enter Ac No:\t");
						scanf("%s",acn);
						
						gotoxy(50,13);
						printf("Enter Amount :\t");
						scanf("%f",&amount);
						strcpy(filename,username2);
						fp = fopen(strcat(filename,".dat"),"r+");
						if(fp == NULL) {
							gotoxy(50,15);
							printf("Account number not registered");
							gotoxy(50,16);
							printf("Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",&cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto Login;

							} else {
								fclose(fp);
								exit(0);
							}
						}



						else {
							fread(&usr1,sizeof(struct user),1,fp);

							fclose(fp);
							gotoxy(50,14);
							if(amount > usr.balance) {
								printf("Insufficient balance");
								gotoxy(50,15);
								printf("Do you want to continue the Transaction?(y/n)");

								fflush(stdin);
								scanf("%c",&cont);
								if(cont=='y') {
									system("cls");
									fclose(fp);
									goto Login;
								} else {
									fclose(fp);
									exit(0);
								}
							} else {


								fp = fopen(filename,"w+");
								usr1.balance += amount;
								fwrite(&usr1,sizeof(struct user),1,fp);

								fclose(fp);
								if(fwrite != NULL) {
									
									fclose(fp);
									fread(&usr,sizeof(struct user),1,fp);
									if(!strcmp(acn,usr.ac)) {
										transferamountresult(amount,username2,filename);
									} else {
										printf("\n account number not matched...");
									}
									

									fclose(fp);

									gotoxy(50,15);
									printf("Do you want to continue the Transaction?(y/n)");
									fflush(stdin);
									scanf("%c",&cont);
									if(cont=='y') {
										system("cls");
										fclose(fp);
										goto Login;

									} else {
										fclose(fp);
										exit(0);
									}
								} else {
									gotoxy(50,15);
									printf("Transformation Unsucessful ......");
									gotoxy(50,16);
									printf("Do you want to continue the Transaction?(y/n)");
									fflush(stdin);
									scanf("%c",&cont);
									if(cont=='y') {
										system("cls");
										fclose(fp);
										goto Login;
									} else {
										fclose(fp);
										exit(0);
									}

								}


							}
						}
					} else if(bal_choice==5) {
setting:
						system("cls");
						welcomeUser();
						gotoxy(56,3);
						printf("WELCOME %s",username1);
						gotoxy(50,4);
						printf("%s",ctime(&now));
						frameset();

						gotoxy(40,8);
						printf("\n Setting:\n");
						printf("\n 1. Change Password");
						printf("\n 2. Change phone Number");
						printf("\n 3. Delete Account");
						printf("\n 4. Go Back\n");

						printf("\n Your Choice : ");
						scanf("%d",&cho_sec);
						if(cho_sec==1) {
							char pword[30],newpass[30],nn[30],acn[30];
							gotoxy(50,11);
							printf("Your name : ");
							scanf("%s",nn);
							
							gotoxy(50,12);
							printf("Your Ac No : ");
							scanf("%s",acn);

							gotoxy(50,13);
							printf("Enter Current password : ");
							scanf("%s",pword);
							fp=fopen(strcat(nn,".dat"),"r+");
							fread(&usr,sizeof(struct user),1,fp);
							if(!strcmp(usr.password,pword)) {
								
									if(!strcmp(acn,usr.ac)) {
										changepassword(newpass);
									} else {
										printf("\n account number not matched...");
									}
								
								fclose(fp);
								fp=fopen(filename,"r+");

								gotoxy(50,16);
								printf("Do you want to check?(y/n)");
								fflush(stdin);
								scanf("%c",&cont);
								if(cont=='y') {
									system("cls");
									fclose(fp);
									goto Login;
								} else {
									fclose(fp);
									exit(0);
								}
							}

						} else if(cho_sec==2) {
							char ph[30],phone[30],nn[30],acn[30];
							gotoxy(50,11);
							printf("Enter Your name : ");
							gotoxy(80,11);
							scanf("%s",nn);
							
							gotoxy(50,12);
							printf("Your Ac No : ");
							scanf("%s",acn);

							gotoxy(50,13);
							printf("Enter Current Phone number : ");
							gotoxy(80,13);
							scanf("%s",phone);

							fp=fopen(strcat(nn,".dat"),"r+");
							fread(&usr,sizeof(struct user),1,fp);
							gotoxy(80,14);
							printf("Your Number : %s",usr.ac);
							if(!strcmp(usr.ac,phone)) {
								if(!strcmp(acn,usr.ac)) {
										changephone(ph);
									} else {
										printf("\n account number not matched...");
									}
								
								fclose(fp);
								fp=fopen(filename,"r+");

								gotoxy(50,16);
								printf("Do you want to check?(y/n)");
								fflush(stdin);
								scanf("%c",&cont);
								if(cont=='y') {
									system("cls");
									fclose(fp);
									goto Login;
								} else {
									fclose(fp);
									exit(0);
								}
							}
						} else if(cho_sec==3) {
							char pwd[30],phone[30],nn[30];
							gotoxy(50,11);
							printf("Enter your name : ");
							scanf("%s",nn);

							gotoxy(50,12);
							printf("Enter Password : ");
							scanf("%s",pwd);

							fp=fopen(strcat(nn,".dat"),"r+");
							fread(&usr,sizeof(struct user),1,fp);
							if(!strcmp(usr.password,pwd)) {
								fclose(fp);
								if(remove(nn)==0) {

									gotoxy(50,13);
									printf("%s Account deleted Successfully,",nn);
									gotoxy(50,14);
									printf("Do You Want to check?(y/n)");
									fflush(stdin);
									scanf("%c",cont);
									if(cont=='y') {

										goto Login;
									} else {
										exit(0);
									}
								} else {
									gotoxy(50,13);
									printf("Error Deleting the Account %s \n",nn);
									sleep(3);
									goto first;
								}
							}

						} else if(cho_sec==4) {
							goto Login;
						} else {
							gotoxy(50,16);
							printf("\n This is Wrong Choice ");
							gotoxy(50,17);
							printf("\n Do you want to continue the Transaction?(y/n)");
							fflush(stdin);
							scanf("%c",cont);
							if(cont=='y') {
								system("cls");
								fclose(fp);
								goto setting;
							} else {
								fclose(fp);
								exit(0);
							}
						}

					}
					if(bal_choice==6) {
						goto first;
					} else {
						gotoxy(50,13);
						printf("You Choosed a Wrong Option !!");
						gotoxy(50,14);
						printf("Do you want to continue?(y/n)");
						fflush(stdin);
						scanf("%c",&cont);
						if(cont=='y') {
							fclose(fp);
							goto Login;
						} else {
							fclose(fp);
							exit(0);
						}
					}

				} else {
					gotoxy(50,15);
					printf("Wrong Password ");
					gotoxy(50,16);
					printf("Do you want to retry once again?(y/n)");
					fflush(stdin);
					scanf("%c",&continu);
					if(continu=='y') {
						system("cls");
						fclose(fp);
						goto first;
					} else {
						fclose(fp);
						exit(0);
					}
				}
			} else {
				gotoxy(50,15);
				printf("Phone Number Not Matched ");
				gotoxy(50,16);
				printf("Do you want to retry once again?(y/n)");
				fflush(stdin);
				scanf("%c",&continu);
				if(continu=='y') {
					system("cls");
					fclose(fp);
					goto first;
				} else {
					fclose(fp);
					exit(0);
				}

			}

		} else if(strcmp(usr.username,username1)) {
			gotoxy(50,15);
			printf("Username Not Matched ");
			gotoxy(50,16);
			printf("Do you want to retry once again?(y/n)");
			fflush(stdin);
			scanf("%c",&continu);
			if(continu=='y') {
				system("cls");
				fclose(fp);
				goto first;
			} else {
				fclose(fp);
				exit(0);
			}
		}
	} else if(choice==2) {
		char pass[30];
		system("cls");
		welCome();

		loginoption();
		frameset();

		// Frame Set ends

		registeruser(pass);

		strcpy(filename,usr.username);
		fp=fopen(strcat(filename,".dat"),"w");

		if(fp==NULL) {
			gotoxy(50,16);
			printf("We can't found your account ! \n Please try again later");
			gotoxy(50,16);
			printf("Do you want to go back to login option?(y/n)");
			fflush(stdin);
			scanf("%c",&cont);
			if(cont=='y') {
				fclose(fp);
				goto first;
			} else {
				fclose(fp);
				exit(0);
			}
		} else {
			if(!strcmp(usr.password,pass)) {
				fwrite(&usr,sizeof(struct user),1,fp);
				fclose(fp);
				gotoxy(50,16);
				printf("Your account has been regester.");
				gotoxy(50,17);
				printf("Do you want to go back to login option?(y/n)");
				fflush(stdin);
				scanf("%c",&cont);
				if(cont=='y') {
					fclose(fp);
					goto first;
				} else {
					fclose(fp);
					exit(0);
				}
			} else {
				Beep(1000,500);
				gotoxy(50,16);
				printf("You Have Entered Different Password ");
				gotoxy(50,17);
				printf("Do you want to go back to login option?(y/n)");
				fflush(stdin);
				scanf("%c",&cont);
				if(cont=='y') {
					goto first;
				} else {
					fclose(fp);
					exit(0);
				}
			}
		}
		fclose(fp);
	}

	else if(choice==3) {
		exit(0);
	}

	else {
		gotoxy(50,13);
		printf("Wrong Choice\n");
		gotoxy(50,14);
		printf("Do you want to go back to login option?(y/n)");
		fflush(stdin);
		scanf("%c",&cont);
		if(cont=='y') {
			fclose(fp);
			goto first;
		} else {
			fclose(fp);
			exit(0);
		}
		goto first;
	}
	fclose(fp);
	return 0;
}
void welCome() {
	printf("	 _________________________________________________________________________________________________________\n");
	printf("	|                                                                                                         |\n");
	printf("	|                                                                                                         |\n");
	printf("	|                                           WELCOME TO BANK                                               |\n");
	printf("	|                                                                                                         |\n");
	printf("	|_________________________________________________________________________________________________________|\n");
}

void loginoption() {
	printf("\n Login Options: \n");
	printf("\n 1. Login to the Account ");
	printf("\n 2. Register an Account ");
	printf("\n 3. Exit\n");
}


void frameset() {
	for(int i=6; i<=20; i++) {
		gotoxy(30,i);
		printf("|");
	}
}


void welcomeUser(void) {
	printf("   	 _________________________________________________________________________________________________________\n");
	printf("	|                                                                                                         |\n");
	printf("	|                                                                                                         |\n");
	printf("	|                                                                                                         |\n");
	printf("	|                                                                                                         |\n");
	printf("	|_________________________________________________________________________________________________________|\n");


}
void transaction() {
	gotoxy(0,8);
	printf(" Transaction : ");
	printf("\n 1. Balance Inquiry ");
	printf("\n 2. Balance Deposit ");
	printf("\n 3. Balance Withdraw ");
	printf("\n 4. Balance Transfer ");
	printf("\n 5. Setting ");
	printf("\n 6. Log out \n");
}
void currentBalance() {
	fread(&usr,sizeof(struct user),1,fp);
	gotoxy(50,11);
	printf("Your Current Balance is %.2f",usr.balance);
}
void depositBalance(float amnt) {
	fread(&usr,sizeof(struct user),1,fp);
	usr.balance+=amnt;
	gotoxy(50,12);
	printf("Successfully Deposited Rs %.2f",amnt);
	gotoxy(50,13);
	printf("Current Balance = Rs %.2f",usr.balance);

	fseek(fp, -(long)sizeof(struct user), SEEK_CUR);
	fwrite(&usr,sizeof(struct user),1,fp);
}
void withdrawBalance(float amnt) {
	fread(&usr,sizeof(struct user),1,fp);
	usr.balance-=amnt;
	gotoxy(50,13);
	printf("Successfully Withdrawal Rs %.2f",amnt);
	gotoxy(50,14);
	printf("Current Balance = Rs %.2f",usr.balance);

	fseek(fp, -(long)sizeof(struct user), SEEK_CUR);
	fwrite(&usr,sizeof(struct user),1,fp);
}
void transferamountresult(float amnt,char usernam[50],char filena[50]) {
	gotoxy(50,13);
	printf("You have succesfully transfered Rs.%.2f to %s",amnt,usernam);
	strcpy(filena,usr.username);
	fp = fopen(strcat(filena,".dat"),"w");
	usr.balance -= amnt;
	gotoxy(50,14);
	printf("Current Balance = Rs %.2f",usr.balance);
	fwrite(&usr,sizeof(struct user),1,fp);
}
void changepassword(char passs[30]) {
	gotoxy(50,14);
	printf("Enter Your new Password : ");
	scanf("%s",passs);
	strcpy(usr.password,passs);

	fseek(fp, -(long)sizeof(struct user), SEEK_CUR);
	fwrite(&usr,sizeof(struct user),1,fp);

	fclose(fp);
	fp=fopen(filename,"r+");

	if(fwrite!=NULL) {
		gotoxy(50,15);
		printf("Password Changed Successfully");
	} else {
		gotoxy(50,15);
		printf("Something went wrong on this !!!!!!");
	}
}
void changephone(char pho[30]) {
	gotoxy(50,13);
	printf("Enter Your new Phone Number: ");
	gotoxy(80,13);
	scanf("%s",pho);
	strcpy(usr.ac,pho);

	fseek(fp, -(long)sizeof(struct user), SEEK_CUR);
	fwrite(&usr,sizeof(struct user),1,fp);

	fclose(fp);
	fp=fopen(filename,"r+");

	if(fwrite!=NULL) {
		gotoxy(50,15);
		printf("Phone number Changed Successfully");
	} else {
		gotoxy(50,14);
		printf("Something went wrong on this !!!!!!");
	}
}
void registeruser(char pass[30]) {
	gotoxy(50,10);
	printf("Enter Username : ");
	gotoxy(80,10);
	scanf("%s",usr.username);
	gotoxy(50,11);
	printf("Enter Phone NO : ");
	gotoxy(80,11);
	scanf("%s",usr.ac);
	gotoxy(50,12);
	printf("Enter Password :");
	gotoxy(80,12);
	scanf("%s",&usr.password);
	gotoxy(50,13);
	printf("ReType Password :");
	gotoxy(80,13);
	scanf("%s",pass);
	gotoxy(50,14);
	printf("Deposit The Amount:");
	gotoxy(80,14);
	scanf("%f",&usr.balance);
}