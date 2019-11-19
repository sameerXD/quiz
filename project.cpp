#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
using namespace std;



//functiosns
void userlogin(void);
int reg();
void instruction(void);
int warm_up();
void quiz(void);
void pattern(int n);
void question_bank();
void answer();


//for login 
struct user{
    char username[10];
    char password[10];
}*pUser;


int main(){
	int i;
	printf("\n\t\t*********************************************\t\t\n");
	printf("\t\t*                                           *\t\t\n");                                            
	printf("\t\t*                                           *\t\t\n");  
	printf("\t\t*                                           *\t\t\n");    
	printf("\t\t*            WELCOME TO THE QUIZ            *\t\t\n");  
	printf("\t\t*                                           *\t\t\n");  
	printf("\t\t*                                           *\t\t\n");  
	printf("\t\t*                                           *\t\t\n");  
	printf("\t\t*********************************************\t\t\n");
    userlogin ( );
    

	
	
	return 0;
}

int reg(){
	struct userreg{
		char name[20];
		int age;
		char father_name[20];
		char email_id[60];
		char qualification[40];
	};
	struct userreg n1;
	char pass[40],email[40];
	printf("\n\t\tWELCOME TO THE REGESTRATION PANEL\t\t\n");
	printf("ENTER YOUR NAME\n");
	scanf("%s",&n1.name);
	printf("ENTER YOUR AGE\n");
	scanf("%d",&n1.age);
	printf("ENTER YOUR FATHERS NAME\n");
	scanf("%s",&n1.father_name);
	printf("ENTER THE EMAIL ID YOU WANT TO CREATE\n");
	scanf("%s",&n1.email_id);
	printf("PLEASE TELL US YOUR QUALIFICATIONS ARE YOU A STUDENT OR A PROFESSIONAL\n");
	scanf("%s",&n1.qualification);           
	printf("YOU HAVE BEEN SUCCESSFULLY REGISTERED!!\n");
	FILE *registr;
	char fname[20]="reg.txt";
	registr=fopen("reg.txt","a+");
	fprintf(registr,"\n----------------------------registration details----------------------------------\n");
	fprintf(registr,"NAME=%s  ",n1.name);
	fprintf(registr,"AGE=%d  ",n1.age);
	fprintf(registr,"FATHER NAME=%s  ",n1.father_name);
	fprintf(registr,"EMAIL=%s  ",n1.email_id);
	fprintf(registr,"QUALIFICATION=%s  ",n1.qualification);
	fclose(registr);

}
    


void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10];int i;char c;

    pUser=(struct user *)malloc(sizeof(struct user));

    printf("1. Login Through An Existing Account\n2. Create New account\n");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",uName);
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        //accessUser();reg()
                        instruction();
                    }
                }
            }
            
            printf("\n----------------------------GAME TERMINATION------------------------\n");
            break;

        case 2:
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
                reg();
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
            }while(c=='Y'||c=='y');
            
            break;
    }
    free ( pUser);//free allocated memory
    fclose(fp);
    userlogin ( );
}

void instruction(void){
	int i,n;
	
	printf("1. to read instruction \n");
	printf("2. to continue to warm_up round 1\n");
	scanf("%d",&i);
	switch(i){
		case 1:
		      printf("----------------INSTRUCTIONS---------------------\n");
	          printf("YOU HAVE EXACTLY TWO ROUNDS IN THIS GAME.\n");
		      printf("\t1. ROUND HAS 5 QUESTIONS WHICH IS CALLED WARM-UP ROUND.\n");
		      printf("     \tYOU HAVE TO ANSWER 3 RIGHT QUESTIONS MINIMUM TO PROCEED.\n");
		       printf("\t2. ROUND HAS 10 QUESTIONS WHICH IS CALLED QUIZ ROUND.\n");
		       printf("    YOU WILL BE ASKED 10 QUESTIONS CONSICUTIVELY \n\tFOR EACH CORRECT ANSWER YOU WILL BE REWARDED $100,000.\n");
		       printf("    YOUR GAME WILL END AS YOU COLLECT $1,000,000.\n");
		       printf("\t1. to continue with the game \n");
		       printf("\t2. to exit the game \n");
		       scanf("%d",&n);
		       if(n==1){
		       	warm_up();
			   }
			   if(n==2){
		       	printf("-------------THANKU FOR BEING HERE---------------------\n");
		       	getch();
		       	exit(1);
			   }
			   else{
			   	printf("NO SUCH OPTION \n-----------------------RETURNING TO THE INSTRUCTION------------------------\n");
			   	instruction();
			   }
		       break;
		       
		case 2: warm_up();
	             break;
	    default: printf("no such option\n");
	}
	
}

int warm_up(){
	
	int s=0;
	system("cls");
	printf("Question 1: Who has been appointed as the new chairman of the Central Board of Indirect taxes and Customs ?\n(A) John Joseph\n(B) Vanaja N. Sarna\n(C) Mahender Singh\n(D) S Ramesh\n");

if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");s++;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is S Ramesh");
		       getch();
		       
			}
		
    	printf("Question 2: Who has been appointed as the acting Chairman of the Union Public Service Commission (UPSC)?\n(A) Arvind Saxena\n(B) Sudha Jain\n(C) Kirti Kumar\n(D) Omi Agrawal\n");			
        if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");s++;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Arvind Saxena");
		       getch();
		       
			}


printf("Question 3: Pappu Karki, the popular Kumaoni folk singer has passed away. He was a native of which state?\n(A) Jammu & Kashmir\n(B) Himachal Pradesh\n(C) Uttarakhand\n(D) Assam\n");
 if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");s++;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Uttarakhand");
		       getch();
		       
			}
        printf("Question 4: India’s first-ever national police museum will be established in which city?\n(A) Chennai\n(B) Delhi\n(C) Nagpur\n(D) Kolkata\n");
				 if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");s++;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Delhi");
		       getch();
		       
			}	
				printf("Question 5: The Central Vigilance Commission (CVC) is in news for appointing Sharad Kumar as new Vigilance Commissioner. As per which committee’s recommendations, the CVC was set up?\n(A) Nittoor Srinivasa Rau committee\n(B) Tejendra Mohan Bhasin committee\n(C) KV Chowdary committee\n(D) K. Santhanam committee\n");
		 if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");s++;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is K. Santhanam committee");
		       getch();
		       
			}
			printf("\n                     YOUR DUM SCORE IS %d\n",s);
		if(s>=3){
	printf("          PASSED\n              BUT DONT BE TOO OPTIMISTIC\n           YOU HAVE JUST STARTED THE DARK LAND\n");
   quiz();
}
else{
	printf("----HAHA FAILED----\n");
	instruction();
}
return 0;

}
void pattern(int n) 
{ 
    int i,j; 
  
    // This is upper half of pattern 
    for (i=1; i<=n; i++) 
    { 
        for (j=1; j<=(2*n); j++) 
        { 
            // Left part of pattern 
            if (i>(n-j+1)) 
                printf(" "); 
            else
                printf("*"); 
                  
            // Right part of pattern 
            if ((i+n)>j) 
                printf(" "); 
            else
                printf("*"); 
        } 
        printf("\n"); 
    } 
      printf("\n----------------------------\n");
      printf("    WELCOME TO THE QUIZ");
      printf("\n----------------------------\n");
    // This is lower half of pattern 
    for (i=1; i<=n; i++) 
    { 
        for (j=1; j<=(2*n); j++) 
        {  
            // Right Part of pattern 
            if (i<j) 
                printf(" "); 
            else
                printf("*"); 
              
            // Left Part of pattern 
            if (i<=((2*n)-j)) 
                printf(" "); 
            else
                printf("*"); 
        } 
        printf("\n"); 
    } 
} 


void question_bank(){
	FILE *qu;
	char filename[20]="question_bank.txt";
	qu=fopen("question_bank.txt","w");
	fprintf(qu,"-------------------QUESTIONS OF QUIZ----------------------\n");
	fprintf(qu,"\n-------------------CONFIDENTIAL----------------------\n");
	fprintf(qu,"\nquestion 1: Which country will host the 45th G7 summit 2019?\n(A) Italy\n(B) Germany\n(C) France\n(D) Canada\nQuestion 2: Which country’s women cricket team has clinched the Asia Cup Twenty-20 tournament 2018?\n(A) South Korea\n(B) Bangladesh\n(C) India\nD) Pakistan\nQuestion 3: Who has won the men’s singles French Open tennis tournament 2018?\n(A) Novak Djokovic\n(B) Dominic Thiem\n(C) Roger Federer\n(D) Rafael Nadal\nQuestion 4: Which country’s football team has won the 2018 Intercontinental Cup football title?\n(A) India\n(B) Sri Lanka\n(C) Kenya\n(D) Argentina\nQuestion 5: Shantaram Laxman Naik, who passed away recently, was the former Congress chief of which state?\n(A) Maharashtra\n(B) Goa\n(C) Bihar\n(D) Karnataka\nQuestion 6: The Maratha and The Kesri were the two main newspapers started by which of the following people?\n(A) Lala Lajpat Rai\n(B) Gopal Krishna Gokhale\n(C) Bal Gangadhar Tilak\n(D) Madan Mohan Malviya\nQuestion 7: National emergency arising out of the war, armed rebellion or external aggression is dealt under which of the following articles?\n(A) Article 280\n(B) Article 352\n(C) Article 356\n(D) Article 370\nQuestion 8: Which of the following personalities is considered to be the originator of the Sankhya philosophy?\n(A) Bharat Muni\n(B) Kapil Muni\n(C) Adi Shankaracharya\n(D) Agastya Rishi\nQuestion 9: Which of the following personalities from India is the only winner of a Special Oscar in the history of Indian Cinema so far?\n(A) Mrinal Sen\n(B) Shyam Bengal\n(C) Satyajit Ray\n(D) Mira Nair\nQuestion 10: Mahatma Gandhi founded which of the following newspapers in 1903 at South Africa?\n(A) Indian Opinion\n(B) Harijan\n(C) Indian Speaker\n(D) India News\n\n");
	fclose(qu);
}

void answer(){
		FILE *qu;
	char filename[20]="ANSWERS.txt";
	qu=fopen("ANSWERS.TXT","w");
	fprintf(qu,"-------------------ANSWERS OF QUIZ----------------------\n");
	fprintf(qu,"\n-------------------CONFIDENTIAL----------------------\n");
	fprintf(qu,"\n   Q1>France\n");
	fprintf(qu,"\n   Q2>Bangladesh\n");
	fprintf(qu,"\n   Q3>Rafael Nadal\n");
	fprintf(qu,"\n   Q4>India\n");
	fprintf(qu,"\n   Q5>Goa\n");
	fprintf(qu,"\n   Q6>Bal Gangadhar Tilak\n");
	fprintf(qu,"\n   Q7>Article 352\n");
	fprintf(qu,"\n   Q8>Kapil Muni\n");
	fprintf(qu,"\n   Q9>Satyajit Ray\n");
	fprintf(qu,"\n   Q10>Indian Opinion\n");
	fclose(qu);
}

void quiz(void){
	 pattern(7); 
		int s=0;
	system("cls");
	question_bank();
	answer();
	answer();
	printf("question 1: Which country will host the 45th G7 summit 2019?\n(A) Italy\n(B) Germany\n(C) France\n(D) Canada\n");

if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is france\n");
		       getch();
		       
			}
		
    	printf("Question 2: Which country’s women cricket team has clinched the Asia Cup Twenty-20 tournament 2018?\n(A) South Korea\n(B) Bangladesh\n(C) India\nD) Pakistan\n");			
        if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is bangladesh\n");
		       getch();
		       
			}


printf("Question 3: Who has won the men’s singles French Open tennis tournament 2018?\n(A) Novak Djokovic\n(B) Dominic Thiem\n(C) Roger Federer\n(D) Rafael Nadal\n");
 if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Rafael Nadal\n");
		       getch();
		       
			}
        printf("Question 4: Which country’s football team has won the 2018 Intercontinental Cup football title?\n(A) India\n(B) Sri Lanka\n(C) Kenya\n(D) Argentina\n");
				 if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is india\n");
		       getch();
		       
			}	
				printf("Question 5: Shantaram Laxman Naik, who passed away recently, was the former Congress chief of which state?\n(A) Maharashtra\n(B) Goa\n(C) Bihar\n(D) Karnataka\n");
		 if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is goa\n");
		       getch();
		       
			}
				printf("Question 6: The Maratha and The Kesri were the two main newspapers started by which of the following people?\n(A) Lala Lajpat Rai\n(B) Gopal Krishna Gokhale\n(C) Bal Gangadhar Tilak\n(D) Madan Mohan Malviya\n");
		 if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Bal Gangadhar Tilak\n");
		       getch();
		       
			}
				printf("Question 7: National emergency arising out of the war, armed rebellion or external aggression is dealt under which of the following articles?\n(A) Article 280\n(B) Article 352\n(C) Article 356\n(D) Article 370\n");
		 if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is article 352\n");
		       getch();
		       
			}
			printf("Question 8: Which of the following personalities is considered to be the originator of the Sankhya philosophy?\n(A) Bharat Muni\n(B) Kapil Muni\n(C) Adi Shankaracharya\n(D) Agastya Rishi\n");
		 if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is kapil munni\n");
		       getch();
		       
			}
				printf("Question 9: Which of the following personalities from India is the only winner of a Special Oscar in the history of Indian Cinema so far?\n(A) Mrinal Sen\n(B) Shyam Bengal\n(C) Satyajit Ray\n(D) Mira Nair\n");
		 if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is Satyajit Ray\n");
		       getch();
		       
			}
				printf("Question 10: Mahatma Gandhi founded which of the following newspapers in 1903 at South Africa?\n(A) Indian Opinion\n(B) Harijan\n(C) Indian Speaker\n(D) India News\n");
		 if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");s=s+100000;
			getch();
			}
			
				else
		       {printf("\n\nWrong!!! The correct answer is indian opinion\n");
		       getch();
		       
			}
			
			printf("\n                     YOU are going to take home $ %d\n",s);
		if(s==1000000){
	printf("          \n \n                    MILLION DOLLARS BABY!!!!      \n");
printf("\n==============TRANSMITTING AMOUNT TO THE BANK==================\n");
printf("connecting--------\n");
getch();
printf("\n\n             BANK RECIEVED $10,000,000\n");
}
}

