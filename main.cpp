#include <iostream>
#include <thread>

#define SIDE_LENGTH 3

using namespace std;

int matrix1[SIDE_LENGTH][SIDE_LENGTH], matrix2[SIDE_LENGTH][SIDE_LENGTH], result[SIDE_LENGTH][SIDE_LENGTH] = {0};

void valueAt(int row, char col) {
  for (int i = 0; i < SIDE_LENGTH; ++i) {
    result[row][col] += matrix1[row][i] * matrix2[i][col];
  }
}

int main(void) {
  thread threads[SIDE_LENGTH][SIDE_LENGTH];

  for (int i = 0; i < SIDE_LENGTH; i++) {
    for (int j = 0; j < SIDE_LENGTH; j++) {
      matrix1[i][j] = SIDE_LENGTH * i + j;
      matrix2[i][j] = SIDE_LENGTH - SIDE_LENGTH * i + j;
    }
  }

  for (int i = 0; i < SIDE_LENGTH; i++) {
    for (int j = 0; j < SIDE_LENGTH; j++) {
      threads[i][j] = thread(valueAt, i, j);
      threads[i][j].join();
    }
  }

  for (int i = 0; i < SIDE_LENGTH; i++) {
    cout << "| ";

    for (int j = 0; j < SIDE_LENGTH; j++) {
      cout << matrix1[i][j] << ' ';
    }

    cout << "|  " << (i == SIDE_LENGTH / 2 ? 'X' : ' ') << "  | ";

    for (int j = 0; j < SIDE_LENGTH; j++) {
      cout << matrix2[i][j] << ' ';
    }

    cout << "|  " << (i == SIDE_LENGTH / 2 ? '=' : ' ') << "  | ";

    for (int j = 0; j < SIDE_LENGTH; j++) {
      cout << result[i][j] << ' ';
    }

    cout << '|' << endl;
  }

  return 0;
}
