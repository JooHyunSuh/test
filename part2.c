#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXARRAY 50
#define ENDWORD '.'
#define MENU1    1
#define MENU2    2
#define MENU3    3
#define MENU4    4

/*배열과 getchar()를 사용하여 문자입력을 받고 회문을 판단하는 코드입니다.
 * 배열의 최대 사이즈는 50, 문자입력 끝의 구분은 . 으로 구분합니다.*/

int submain(void);
void menuprint(int select);
int uppertolower(char *copyarray, int arrlength);
int ispairword(char *copyarray, int arrlength);


int main(void)
{
    submain();
    return 0;
}

int submain(void)
{
    char originword[MAXARRAY];
    char copyarray[MAXARRAY];
    char temp = '0';
    int index = 0;
    int arrlength = 0;
    bool apcheck = false;

    memset(originword,0,sizeof(originword);
    memset(copyarray,0,sizeof(copyarray);
    
    while(true){
	menuprint(MENU1);

        for(index; index < MAXARRAY; index++){
	    temp = getchar();

	    if(temp == ENDWORD){
		break;
	    }

	    apcheck = isalph(temp);
	    if(apcheck==true){
		originword[index]=temp;
		copyarray[index]=originword[index]; /*소문자처리를 해줘야할 때 원래의 데이터를 건드리지 않기 위해 하나의 배열을 더 만듦*/
	    }else{
		menuprint(MENU2);
		break;
	    }
	}
        
	menuprint(MENU3);
	temp = getchar();
        arrlength = sizeof(originword);

	if(temp == 'Y' || temp == 'y' ){
	    ispairword(originword,arrlength);
	}else if(temp == 'N' || temp == 'n'){
	    uppertolower(copyarray,arrlength);
	    ispairword(copyarray,arrlength);
	}else{
	    menuprint(MENU2);
	    break;
	}

	menuprint(MENU4);
        temp = getchar();
        if(temp == 'Y' || temp == 'y' ){
	     continue;
	}else if(temp == 'N' || temp == 'n'){
             break;
	}else{
             menuprint(MENU2);
	     break;
	}	
    }  
}

void menuprint(int select)
{
    if(select == MENU1){
	printf("회문 판독 프로그램 입니다.\n");
	printf("판독하고 싶은 단어를 입력해주세요! 단, 영어 알파벳만 지원하고 50자 이하여야 하며 단어의 끝에는 .(온점)이 들어가야 합니다.\n");
	printf("단어 입력: ");
    }else if(select == MENU2){
	printf("ERROR. 프로그램을 종료합니다.\n");
    }else if(select == MENU3){
        printf("대문자와 소문자를 구별할까요? 예면 Y, 아니면 N \n");
    }else if(select == MENU4){
	printf("계속진행하시겠습니까? 진행  Y, 종료 N \n ");
    }else{
	/*nothing*/
    }
}

int uppertolower(char *wordarray,int arrlength)
{
  int index = 0;
  if(wordarray == NULL){
      menuprint(MENU2);
      break;
  }else{
      for(index; index < arrlength; index++){
	if(wordarray[index] >= 65 && wordarray[index] <= 90){
	    wordarray[index] = wordarray[index] + 32;
	}else if(wordarray[index] >= 97 && wordarray[index]<=122 ){
	    /*nothing*/
	}else{
	    printf("불가불가");
	    break;
	}
      }
  }
  return 0;
}

int ispairword(char *wordarray, int arrlength)
{
  int index = 0;
  int mid = 0;
  if(arrlength > 0){
     mid = arrlength/2;
  }
  if(wordarray == NULL){
      menuprint(MENU2); 
      break; 
  }else{
      for(index; index < half; index++){
	  if(wordarray[index] != wordarray[index]){
	    printf("회문이 아닙니다.");
	    break;
	  }else{
	    printf("회문입니다.");
	  }
      }
  }
  return 0;
}
