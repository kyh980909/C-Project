#include <stdio.h>
#include <windows.h>

#define UP 72						//�Է¹��� ������ �ƽ�Ű�ڵ尪
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32
#define ESC 27
#define MAP_LEN_X 81				//�� ���� ����
#define MAP_LEN_Y 48				//�� ���� ����
#define CHARACTER_COLOR 0			//�ɸ��� ����(������)
#define PORTAL_COLOR 14				//��Ż ����(�����)
#define TIME 300					//���ѷα� �ö󰡴� �ð�

int num = 1;						//num�� ��
void gotoxy(int x, int y);			//��ǥ�Լ�
void start_menu();					//����ȭ��
void select_menu();					//����Ű

void character_map1();				//��1 �ɸ���
void character_map2();				//��2 �ɸ���
void character_map3();				//����� �� �ɸ���
void character_map4();				//�ϸ��� �� �ɸ���
void character_map5();				//����� �ɸ���
void character_map6();				//������ �� �ɸ���
void character_map7();				//������ 5�� �ɸ���
void character_map8();				//���� �ɸ���
void character_map9();				//�ΰ� Ȧ �Ա�
void character_map10();				//�Ĵ�
void character_map11();				//�ΰ� Ȧ
void character_map12();				//ī���׸���

void draw_start_menu();				//����ȭ��
void draw_map1();					//��1
void draw_map2();					//�ΰ�����
void draw_map3();					//����� ��
void draw_map4();					//�ϸ��� ��
void draw_map5();					//�����
void draw_map6();					//������ ��
void draw_map7();					//������ 5��
void draw_map8();					//����
void draw_map9();					//�ΰ� Ȧ �Ա�
void draw_map10();					//�Ĵ�
void draw_map11();					//�ΰ� Ȧ
void draw_map12();					//ī���׸���
void draw_Quiz();					//����â
void draw_Quest();					//����Ʈ â
void draw_Map();					//�� â
void Prologue();					//���ѷα�
void ending_credit();				//����ũ����

void setcursortype();				//Ŀ�� ����� �Լ�
void character_pause_pos();			//�ɸ��� �ʱ� ��ǥ �� �Ͻ����� �������� �ɸ��� ���� ��ǥ ����
void SetColor(unsigned short text, unsigned short back);	//���ڰ� ���� �ٲٴ� �Լ�

void p1_go();						//��2�� ���� ��Ż
void p1_come();						//��2���� ��1�� ���� ��Ż
void p2_go();						//��2���� ����� ������ ���� ��Ż
void p2_come();						//����� �տ��� ��2�� ���� ��Ż
void p3_go_r();						//����� �տ��� ��������� ���� ��Ż(������)
void p3_go_l();						//����� �տ��� ��������� ���� ��Ż(����)
void p3_come_r();					//��������� ����� ������ ���� ��Ż(������)
void p3_come_l();					//��������� ����� ������ ���� ��Ż(����)
void p4_go();						//��2���� �ϸ��� ������ ���� ��Ż
void p4_come();						//�ϸ��� �տ��� ��2�� ���� ��Ż
void p5_go();						//����� �տ��� ������ ������ ���� ��Ż
void p5_come();						//������ �տ��� ����� ������ ���� ��Ż
void p6_go();						//������ �տ��� ���������� ���� ��Ż
void p6_come();						//���������� ������ ������ ���� ��Ż
void p7_go();						//������ �տ��� �������� ���� ��Ż
void p7_go_c();						//ī���׸��ƿ��� ������ ������ ���� ��Ż
void p7_come_c();					//������ �տ��� ī���׸��Ʒ� ���� ��Ż
void p7_come();						//�������� ������ ������ ���� ��Ż
void p8_go();						//�������� �ϸ��� ������ ���� ��Ż
void p8_come();						//�ϸ��� �տ��� �������� ���� ��Ż
void p9_go();						//�������� �ΰ� Ȧ �Ա��� ���� ��Ż
void p9_come();						//�ΰ� Ȧ �Ա����� �������� ���� ��Ż
void p10_go_r();					//�ΰ� Ȧ �Ա����� �Ĵ簡�� ��Ż(�Ĵ� ������ ��Ż)
void p10_come_l();					//�Ĵ翡�� �ΰ� Ȧ �Ա����� ��Ż(�ΰ� Ȧ �Ա� ���� ��Ż)
void p10_go_l();					//�ΰ� Ȧ �Ա����� �Ĵ簡�� ��Ż(�Ĵ� ���� ��Ż)
void p10_come_r();					//�Ĵ翡�� �ΰ� Ȧ �Ա����� ��Ż(�ΰ� Ȧ �Ա� ������ ��Ż)
void p11_go1();						//�ΰ� Ȧ �Ա����� �ΰ� Ȧ ���� 1�� ��Ż
void p11_go2();						//�ΰ� Ȧ �Ա����� �ΰ� Ȧ ���� 2�� ��Ż
void p11_go3();						//�ΰ� Ȧ �Ա����� �ΰ� Ȧ ���� 3�� ��Ż
void p11_come1();					//�ΰ� Ȧ ���� �ΰ� Ȧ �Ա����� 1�� ��Ż
void p11_come2();					//�ΰ� Ȧ ���� �ΰ� Ȧ �Ա����� 2�� ��Ż
void p11_come3();					//�ΰ� Ȧ ���� �ΰ� Ȧ �Ա����� 3�� ��Ż

void map1_status();					//������ �Ա� ����â
void map2_status();					//�� ���� �� ����â
void map3_status();					//����� �� ����â
void map4_status();					//�ϸ��� �� ����â
void map5_status();					//����� ����â
void map6_status();					//������ �� ����â
void map7_status();					//������ ����â
void map8_status();					//���� ����â
void map9_status();					//�ΰ� Ȧ �Ա� ����â
void map10_status();				//�Ĵ� ����â
void map11_status();				//�ΰ� Ȧ ����â
void map12_status();				//ī���׸��� ����â

void Quiz();						//�л����� ��� ���� ����
void Q1();							//1�� ����
void Q2();							//2�� ����
void Q3();							//3�� ����
int end = 1;						//Quiz�Լ��� while���� ������ ���� ����

int menuPos = 17;				//Y�� �ʱⰪ
int x = 104, y = 24;			//�ɸ��� �ʱ� ��ǥ��, x,y ��ǥ ��������
int map[MAP_LEN_Y][MAP_LEN_X];	//�� ���̽�
int portal1;					//��Ż1 �Դ� ���� �Ҷ� �ɸ��� ��ǥ �����ִ� ����
int portal2;					//��Ż2 �Դ� ���� �Ҷ� �ɸ��� ��ǥ �����ִ� ����
int portal3;					//��2�� ����� ��
int portal4;					//��2�� �ϸ��� ��
int portal5;					//������� ����� ��
int portal6;					//����� �հ� ������ ��
int portal7;					//������ �հ� ������
int portal8;					//������ �հ� ����
int portal9;					//������ �ϸ��� ��
int portal10;					//�ΰ� Ȧ �Ա�
int portal11;					//�Ĵ�
int portal12;					//�ΰ� Ȧ
int portal13;					//ī���׸���
int end_portal = 1;				//���� ���� ��Ż

int total_coin;					//�ֿ� �������� ��
int drink;						//�̾� ���� ����� ���� ����
int food_ticket;				//�ı� ����
int food;						//����
int student_card;				//�л���
int choice, Quiz_num = 1;		//choice�� ���� Ǯ�� �� ����, Quiz_num�� ���� ��ȣ
int Total_Quest;				//����Ʈ Ŭ���� ����
int Quest1;						//����Ʈ1
int Quest2;						//����Ʈ2
int Quest3;						//����Ʈ3
int Quest4;						//����Ʈ4
int Quest5;						//����Ʈ5

int main(void)
{
	setcursortype();				// �����̴� Ŀ���� ���ش�.
	Prologue();
	start_menu();
	select_menu();

	if (menuPos == 17)				//���ӽ���
	{
		while (1)
		{
			system("cls");
			switch (num)				//�ʵ�
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
	else if (menuPos == 18)			//������ �� ���
	{
		ending_credit();
		getch();
	}
	else if (menuPos == 19)			//��������
		exit(1);

	return 0;
}

void gotoxy(int x, int y)			//��ǥ�Լ�
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
				printf("��");
			}
			else if (menuPos == 19)
			{
				gotoxy(50, menuPos);
				printf("  ");
				gotoxy(51, menuPos - 1);
				printf("��");
				menuPos--;

			}
			else if (menuPos == 18)
			{
				gotoxy(50, menuPos);
				printf("  ");
				gotoxy(51, menuPos - 1);
				printf("��");
				menuPos--;
			}
			break;
		case DOWN:	//DOWN
			if (menuPos <= 17)
			{
				gotoxy(50, 17);
				printf("  ");
				gotoxy(51, 18);
				printf("��");
				menuPos++;
			}
			else if (menuPos == 18)
			{
				gotoxy(50, 18);
				printf("  ");
				gotoxy(51, 19);
				printf("��");
				menuPos++;
			}
			else if (menuPos >= 19)
			{
				menuPos = 17;
				gotoxy(50, 19);
				printf("  ");
				gotoxy(51, 17);
				printf("��");
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

void start_menu() //����ȭ��
{
	draw_start_menu();

	gotoxy(53, 17);
	printf("��ϱ�");	//menuPos 17
	gotoxy(53, 18);
	printf("������ �� ���");	//menuPos 18
	gotoxy(53, 19);
	printf("����");		//menuPos 19
	gotoxy(51, 17);
	printf("��");
}

void character_map1()										//�б� �Ա�
{
	FILE *fp;
	fp = fopen("��1.txt", "r");	//��1 ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	if (portal1 == 0)
		character_pause_pos();
	else if (portal1 == 1)
		p1_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;									//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);						//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:											//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{

				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1)
				break;

		case RIGHT:											//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 4)
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x, y);
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("������ �ֿ���!");
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
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 26);
					printf("                    ");
				}
				break;
			}
			else if (map[y][m_x] == 1)
				break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 4)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("������ �ֿ���!");
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

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y + 1][check_x] == 2)
			{
				if (Total_Quest >= 5)
				{
					system("mode con cols=20 lines=20");
					system("cls");
					gotoxy(2, 10);
					printf("�� �� �� ��!!!!");
					Sleep(1000);
					system("cls");
					ending_credit();
				}
				else
				{
					gotoxy(2, 26);
					printf("���� ���� �ʹ�..�Ф�");
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
	fp = fopen("��2.txt", "r");	//��2 ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:												//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 3;										//��2���� ����� ������ �̵�
				portal3 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			else if (map[y][m_x] == 3)
				break;
			else if (map[y][m_x] == 4)
				break;

		case RIGHT:												//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			else if (map[y - 1][check_x] == 3)
				break;
			else if (map[y - 1][check_x] == 4)
				break;

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
	fp = fopen("����� ��.txt", "r");   //����� �� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
	int m_x, check_x = x / 2;                              //�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);         //�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:                                    //�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;                           //���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0 || map[y][m_x] == 5 || map[y][m_x] == 8 || map[y][m_x] == 11)         //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;

		case RIGHT:                                 //�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;                        //���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0 || map[y][m_x] == 5 || map[y][m_x] == 8 || map[y][m_x] == 11)      //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case UP:                                          //�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0 || map[y - 1][check_x] == 5 || map[y - 1][check_x] == 8 || map[y - 1][check_x] == 11)      //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 48);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 48);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 48);
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 48);
					printf("                    ");
				}
				break;
			}
			else
				break;

		case DOWN:                                                                  //�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0 || map[y + 1][check_x] == 5 || map[y + 1][check_x] == 11)      //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("���...");
				Sleep(300);
				gotoxy(2, 48);
				printf("        ");
			}
			else if (map[y][check_x] == 11)
			{
				gotoxy(2, 48);
				printf("�������� �� ã���ô���..");
				Sleep(300);
				gotoxy(2, 48);
				printf("                        ");
			}
			else if (map[y][x / 2 - 1] == 7)
			{
				if (total_coin == 0)
				{
					gotoxy(2, 48);
					printf("������� ���÷��� ���� 1���� �ʿ��մϴ�.");
					Sleep(500);
					gotoxy(2, 48);
					printf("                                        ");
				}
				else if (total_coin >= 1)
				{
					gotoxy(2, 48);
					printf("������� ���Դ�.");
					Sleep(500);
					gotoxy(2, 48);
					printf("���� ����         ");
					Sleep(500);
					gotoxy(2, 48);
					printf("ļ.. �ÿ��ϴ�!");
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
				printf("����: ��� �ַ� ���� �ȳ�?");
				Sleep(1000);
				gotoxy(2, 48);
				printf("����: ���� �ַΰ� �����? ������");
				Sleep(1000);
				gotoxy(2, 48);
				printf("���� �ַ�: (xx...)              ");
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
	fp = fopen("�ϸ��� ��.txt", "r");	//�ϸ��� �� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	if (portal9 == 0)
		p8_go();
	else if (portal9 == 1)
		p4_go();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;							//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);	//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:										//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;							//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case RIGHT:								//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;					//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)				//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 47);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 47);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 47);
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 47);
					printf("                    ");
				}

				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 3)
				break;

			break;
		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y + 1][check_x] == 4)
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 47);
					printf("������ �ֿ���!");
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
	fp = fopen("�����.txt", "r");	//����� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}
	if (portal5 == 1)
		p3_go_r();
	else if (portal5 == 2)
		p3_go_l();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;							//�迭�� �� üũ, y�� �̵��� x��
	int coin = 0;

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);	//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:										//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;							//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0 || map[y][m_x] == 8)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case RIGHT:										//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;							//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0 || map[y][m_x] == 8)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 27);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 27);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 27);
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 27);
					printf("                    ");
				}

				break;
			}

			break;
		case UP:										//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)				//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 2)			//����� ������ ��Ż
			{
				system("cls");
				num = 3;
				portal3 = 1;
				goto exit;
			}
			else if (map[y - 1][check_x] == 6)			//����� ���� ��Ż
			{
				system("cls");
				num = 3;
				portal3 = 2;
				goto exit;
			}
			else if (map[y - 1][check_x] == 4)
			{
				gotoxy(2, 27);
				printf("3�г� ������ �� �� �����ϴ�.");
				Sleep(500);
				gotoxy(2, 27);
				printf("                                 ");
				break;
			}
			else if (map[y - 1][check_x] == 5)
			{
				gotoxy(2, 27);
				printf("������� �� �� �����ϴ�.");
				Sleep(500);
				gotoxy(2, 27);
				printf("                               ");
				break;
			}
			else if (map[y - 1][check_x] == 10)
			{
				gotoxy(2, 27);
				printf("�������� ���� �ٻ޴ϴ�.");
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 27);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 27);
					printf("                ");
					gotoxy(172, 5);
					printf("%d", total_coin);
				}

				break;
			}

			break;

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else
				break;

			break;

		case SPACE:
			if (map[y][check_x] == 8)
			{
				gotoxy(2, 27);
				printf("���ļ�: �� ���� �����̱���..");
				Sleep(800);
				gotoxy(2, 27);
				printf("����ȣ: ������ ���ؼ�...������..");
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
	fp = fopen("������ ��.txt", "r");	//������ �ո� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	if (portal7 == 0)
		p5_go();
	else if (portal7 == 1)
		p6_come();
	else if (portal7 == 2)
		p7_come();
	else if (portal7 == 3)
		p7_go_c();		//ī���׸��� > ������ ��
	else if (portal7 == 4)
		p7_come();

	int coin = 0;
	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);	//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:											//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 48);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 48);
					printf("                ");
					gotoxy(74, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 48);
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 48);
					printf("                    ");
				}

				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 5)
				break;

		case RIGHT:											//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				system("cls");
				num = 8;
				portal4 = 0;
				goto exit;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 5)
				break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
	fp = fopen("������.txt", "r");	//�������� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	if (portal8 == 0)
		p6_go();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);	//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:											//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 8)
			{
				gotoxy(2, 48);
				printf("�� �� �����ϴ�.");
				Sleep(500);
				gotoxy(2, 48);
				printf("                   ");
			}
			else if (map[y][m_x] == 9)
			{
				gotoxy(2, 48);
				printf("���ļ�: �ȳ��� �輼��~");
				Sleep(800);
				gotoxy(2, 48);
				printf("                      ");
				x -= 4;
				check_x -= 2;
				gotoxy(x + 4, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:											//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("�� �� �����ϴ�.");
				Sleep(500);
				gotoxy(2, 48);
				printf("                   ");
			}
			else if (map[y][m_x] == 9)
			{
				gotoxy(2, 48);
				printf("�ȶ�");
				Sleep(800);
				gotoxy(2, 48);
				printf("�� ������: ��������");
				Sleep(800);
				x += 4;
				check_x += 2;
				gotoxy(x - 4, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				Sleep(800);
				gotoxy(2, 48);
				printf("���ļ�: �ȳ��ϼ��� ������~");
				Sleep(800);
				gotoxy(2, 48);
				printf("�� ������: ��� �ļҾ�~^^ ");
				Sleep(800);
				gotoxy(2, 48);
				printf("                            ");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y + 1][check_x] == 1 || y == 25)
				break;
			break;

		case SPACE:
			if (map[y][x / 2 + 2] == 4)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				if (Quest2 == 0)
				{
					gotoxy(2, 48);
					printf("�� ������: ä�� �������� �л����� �ʿ��� ����");
					Sleep(800);
					gotoxy(2, 48);
					printf("�� ������: �׸��� ������ �л����� ����       ");
					Sleep(800);
					gotoxy(2, 48);
					printf("�� ������: �׷��� �׳� �ָ� ��̾�����?      ");
					Sleep(800);
					gotoxy(2, 48);
					printf("�� ������: ���� ���� ������ ���߸� �л����� �ٲ�~^^");
					Sleep(800);
					gotoxy(2, 48);
					printf("3�� �Ŀ� ������ ���ɴϴ�.                          ");
					Sleep(1000);
					gotoxy(2, 48);
					printf("2�� �Ŀ� ������ ���ɴϴ�.                          ");
					Sleep(1000);
					gotoxy(2, 48);
					printf("1�� �Ŀ� ������ ���ɴϴ�.                          ");
					Sleep(1000);
					Quiz();
					draw_map7();
					gotoxy(46, 6);
					printf("��");
					student_card = 1;
					map7_status();
					gotoxy(2, 48);
					printf("�� ������: �� ����� ���� �л��� �̾�^^ ä�� �� �帮��~");
					getch();
					gotoxy(2, 48);
					printf("�л����� �����.                                       ");
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
	fp = fopen("����.txt", "r");	//������ ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
	int m_x, check_x = x / 2;									//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);						//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:											//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{

				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				system("cls");
				num = 6;
				portal7 = 2;
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;

		case RIGHT:											//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;								//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)							//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
				}
			}
			else if (map[y][m_x] == 1)
				break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)						//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 4)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("������ �ֿ���!");
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

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
	fp = fopen("�ΰ� Ȧ �Ա�.txt", "r");	//�ΰ� Ȧ �Ա� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:												//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 10;										//�ΰ� Ȧ �տ��� �Ĵ����� �̵�
				portal11 = 0;									//�Ĵ� ������ ��Ż�� ������
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 10;										//�ΰ� Ȧ �տ��� �Ĵ����� �̵�
				portal11 = 1;									//�Ĵ� ���� ��Ż�� ������
				goto exit;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 2)
			{
				if (student_card == 0)
				{
					gotoxy(2, 17);
					printf("�л����� ��� �� �� �����ϴ�.");
					Sleep(500);
					gotoxy(2, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//�ΰ� Ȧ �տ��� �ΰ� Ȧ�� �̵�
					portal12 = 0;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 5)
			{
				if (student_card == 0)
				{
					gotoxy(0, 17);
					printf("�л����� ��� �� �� �����ϴ�.");
					Sleep(500);
					gotoxy(0, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//�ΰ� Ȧ �տ��� �ΰ� Ȧ�� �̵�
					portal12 = 1;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 7)
			{
				if (student_card == 0)
				{
					gotoxy(0, 17);
					printf("�л����� ��� �� �� �����ϴ�.");
					Sleep(500);
					gotoxy(0, 17);
					printf("                                   ");
					break;
				}
				else
				{
					system("cls");
					num = 11;										//�ΰ� Ȧ �տ��� �ΰ� Ȧ�� �̵�
					portal12 = 2;
					goto exit;
				}
			}
			else if (map[y - 1][check_x] == 1 || map[y - 1][check_x] == 3 || map[y - 1][check_x] == 8)
				break;

		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

void character_map12()                              //ī���׸���
{
	FILE *fp;
	fp = fopen("ī���׸���.txt", "r");   //ī���׸��� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	if (portal13 == 1)
		p7_come_c();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;                           //�迭�� �� üũ, y�� �̵��� x��

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[26][61]);                  //�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:                                 //�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;                        //���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)                     //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 4 || map[y][m_x] == 5 || map[y][m_x] == 6 || map[y][m_x] == 7)
				break;

		case RIGHT:                                 //�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;                        //���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)                     //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1 || map[y][m_x] == 4 || map[y][m_x] == 5 || map[y][m_x] == 6 || map[y][m_x] == 7 || map[y][m_x] == 8)
				break;

		case UP:                                 //�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)                  //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				gotoxy(x, y);
				SetColor(CHARACTER_COLOR, 7);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 1 || map[y - 1][check_x] == 4 || map[y - 1][check_x] == 5 || map[y - 1][check_x] == 6 || map[y - 1][check_x] == 7)
				break;

		case DOWN:                                 //�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)                  //�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
					printf("Ŀ�Ǹ� ���÷��� ���� 1���� �ʿ��մϴ�.");
					Sleep(500);
					gotoxy(2, 26);
					printf("                                      ");
				}
				else if (total_coin >= 1)
				{
					gotoxy(2, 26);
					printf("Ŀ�ǰ� ���Դ�.");
					Sleep(500);
					gotoxy(2, 26);
					printf("��--��--      ");
					Sleep(500);
					gotoxy(2, 26);
					printf("Ŀ�Ƿ� ����������!!");
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
	fp = fopen("�Ĵ�.txt", "r");	//�Ĵ� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}
	if (portal11 == 0)
		p10_go_r();
	else if (portal11 == 1)
		p10_go_l();

	int ch;
	int i, j;
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��
	int coin = 0;

	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:												//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 2)
			{
				system("cls");
				num = 9;										//�ΰ� Ȧ �տ��� �Ĵ����� �̵�
				portal10 = 2;									//�Ĵ� ������ ��Ż�� ������
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
				printf("��");
				if (coin == 0)
				{
					coin++;
					total_coin++;
					gotoxy(2, 26);
					printf("������ �ֿ���!");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
					gotoxy(130, 5);
					printf("%d", total_coin);
				}
				else
				{
					gotoxy(2, 26);
					printf("�������� �˾Ҵµ�...");
					Sleep(300);
					gotoxy(2, 26);
					printf("                    ");
				}
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 10)
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;
		case DOWN:											//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
					printf("�ı��� �������� ���� 5���� �ʿ��մϴ�.");
					Sleep(500);
					gotoxy(2, 26);
					printf("                                       ");
					break;
				}
				else if ((total_coin > 0) && (total_coin >= 5) || (total_coin % 5 == 0))	//������ 1���̻��̰� ������ 10�� �̻��̰ų� ������ ������ 10�� ��� ���� �� �ı��� ������ �ְ� ������ 0���� ������ if ���
				{
					gotoxy(2, 26);
					printf("�ı��� �̴´�.");
					getch();
					gotoxy(2, 26);
					printf("(���� ����)   ");
					getch();
					gotoxy(2, 26);
					printf("�ı��� ���Դ�.");
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
					printf("�ı��� �����ϴ�.");
					Sleep(300);
					gotoxy(2, 26);
					printf("                ");
					break;
				}
				else if (food_ticket > 0)
				{
					gotoxy(2, 26);
					printf("���ļ�: �ȳ��ϼ���~^^");
					getch();
					gotoxy(2, 26);
					printf("���ļ�: �߽� �ϳ� �ּ���~");
					getch();
					gotoxy(2, 26);
					printf("�߽� �� ���� �����.     ");
					gotoxy(2, 26);
					printf("�ı� �� ���� �Ҿ���.     ");
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
					printf("�ȳ�");
					Sleep(500);
					gotoxy(2, 26);
					printf("����");
					Sleep(500);
					gotoxy(2, 26);
					printf("�ķ�� �ķ��");
					Sleep(500);
					gotoxy(2, 26);
					printf("���ļ�: �� �Ծ���~");
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
	fp = fopen("�ΰ� Ȧ.txt", "r");	//�ΰ� Ȧ ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
	int m_x, check_x = x / 2;										//�迭�� �� üũ, y�� �̵��� x��

	gotoxy(2, 47);
	printf("������: �ȳ��ϼ���~^^");
	Sleep(500);
	while (1)
	{
		ch = getch();
		fscanf(fp, "%d", &map[MAP_LEN_Y][MAP_LEN_X]);			//�� ���� �޾ƿ���

		switch (ch)
		{
		case LEFT:												//�ɸ��� ���� �̵��� �浹üũ
			m_x = x / 2 - 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x -= 2;
				check_x--;
				gotoxy(x + 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case RIGHT:												//�ɸ��� ������ �̵��� �浹üũ
			m_x = x / 2 + 1;									//���ڴ� 2ĭ�� �����ؼ� gotoxy���� �迭�� ��ǥ�� ���߱� ���� ����
			if (map[y][m_x] == 0)								//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				x += 2;
				check_x++;
				gotoxy(x - 2, y);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y][m_x] == 1)
				break;
			break;

		case UP:											//�ɸ��� ���� �̵��� �浹üũ
			if (map[y][check_x] == 9)
			{
				gotoxy(2, 47);
				printf("                      ");
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 0)					//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y--;
				gotoxy(x, y + 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
				break;
			}
			else if (map[y - 1][check_x] == 1)
				break;
			break;

		case DOWN:														//�ɸ��� �Ʒ��� �̵��� �浹üũ
			if (map[y + 1][check_x] == 0)	//�ɸ��Ͱ� �� �濡 ���� �ִ��� ������ üũ ������ ���� ������ �Ȱ�
			{
				y++;
				gotoxy(x, y - 1);
				printf(" ");
				SetColor(CHARACTER_COLOR, 7);
				gotoxy(x, y);
				printf("��");
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
				printf("��");
				gotoxy(2, 47);
				printf("������: �ȳ��� ������~^^");
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
				printf("��ü: ������ �ٿ� �ϳ��Ԣ�");
				Sleep(1000);
				gotoxy(2, 47);
				printf("��ü: �� �鼺 ���� �帮���");
				Sleep(1000);
				gotoxy(2, 47);
				printf("��ü: �� õ�翩 �����ϼ��� ");
				Sleep(1000);
				gotoxy(2, 47);
				printf("��ü: ���� ���� ���� ���ɢ�");
				Sleep(1000);
				gotoxy(2, 47);
				printf("��ü: ��-���              ");
				Sleep(1000);
				gotoxy(2, 47);
				printf("���ļ�: (���� �����)");
				Sleep(3000);
				gotoxy(2, 47);
				printf("���ļ�: (�ٹ��ٹ�)Zzz..");
				Sleep(1000);
				gotoxy(2, 47);
				printf("��ü: �Ƹ�             ");
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

void character_pause_pos()			//�ɸ��� �ʱ���ġ �� �Ͻ����� ������ �ִ� ��ġ ����
{
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void p1_go()			//��1���� ��2�� �� �� ��ǥ
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 24;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p1_come()			//��2���� ��1�� �� �� ��ǥ
{
	gotoxy(x, y);
	printf(" ");
	x = 10;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p2_go()			//����� ������ �� �� ��ǥ
{
	gotoxy(12, 3);
	printf(" ");
	x = 158;
	y = 43;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p2_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 12;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p3_go_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 156;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p3_go_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 4;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p3_come_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 72;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p3_come_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 4;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p4_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 42;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p4_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 12;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p5_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 6;
	y = 46;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p5_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 6;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p6_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p6_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 32;
	y = 18;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p7_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p7_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 60;
	y = 29;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p7_come_c()		//ī���׸��� ���� ��ǥ
{
	gotoxy(x, y);
	printf(" ");
	x = 50;
	y = 24;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p7_go_c()		//ī���׸��ƿ��� ������ ������ ������ �� ��ǥ
{
	gotoxy(x, y);
	printf(" ");
	x = 46;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p8_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 64;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p8_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 13;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p9_go()
{
	gotoxy(x, y);
	printf(" ");
	x = 10;
	y = 15;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p9_come()
{
	gotoxy(x, y);
	printf(" ");
	x = 58;
	y = 4;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p10_go_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 23;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p10_come_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 8;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p10_go_l()
{
	gotoxy(x, y);
	printf(" ");
	x = 2;
	y = 22;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p10_come_r()
{
	gotoxy(x, y);
	printf(" ");
	x = 118;
	y = 8;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_go1()
{
	gotoxy(x, y);
	printf(" ");
	x = 30;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_go2()
{
	gotoxy(x, y);
	printf(" ");
	x = 80;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_go3()
{
	gotoxy(x, y);
	printf(" ");
	x = 136;
	y = 45;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_come1()
{
	gotoxy(x, y);
	printf(" ");
	x = 30;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_come2()
{
	gotoxy(x, y);
	printf(" ");
	x = 58;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void p11_come3()
{
	gotoxy(x, y);
	printf(" ");
	x = 90;
	y = 1;
	SetColor(CHARACTER_COLOR, 7);
	gotoxy(x, y);
	printf("��");
}

void map1_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(126, 1);
	printf("������ �Ա�");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("����: %d��", total_coin);
	gotoxy(123, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 21);
	printf("Q:����Ʈ ����");
	gotoxy(123, 22);
	printf("M:���� ����");
}

void map2_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(127, 1);
	printf("�� ���� ��");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("����: %d��", total_coin);
	gotoxy(123, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 21);
	printf("Q:����Ʈ ����");
	gotoxy(123, 22);
	printf("M:���� ����");
}

void map3_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(167, 1);
	printf("����� ��");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("���� ������ �ִ°�");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("����: %d��", total_coin);
	gotoxy(166, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("���۹�");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("��");
	gotoxy(163, 15);
	printf("��    �̵�     ��");
	gotoxy(170, 17);
	printf("��");
	gotoxy(163, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(163, 21);
	printf("Q:����Ʈ ����");
	gotoxy(163, 22);
	printf("M:���� ����");
}

void map4_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(166, 1);
	printf("�ϸ��� ��");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("���� ������ �ִ°�");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("����: %d��", total_coin);
	gotoxy(166, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("���۹�");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("��");
	gotoxy(163, 15);
	printf("��    �̵�     ��");
	gotoxy(170, 17);
	printf("��");
	gotoxy(163, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(163, 21);
	printf("Q:����Ʈ ����");
	gotoxy(163, 22);
	printf("M:���� ����");
}

void map5_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(168, 1);
	printf("�����");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("���� ������ �ִ°�");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(166, 5);
	printf("����: %d��", total_coin);
	gotoxy(166, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(166, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(166, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(166, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("���۹�");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("��");
	gotoxy(163, 15);
	printf("��    �̵�     ��");
	gotoxy(170, 17);
	printf("��");
	gotoxy(163, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(163, 21);
	printf("Q:����Ʈ ����");
	gotoxy(163, 22);
	printf("M:���� ����");
}

void map6_status()
{
	gotoxy(64, 0);
	printf("--------------------");
	gotoxy(69, 1);
	printf("������ ��");
	gotoxy(64, 2);
	printf("--------------------");
	gotoxy(65, 3);
	printf("���� ������ �ִ°�");
	gotoxy(64, 4);
	printf("--------------------");
	gotoxy(68, 5);
	printf("����: %d��", total_coin);
	gotoxy(68, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(68, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(68, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(68, 8);
		printf("    ");
	}
	gotoxy(64, 10);
	printf("--------------------");
	gotoxy(70, 11);
	printf("���۹�");
	gotoxy(64, 12);
	printf("--------------------");
	gotoxy(72, 13);
	printf("��");
	gotoxy(65, 15);
	printf("��    �̵�     ��");
	gotoxy(72, 17);
	printf("��");
	gotoxy(65, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(65, 21);
	printf("Q:����Ʈ ����");
	gotoxy(66, 22);
	printf("M:���� ����");
}

void map7_status()
{
	gotoxy(64, 0);
	printf("--------------------");
	gotoxy(69, 1);
	printf("������");
	gotoxy(64, 2);
	printf("--------------------");
	gotoxy(65, 3);
	printf("���� ������ �ִ°�");
	gotoxy(64, 4);
	printf("--------------------");
	gotoxy(68, 5);
	printf("����: %d��", total_coin);
	gotoxy(68, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(68, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(68, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(68, 8);
		printf("    ");
	}
	gotoxy(64, 10);
	printf("--------------------");
	gotoxy(70, 11);
	printf("���۹�");
	gotoxy(64, 12);
	printf("--------------------");
	gotoxy(72, 13);
	printf("��");
	gotoxy(65, 15);
	printf("��    �̵�     ��");
	gotoxy(72, 17);
	printf("��");
	gotoxy(65, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(65, 21);
	printf("Q:����Ʈ ����");
	gotoxy(66, 22);
	printf("M:���� ����");
}

void map8_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(127, 1);
	printf("���� ��ġ");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("����: %d��", total_coin);
	gotoxy(124, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 21);
	printf("Q:����Ʈ ����");
	gotoxy(123, 22);
	printf("M:���� ����");
}

void map9_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(125, 1);
	printf("�ΰ� Ȧ �Ա�");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("����: %d��", total_coin);
	gotoxy(124, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 18);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 19);
	printf("Q:����Ʈ ����");
	gotoxy(123, 20);
	printf("M:���� ����");
}

void map10_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(130, 1);
	printf("�Ĵ�");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(124, 5);
	printf("����: %d��", total_coin);
	gotoxy(124, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(124, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(124, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(124, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 21);
	printf("Q:����Ʈ ����");
	gotoxy(123, 22);
	printf("M:���� ����");
}

void map11_status()
{
	gotoxy(162, 0);
	printf("--------------------");
	gotoxy(167, 1);
	printf("�ΰ� Ȧ");
	gotoxy(162, 2);
	printf("--------------------");
	gotoxy(163, 3);
	printf("���� ������ �ִ°�");
	gotoxy(162, 4);
	printf("--------------------");
	gotoxy(168, 5);
	printf("����: %d��", total_coin);
	gotoxy(168, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(168, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(168, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(168, 8);
		printf("    ");
	}
	gotoxy(162, 10);
	printf("--------------------");
	gotoxy(168, 11);
	printf("���۹�");
	gotoxy(162, 12);
	printf("--------------------");
	gotoxy(170, 13);
	printf("��");
	gotoxy(163, 15);
	printf("��    �̵�     ��");
	gotoxy(170, 17);
	printf("��");
	gotoxy(163, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(163, 21);
	printf("Q:����Ʈ ����");
	gotoxy(163, 22);
	printf("M:���� ����");
}

void map12_status()
{
	gotoxy(122, 0);
	printf("--------------------");
	gotoxy(126, 1);
	printf("ī���׸���");
	gotoxy(122, 2);
	printf("--------------------");
	gotoxy(123, 3);
	printf("���� ������ �ִ°�");
	gotoxy(122, 4);
	printf("--------------------");
	gotoxy(123, 5);
	printf("����: %d��", total_coin);
	gotoxy(123, 6);
	printf("�ı�: %d��", food_ticket);
	if (student_card == 1)
	{
		gotoxy(123, 7);
		printf("�л���");
	}
	if (food == 1)
	{
		gotoxy(123, 8);
		printf("�߽�");
	}
	else
	{
		gotoxy(123, 8);
		printf("    ");
	}
	gotoxy(122, 10);
	printf("--------------------");
	gotoxy(128, 11);
	printf("���۹�");
	gotoxy(122, 12);
	printf("--------------------");
	gotoxy(130, 13);
	printf("��");
	gotoxy(123, 15);
	printf("��    �̵�     ��");
	gotoxy(130, 17);
	printf("��");
	gotoxy(123, 20);
	printf("Space bar:��ȭ�ɱ�");
	gotoxy(123, 21);
	printf("Q:����Ʈ ����");
	gotoxy(123, 22);
	printf("M:���� ����");
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
	system("mode con cols=124 lines=27");						//�ܼ�â ũ������
	fp = fopen("����ȭ��.txt", "r");	//����ȭ�� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
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
				printf("��");
				SetColor(0, 7);
			}
			if (map[i][j] == 8)
			{
				SetColor(4, 7);
				printf("��");
				SetColor(0, 7);
			}
			if (map[i][j] == 9)
			{
				SetColor(0, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
				printf("��");
			else if (map[i][j] == 3)
				printf("��");
			else if (map[i][j] == 4)
				printf("��");
			else if (map[i][j] == 5)
				printf("��");
			else if (map[i][j] == 6)
				printf("��");
			else if (map[i][j] == 7)
				printf("��");
		}
		Sleep(100);			//���⶧ �ּ� ó�� Ǯ��
		printf("\n");
	}
	fclose(fp);
}

void draw_map1()											//�б��Ա�
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");					//�ܼ�â ũ������
	fp = fopen("��1.txt", "r");	//��1 ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");			//��Ż
				SetColor(0, 7);
			}
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("��");			//����
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("  ");			//�ܵ��
				SetColor(0, 7);
			}
			else if (map[i][j] == 5)
				printf("��");				//�б��� ����
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
	system("mode con cols=142 lines=28");	//�ܼ�â ũ������
	fp = fopen("��2.txt", "r");	//��2 ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("  ");
				SetColor(0, 7);
			}            //�ܵ��
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("��");
				SetColor(0, 7);
			}			//���ε�
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
	system("mode con cols=182 lines=50");	//�ܼ�â ũ������
	fp = fopen("����� ��.txt", "r");		//����� �� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");			//��Ż
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("��");
				SetColor(0, 7);
			}			//���� ���
			else if (map[i][j] == 4)
			{
				SetColor(10, 7);
				printf("��");
				SetColor(0, 7);
			}			//����
			else if (map[i][j] == 5)
				printf("  ");			//ù��° ��� ��ȭ
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}			//��Ż
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("��");			//���Ǳ�
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
				printf("  ");			//Ŀ�õ� ��ȭ
			else if (map[i][j] == 9)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);
			}			//���� ���
			else if (map[i][j] == 10)
			{
				SetColor(14, 7);
				printf("��");
				SetColor(0, 7);
			}		//����

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
	system("mode con cols=182 lines=49");	//�ܼ�â ũ������
	fp = fopen("�ϸ��� ��.txt", "r");		//�ϸ��� �� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}		//��Ż
			else if (map[i][j] == 3)
			{
				SetColor(0, 10);
				printf("��");
				SetColor(0, 7);
			}//���
			else if (map[i][j] == 4)
			{
				SetColor(14, 7);
				printf("��");
				SetColor(0, 7);
			}		//����
			else if (map[i][j] == 6)
			{
				SetColor(0, 10);
				printf("  ");
				SetColor(0, 7);
			} //�ʷϻ� ���
			else if (map[i][j] == 7)
			{
				SetColor(0, 9);
				printf("  ");
				SetColor(0, 7);
			}		//����
			else if (map[i][j] == 8)
			{
				printf("��");
			}		//��ġ
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
	system("mode con cols=182 lines=30");	//�ܼ�â ũ������
	fp = fopen("�����.txt", "r");		//map_one ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 81; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}			//��Ż
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("��");
				SetColor(0, 7);
			}			//���
			else if (map[i][j] == 4)
				printf("��");			//3�г� ���� ��
			else if (map[i][j] == 5)
				printf("��");			//����� ��
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}

			else if (map[i][j] == 7)
				printf("��");			//å��
			else if (map[i][j] == 8)
				printf("  ");			//��ȭ
			else if (map[i][j] == 9)
				printf("��");			//������ å��
			else if (map[i][j] == 10)
				printf("��");			//������ ��
			else if (map[i][j] == 11)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 12)
			{
				SetColor(14, 7);
				printf("��");
				SetColor(0, 7);
			}		//����
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
	system("mode con cols=84 lines=50");	//�ܼ�â ũ������
	fp = fopen("������ ��.txt", "r");		//map_one ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < 32; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}		//��Ż
			else if (map[i][j] == 3)
			{
				SetColor(10, 7);
				printf("��");
				SetColor(0, 7);
			}		//����
			else if (map[i][j] == 4)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 5)
			{
				printf("��");
			}
			else if (map[i][j] == 6)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}	//����
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
	system("mode con cols=84 lines=50");	//�ܼ�â ũ������
	fp = fopen("������.txt", "r");		//������ ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < MAP_LEN_Y; i++)
	{
		for (j = 0; j < 32; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}			//��Ż
			else if (map[i][j] == 3)
			{
				SetColor(9, 7);
				printf("��");
				SetColor(0, 7);
			}			//���� ���
			else if (map[i][j] == 4)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);
			}			//���� ���
			else if (map[i][j] == 5)
			{
				SetColor(2, 7);
				printf("��");
				SetColor(0, 7);
			}			//�л���
			else if (map[i][j] == 6)
			{
				printf("��");			//������ �繫�� å��1
			}
			else if (map[i][j] == 7)
			{
				printf("��");			//������ �繫�� å��2
			}
			else if (map[i][j] == 8)
				printf("||");			//������ �繫�� ��
			else if (map[i][j] == 9)
				printf("||");			//���켮 ������ �繫�� ��
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
	system("mode con cols=142 lines=36");						//�ܼ�â ũ������
	fp = fopen("����.txt", "r");		//���� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 34; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");			//��
			else if (map[i][j] == 0)
				printf("  ");			//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");			//��Ż
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
			{
				SetColor(10, 7);
				printf("��");
				SetColor(0, 7);
			}			//����
			else if (map[i][j] == 4)
			{
				SetColor(0, 10);
				printf("  ");			//�ܵ��
				SetColor(0, 7);
			}
			else if (map[i][j] == 5) //��ġ
				printf("��");
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
	system("mode con cols=142 lines=21");	//�ܼ�â ũ������
	fp = fopen("�ΰ� Ȧ �Ա�.txt", "r");	//�ΰ� Ȧ �Ա� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("��");
			else if (map[i][j] == 4)
				printf("��");
			else if (map[i][j] == 5)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 6)
			{
				printf("��");
			}
			else if (map[i][j] == 7)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
			{
				SetColor(0, 0);
				printf("  ");			//���
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
	system("mode con cols=142 lines=28");	//�ܼ�â ũ������
	fp = fopen("�Ĵ�.txt", "r");	//�Ĵ� ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");				//��
			else if (map[i][j] == 0)
				printf("  ");				//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");				//��Ż
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("��");				//��Ź
			else if (map[i][j] == 4)
				printf("��");				//�ı� �Ǹű�
			else if (map[i][j] == 5)
				printf("��");				//�� ������
			else if (map[i][j] == 6)
			{
				SetColor(9, 7);
				printf("��");				//����
				SetColor(0, 7);
			}
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);				//����
			}
			else if (map[i][j] == 8)
				printf("||");
			else if (map[i][j] == 9)
				printf("��");
			else if (map[i][j] == 10)
			{
				SetColor(14, 7);
				printf("��");
				SetColor(0, 7);
			}		//����	
			else if (map[i][j] == 11)
				printf("��");
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
	system("mode con cols=182 lines=50");	//�ܼ�â ũ������
	fp = fopen("�ΰ� Ȧ.txt", "r");	//�ΰ� Ȧ ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 47; i++)
	{
		for (j = 0; j < MAP_LEN_X; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");				//��	
			else if (map[i][j] == 0)
				printf("  ");				//����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");				//��Ż1
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("��");				//�ΰ� Ȧ ����
			else if (map[i][j] == 4)
				printf("��");
			else if (map[i][j] == 5)
			{
				SetColor(9, 7);
				printf("��");				//����
				SetColor(0, 7);
			}
			else if (map[i][j] == 6)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);				//����
			}
			else if (map[i][j] == 7)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");				//��Ż2
				SetColor(0, 7);
			}
			else if (map[i][j] == 8)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");				//��Ż3
				SetColor(0, 7);
			}
			else if (map[i][j] == 9)
				printf("  ");				//�λ�

		}
		printf("\n");
	}
	fclose(fp);
}

void draw_map12()                                 //ī���׸���
{
	int i, j;
	FILE *fp;
	system("color 70");
	system("mode con cols=142 lines=28");               //�ܼ�â ũ������
	fp = fopen("ī���׸���.txt", "r");   //��1 ���ϰ��&�ҷ�����
	if (fp == NULL)
	{
		printf("����\n");
		return 1;
	}

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 61; j++)
		{
			fscanf(fp, "%d", &map[i][j]);
			if (map[i][j] == 1)
				printf("��");         //��
			else if (map[i][j] == 0)
				printf("  ");         //����
			else if (map[i][j] == 2)
			{
				SetColor(PORTAL_COLOR, 7);
				printf("��");         //��Ż
				SetColor(0, 7);
			}
			else if (map[i][j] == 3)
				printf("��");            //Ŀ��
			else if (map[i][j] == 4)
				printf("��");            //Ź��
			else if (map[i][j] == 5)
				printf("��");            //����
			else if (map[i][j] == 6)
			{
				SetColor(9, 7);
				printf("��");            //����
				SetColor(0, 7);
			}
			else if (map[i][j] == 7)
			{
				SetColor(12, 7);
				printf("��");
				SetColor(0, 7);            //����
			}
			else if (map[i][j] == 8)
			{
				SetColor(10, 4);
				printf("  ");
				SetColor(0, 7);   //�ֹ��ϴ� ��
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
	printf("��");
	gotoxy(68, 2);
	printf("��");
	gotoxy(2, 18);
	printf("��");
	gotoxy(68, 18);
	printf("��");
	gotoxy(4, 2);
	for (i = 0; i < 32; i++)
		printf("��");
	gotoxy(4, 18);
	for (i = 0; i < 32; i++)
		printf("��");
	for (i = 0; i < 15; i++)
	{
		gotoxy(2, i + 3);
		printf("��");
		printf("\n");
	}
	for (i = 0; i < 15; i++)
	{
		gotoxy(68, i + 3);
		printf("��");
		printf("\n");
	}
}

void draw_Quest()
{
	int i;

	system("mode con cols=50 lines=25");
	gotoxy(2, 2);
	printf("��");
	gotoxy(44, 2);
	printf("��");
	gotoxy(2, 23);
	printf("��");
	gotoxy(44, 23);
	printf("��");
	gotoxy(4, 2);
	for (i = 0; i < 20; i++)
		printf("��");
	gotoxy(4, 23);
	for (i = 0; i < 20; i++)
		printf("��");
	for (i = 0; i < 20; i++)
	{
		gotoxy(2, i + 3);
		printf("��");
		printf("\n");
	}
	for (i = 0; i < 20; i++)
	{
		gotoxy(44, i + 3);
		printf("��");
		printf("\n");
	}

	gotoxy(18, 4);
	printf("�� �� ���");
	if (Quest1 >= 1)
	{
		gotoxy(4, 8);
		printf("1. ���Ǳ⿡�� ����� �̾� ���ñ�");
		SetColor(2, 7);
		gotoxy(37, 8);
		printf("�Ϸ�");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 8);
		printf("1. ���Ǳ⿡�� ����� �̾� ���ñ�");
	}
	if (Quest2 >= 1)
	{
		gotoxy(4, 11);
		printf("2. �� �������� ���ô� ���� ���߱�");
		gotoxy(8, 12);
		printf("����: �л���");
		SetColor(2, 7);
		gotoxy(38, 11);
		printf("�Ϸ�");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 11);
		printf("2. �� �������� ���ô� ���� ���߱�");
		gotoxy(8, 12);
		printf("����: �л���");
	}
	if (Quest3 >= 1)
	{
		gotoxy(4, 14);
		printf("3. �ı� �̾Ƽ� ���� �Ա�");
		SetColor(2, 7);
		gotoxy(29, 14);
		printf("�Ϸ�");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 14);
		printf("3. �ı� �̾Ƽ� ���� �Ա�");
	}
	if (Quest4 >= 1)
	{
		gotoxy(4, 17);
		printf("4. �л����� ã�Ƽ� ä�� ���");
		SetColor(2, 7);
		gotoxy(33, 17);
		printf("�Ϸ�");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 17);
		printf("4. �л����� ã�Ƽ� ä�� ���");
	}
	if (Quest5 >= 1)
	{
		gotoxy(4, 20);
		printf("5. ī���Ϳ��� Ŀ�� �ֹ��� ���ñ�");
		SetColor(2, 7);
		gotoxy(37, 20);
		printf("�Ϸ�");
		SetColor(0, 7);
	}
	else
	{
		gotoxy(4, 20);
		printf("5. ī���Ϳ��� Ŀ�� �ֹ��� ���ñ�");
	}
}

void draw_Map()
{
	int i;

	system("mode con cols=50 lines=25");
	gotoxy(2, 2);
	printf("��");
	gotoxy(44, 2);
	printf("��");
	gotoxy(2, 23);
	printf("��");
	gotoxy(44, 23);
	printf("��");
	gotoxy(4, 2);
	for (i = 0; i < 20; i++)
		printf("��");
	gotoxy(4, 23);
	for (i = 0; i < 20; i++)
		printf("��");
	gotoxy(3, 6);
	for (i = 0; i < 20; i++)
		printf("��");
	for (i = 0; i < 20; i++)
	{
		gotoxy(2, i + 3);
		printf("��");
		printf("\n");
	}
	for (i = 0; i < 20; i++)
	{
		gotoxy(44, i + 3);
		printf("��");
		printf("\n");
	}

	gotoxy(22, 4);
	printf("����");

	gotoxy(22, 22);
	printf("�Ա�");

	gotoxy(23, 21);
	printf("��");

	gotoxy(20, 19);
	printf("�ΰ�����");

	gotoxy(15, 18);
	printf("��              ��");

	gotoxy(5, 16);
	printf("�����   �𸮾ư�              �ϸ���");

	gotoxy(7, 15);
	printf("��                       ��");

	gotoxy(5, 12);
	printf("������    ��     ����");

	gotoxy(7, 11);
	printf("��              ��");

	gotoxy(5, 9);
	printf("ī���׸���     �ΰ�Ȧ");
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
		printf("���õ�");

		y--;
		if (y <= 16)
		{
			gotoxy(11, num[0] + 1);
			printf("              ");
			gotoxy(11, num[0]);
			printf("�ѱ��������б�");
			num[0]--;
		}
		if (y <= 14)
		{
			gotoxy(8, num[1] + 1);
			printf("                     ");
			gotoxy(8, num[1]);
			printf("��ǻ�ͼ���Ʈ���� �а�");
			num[1]--;
		}
		if (y <= 12)
		{
			gotoxy(13, num[2] + 1);
			printf("           ");
			gotoxy(13, num[2]);
			printf("���ļ� ����");
			num[2]--;
		}
		if (y <= 10)
		{
			gotoxy(13, num[3] + 1);
			printf("            ");
			gotoxy(13, num[3]);
			printf("��� �Ѵ�.");
			num[3]--;
		}
		if (y <= 8)
		{
			gotoxy(0, num[4] + 1);
			printf("                                        ");
			gotoxy(0, num[4]);
			printf("������ �� ������ ������ �ļ� ���� �Դϴ�");
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
		printf("����.1 C �� ������ ����� �̸���?");
		gotoxy(10, 7);
		printf("1. ��߳� ��Ʈ�� ��Ʈ��");
		gotoxy(10, 9);
		printf("2. ���ȣ");
		gotoxy(10, 11);
		printf("3. ���Ͻ� ��ġ");

		choice = getch();

		if (choice == '1')
		{
			gotoxy(10, 13);
			printf("��!");
			Sleep(300);
			gotoxy(10, 13);
			printf("   ");
			continue;
		}
		else if (choice == '2')
		{
			gotoxy(10, 13);
			printf("���信 �������.");
			Sleep(300);
			gotoxy(10, 13);
			printf("                ");
			continue;

		}
		else if (choice == '3')
		{
			gotoxy(10, 13);
			printf("����!");
			Sleep(300);
			gotoxy(10, 13);
			printf("     ");
			Quiz_num = 2;
			break;
		}
		else
		{
			gotoxy(10, 13);
			printf("1~3�� �߿� ���ô�.^^");
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
		printf("����.2 ���� ������ ��� ����Ǵ°�?");
		gotoxy(10, 7);
		printf("1. �Լ� ����                       ");
		gotoxy(10, 9);
		printf("2. �Լ� �ܺ�");
		gotoxy(10, 11);
		printf("3. ���� �Լ� ");

		choice = getch();

		if (choice == '3')
		{
			gotoxy(10, 13);
			printf("��!");
			Sleep(300);
			gotoxy(10, 13);
			printf("   ");
			continue;
		}
		else if (choice == '1')
		{
			gotoxy(10, 13);
			printf("���信 �������.");
			Sleep(300);
			gotoxy(10, 13);
			printf("                ");
			continue;

		}
		else if (choice == '2')
		{
			gotoxy(10, 13);
			printf("����!");
			Sleep(300);
			gotoxy(10, 13);
			printf("     ");
			Quiz_num = 3;
			break;
		}
		else
		{
			gotoxy(10, 13);
			printf("1~3�� �߿� ���ô�.^^");
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
		printf("����.3 int a[2][2] = {1,2,3,4}���� a[1][1]�� �ʱⰪ��?");
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
			printf("��!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;
		}
		else if (choice == '2')
		{
			gotoxy(10, 15);
			printf("��!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;

		}
		else if (choice == '3')
		{
			gotoxy(10, 15);
			printf("��!");
			Sleep(300);
			gotoxy(10, 15);
			printf("   ");
			continue;
		}
		else if (choice == '4')
		{
			gotoxy(10, 15);
			printf("����!");
			Sleep(300);
			gotoxy(10, 15);
			printf("     ");
			end = 0;
			break;
		}
		else
		{
			gotoxy(10, 15);
			printf("1~4�� �߿� ���ô�.^^");
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
			printf("������: ���ȣ �̾���");
			num[0]--;
		}
		if (y <= 34)
		{
			gotoxy(14, num[1] + 1);
			printf("                  ");
			gotoxy(14, num[1]);
			printf("-������ �ֽ� �е�-");
			num[1]--;
		}
		if (y <= 32)
		{
			gotoxy(16, num[2] + 1);
			printf("             ");
			gotoxy(16, num[2]);
			printf("������ ������");
			num[2]--;
		}
		if (y <= 30)
		{
			gotoxy(16, num[3] + 1);
			printf("             ");
			gotoxy(16, num[3]);
			printf("������ �����");
			num[3]--;
		}
		if (y <= 28)
		{
			gotoxy(16, num[4] + 1);
			printf("             ");
			gotoxy(16, num[4]);
			printf("���켮 ������");
			num[4]--;
		}
		if (y <= 25)
		{
			gotoxy(19, num[5] + 1);
			printf("      ");
			gotoxy(19, num[5]);
			printf("-�ı�-");
			num[5]--;
		}
		if (y <= 22)
		{
			gotoxy(10, num[6] + 1);
			printf("                          ");
			gotoxy(10, num[6]);
			printf("�̹� ������Ʈ�� �����ϸ鼭");
			num[6]--;
		}
		if (y <= 20)
		{
			gotoxy(10, num[7] + 1);
			printf("                             ");
			gotoxy(10, num[7]);
			printf("�ּ��� �߿伺�� ������ ���ݰ�");
			num[7]--;
		}
		if (y <= 18)
		{
			gotoxy(6, num[8] + 1);
			printf("                                       ");
			gotoxy(6, num[8]);
			printf("����� �Ƿ��� ���� ���� ������ ���׿�^^");
			num[8]--;
		}
		if (y <= 16)
		{
			gotoxy(8, num[9] + 1);
			printf("                                   ");
			gotoxy(8, num[9]);
			printf("C���� ���� ������ ù��° ��ǰ�ε�");
			num[9]--;
		}
		if (y <= 14)
		{
			gotoxy(1, num[10] + 1);
			printf("                                                ");
			gotoxy(1, num[10]);
			printf("��ȸ���� ������ ��ȥ�� ���� �־���������ϴ٤���");
			num[10]--;
		}
		if (y <= 12)
		{
			gotoxy(12, num[11] + 1);
			printf("                           ");
			gotoxy(12, num[11]);
			printf("�÷��� ���ּż� �����մϴ�.");
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
	printf("�����Ͻ÷��� �ƹ�Ű�� ��������");
	getch();
	exit(0);
}