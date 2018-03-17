#include <stdio.h>
#include <windows.h>

#define UP 72						//입력받을 값들의 아스키코드값
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32
#define ESC 27
#define MAP_LEN_X 81				//맵 가로 길이
#define MAP_LEN_Y 48				//맵 세로 길이
#define CHARACTER_COLOR 0			//케릭터 색깔(검정색)
#define PORTAL_COLOR 14				//포탈 색깔(노랑색)
#define TIME 300					//프롤로그 올라가는 시간

int num = 1;						//num번 맵
void gotoxy(int x, int y);			//좌표함수
void start_menu();					//시작화면
void select_menu();					//방향키

void character_map1();				//맵1 케릭터
void character_map2();				//맵2 케릭터
void character_map3();				//갈멜관 앞 케릭터
void character_map4();				//일립관 앞 케릭터
void character_map5();				//갈멜관 케릭터
void character_map6();				//복음관 앞 케릭터
void character_map7();				//복음관 5층 케릭터
void character_map8();				//원벤 케릭터
void character_map9();				//로고스 홀 입구
void character_map10();				//식당
void character_map11();				//로고스 홀
void character_map12();				//카페테리아

void draw_start_menu();				//시작화면
void draw_map1();					//맵1
void draw_map2();					//두갈래길
void draw_map3();					//갈멜관 앞
void draw_map4();					//일립관 앞
void draw_map5();					//갈멜관
void draw_map6();					//복음관 앞
void draw_map7();					//복음관 5층
void draw_map8();					//원벤
void draw_map9();					//로고스 홀 입구
void draw_map10();					//식당
void draw_map11();					//로고스 홀
void draw_map12();					//카페테리아
void draw_Quiz();					//퀴즈창
void draw_Quest();					//퀘스트 창
void draw_Map();					//맵 창
void Prologue();					//프롤로그
void ending_credit();				//엔딩크레딧

void setcursortype();				//커서 숨기는 함수
void character_pause_pos();			//케릭터 초기 좌표 겸 일시정지 눌렀을시 케릭터 원래 좌표 유지
void SetColor(unsigned short text, unsigned short back);	//글자과 배경색 바꾸는 함수

void p1_go();						//맵2로 가는 포탈
void p1_come();						//맵2에서 맵1로 가는 포탈
void p2_go();						//맵2에서 갈멜관 앞으로 가는 포탈
void p2_come();						//갈멜관 앞에서 맵2로 가는 포탈
void p3_go_r();						//갈멜관 앞에서 갈멜관으로 가는 포탈(오른쪽)
void p3_go_l();						//갈멜관 앞에서 갈멜관으로 가는 포탈(왼쪽)
void p3_come_r();					//갈멜관에서 갈멜관 앞으로 가는 포탈(오른쪽)
void p3_come_l();					//갈멜관에서 갈멜관 앞으로 가는 포탈(왼쪽)
void p4_go();						//맵2에서 일립관 앞으로 가는 포탈
void p4_come();						//일립관 앞에서 맵2로 가는 포탈
void p5_go();						//갈멜관 앞에서 복음관 앞으로 가는 포탈
void p5_come();						//복음관 앞에서 갈멜관 앞으로 가는 포탈
void p6_go();						//복음관 앞에서 복음관으로 가는 포탈
void p6_come();						//복음관에서 복음관 앞으로 가는 포탈
void p7_go();						//복음관 앞에서 원벤으로 가는 포탈
void p7_go_c();						//카페테리아에서 복음관 앞으로 가는 포탈
void p7_come_c();					//복음관 앞에서 카페테리아로 가는 포탈
void p7_come();						//원벤에서 복음관 앞으로 가는 포탈
void p8_go();						//원벤에서 일립관 앞으로 가는 포탈
void p8_come();						//일립관 앞에서 원벤으로 가는 포탈
void p9_go();						//원벤에서 로고스 홀 입구로 가는 포탈
void p9_come();						//로고스 홀 입구에서 원벤으로 가는 포탈
void p10_go_r();					//로고스 홀 입구에서 식당가는 포탈(식당 오른쪽 포탈)
void p10_come_l();					//식당에서 로고스 홀 입구가는 포탈(로고스 홀 입구 왼쪽 포탈)
void p10_go_l();					//로고스 홀 입구에서 식당가는 포탈(식당 왼쪽 포탈)
void p10_come_r();					//식당에서 로고스 홀 입구가는 포탈(로고스 홀 입구 오른쪽 포탈)
void p11_go1();						//로고스 홀 입구에서 로고스 홀 가는 1번 포탈
void p11_go2();						//로고스 홀 입구에서 로고스 홀 가는 2번 포탈
void p11_go3();						//로고스 홀 입구에서 로고스 홀 가는 3번 포탈
void p11_come1();					//로고스 홀 에서 로고스 홀 입구가는 1번 포탈
void p11_come2();					//로고스 홀 에서 로고스 홀 입구가는 2번 포탈
void p11_come3();					//로고스 홀 에서 로고스 홀 입구가는 3번 포탈

void map1_status();					//성서대 입구 상태창
void map2_status();					//두 갈래 길 상태창
void map3_status();					//갈멜관 앞 상태창
void map4_status();					//일립관 앞 상태창
void map5_status();					//갈멜관 상태창
void map6_status();					//복음관 앞 상태창
void map7_status();					//복음관 상태창
void map8_status();					//원벤 상태창
void map9_status();					//로고스 홀 입구 상태창
void map10_status();				//식당 상태창
void map11_status();				//로고스 홀 상태창
void map12_status();				//카페테리아 상태창

void Quiz();						//학생증을 얻기 위한 퀴즈
void Q1();							//1번 문제
void Q2();							//2번 문제
void Q3();							//3번 문제
int end = 1;						//Quiz함수의 while문을 끝내기 위한 변수

int menuPos = 17;				//Y축 초기값
int x = 104, y = 24;			//케릭터 초기 좌표값, x,y 좌표 전역변수
int map[MAP_LEN_Y][MAP_LEN_X];	//맵 베이스
int portal1;					//포탈1 왔다 갔다 할때 케릭터 좌표 정해주는 기준
int portal2;					//포탈2 왔다 갔다 할때 케릭터 좌표 정해주는 기준
int portal3;					//맵2와 갈멜관 앞
int portal4;					//맵2와 일립관 앞
int portal5;					//갈멜관과 갈멜관 앞
int portal6;					//갈멜관 앞과 복음관 앞
int portal7;					//복음관 앞과 복음관
int portal8;					//복음관 앞과 원벤
int portal9;					//원벤과 일립관 앞
int portal10;					//로고스 홀 입구
int portal11;					//식당
int portal12;					//로고스 홀
int portal13;					//카페테리아
int end_portal = 1;				//게임 엔딩 포탈

int total_coin;					//주운 동전들의 합
int drink;						//뽑아 마신 음료수 갯수 세기
int food_ticket;				//식권 갯수
int food;						//점심
int student_card;				//학생증
int choice, Quiz_num = 1;		//choice는 문제 풀때 답 선택, Quiz_num은 문제 번호
int Total_Quest;				//퀘스트 클리어 갯수
int Quest1;						//퀘스트1
int Quest2;						//퀘스트2
int Quest3;						//퀘스트3
int Quest4;						//퀘스트4
int Quest5;						//퀘스트5

int main(void)
{
	setcursortype();				// 깜박이는 커서를 없앤다.
	Prologue();
	start_menu();
	select_menu();

	if (menuPos == 17)				//게임시작
	{
		while (1)
		{
			system("cls");
			switch (num)				//맵들
			{
			case 1:
				draw_map1();
				map1_status();
				character_map1();
				break;
			case 2:
				draw_map2();
				map2_status();
				character_map2();
				break;
			case 3:
				draw_map3();
				map3_status();
				character_map3();
				break;
			case 4:
				draw_map4();
				map4_status();
				character_map4();
				break;
			case 5:
				draw_map5();
				map5_status();
				character_map5();
				break;
			case 6:
				draw_map6();
				map6_status();
				character_map6();
				break;
			case 7:
				draw_map7();
				map7_status();
				character_map7();
				break;
			case 8:
				draw_map8();
				map8_status();
				character_map8();
				break;
			case 9:
				draw_map9();
				map9_status();
				character_map9();
				break;
			case 10:
				draw_map10();
				map10_status();
				character_map10();
				break;
			case 11:
				draw_map11();
				map11_status();
				character_map11();
				break;
			case 12:
				draw_map12();
				map12_status();
				character_map12();
				break;
			default:
				break;
			}
		}
	}
	else if (menuPos == 18)			//도움을 준 사람
	{
		ending_credit();
		getch();
	}
	else if (menuPos == 19)			//게임종료
		exit(1);

	return 0;
}

void gotoxy(int x, int y)			//좌표함수
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void select_menu()
{
	int ch;

	while (1)
	{
		ch = getch();

		switch (ch)
		{
		case UP:	//UP
			if (menuPos <= 17)
			{
				menuPos = 19;
				gotoxy(50, 17);
				printf("  ");
				gotoxy(51, menuPos);
				printf("▶");
			}
			else if (menuPos == 19)
			{
				gotoxy(50, menuPos);
				printf("  ");
				gotoxy(51, menuPos - 1);
				printf("▶");
				menuPos--;

			}
			else if (menuPos == 18)
			{
				gotoxy(50, menuPos);
				printf("  ");
				gotoxy(51, menuPos - 1);
				printf("▶");
				menuPos--;
			}
			break;
		case DOWN:	//DOWN
			if (menuPos <= 17)
			{
				gotoxy(50, 17);
				printf("  ");
				gotoxy(51, 18);
				printf("▶");
				menuPos++;
			}
			else if (menuPos == 18)
			{
				gotoxy(50, 18);
				printf("  ");
				gotoxy(51, 19);
				printf("▶");
				menuPos++;
			}
			else if (menuPos >= 19)
			{
				menuPos = 17;
				gotoxy(50, 19);
				printf("  ");
				gotoxy(51, 17);
				printf("▶");
			}
			break;

		}	//switch
		if (ch == 13 && menuPos == 17)				//ENTER
		{
			system("cls");
			break;
		}
		else if (ch == 13 && menuPos == 18)			//ENTER
		{
			system("cls");
			break;
		}
		else if (ch == 13 && menuPos == 19)			//ENTER
		{
			system("cls");
			break;
		}
	}	//while


}

void start_menu() //시작화면
{
	draw_start_menu();

	gotoxy(53, 17);
	printf("등교하기");	//menuPos 17
	gotoxy(53, 18);
	printf("도움을 준 사람");	//menuPos 18
	gotoxy(53, 19);
	printf("종료");		//menuPos 19
	gotoxy(51, 17);
	printf("▶");
}

void character_map1()										//학교 입구
{
	FILE *fp;
	fp = fopen("맵1.txt", "r");	//맵1 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal1 == 0)
		character_pause_pos();
	else if (portal1 == 1)
		p1_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;									//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);						//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:											//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{

				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1)
				break;

		case RIGHT:											//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 4)
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
					gotoxy(129, 5);
					printf("%d", total_coin);
					break;
				}
				else
				{
					gotoxy(2, 26);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 26);
					printf("                    ");
				}
				break;
			}
			else if (map[y][m_x] == 1)
				break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 4)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 26);
					printf("              ");
					gotoxy(129, 5);
					printf("%d", total_coin);
				}
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				system("cls");
				num = 2;
				portal2 = 0;
				goto exit;
			}
			else if (map[y - 1][check_x] == 1)
				break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				if (Total_Quest >= 5)
				{
					system("mode con cols=20 lines=20");
					system("cls");
					gotoxy(2, 10);
					printf("집 에 간 다!!!!");
					Sleep(1000);
					system("cls");
					ending_credit();
				}
				else
				{
					gotoxy(2, 26);
					printf("집에 가고 싶다..ㅠㅠ");
					Sleep(500);
					gotoxy(2, 26);
					printf("                    ");
				}
				break;

			}
			else if (map[y + 1][check_x] == 1 || y == 25)
				break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map1();
					character_pause_pos();
					map1_status();
					break;
				}
				else
					continue;
			}
			break;

		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map1();
					character_pause_pos();
					map1_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map2()
{
	FILE *fp;
	fp = fopen("맵2.txt", "r");	//맵2 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal2 == 0)
		p1_go();										//x=60 y=24
	else if (portal2 == 1)
		p2_come();
	else if (portal2 == 2)
		p4_come();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:												//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 3;										//맵2에서 갈멜관 앞으로 이동
				portal3 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			else if (map[y][m_x] == 3)
				break;
			else if (map[y][m_x] == 4)
				break;

		case RIGHT:												//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 4;
				portal9 = 1;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			else if (map[y][m_x] == 3)
				break;
			else if (map[y][m_x] == 4)
				break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			else if (map[y - 1][check_x] == 3)
				break;
			else if (map[y - 1][check_x] == 4)
				break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num--;
				portal1 = 1;
				goto exit;
			}
			else if (map[y + 1][check_x] == 1)
				break;
			else if (map[y + 1][check_x] == 3)
				break;
			else if (map[y + 1][check_x] == 4)
				break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map2();
					character_pause_pos();
					map2_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map2();
					character_pause_pos();
					map2_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map3()
{
	FILE *fp;
	fp = fopen("갈멜관 앞.txt", "r");   //갈멜관 앞 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal3 == 0)
		p2_go();
	else if (portal3 == 1)
		p3_come_r();
	else if (portal3 == 2)
		p3_come_l();
	else if (portal3 == 3)
		p5_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;                              //배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);         //맵 파일 받아오기

		switch (ch)
		{
		case LEFT:                                    //케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;                           //문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0 || map[y][m_x] == 5 || map[y][m_x] == 8 || map[y][m_x] == 11)         //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case RIGHT:                                 //케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;                        //문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0 || map[y][m_x] == 5 || map[y][m_x] == 8 || map[y][m_x] == 11)      //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 2;
				portal2 = 1;
				portal3 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case UP:                                          //케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0 || map[y - 1][check_x] == 5 || map[y - 1][check_x] == 8 || map[y - 1][check_x] == 11)      //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				system("cls");
				num = 6;
				portal7 = 0;
				goto exit;
			}
			else if (map[y - 1][check_x] == 10)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 48);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 48);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 48);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 48);
					printf("                    ");
				}
				break;
			}
			else
				break;

		case DOWN:                                                                  //케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0 || map[y + 1][check_x] == 5 || map[y + 1][check_x] == 11)      //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num = 5;
				portal5 = 1;
				goto exit;
			}
			else if (map[y + 1][check_x] == 6)
			{
				system("cls");
				num = 5;
				portal5 = 2;
				goto exit;
			}
			else
				break;

			break;

		case SPACE:
			if (map[y][check_x] == 5)
			{
				gotoxy(2, 48);
				printf("흠냐...");
				Sleep(300);
				gotoxy(2, 48);
				printf("        ");
			}
			else if (map[y][check_x] == 11)
			{
				gotoxy(2, 48);
				printf("교수님이 너 찾으시던데..");
				Sleep(300);
				gotoxy(2, 48);
				printf("                        ");
			}
			else if (map[y][x / 2 - 1] == 7)
			{
				if (total_coin == 0)
				{
					gotoxy(2, 48);
					printf("음료수를 마시려면 동전 1개가 필요합니다.");
					Sleep(500);
					gotoxy(2, 48);
					printf("                                        ");
				}
				else if (total_coin >= 1)
				{
					gotoxy(2, 48);
					printf("음료수가 나왔다.");
					Sleep(500);
					gotoxy(2, 48);
					printf("벌컥 벌컥         ");
					Sleep(500);
					gotoxy(2, 48);
					printf("캬.. 시원하다!");
					Sleep(500);
					gotoxy(2, 48);
					printf("                 ");
					total_coin--;
					Total_Quest++;
					Quest1++;
					map3_status();
				}
			}
			else if (map[y][check_x] == 8)
			{
				gotoxy(2, 48);
				printf("여자: 어디서 솔로 냄새 안나?");
				Sleep(1000);
				gotoxy(2, 48);
				printf("남자: 요즘 솔로가 어딨어? ㅋㅋㅋ");
				Sleep(1000);
				gotoxy(2, 48);
				printf("요즘 솔로: (xx...)              ");
				Sleep(800);
				gotoxy(2, 48);
				printf("                     ");
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map3();
					character_pause_pos();
					map3_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map3();
					character_pause_pos();
					map3_status();
					break;
				}
				else
					continue;
			}
			break;
		}
	}
	fclose(fp);
exit:;
}

void character_map4()
{
	FILE *fp;
	fp = fopen("일립관 앞.txt", "r");	//일립관 앞 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal9 == 0)
		p8_go();
	else if (portal9 == 1)
		p4_go();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;							//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);	//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:										//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;							//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 2;
				portal2 = 2;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case RIGHT:								//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;					//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)				//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num;
				portal2++;
				goto exit;
			}
			else if (map[y][m_x] == 4)
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 47);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 47);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 47);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 47);
					printf("                    ");
				}

				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;
		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				system("cls");
				num = 8;
				portal4 = 1;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 4)
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 47);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 47);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				break;
			}
			else if (map[y][m_x] == 1)
				break;

			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map4();
					character_pause_pos();
					map4_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map4();
					character_pause_pos();
					map4_status();
					break;
				}
				else
					continue;
			}
			break;
		}
	}
	fclose(fp);
exit:;
}

void character_map5()
{
	FILE *fp;
	fp = fopen("갈멜관.txt", "r");	//갈멜관 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}
	if (portal5 == 1)
		p3_go_r();
	else if (portal5 == 2)
		p3_go_l();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;							//배열의 값 체크, y축 이동시 x값
	int coin = 0;

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);	//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:										//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;							//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0 || map[y][m_x] == 8)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num--;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case RIGHT:										//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;							//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0 || map[y][m_x] == 8)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num--;
				portal2++;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;
			else if (map[y][m_x] == 12)
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 27);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 27);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 27);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 27);
					printf("                    ");
				}

				break;
			}

			break;
		case UP:										//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)				//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 2)			//갈멜관 오른쪽 포탈
			{
				system("cls");
				num = 3;
				portal3 = 1;
				goto exit;
			}
			else if (map[y - 1][check_x] == 6)			//갈멜관 왼쪽 포탈
			{
				system("cls");
				num = 3;
				portal3 = 2;
				goto exit;
			}
			else if (map[y - 1][check_x] == 4)
			{
				gotoxy(2, 27);
				printf("3학년 과실은 들어갈 수 없습니다.");
				Sleep(500);
				gotoxy(2, 27);
				printf("                                 ");
				break;
			}
			else if (map[y - 1][check_x] == 5)
			{
				gotoxy(2, 27);
				printf("전산실은 들어갈 수 없습니다.");
				Sleep(500);
				gotoxy(2, 27);
				printf("                               ");
				break;
			}
			else if (map[y - 1][check_x] == 10)
			{
				gotoxy(2, 27);
				printf("조교님은 현재 바쁩니다.");
				Sleep(500);
				gotoxy(2, 27);
				printf("                        ");
				break;
			}
			else if (map[y - 1][check_x] == 12)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 27);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 27);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}

				break;
			}

			break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else
				break;

			break;

		case SPACE:
			if (map[y][check_x] == 8)
			{
				gotoxy(2, 27);
				printf("김컴소: 넌 정말 열심이구나..");
				Sleep(800);
				gotoxy(2, 27);
				printf("갓용호: 만점을 위해선...후후후..");
				Sleep(800);
				gotoxy(2, 27);
				printf("                                 ");
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map5();
					character_pause_pos();
					map5_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map5();
					character_pause_pos();
					map5_status();
					break;
				}
				else
					continue;
			}
			break;
		}
	}
	fclose(fp);
exit:;
}

void character_map6()
{
	FILE *fp;
	fp = fopen("복음관 앞.txt", "r");	//복음관 앞맵 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal7 == 0)
		p5_go();
	else if (portal7 == 1)
		p6_come();
	else if (portal7 == 2)
		p7_come();
	else if (portal7 == 3)
		p7_go_c();		//카페테리아 > 복음관 앞
	else if (portal7 == 4)
		p7_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);	//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:											//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				system("cls");
				num = 7;
				portal8 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 6)
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 48);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 48);
					printf("                ");
					gotoxy(74, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 48);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 48);
					printf("                    ");
				}

				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 5)
				break;

		case RIGHT:											//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				system("cls");
				num = 8;
				portal4 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 5)
				break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				system("cls");
				num = 12;
				portal13 = 1;
				goto exit;
			}
			else if (map[y - 1][check_x] == 1 || map[y - 1][check_x] == 5)
				break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num = 3;
				portal3 = 3;
				goto exit;
			}
			else if (map[y + 1][check_x] == 1 || y == 25 || map[y + 1][check_x] == 5)
				break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map6();
					character_pause_pos();
					map6_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map6();
					character_pause_pos();
					map6_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map7()
{
	FILE *fp;
	fp = fopen("복음관.txt", "r");	//복음관맵 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal8 == 0)
		p6_go();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);	//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:											//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 8)
			{
				gotoxy(2, 48);
				printf("들어갈 수 없습니다.");
				Sleep(500);
				gotoxy(2, 48);
				printf("                   ");
			}
			else if (map[y][m_x] == 9)
			{
				gotoxy(2, 48);
				printf("김컴소: 안녕히 계세요~");
				Sleep(800);
				gotoxy(2, 48);
				printf("                      ");
				x -= 4;
				check_x -= 2;
				gotoxy(x + 4, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:											//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 6;
				portal7 = 1;
				goto exit;
			}
			else if (map[y][m_x] == 8)
			{
				gotoxy(2, 48);
				printf("들어갈 수 없습니다.");
				Sleep(500);
				gotoxy(2, 48);
				printf("                   ");
			}
			else if (map[y][m_x] == 9)
			{
				gotoxy(2, 48);
				printf("똑똑");
				Sleep(800);
				gotoxy(2, 48);
				printf("현 교수님: 들어오세요");
				Sleep(800);
				x += 4;
				check_x += 2;
				gotoxy(x - 4, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				Sleep(800);
				gotoxy(2, 48);
				printf("김컴소: 안녕하세요 교수님~");
				Sleep(800);
				gotoxy(2, 48);
				printf("현 교수님: 어서와 컴소야~^^ ");
				Sleep(800);
				gotoxy(2, 48);
				printf("                            ");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 1 || y == 25)
				break;
			break;

		case SPACE:
			if (map[y][x / 2 + 2] == 4)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				if (Quest2 == 0)
				{
					gotoxy(2, 48);
					printf("현 교수님: 채플 들으려면 학생증이 필요할 꺼야");
					Sleep(800);
					gotoxy(2, 48);
					printf("현 교수님: 그리고 나에겐 학생증이 있지       ");
					Sleep(800);
					gotoxy(2, 48);
					printf("현 교수님: 그런데 그냥 주면 재미없겠지?      ");
					Sleep(800);
					gotoxy(2, 48);
					printf("현 교수님: 내가 내는 문제를 맞추면 학생증을 줄께~^^");
					Sleep(800);
					gotoxy(2, 48);
					printf("3초 후에 문제가 나옵니다.                          ");
					Sleep(1000);
					gotoxy(2, 48);
					printf("2초 후에 문제가 나옵니다.                          ");
					Sleep(1000);
					gotoxy(2, 48);
					printf("1초 후에 문제가 나옵니다.                          ");
					Sleep(1000);
					Quiz();
					draw_map7();
					gotoxy(46, 6);
					printf("옷");
					student_card = 1;
					map7_status();
					gotoxy(2, 48);
					printf("현 교수님: 잘 맞췄네 여기 학생증 이야^^ 채플 잘 드리렴~");
					getch();
					gotoxy(2, 48);
					printf("학생증을 얻었다.                                       ");
					Sleep(500);
					gotoxy(2, 48);
					printf("                 ");
					Quest2++;
					Total_Quest++;
					break;
				}
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map7();
					character_pause_pos();
					map7_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map7();
					character_pause_pos();
					map7_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map8()
{
	FILE *fp;
	fp = fopen("원벤.txt", "r");	//원벤맵 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}
	if (portal4 == 0)
		p7_go();
	else if (portal4 == 1)
		p8_come();
	else if (portal4 == 2)
		p9_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;									//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);						//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:											//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{

				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				system("cls");
				num = 6;
				portal7 = 2;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;

		case RIGHT:											//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;								//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)							//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				system("cls");
				num = 4;
				portal9 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 4)
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
				}
			}
			else if (map[y][m_x] == 1)
				break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)						//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 4)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
				}
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				system("cls");
				num = 9;
				portal10 = 0;
				goto exit;
			}
			else if (map[y - 1][check_x] == 1)
				break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map8();
					character_pause_pos();
					map8_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map8();
					character_pause_pos();
					map8_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map9()
{
	FILE *fp;
	fp = fopen("로고스 홀 입구.txt", "r");	//로고스 홀 입구 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal10 == 0)
		p9_go();
	else if (portal10 == 1)
		p10_come_l();
	else if (portal10 == 2)
		p10_come_r();
	else if (portal10 == 3)
		p11_come1();
	else if (portal10 == 4)
		p11_come2();
	else if (portal10 == 5)
		p11_come3();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:												//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 10;										//로고스 홀 앞에서 식당으로 이동
				portal11 = 0;									//식당 오른쪽 포탈로 나오기
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 10;										//로고스 홀 앞에서 식당으로 이동
				portal11 = 1;									//식당 왼쪽 포탈로 나오기
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				if (student_card == 0)
				{
					gotoxy(2, 17);
					printf("학생증이 없어서 들어갈 수 없습니다.");
					Sleep(500);
					gotoxy(2, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//로고스 홀 앞에서 로고스 홀로 이동
					portal12 = 0;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 5)
			{
				if (student_card == 0)
				{
					gotoxy(0, 17);
					printf("학생증이 없어서 들어갈 수 없습니다.");
					Sleep(500);
					gotoxy(0, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//로고스 홀 앞에서 로고스 홀로 이동
					portal12 = 1;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 7)
			{
				if (student_card == 0)
				{
					gotoxy(0, 17);
					printf("학생증이 없어서 들어갈 수 없습니다.");
					Sleep(500);
					gotoxy(0, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//로고스 홀 앞에서 로고스 홀로 이동
					portal12 = 2;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 1 || map[y - 1][check_x] == 3 || map[y - 1][check_x] == 8)
				break;

		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num = 8;
				portal4 = 2;
				goto exit;
			}
			else if (map[y + 1][check_x] == 1)
				break;
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map9();
					character_pause_pos();
					map9_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map9();
					character_pause_pos();
					map9_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map12()                              //카페테리아
{
	FILE *fp;
	fp = fopen("카페테리아.txt", "r");   //카페테리아 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal13 == 1)
		p7_come_c();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;                           //배열의 값 체크, y축 이동시 x값

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);                  //맵 파일 받아오기

		switch (ch)
		{
		case LEFT:                                 //케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;                        //문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)                     //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 4 || map[y][m_x] == 5 || map[y][m_x] == 6 || map[y][m_x] == 7)
				break;

		case RIGHT:                                 //케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;                        //문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)                     //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 4 || map[y][m_x] == 5 || map[y][m_x] == 6 || map[y][m_x] == 7 || map[y][m_x] == 8)
				break;

		case UP:                                 //케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)                  //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 1 || map[y - 1][check_x] == 4 || map[y - 1][check_x] == 5 || map[y - 1][check_x] == 6 || map[y - 1][check_x] == 7)
				break;

		case DOWN:                                 //케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)                  //케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num = 6;
				portal7 = 3;
				goto exit;
			}
			else if (map[y + 1][check_x] == 1 || y == 25 || map[y - 1][check_x] == 4 || map[y - 1][check_x] == 5 || map[y - 1][check_x] == 6 || map[y - 1][check_x] == 7 || map[y - 1][check_x] == 8)
				break;
			break;

		case SPACE:
			if (map[y + 1][check_x] == 8 || map[y][x / 2 + 1] == 8)
			{
				if (total_coin == 0)
				{
					gotoxy(2, 26);
					printf("커피를 마시려면 동전 1개가 필요합니다.");
					Sleep(500);
					gotoxy(2, 26);
					printf("                                      ");
				}
				else if (total_coin >= 1)
				{
					gotoxy(2, 26);
					printf("커피가 나왔다.");
					Sleep(500);
					gotoxy(2, 26);
					printf("쪽--쪽--      ");
					Sleep(500);
					gotoxy(2, 26);
					printf("커피로 에너지충전!!");
					Sleep(500);
					gotoxy(2, 26);
					printf("                    ");
					total_coin--;
					Total_Quest++;
					Quest5++;
					map12_status();
				}
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map12();
					character_pause_pos();
					map12_status();
					break;
				}
				else
					continue;
			}
			break;

		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map12();
					character_pause_pos();
					map12_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}
void character_map10()
{
	FILE *fp;
	fp = fopen("식당.txt", "r");	//식당 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}
	if (portal11 == 0)
		p10_go_r();
	else if (portal11 == 1)
		p10_go_l();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값
	int coin = 0;

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:												//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 9;										//로고스 홀 앞에서 식당으로 이동
				portal10 = 2;									//식당 오른쪽 포탈로 나오기
				goto exit;
			}
			else if (map[y][m_x] == 10)
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("동전을 주웠다!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
					gotoxy(130, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 26);
					printf("동전인줄 알았는데...");
					Sleep(300);
					gotoxy(2, 26);
					printf("                    ");
				}
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 9;
				portal10 = 1;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 10)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;
		case DOWN:											//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 1)
				break;
			break;

		case SPACE:
			if (map[y][x / 2 - 1] == 4)
			{
				if (total_coin < 5)
				{
					gotoxy(2, 26);
					printf("식권을 뽑으려면 동전 5개가 필요합니다.");
					Sleep(500);
					gotoxy(2, 26);
					printf("                                       ");
					break;
				}
				else if ((total_coin > 0) && (total_coin >= 5) || (total_coin % 5 == 0))	//동전이 1개이상이고 동전이 10개 이상이거나 동전의 개수가 10의 배수 개일 때 식권을 뽑을수 있고 동전이 0보다 작으면 if 출력
				{
					gotoxy(2, 26);
					printf("식권을 뽑는다.");
					getch();
					gotoxy(2, 26);
					printf("(지잉 지잉)   ");
					getch();
					gotoxy(2, 26);
					printf("식권이 나왔다.");
					Sleep(300);
					gotoxy(2, 26);
					printf("              ");
					total_coin -= 5;
					food_ticket++;
					map10_status();
					break;
				}
			}
			else if (map[y][x / 2 + 1] == 11)
			{
				if (food_ticket == 0)
				{
					gotoxy(2, 26);
					printf("식권이 없습니다.");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
					break;
				}
				else if (food_ticket > 0)
				{
					gotoxy(2, 26);
					printf("김컴소: 안녕하세요~^^");
					getch();
					gotoxy(2, 26);
					printf("김컴소: 중식 하나 주세요~");
					getch();
					gotoxy(2, 26);
					printf("중식 한 개를 얻었다.     ");
					gotoxy(2, 26);
					printf("식권 한 개를 잃었다.     ");
					Sleep(300);
					gotoxy(2, 26);
					printf("                         ");
					food_ticket--;
					food++;
					map10_status();
					break;
				}
			}
			if (map[y][x / 2 - 1] == 3 || map[y][x / 2 + 1] == 3)
			{
				if (food == 1)
				{
					food--;
					gotoxy(2, 26);
					printf("냠냠");
					Sleep(500);
					gotoxy(2, 26);
					printf("쩝쩝");
					Sleep(500);
					gotoxy(2, 26);
					printf("후루룩 후루룩");
					Sleep(500);
					gotoxy(2, 26);
					printf("김컴소: 잘 먹었다~");
					Sleep(500);
					gotoxy(2, 26);
					printf("                  ");
					Quest3++;
					Total_Quest++;
					map10_status();
				}
			}
			break;

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map10();
					character_pause_pos();
					map10_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map10();
					character_pause_pos();
					map10_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_map11()
{
	FILE *fp;
	fp = fopen("로고스 홀.txt", "r");	//로고스 홀 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	if (portal12 == 0)
		p11_go1();
	else if (portal12 == 1)
		p11_go2();
	else if (portal12 == 2)
		p11_go3();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//배열의 값 체크, y축 이동시 x값

	gotoxy(2, 47);
	printf("총학팀: 안녕하세요~^^");
	Sleep(500);
	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//맵 파일 받아오기

		switch (ch)
		{
		case LEFT:												//케릭터 왼쪽 이동과 충돌체크
			m_x = x / 2 - 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//케릭터 오른쪽 이동과 충돌체크
			m_x = x / 2 + 1;									//문자는 2칸을 차지해서 gotoxy문과 배열의 좌표를 맞추기 위해 만듬
			if (map[y][m_x] == 0)								//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//케릭터 위쪽 이동과 충돌체크
			if (map[y][check_x] == 9)
			{
				gotoxy(2, 47);
				printf("                      ");
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 0)					//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;

		case DOWN:														//케릭터 아래쪽 이동과 충돌체크
			if (map[y + 1][check_x] == 0)	//케릭터가 갈 길에 블럭이 있는지 없는지 체크 없으면 가고 있으면 안감
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				system("cls");
				num = 9;
				portal10 = 3;
				goto exit;
			}
			else if (map[y + 1][check_x] == 7)
			{
				system("cls");
				num = 9;
				portal10 = 4;
				goto exit;
			}
			else if (map[y + 1][check_x] == 8)
			{
				system("cls");
				num = 9;
				portal10 = 5;
				goto exit;
			}
			else if (map[y + 1][check_x] == 9)
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("옷");
				gotoxy(2, 47);
				printf("총학팀: 안녕히 가세요~^^");
				Sleep(500);
				break;
			}
			else if (map[y + 1][check_x] == 1)
				break;
			break;

		case SPACE:
			if (map[y + 1][check_x] == 3)
			{
				gotoxy(2, 47);
				printf("전체: 만복의 근원 하나님♩");
				Sleep(1000);
				gotoxy(2, 47);
				printf("전체: 온 백성 찬송 드리고♩");
				Sleep(1000);
				gotoxy(2, 47);
				printf("전체: 저 천사여 찬송하세♩ ");
				Sleep(1000);
				gotoxy(2, 47);
				printf("전체: 찬송 성부 성자 성령♩");
				Sleep(1000);
				gotoxy(2, 47);
				printf("전체: 아-멘♩              ");
				Sleep(1000);
				gotoxy(2, 47);
				printf("김컴소: (말씀 듣는중)");
				Sleep(3000);
				gotoxy(2, 47);
				printf("김컴소: (꾸벅꾸벅)Zzz..");
				Sleep(1000);
				gotoxy(2, 47);
				printf("전체: 아멘             ");
				Sleep(1000);
				gotoxy(2, 47);
				printf("           ");
				Quest4++;
				Total_Quest++;
				break;
			}

		case 113:
			draw_Quest();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map11();
					character_pause_pos();
					map11_status();
					break;
				}
				else
					continue;
			}
			break;
		case 109:
			draw_Map();
			while (1)
			{
				ch = getch();
				if (ch == 27)
				{
					draw_map11();
					character_pause_pos();
					map11_status();
					break;
				}
				else
					continue;
			}
			break;
		}
		fclose(fp);
	}
exit:;
}

void character_pause_pos()			//케릭터 초기위치 겸 일시정지 전까지 있던 위치 유지
{
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void p1_go()			//맵1에서 맵2로 갈 때 좌표
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 24;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p1_come()			//맵2에서 맵1로 갈 때 좌표
{
	gotoxy(x, y);
	printf(" ");
	x = 10;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p2_go()			//갈멜관 앞으로 갈 때 좌표
{
	gotoxy(12, 3);
	printf(" ");
	x = 158;
	y = 43;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p2_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 12;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p3_go_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 156;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p3_go_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 4;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p3_come_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 72;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p3_come_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 4;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p4_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 42;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p4_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 12;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p5_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 6;
	y = 46;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p5_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 6;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p6_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p6_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 32;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p7_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p7_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 29;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p7_come_c()		//카페테리아 시작 좌표
{
	gotoxy(x, y);
	printf(" ");
	x = 50;
	y = 24;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p7_go_c()		//카페테리아에서 복음관 앞으로 나왔을 때 좌표
{
	gotoxy(x, y);
	printf(" ");
	x = 46;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p8_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 64;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p8_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 13;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p9_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 10;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p9_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 58;
	y = 4;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p10_go_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 23;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p10_come_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 8;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p10_go_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 22;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p10_come_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 8;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_go1()
{
	gotoxy(x, y);
	printf(" ");
	x = 30;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_go2()
{
	gotoxy(x, y);
	printf(" ");
	x = 80;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_go3()
{
	gotoxy(x, y);
	printf(" ");
	x = 136;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_come1()
{
	gotoxy(x, y);
	printf(" ");
	x = 30;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_come2()
{
	gotoxy(x, y);
	printf(" ");
	x = 58;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void p11_come3()
{
	gotoxy(x, y);
	printf(" ");
	x = 90;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("옷");
}

void map1_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(126, 1);
	printf("성서대 입구");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("동전: %d개", total_coin);
	gotoxy(123, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("중식");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 20);
	printf("Space bar:대화걸기");
	gotoxy(123, 21);
	printf("Q:퀘스트 보기");
	gotoxy(123, 22);
	printf("M:지도 보기");
}

void map2_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(127, 1);
	printf("두 갈래 길");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("동전: %d개", total_coin);
	gotoxy(123, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("중식");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 20);
	printf("Space bar:대화걸기");
	gotoxy(123, 21);
	printf("Q:퀘스트 보기");
	gotoxy(123, 22);
	printf("M:지도 보기");
}

void map3_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(167, 1);
	printf("갈멜관 앞");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("지금 가지고 있는거");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("동전: %d개", total_coin);
	gotoxy(166, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("중식");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("조작법");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("↑");
	gotoxy(163, 15);
	printf("←    이동     →");
	gotoxy(170, 17);
	printf("↓");
	gotoxy(163, 20);
	printf("Space bar:대화걸기");
	gotoxy(163, 21);
	printf("Q:퀘스트 보기");
	gotoxy(163, 22);
	printf("M:지도 보기");
}

void map4_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(166, 1);
	printf("일립관 앞");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("지금 가지고 있는거");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("동전: %d개", total_coin);
	gotoxy(166, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("중식");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("조작법");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("↑");
	gotoxy(163, 15);
	printf("←    이동     →");
	gotoxy(170, 17);
	printf("↓");
	gotoxy(163, 20);
	printf("Space bar:대화걸기");
	gotoxy(163, 21);
	printf("Q:퀘스트 보기");
	gotoxy(163, 22);
	printf("M:지도 보기");
}

void map5_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(168, 1);
	printf("갈멜관");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("지금 가지고 있는거");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("동전: %d개", total_coin);
	gotoxy(166, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("중식");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("조작법");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("↑");
	gotoxy(163, 15);
	printf("←    이동     →");
	gotoxy(170, 17);
	printf("↓");
	gotoxy(163, 20);
	printf("Space bar:대화걸기");
	gotoxy(163, 21);
	printf("Q:퀘스트 보기");
	gotoxy(163, 22);
	printf("M:지도 보기");
}

void map6_status()
{
	gotoxy(64, 0);
	printf("--------------------");
	gotoxy(69, 1);
	printf("복음관 앞");
	gotoxy(64, 2);
	printf("--------------------");
	gotoxy(65, 3);
	printf("지금 가지고 있는거");
	gotoxy(64, 4);
	printf("--------------------");
	gotoxy(68, 5);
	printf("동전: %d개", total_coin);
	gotoxy(68, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(68, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(68, 8);
		printf("중식");
	}
	else
	{
		gotoxy(68, 8);
		printf("    ");
	}
	gotoxy(64, 10);
	printf("--------------------");
	gotoxy(70, 11);
	printf("조작법");
	gotoxy(64, 12);
	printf("--------------------");
	gotoxy(72, 13);
	printf("↑");
	gotoxy(65, 15);
	printf("←    이동     →");
	gotoxy(72, 17);
	printf("↓");
	gotoxy(65, 20);
	printf("Space bar:대화걸기");
	gotoxy(65, 21);
	printf("Q:퀘스트 보기");
	gotoxy(66, 22);
	printf("M:지도 보기");
}

void map7_status()
{
	gotoxy(64, 0);
	printf("--------------------");
	gotoxy(69, 1);
	printf("복음관");
	gotoxy(64, 2);
	printf("--------------------");
	gotoxy(65, 3);
	printf("지금 가지고 있는거");
	gotoxy(64, 4);
	printf("--------------------");
	gotoxy(68, 5);
	printf("동전: %d개", total_coin);
	gotoxy(68, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(68, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(68, 8);
		printf("중식");
	}
	else
	{
		gotoxy(68, 8);
		printf("    ");
	}
	gotoxy(64, 10);
	printf("--------------------");
	gotoxy(70, 11);
	printf("조작법");
	gotoxy(64, 12);
	printf("--------------------");
	gotoxy(72, 13);
	printf("↑");
	gotoxy(65, 15);
	printf("←    이동     →");
	gotoxy(72, 17);
	printf("↓");
	gotoxy(65, 20);
	printf("Space bar:대화걸기");
	gotoxy(65, 21);
	printf("Q:퀘스트 보기");
	gotoxy(66, 22);
	printf("M:지도 보기");
}

void map8_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(127, 1);
	printf("원형 벤치");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("동전: %d개", total_coin);
	gotoxy(124, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("중식");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 20);
	printf("Space bar:대화걸기");
	gotoxy(123, 21);
	printf("Q:퀘스트 보기");
	gotoxy(123, 22);
	printf("M:지도 보기");
}

void map9_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(125, 1);
	printf("로고스 홀 입구");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("동전: %d개", total_coin);
	gotoxy(124, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("중식");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 18);
	printf("Space bar:대화걸기");
	gotoxy(123, 19);
	printf("Q:퀘스트 보기");
	gotoxy(123, 20);
	printf("M:지도 보기");
}

void map10_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(130, 1);
	printf("식당");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("동전: %d개", total_coin);
	gotoxy(124, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("중식");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 20);
	printf("Space bar:대화걸기");
	gotoxy(123, 21);
	printf("Q:퀘스트 보기");
	gotoxy(123, 22);
	printf("M:지도 보기");
}

void map11_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(167, 1);
	printf("로고스 홀");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("지금 가지고 있는거");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(168, 5);
	printf("동전: %d개", total_coin);
	gotoxy(168, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(168, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(168, 8);
		printf("중식");
	}
	else
	{
		gotoxy(168, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("조작법");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("↑");
	gotoxy(163, 15);
	printf("←    이동     →");
	gotoxy(170, 17);
	printf("↓");
	gotoxy(163, 20);
	printf("Space bar:대화걸기");
	gotoxy(163, 21);
	printf("Q:퀘스트 보기");
	gotoxy(163, 22);
	printf("M:지도 보기");
}

void map12_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(126, 1);
	printf("카페테리아");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("지금 가지고 있는거");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("동전: %d개", total_coin);
	gotoxy(123, 6);
	printf("식권: %d개", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("학생증");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("중식");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("조작법");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("↑");
	gotoxy(123, 15);
	printf("←    이동     →");
	gotoxy(130, 17);
	printf("↓");
	gotoxy(123, 20);
	printf("Space bar:대화걸기");
	gotoxy(123, 21);
	printf("Q:퀘스트 보기");
	gotoxy(123, 22);
	printf("M:지도 보기");
}


void setcursortype()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void draw_start_menu()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=124 lines=27");						//콘솔창 크기조절
	fp = fopen("시작화면.txt", "r");	//시작화면 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				SetColor(1, 7);
				printf("■");
				SetColor(0, 7);
			}
			if (map[i][j] == 8)
			{
				SetColor(4, 7);
				printf("■");
				SetColor(0, 7);
			}
			if (map[i][j] == 9)
			{
				SetColor(0, 7);
				printf("■");
				SetColor(0, 7);
			}
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
				printf("┌");
			else if (map[i][j] == 3)
				printf("┐");
			else if (map[i][j] == 4)
				printf("─");
			else if (map[i][j] == 5)
				printf("└");
			else if (map[i][j] == 6)
				printf("┘");
			else if (map[i][j] == 7)
				printf("│");
		}
		Sleep(100);			//제출때 주석 처리 풀기
		printf("\n");
	}
	fclose(fp);
}

void draw_map1()											//학교입구
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");					//콘솔창 크기조절
	fp = fopen("맵1.txt", "r");	//맵1 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//블럭
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");			//포탈
				SetColor(0, 7);
			}
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("◎");			//동전
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("  ");			//잔디밭
				SetColor(0, 7);
			}
			else if (map[i][j] == 5)
				printf("▤");				//학교앞 정자
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map2()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");	//콘솔창 크기조절
	fp = fopen("맵2.txt", "r");	//맵2 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("  ");
				SetColor(0, 7);
			}            //잔디밭
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("●");
				SetColor(0, 7);
			}			//가로등
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map3()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=182 lines=50");	//콘솔창 크기조절
	fp = fopen("갈멜관 앞.txt", "r");		//갈멜관 앞 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");			//포탈
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("웃");
				SetColor(0, 7);
			}			//남자 사람
			else if (map[i][j] == 4)
			{
				SetColor(10, 7);
				printf("♣");
				SetColor(0, 7);
			}			//나무
			else if (map[i][j] == 5)
				printf("  ");			//첫번째 사람 대화
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}			//포탈
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("■");			//자판기
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
				printf("  ");			//커플들 대화
			else if (map[i][j] == 9)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);
			}			//여자 사람
			else if (map[i][j] == 10)
			{
				SetColor(14, 7);
				printf("◎");
				SetColor(0, 7);
			}		//동전

		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map4()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=182 lines=49");	//콘솔창 크기조절
	fp = fopen("일립관 앞.txt", "r");		//일립관 앞 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}		//포탈
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("웃");
				SetColor(0, 7);
			}//사람
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("◎");
				SetColor(0, 7);
			}		//동전
			else if (map[i][j] == 6)
			{
				SetColor(0, 10);
				printf("  ");
				SetColor(0, 7);
			} //초록색 배경
			else if (map[i][j] == 7)
			{
				SetColor(0, 9);
				printf("  ");
				SetColor(0, 7);
			}		//연못
			else if (map[i][j] == 8)
			{
				printf("▤");
			}		//벤치
		}
		printf("\n");
	}
	fclose(fp);
}
void draw_map5()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=182 lines=30");	//콘솔창 크기조절
	fp = fopen("갈멜관.txt", "r");		//map_one 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 81; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}			//포탈
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("웃");
				SetColor(0, 7);
			}			//사람
			else if (map[i][j] == 4)
				printf("〓");			//3학년 과실 문
			else if (map[i][j] == 5)
				printf("〓");			//전산실 문
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}

			else if (map[i][j] == 7)
				printf("▥");			//책상
			else if (map[i][j] == 8)
				printf("  ");			//대화
			else if (map[i][j] == 9)
				printf("▤");			//조교님 책상
			else if (map[i][j] == 10)
				printf("〓");			//조교실 문
			else if (map[i][j] == 11)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);
			}
			else if (map[i][j] == 12)
			{
				SetColor(14, 7);
				printf("◎");
				SetColor(0, 7);
			}		//동전
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map6()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=84 lines=50");	//콘솔창 크기조절
	fp = fopen("복음관 앞.txt", "r");		//map_one 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < 32; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}		//포탈
			else if (map[i][j] == 3)
			{
				SetColor(10, 7);
				printf("♣");
				SetColor(0, 7);
			}		//나무
			else if (map[i][j] == 4)
			{
				SetColor(12, 7);
				printf("♣");
				SetColor(0, 7);
			}
			else if (map[i][j] == 5)
			{
				printf("▤");
			}
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◎");
				SetColor(0, 7);
			}	//동전
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map7()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=84 lines=50");	//콘솔창 크기조절
	fp = fopen("복음관.txt", "r");		//복음관 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < 32; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}			//포탈
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("웃");
				SetColor(0, 7);
			}			//남자 사람
			else if (map[i][j] == 4)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);
			}			//여자 사람
			else if (map[i][j] == 5)
			{
				SetColor(2, 7);
				printf("≡");
				SetColor(0, 7);
			}			//학생증
			else if (map[i][j] == 6)
			{
				printf("▥");			//교수님 사무실 책상1
			}
			else if (map[i][j] == 7)
			{
				printf("▤");			//교수님 사무실 책상2
			}
			else if (map[i][j] == 8)
				printf("||");			//교수님 사무실 문
			else if (map[i][j] == 9)
				printf("||");			//현우석 교수님 사무실 문
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map8()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=36");						//콘솔창 크기조절
	fp = fopen("원벤.txt", "r");		//원벤 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 34; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");			//벽
			else if (map[i][j] == 0)
				printf("  ");			//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");			//포탈
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(10, 7);
				printf("♣");
				SetColor(0, 7);
			}			//나무
			else if (map[i][j] == 4)
			{
				SetColor(0, 10);
				printf("  ");			//잔디밭
				SetColor(0, 7);
			}
			else if (map[i][j] == 5) //벤치
				printf("▤");
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map9()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=21");	//콘솔창 크기조절
	fp = fopen("로고스 홀 입구.txt", "r");	//로고스 홀 입구 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("▤");
			else if (map[i][j] == 4)
				printf("▒");
			else if (map[i][j] == 5)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}
			else if (map[i][j] == 6)
			{
				printf("▤");
			}
			else if (map[i][j] == 7)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
			{
				SetColor(0, 0);
				printf("  ");			//기둥
				SetColor(0, 7);
			}
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map10()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");	//콘솔창 크기조절
	fp = fopen("식당.txt", "r");	//식당 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");				//블럭
			else if (map[i][j] == 0)
				printf("  ");				//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");				//포탈
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("▥");				//식탁
			else if (map[i][j] == 4)
				printf("▒");				//식권 판매기
			else if (map[i][j] == 5)
				printf("▩");				//컵 보관대
			else if (map[i][j] == 6)
			{
				SetColor(9, 7);
				printf("웃");				//남자
				SetColor(0, 7);
			}
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);				//여자
			}
			else if (map[i][j] == 8)
				printf("||");
			else if (map[i][j] == 9)
				printf("〓");
			else if (map[i][j] == 10)
			{
				SetColor(14, 7);
				printf("◎");
				SetColor(0, 7);
			}		//동전	
			else if (map[i][j] == 11)
				printf("▥");
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map11()
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=182 lines=50");	//콘솔창 크기조절
	fp = fopen("로고스 홀.txt", "r");	//로고스 홀 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 47; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");				//블럭	
			else if (map[i][j] == 0)
				printf("  ");				//공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");				//포탈1
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("▤");				//로고스 홀 의자
			else if (map[i][j] == 4)
				printf("†");
			else if (map[i][j] == 5)
			{
				SetColor(9, 7);
				printf("웃");				//남자
				SetColor(0, 7);
			}
			else if (map[i][j] == 6)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);				//여자
			}
			else if (map[i][j] == 7)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");				//포탈2
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");				//포탈3
				SetColor(0, 7);
			}
			else if (map[i][j] == 9)
				printf("  ");				//인사

		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map12()                                 //카페테리아
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");               //콘솔창 크기조절
	fp = fopen("카페테리아.txt", "r");   //맵1 파일경로&불러오기
	if (fp == NULL)
	{
		printf("실패\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("■");         //블럭
			else if (map[i][j] == 0)
				printf("  ");         //공간
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("◇");         //포탈
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("♨");            //커피
			else if (map[i][j] == 4)
				printf("▦");            //탁자
			else if (map[i][j] == 5)
				printf("▤");            //의자
			else if (map[i][j] == 6)
			{
				SetColor(9, 7);
				printf("웃");            //남자
				SetColor(0, 7);
			}
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("웃");
				SetColor(0, 7);            //여자
			}
			else if (map[i][j] == 8)
			{
				SetColor(10, 4);
				printf("  ");
				SetColor(0, 7);   //주문하는 곳
			}
		}
		printf("\n");
	}
	fclose(fp);
}

void draw_Quiz()
{
	int i;

	system("mode con cols=72 lines=20");
	system("cls");

	gotoxy(2, 2);
	printf("┌");
	gotoxy(68, 2);
	printf("┐");
	gotoxy(2, 18);
	printf("└");
	gotoxy(68, 18);
	printf("┘");
	gotoxy(4, 2);
	for (i = 0; i < 32; i++)
		printf("─");
	gotoxy(4, 18);
	for (i = 0; i < 32; i++)
		printf("─");
	for (i = 0; i < 15; i++)
	{
		gotoxy(2, i + 3);
		printf("│");
		printf("\n");
	}
	for (i = 0; i < 15; i++)
	{
		gotoxy(68, i + 3);
		printf("│");
		printf("\n");
	}
}

void draw_Quest()
{
	int i;

	system("mode con cols=50 lines=25");
	gotoxy(2, 2);
	printf("┌");
	gotoxy(44, 2);
	printf("┐");
	gotoxy(2, 23);
	printf("└");
	gotoxy(44, 23);
	printf("┘");
	gotoxy(4, 2);
	for (i = 0; i < 20; i++)
		printf("─");
	gotoxy(4, 23);
	for (i = 0; i < 20; i++)
		printf("─");
	for (i = 0; i < 20; i++)
	{
		gotoxy(2, i + 3);
		printf("│");
		printf("\n");
	}
	for (i = 0; i < 20; i++)
	{
		gotoxy(44, i + 3);
		printf("│");
		printf("\n");
	}

	gotoxy(18, 4);
	printf("할 일 목록");
	if (Quest1 >= 1)
	{
		gotoxy(4, 8);
		printf("1. 자판기에서 음료수 뽑아 마시기");
		SetColor(2, 7);
		gotoxy(37, 8);
		printf("완료");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 8);
		printf("1. 자판기에서 음료수 뽑아 마시기");
	}
	if (Quest2 >= 1)
	{
		gotoxy(4, 11);
		printf("2. 현 교수님이 내시는 문제 맞추기");
		gotoxy(8, 12);
		printf("보상: 학생증");
		SetColor(2, 7);
		gotoxy(38, 11);
		printf("완료");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 11);
		printf("2. 현 교수님이 내시는 문제 맞추기");
		gotoxy(8, 12);
		printf("보상: 학생증");
	}
	if (Quest3 >= 1)
	{
		gotoxy(4, 14);
		printf("3. 식권 뽑아서 점심 먹기");
		SetColor(2, 7);
		gotoxy(29, 14);
		printf("완료");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 14);
		printf("3. 식권 뽑아서 점심 먹기");
	}
	if (Quest4 >= 1)
	{
		gotoxy(4, 17);
		printf("4. 학생증을 찾아서 채플 듣기");
		SetColor(2, 7);
		gotoxy(33, 17);
		printf("완료");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 17);
		printf("4. 학생증을 찾아서 채플 듣기");
	}
	if (Quest5 >= 1)
	{
		gotoxy(4, 20);
		printf("5. 카운터에서 커피 주문해 마시기");
		SetColor(2, 7);
		gotoxy(37, 20);
		printf("완료");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 20);
		printf("5. 카운터에서 커피 주문해 마시기");
	}
}

void draw_Map()
{
	int i;

	system("mode con cols=50 lines=25");
	gotoxy(2, 2);
	printf("┌");
	gotoxy(44, 2);
	printf("┐");
	gotoxy(2, 23);
	printf("└");
	gotoxy(44, 23);
	printf("┘");
	gotoxy(4, 2);
	for (i = 0; i < 20; i++)
		printf("─");
	gotoxy(4, 23);
	for (i = 0; i < 20; i++)
		printf("─");
	gotoxy(3, 6);
	for (i = 0; i < 20; i++)
		printf("─");
	for (i = 0; i < 20; i++)
	{
		gotoxy(2, i + 3);
		printf("│");
		printf("\n");
	}
	for (i = 0; i < 20; i++)
	{
		gotoxy(44, i + 3);
		printf("│");
		printf("\n");
	}

	gotoxy(22, 4);
	printf("지도");

	gotoxy(22, 22);
	printf("입구");

	gotoxy(23, 21);
	printf("↑");

	gotoxy(20, 19);
	printf("두갈래길");

	gotoxy(15, 18);
	printf("↖              ↗");

	gotoxy(5, 16);
	printf("갈멜관   모리아관              일립관");

	gotoxy(7, 15);
	printf("↑                       ↖");

	gotoxy(5, 12);
	printf("복음관    →     원벤");

	gotoxy(7, 11);
	printf("↑              ↑");

	gotoxy(5, 9);
	printf("카페테리아     로고스홀");
}

void Prologue()
{
	system("mode con cols=40 lines=20");

	int i, j = 1, y = 19;
	int num[5] = { 19,19,19,19,19 };

	for (i = 0; i < 20; i++)
	{
		gotoxy(15, y + 1);
		printf("      ");
		gotoxy(15, y);
		printf("오늘도");

		y--;
		if (y <= 16)
		{
			gotoxy(11, num[0] + 1);
			printf("              ");
			gotoxy(11, num[0]);
			printf("한국성서대학교");
			num[0]--;
		}
		if (y <= 14)
		{
			gotoxy(8, num[1] + 1);
			printf("                     ");
			gotoxy(8, num[1]);
			printf("컴퓨터소프트웨어 학과");
			num[1]--;
		}
		if (y <= 12)
		{
			gotoxy(13, num[2] + 1);
			printf("           ");
			gotoxy(13, num[2]);
			printf("김컴소 군은");
			num[2]--;
		}
		if (y <= 10)
		{
			gotoxy(13, num[3] + 1);
			printf("            ");
			gotoxy(13, num[3]);
			printf("등교를 한다.");
			num[3]--;
		}
		if (y <= 8)
		{
			gotoxy(0, num[4] + 1);
			printf("                                        ");
			gotoxy(0, num[4]);
			printf("※주의 이 게임은 전지적 컴소 시점 입니다");
			num[4]--;
		}
		Sleep(TIME);
	}
}

void Quiz()
{
	draw_Quiz();
	while (end)
	{
		switch (Quiz_num)
		{
		case 1:
			Q1();
			break;
		case 2:
			Q2();
			break;
		case 3:
			Q3();
			break;
		default:
			break;
		}
	}
}

void Q1()
{
	while (1)
	{
		gotoxy(10, 5);
		printf("문제.1 C 언어를 개발한 사람의 이름은?");
		gotoxy(10, 7);
		printf("1. 비야네 스트롭 스트룹");
		gotoxy(10, 9);
		printf("2. 김용호");
		gotoxy(10, 11);
		printf("3. 데니스 리치");

		choice = getch();

		if (choice == '1')
		{
			gotoxy(10, 13);
			printf("땡!");
			Sleep(300);
			gotoxy(10, 13);
			printf("   ");
			continue;
		}
		else if (choice == '2')
		{
			gotoxy(10, 13);
			printf("정답에 가까웠다.");
			Sleep(300);
			gotoxy(10, 13);
			printf("                ");
			continue;

		}
		else if (choice == '3')
		{
			gotoxy(10, 13);
			printf("정답!");
			Sleep(300);
			gotoxy(10, 13);
			printf("     ");
			Quiz_num = 2;
			break;
		}
		else
		{
			gotoxy(10, 13);
			printf("1~3번 중에 고릅시다.^^");
			Sleep(300);
			gotoxy(10, 13);
			printf("                      ");
			continue;
		}
	}
}

void Q2()
{
	while (1)
	{
		gotoxy(10, 5);
		printf("문제.2 전역 변수는 어디에 선언되는가?");
		gotoxy(10, 7);
		printf("1. 함수 내부                       ");
		gotoxy(10, 9);
		printf("2. 함수 외부");
		gotoxy(10, 11);
		printf("3. 메인 함수 ");

		choice = getch();

		if (choice == '3')
		{
			gotoxy(10, 13);
			printf("땡!");
			Sleep(300);
			gotoxy(10, 13);
			printf("   ");
			continue;
		}
		else if (choice == '1')
		{
			gotoxy(10, 13);
			printf("정답에 가까웠다.");
			Sleep(300);
			gotoxy(10, 13);
			printf("                ");
			continue;

		}
		else if (choice == '2')
		{
			gotoxy(10, 13);
			printf("정답!");
			Sleep(300);
			gotoxy(10, 13);
			printf("     ");
			Quiz_num = 3;
			break;
		}
		else
		{
			gotoxy(10, 13);
			printf("1~3번 중에 고릅시다.^^");
			Sleep(300);
			gotoxy(10, 13);
			printf("                      ");
			continue;
		}
	}
}

void Q3()
{
	while (1)
	{
		gotoxy(10, 5);
		printf("문제.3 int a[2][2] = {1,2,3,4}에서 a[1][1]의 초기값은?");
		gotoxy(10, 7);
		printf("1. 1                ");
		gotoxy(10, 9);
		printf("2. 2                ");
		gotoxy(10, 11);
		printf("3. 3                ");
		gotoxy(10, 13);
		printf("4. 4                ");

		choice = getch();

		if (choice == '1')
		{
			gotoxy(10, 15);
			printf("땡!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;
		}
		else if (choice == '2')
		{
			gotoxy(10, 15);
			printf("땡!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;

		}
		else if (choice == '3')
		{
			gotoxy(10, 15);
			printf("땡!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;
		}
		else if (choice == '4')
		{
			gotoxy(10, 15);
			printf("정답!");
			Sleep(300);
			gotoxy(10, 15);
			printf("     ");
			end = 0;
			break;
		}
		else
		{
			gotoxy(10, 15);
			printf("1~4번 중에 고릅시다.^^");
			Sleep(300);
			gotoxy(10, 15);
			printf("                      ");
			continue;
		}
	}
}

void ending_credit()
{
	system("mode con cols=50 lines=41");

	int i, j = 1, y = 40;
	int num[14] = { 40,40,40,40,40,40,40,40,40,40,40,40,40,40 };

	for (i = 0; i < 40; i++)
	{
		gotoxy(16, y + 1);
		printf("               ");
		gotoxy(16, y);
		printf("-Ending Credit-");
		y--;
		if (y <= 37)
		{
			gotoxy(16, num[0] + 1);
			printf("                     ");
			gotoxy(16, num[0]);
			printf("제작자: 김용호 이어진");
			num[0]--;
		}
		if (y <= 34)
		{
			gotoxy(14, num[1] + 1);
			printf("                  ");
			gotoxy(14, num[1]);
			printf("-도움을 주신 분들-");
			num[1]--;
		}
		if (y <= 32)
		{
			gotoxy(16, num[2] + 1);
			printf("             ");
			gotoxy(16, num[2]);
			printf("최은비 조교님");
			num[2]--;
		}
		if (y <= 30)
		{
			gotoxy(16, num[3] + 1);
			printf("             ");
			gotoxy(16, num[3]);
			printf("남궁찬 선배님");
			num[3]--;
		}
		if (y <= 28)
		{
			gotoxy(16, num[4] + 1);
			printf("             ");
			gotoxy(16, num[4]);
			printf("현우석 교수님");
			num[4]--;
		}
		if (y <= 25)
		{
			gotoxy(19, num[5] + 1);
			printf("      ");
			gotoxy(19, num[5]);
			printf("-후기-");
			num[5]--;
		}
		if (y <= 22)
		{
			gotoxy(10, num[6] + 1);
			printf("                          ");
			gotoxy(10, num[6]);
			printf("이번 프로젝트를 진행하면서");
			num[6]--;
		}
		if (y <= 20)
		{
			gotoxy(10, num[7] + 1);
			printf("                             ");
			gotoxy(10, num[7]);
			printf("주석의 중요성을 절실히 깨닫고");
			num[7]--;
		}
		if (y <= 18)
		{
			gotoxy(6, num[8] + 1);
			printf("                                       ");
			gotoxy(6, num[8]);
			printf("디버깅 실력이 정말 많이 늘은것 같네요^^");
			num[8]--;
		}
		if (y <= 16)
		{
			gotoxy(8, num[9] + 1);
			printf("                                   ");
			gotoxy(8, num[9]);
			printf("C언어로 만든 저희의 첫번째 작품인데");
			num[9]--;
		}
		if (y <= 14)
		{
			gotoxy(1, num[10] + 1);
			printf("                                                ");
			gotoxy(1, num[10]);
			printf("후회없이 저희의 영혼을 갈아 넣었만들었습니다ㅎㅎ");
			num[10]--;
		}
		if (y <= 12)
		{
			gotoxy(12, num[11] + 1);
			printf("                           ");
			gotoxy(12, num[11]);
			printf("플레이 해주셔서 감사합니다.");
			num[11]--;
		}
		if (y <= 10)
		{
			gotoxy(16, num[12] + 1);
			printf("             ");
			gotoxy(16, num[12]);
			printf("(_ _) ( _ _ )");
			num[12]--;
		}
		if (y <= 8)
		{
			gotoxy(20, num[13] + 1);
			printf("     ");
			gotoxy(20, num[13]);
			printf("-END-");
			num[13]--;
		}
		Sleep(TIME);
		if (y == 0)
		{
			gotoxy(0, 0);
			printf("                                              ");
		}
	}
	gotoxy(0, 40);
	printf("종료하시려면 아무키나 누르세요");
	getch();
	exit(0);
}