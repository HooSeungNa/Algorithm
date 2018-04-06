#include <stdio.h>
#include <stdbool.h>


int board[11][11];          // existence of a queen at board (i,j)
int size;                   // size of the chess board
bool SUCCESS = true;
bool FAILURE = false;
int explore_row(int i);     // 재귀함수를 통해서 문제를 계산
bool is_safe(int i,int j);  // queen 을 놓을수 있는 자리인지 확인
void print_queen();         // queen 이 놓인 체스판을 출

int main( int argc, char *argv[] )
{
        int i, j;
        scanf("%d", &size);
        for (i = 0; i < size; i++)
                for (j = 0; j < size; j++)
                        board[i][j] = 0;
        if (explore_row(0) == SUCCESS) {
                clear_map();
                print_queen();
        } else {
                printf("Not possible\n");
        }
        return 0;
}
int explore_row(int i)             // explore row i for queen i
{
        int j;                     // column index
        if (i >= size)
                return SUCCESS;
        for (j = 0; j < size; j++) // backtracking을 이용한 유망성 검사
        {
                if (is_safe(i, j) == SUCCESS) {
                        board[i][j] = 1;
                        set_queen(i, j);
                        if (explore_row(i + 1) == SUCCESS) {
                                return SUCCESS;
                        } else {
                                delete_queen(i, j);
                                board[i][j] = 0;
                        }
                }
        }
        return FAILURE;
}
bool is_safe(int i, int j){         // queen 을 놓을수 있는 위치인지 확인
        if (board[i][j] == 0)
                return SUCCESS;
        else
                return false;
}
void set_queen(int i, int j){       // queen 을 board에 놓는 함수
        int n, m;
        for (n = i; n <= size; n++) {
                if (board[n][j] != 1)
                        board[n][j] -= 1;
        }
        for (n = i; n >= 0; n--) {
                if (board[n][j] != 1)
                        board[n][j] -= 1;
        }
        for (m = j; m <= size; m++) {
                if (board[i][m] != 1)
                        board[i][m] -= 1;
        }
        for (m = j; m >= 0; m--) {
                if (board[i][m] != 1)
                        board[i][m] -= 1;
        }
        n = i, m = j;
        while (n <= size && m <= size) {
                if (board[n][m] != 1)
                        board[n][m] -= 1;
                m++;
                n++;
        }
        n = i, m = j;
        while (n >= 0 && m >= 0) {
                if (board[n][m] != 1)
                        board[n][m] -= 1;
                m--;
                n--;
        }
        n = i, m = j;
        while (n >= 0 && m >= 0) {
                if (board[n][m] != 1)
                        board[n][m] -= 1;
                m++;
                n--;
        }
        n = i, m = j;
        while (n >= 0 && m >= 0 && n <= size && m <= size) {
                if (board[n][m] != 1)
                        board[n][m] -= 1;
                m--;
                n++;
        }
}
void delete_queen(int i, int j){    // queen 을 board에서 지우는 함수
        int n, m;
        for (n = i; n <= size; n++) {
                if (board[n][j] != 1 && board[n][j] == 0)
                        board[n][j] = 0;
                else if (board[n][j] != 1 && board[n][j] != 0)
                        board[n][j] += 1;
        }
        for (n = i; n >= 0; n--) {
                if (board[n][j] != 1 && board[n][j] == 0)
                        board[n][j] = 0;
                else if (board[n][j] != 1 && board[n][j] != 0)
                        board[n][j] += 1;
        }
        n = i;
        for (m = j; m <= size; m++) {
                if (board[i][m] != 1 && board[i][m] == 0)
                        board[i][m] = 0;
                else if (board[i][m] != 1 && board[i][m] != 0)
                        board[i][m] += 1;
        }
        n = i;
        for (m = j; m >= 0; m--) {
                if (board[i][m] != 1 && board[i][m] == 0)
                        board[i][m] = 0;
                else if (board[i][m] != 1 && board[i][m] != 0)
                        board[i][m] += 1;
        }
        n = i,m = j;
        while (n <= size && m <= size) {
                if (board[n][m] != 1 && board[n][m] == 0)
                        board[n][m] = 0;
                else if (board[n][m] != 1 && board[n][m] != 0)
                        board[n][m] += 1;
                m++;
                n++;
        }
        n=i, m=j;
        while (n >= 0 && m >= 0) {
                if (board[n][m] != 1 && board[n][m] == 0)
                        board[n][m] = 0;
                else if (board[n][m] != 1 && board[n][m] != 0)
                        board[n][m] += 1;
                m--;
                n--;
        }
        n = i, m = j;
        while (n >= 0 && m >= 0 && n <= size && m <= size){
                if (board[n][m] != 1 && board[n][m] == 0)
                        board[n][m] = 0;
                else if (board[n][m] != 1 && board[n][m] != 0)
                        board[n][m] += 1;
                m--;
                n++;
        }
        n = i, m = j;
        while (n >= 0 && m >= 0) {
                if (board[n][m] != 1 && board[n][m] == 0)
                        board[n][m] = 0;
                else if (board[n][m] != 1 && board[n][m] != 0)
                        board[n][m] += 1;
                m++;
                n--;
        }
}

void print_queen(){                 // board 를 출력하는 함수
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("%d ", board[i][j]);
                }
                printf("\n");
        }

}
void clear_map(){                   // 1을 제외한 나머지 수를 0으로 만드는 함수
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        if (board[i][j] != 1)
                                board[i][j] = 0;

                }
        }
}
