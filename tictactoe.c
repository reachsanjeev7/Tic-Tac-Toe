#include<stdio.h>
#include<stdlib.h>
char board[4][4] = {{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '} };

void board_print(void)
{
	printf("--------------\n");
	printf("| %c | %c | %c |\n", board[1][1], board[1][2], board[1][3]);
	printf(" --  --   --\n");
	printf("| %c | %c | %c |\n", board[2][1], board[2][2], board[2][3]);
	printf(" --  --   --\n");
	printf("| %c | %c | %c |\n", board[3][1], board[3][2], board[3][3]);
	printf("--------------\n");
}
int board_check(char turn)
{
	if (board[1][1] == turn && board[1][2] == turn && board[1][3] == turn)
		return 1;
	if (board[2][1] == turn && board[2][2] == turn && board[2][3] == turn)
		return 1;
	if (board[3][1] == turn && board[3][2] == turn && board[3][3] == turn)
		return 1;
	if (board[1][1] == turn && board[2][1] == turn && board[3][1] == turn)
		return 1;
	if (board[1][2] == turn && board[2][2] == turn && board[3][2] == turn)
		return 1;
	if (board[1][3] == turn && board[2][3] == turn && board[3][3] == turn)
		return 1;
	if (board[1][1] == turn && board[2][2] == turn && board[3][3] == turn)
		return 1;
	if (board[1][3] == turn && board[2][2] == turn && board[3][1] == turn)
		return 1;
}
int main(void)
{
	int i, row, column, result, count = 0;
	char turn;

	board_print();
	for (i = 1; i < 100; i++) {
		if (i%2 != 0) {
			turn = 'X';
			printf("X turn \nEnter row column\n");
			scanf("%d %d", &row, &column);
			if (row <= 0 || row > 3 || column <= 0 || column > 3 || board[row][column] != ' ') {
				printf("Wrong selection\n");
				continue;
			} else {
				board[row][column] = turn;
				count++;
				board_print();
			}
			result = board_check(turn);
			if (result == 1) {
				printf("%c wins..!!\n", turn);
				break;
			}
		} else {
			turn = 'O';
			printf("O turn \nEnter row and column\n");
			scanf("%d %d", &row, &column);
			if (row <= 0 || row > 3 || column <= 0 || column > 3 || board[row][column] != ' ') {
				printf("Wrong selection\n");
				continue;
			} else {
				board[row][column] = turn;
				board_print();
				count++;
			}
			result = board_check(turn);
			if (result == 1) {
				printf("%c wins..!!\n", turn);
				break;
			}
		}
		if (count == 9) {
			printf("no win no loss..!!\n");
			break;
		}
	}
}
