#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXARRAY 50
#define ENDWORD '\n'
#define MENU1 1
#define MENU2 2
#define MENU3 3
#define MENU4 4

/*배열과 getchar()를 사용하여 문자입력을 받고 회문을 판단하는 코드입니다.
 * 배열의 최대 사이즈는 50, 문자입력 끝의 구분은 \n(엔터)로 구분합니다.*/

int submain(void);
/*메뉴출력 함수*/
void menuprint(int select);
/*끝날껀지 물어보는 함수*/
bool menuask(void);
/*대문자를 소문자로 바꿔주는 함수*/
int uppertolower(char *wordarray, int arrlength);
/*알파벳인지 아닌지 알려주는 함수*/
bool isalp(char word);
/*회문판단 함수*/
bool ispairword(char *wordarray, int arrlength);
/*입력한 문자 출력*/
int printword(char *wordarray, int arrlength);

int main(void)
{
    submain();
    return 0;
}

int submain(void)
{
    char originword[MAXARRAY];
    char copyarray[MAXARRAY];
    char temp;
    int index = 0;
    /*배열길이*/
    int arrlength = 0;
    /*알파벳확인 리턴값*/
    bool apcheck = false;
    /*회문확인 리턴값*/
    bool finalcheck = false;
    bool status = false;

    memset(originword, 0, sizeof(originword));
    memset(copyarray, 0, sizeof(copyarray));


START:
	menuprint(MENU1);
        for (index = 0; index < MAXARRAY; index++){
            temp = getchar();
            /*알파벳인지 아닌지 확인,입력 받은값이 알파벳인지 아닌지 확인후, 맞으면 배열에 넣고  엔터를  받으면 입력을 멈춤*/
            if (temp == ENDWORD){
                break;
            }else
            {
                apcheck = isalp(temp);
                if (apcheck == true){
                    originword[index] = temp;
                    copyarray[index] = originword[index]; /*소문자처리를 해줘야할 때 원래의 데이터를 변경하지 않기 위해 하나의 배열을 더 만듦*/
                    arrlength++;
                }else{
                    goto ERROR;
                }
            }
        }
        menuprint(MENU3);
        scanf("%c", &temp);
      
        if (temp == 'Y' || temp == 'y'){
            finalcheck = ispairword(originword, arrlength);
        }else if (temp == 'N' || temp == 'n'){
            uppertolower(copyarray, arrlength);
            finalcheck = ispairword(copyarray, arrlength);
        }
        else{
            goto ERROR;
        }

        printf("입력한 단어: ");
        printword(originword, arrlength);
        if (finalcheck == true){
            printf("회문입니다!\n");
        }else if (finalcheck == false){
            printf("회문이아닙니다. \n");
        }else{
            goto ERROR;
        }
        status = menuask();
         
        if (status == false){
            goto FINISH;
        }else{
            memset(originword, 0, sizeof(originword));
            memset(copyarray, 0, sizeof(copyarray));
	    goto START;
        }

/*잘못된 입력을 받았을시 오류문자 출력과 함께 -1을 반환하며 프로그램 종료*/
ERROR:
    menuprint(MENU2);
    return -1;
FINISH:
    return 0;
}

void menuprint(int select)
{
    if (select == MENU1){
        printf("회문 판독 프로그램 입니다.\n");
        printf("판독하고 싶은 단어를 입력해주세요! 단어를 입력후 엔터를 눌러주세요. 단, 알파벳(영어)만 지원하고 50자 이하여야 합니다.\n");
        printf("단어 입력: ");
    }else if (select == MENU2){
        printf("ERROR. 프로그램을 종료합니다.\n");
    }else if (select == MENU3){
        printf("대문자와 소문자를 구별할까요? 예면 Y, 아니면 N \n");
    }else if (select == MENU4){
        printf("계속진행하시겠습니까? 진행  Y \n ");
    }else{
        /*nothing*/
    }
}

int uppertolower(char *wordarray, int arrlength)
{
    int index = 0;
    if (wordarray == NULL){
        menuprint(MENU2);
    }
    else{
        for (index; index < arrlength; index++){
            if (wordarray[index] >= 65 && wordarray[index] <= 90){
                wordarray[index] = wordarray[index] + 32;
            }else if (wordarray[index] >= 97 && wordarray[index] <= 122){
                /*nothing*/
            }else{
                /*nothing*/
            }
        }
    }
    return 0;
}
bool isalp(char word)
{
    bool check = false;
    if (word >= 65 && word <= 90){
        return true;
    }else if (word >= 97 && word <= 122){
        return true;
    }else{
        return false;
    }
}

bool ispairword(char *wordarray, int arrlength)
{
    int index = 0;
    int mid = 0;
    int compare = 0;
    bool check = false;

    /* 길이에 대한 유효값 확인 후 작업, 유효한 값이 아닐시 강제 종료*/
    if (arrlength <= 0){
        menuprint(MENU2);
        return -1;
    }else{
        mid = (int)(arrlength / 2);
    }

    /*배열에 대한 유효값 확인 후 작업, 유효한 값이 아닐시 강제 종료*/
    if (wordarray == NULL){
        menuprint(MENU2);
        return -1;
    }else{
        check = true;
        for (index; index < mid; index++){
            compare = (arrlength - 1) - index;
            if (wordarray[index] != wordarray[compare]){
                check = false;
                break;
            }
        }
    }
    return check;
}

int printword(char *wordarray, int arrlength)
{

    int index = 0;
    if (wordarray == NULL){
        return -1;
    }else{
        for (index; index < arrlength; index++){
            printf("%c", wordarray[index]);
        }
        printf("\n");
        return 0;
    }
}

bool menuask(void)
{
    bool go = false;
    bool result = false;
    char answer;
    go = true;
    while (go){
        menuprint(MENU4);
        scanf("%c", &answer);
        if (answer == 'Y' || answer == 'y'){
            result = true;
            go = false;
        }else{
            go = false;
        }
    }
    return result;
}
