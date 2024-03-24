#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

int notesNum = 0;
int noteLines = 0;


int appendFile(int docNum) {
	FILE *fp = NULL;
	char file_buff[200];
	
	switch (docNum) {
		case 1:
			fp = fopen("doc1.txt", "a");
			break;
		
		case 2:
			fp = fopen("doc2.txt", "a");
			break;
		
		case 3:
			fp = fopen("doc3.txt", "a"); 
			break;
		
		case 4:
			fp = fopen("doc4.txt", "a"); 
			break;
		
		case 5:
			fp = fopen("doc5.txt", "a"); 
			break;
		
		default:
			return -1; 
		break;
		
	}
	
	if (fp == NULL) {
		return -2; 
	}
	
	
	int i;
	
	for (i = 0; ; i++) { 
		
		if (i == 0) {
			fputs("\n", fp);
		}
		

		
		printf("[ %d ] ", notesNum + i + 1);
		scanf("%s", file_buff);
		fflush(stdin);
		
		
		
		if (strcmp(file_buff, "!stop") == 0) {
			
			break;
			
		}
		
		if (i >= 1) {
			fputs("\n", fp);
		}
		
		fputs(file_buff, fp);
		

		
	}
	
	fclose(fp);
	
	return 0;
}

int writeFile(int docNum) {
	FILE *fp = NULL;
	char file_buff[200];
	
	switch (docNum) { 
		case 1:
			fp = fopen("doc1.txt", "w"); 
			break;
		
		case 2:
			fp = fopen("doc2.txt", "w");
			break;
		
		case 3:
			fp = fopen("doc3.txt", "w"); 
			break;
		
		case 4:
			fp = fopen("doc4.txt", "w");
			break;
		
		case 5:
			fp = fopen("doc5.txt", "w");
			break;
		
		default:
			return -1;
		break;
		
	}
	
	if (fp == NULL) {
		return -2; 
	}
	
	
	int i;

	for (i = 0; ; i++) { 
		
		
		printf("[ %d ] ", i + 1);
		scanf("%s", file_buff);
		fflush(stdin);
		

		
		if (strcmp(file_buff, "!stop") == 0) {
			
			break;
			
		}
		
		if (i >= 2) {
			fputs("\n", fp);
		}
		
		fputs(file_buff, fp);
		
		if (i == 0) {
			
			fputs("\n", fp);
			
		}
		
	}
	
	fclose(fp);
	
	
	
	
	
	return 0;
}

int loadFile(int docNum) {
	
	notesNum = 0;
	FILE *fp = NULL;
	char file_buff[200];
	char *notes[265];
	
	switch (docNum) {
		case 1:
			fp = fopen("doc1.txt", "r");
			break;
		
		case 2:
			fp = fopen("doc2.txt", "r");
			break;
		
		case 3:
			fp = fopen("doc3.txt", "r");
			break;
		
		case 4:
			fp = fopen("doc4.txt", "r");
			break;
		
		case 5:
			fp = fopen("doc5.txt", "r");
			break;
		
		default:
			return -1;
			break;
			
	}
	
	if (fp == NULL) {
		return -2; 
	}
	
	int c;
	
	
	printf("\n[ ! ] 문서 %d번의 내용입니다.\n", docNum);
	printf("-----------------------------------------------------------------\n");
	

	
	int i = 0;
	while(fgets(file_buff, sizeof(file_buff), fp) != NULL){
		
		notesNum++;
		notes[i] = file_buff;
		
		printf("%d ", i + 1);
 		printf("%s", notes[i]); // 내용 표시
		
		i++;
	}
	
	
	printf("\n-----------------------------------------------------------------\n");
	fclose(fp);
	
	return 0; 

}


int main(void) {
	
	int mode = -1; 
	
	
	
	int document; 
	int documentResult; 
	int control; 
	int editNum; 
	char newLine[265];
	
	while (1) {
		if (mode == -1) { 

			printf("\n[ SYSTEM ] 불러올 문서를 선택해주십시오.\n");
			printf("\n[+] 문서는 1~5번 문서까지 있습니다.");
			printf("\n[+] 예시로 1번 문서를 불러오려면 '1'번을 입력하십시오.");
			
			printf ("\n\n불러올 문서: ");
			scanf("%d", &document);
			fflush(stdin);
			
			mode = 2; 

			
		} else if (mode == 0) {
			
			printf ("\n\n불러올 문서: ");
			scanf("%d", &document);
			fflush(stdin);
			mode = 2;
			
		} else if (mode == 1) {
			
			printf("[1] 새로 덮어쓰기 [2] 다른 문서 불러오기 [3] 덧붙이기 [4] 프로그램 종료");
			printf("\n\n입력: ");
			
			scanf("%d", &control);
			fflush(stdin);
			
			
			
			switch (control) {
				case 1:
					

					printf("\n[ ! ] 새로 덮어쓰기를 시작합니다. 종료하시려면 '!stop'을 입력하십시오.\n\n");
					
					writeFile(document);
					loadFile(document);
					
					break;
				case 2:
					printf("\n[ ! ] 불러 올 문서를 다시 선택합니다.");
					mode = 0;
					break;
				case 3:
					
					printf("\n[ ! ] 덧붙이기를 시작합니다. 종료하시려면 '!stop'을 입력하십시오.\n\n");
					
					appendFile(document);
					loadFile(document);
					
					break;
				case 4:
					printf("\n[ ! ] 프로그램을 종료합니다.\n");
					return 0;
			}
					
			
		} else if (mode == 2) { 
			
			documentResult = loadFile(document);
			

			
			switch(documentResult) {
	

				
				case 0: 
					mode = 1; 
					break;
				
				case -1: 
					printf("\n[ 경고 ] 1~5번 이외의 번호입니다. 다시 입력하십시오.");
					
					mode = 0; 
					break;
				
				case -2: 
					printf("\n[ 오류 ] 파일이 존재하지 않습니다. 파일이 해당 위치에 있는지 확인 후, 다시 시도하십시오.");
					mode = 0; 
					break;
			}
		}
	}
	
	
	
	
	return 0;
}