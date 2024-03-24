#include <stdio.h>
#include <string.h> // Str 관리 Header

typedef enum {false, true} bool; // bool 사용

 // 전역 변수: 받은 내용
int notesNum = 0; // 전역 변수: 받은 내용의 줄 수
int noteLines = 0;


int appendFile(int docNum) {
	FILE *fp = NULL;
	char file_buff[200];
	
	switch (docNum) { // 파일 번호 감지
		case 1:
			fp = fopen("doc1.txt", "a"); // 1번인 경우
			break;
		
		case 2:
			fp = fopen("doc2.txt", "a"); // 2번인 경우
			break;
		
		case 3:
			fp = fopen("doc3.txt", "a"); // 3번인 경우
			break;
		
		case 4:
			fp = fopen("doc4.txt", "a"); // 4번인 경우
			break;
		
		case 5:
			fp = fopen("doc5.txt", "a"); // 5번인 경우
			break;
		
		default:
			return -1; // Error -1: 없는 번호
		break;
		
	}
	
	if (fp == NULL) {
		return -2; // Error -2: 읽을 파일 없음
	}
	
	
	int i;
	
	for (i = 0; ; i++) { // !stop 입력 시 종료
		
		if (i == 0) {
			fputs("\n", fp);
		}
		

		
		printf("\033[0;35m[ \033[0m%d \033[0;35m] \033[0m", notesNum + i + 1);
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
	
	switch (docNum) { // 파일 번호 감지
		case 1:
			fp = fopen("doc1.txt", "w"); // 1번인 경우
			break;
		
		case 2:
			fp = fopen("doc2.txt", "w"); // 2번인 경우
			break;
		
		case 3:
			fp = fopen("doc3.txt", "w"); // 3번인 경우
			break;
		
		case 4:
			fp = fopen("doc4.txt", "w"); // 4번인 경우
			break;
		
		case 5:
			fp = fopen("doc5.txt", "w"); // 5번인 경우
			break;
		
		default:
			return -1; // Erorr -1: 없는 번호
		break;
		
	}
	
	if (fp == NULL) {
		return -2; // Error -2: 읽을 파일 없음
	}
	
	
	int i;

	for (i = 0; ; i++) { // !stop 입력 시 종료
		
		
		printf("\033[0;35m[ \033[0m%d \033[0;35m] \033[0m", i + 1);
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
	
	switch (docNum) { // 파일 번호 감지
		case 1:
			fp = fopen("doc1.txt", "r"); // 1번인 경우
			break;
		
		case 2:
			fp = fopen("doc2.txt", "r"); // 2번인 경우
			break;
		
		case 3:
			fp = fopen("doc3.txt", "r"); // 3번인 경우
			break;
		
		case 4:
			fp = fopen("doc4.txt", "r"); // 4번인 경우
			break;
		
		case 5:
			fp = fopen("doc5.txt", "r"); // 5번인 경우
			break;
		
		default:
			return -1; // Erorr -1: 없는 번호
			break;
			
	}
	
	if (fp == NULL) {
		return -2; // Error -2: 읽을 파일 없음
	}
	
	int c;
	
	
	printf("\n\033[0;35m[ ! ] \033[0m문서 \033[0;35m%d\033[0m번의 내용입니다.\n", docNum);
	printf("\033[0;35m-----------------------------------------------------------------\n\033[0m");
	
	//while ((c = fgetc(fp)) != EOF) { // EOF = End of File 
	//	putchar(c);
	//} // Char 단위

	
	int i = 0;
	while(fgets(file_buff, sizeof(file_buff), fp) != NULL){
		
		notesNum++;
		notes[i] = file_buff; // 변수에 읽은 파일 내용 넣기
		
		printf("\033[0;35m%d\033[0m ", i + 1); // 줄 번호 표시
 		printf("%s", notes[i]); // 내용 표시
		
		// memset(file_buff, 0, sizeof(file_buff)); // 메모리 초기화
		i++;
	}
	
	
	printf("\n\033[0;35m-----------------------------------------------------------------\n\033[0m");
	fclose(fp);
	
	return 0; // 자동으로 편집모드로 전환하기

}

// Main 함수 =========================================================================================

int main(void) {
	
	int mode = -1; 
	
	
	/*
	[ Mode - 모드]
	-1: 초기에 입력 받기
	0: 다시 입력 받기
	1 읽기 및 쓰기 모드
	2: 입력 받은 값 판단 후 결과 도출 (안네 메시지)
	*/
	
	int document; // 선택된 문서
	int documentResult; // 오류 검사 결과
	int control; // 파일 처리 방식 선택
	int editNum; // 편집할 줄 선택
	char newLine[265];
	
	while (1) {
		if (mode == -1) { // 불러오기 모드
			// 불러올 파일 번호 받기
			printf("\n\033[0;36m[ SYSTEM ]\033[0m 불러올 문서를 선택해주십시오.\n");
			printf("\n\033[0;36m[+]\033[0m 문서는 1~5번 문서까지 있습니다.");
			printf("\n\033[0;36m[+]\033[0m 예시로 1번 문서를 불러오려면 '1'번을 입력하십시오.");
			
			printf ("\n\n불러올 문서: ");
			scanf("%d", &document);
			fflush(stdin);
			
			mode = 2; // 오류 검사로 이동

			
		} else if (mode == 0) { // 오류 시 다시 입력 받기
			
			printf ("\n\n불러올 문서: ");
			scanf("%d", &document);
			fflush(stdin);
			mode = 2;
			
		} else if (mode == 1) { // 읽기 및 쓰기 모드
			
			printf("\033[0;35m[1]\033[0m 새로 덮어쓰기 \033[0;35m[2]\033[0m 다른 문서 불러오기 \033[0;35m[3]\033[0m 덧붙이기 \033[0;35m[4]\033[0m 프로그램 종료");
			printf("\n\n입력: ");
			
			scanf("%d", &control);
			fflush(stdin);
			
			
			
			switch (control) {
				case 1:
					

					printf("\n\033[0;35m[ ! ] \033[0m새로 덮어쓰기를 시작합니다. 종료하시려면 '!stop'을 입력하십시오.\n\n");
					
					writeFile(document);
					loadFile(document);
					
					break;
				case 2:
					printf("\n\033[0;35m[ ! ] \033[0m불러 올 문서를 다시 선택합니다.");
					mode = 0;
					break;
				case 3:
					
					printf("\n\033[0;35m[ ! ] \033[0m덧붙이기를 시작합니다. 종료하시려면 '!stop'을 입력하십시오.\n\n");
					
					appendFile(document);
					loadFile(document);
					
					break;
				case 4:
					printf("\n\033[0;35m[ ! ] \033[0m프로그램을 종료합니다.\n");
					return 0;
			}
					
			
		} else if (mode == 2) { // 받아온 오류 검사 및 결과 도출
			
			documentResult = loadFile(document);
			

			
			switch(documentResult) {
	

				
				case 0: // 정상 파일 불러오기 후 쓰기 모드로의 전환
					mode = 1; // 모드: 편집 및 수정 모드
					break;
				
				case -1: // 번호 없음
					printf("\033[1;33m\n[ 경고 ]\033[0m 1~5번 이외의 번호입니다. 다시 입력하십시오.");
					
					mode = 0; // 모드: 재입력 모드
					break;
				
				case -2: // 파일 없음
					printf("\n\033[1;31m[ 오류 ]\033[0m 파일이 존재하지 않습니다. 파일이 해당 위치에 있는지 확인 후, 다시 시도하십시오.");
					mode = 0; // 모드: 재입력 모드
					break;
			}
		}
	}
	
	
	
	
	return 0;
}