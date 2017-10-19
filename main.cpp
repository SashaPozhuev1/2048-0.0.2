#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

int main() {
	srand( time( 0 ) );
	cout << "j - turn down;\nk - turn up;\nh - turn left;\nl - turn right;\nq - exit\n\n\n";

	int chislo, znak, sum = 0;
	int stroka, stolbec, k;
	int count = 0;
	int matrix[ 4 ][ 4 ];
	bool prav = false;


	///////Задали и вывели матрицу:
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			znak = rand() % 2;
			if ( znak == 0 ) {
				chislo = rand() % 11;
				if ( chislo == 0 ) {
					matrix[ i ][ j ] = 4;
				}
				else {
					matrix[ i ][ j ] = 2;
				}

				cout << matrix[ i ][ j ] << "	";
			}
			else {
				matrix[ i ][ j ] = 0;
				cout << "*	";
			}
		}
		cout << "\n";
	}
	cout << "\n\n\n";

	char deistvie;
	cin >> deistvie;

	while ( deistvie != 'q' ) {
		///////Проверка матрицы:
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				if ( ( matrix[ i ][ j ] != 0 ) && ( matrix[ i ][ j + 1 ] != 0) && ( matrix[ i + 1 ][ j ] != 0 ) && ( matrix[ i + 1 ][ j + 1 ] != 0 ) ) {
					if ( ( matrix[ i ][ j ] != matrix[ i ][ j + 1 ] ) && ( matrix[ i ][ j ] != matrix[ i + 1 ][ j ] ) && ( matrix[ i ][ j + 1 ] != matrix[ i + 1 ][ j + 1 ] ) && ( matrix[ i + 1 ][ j ] != matrix[ i + 1 ][ j + 1 ] ) ) {
						count++;
					}
				}
			}
		}

		if ( count == 9 ) {
			break;
		}
		else {
			count = 0;
			///////обработка действия:
			switch ( deistvie ) {
			case 'j':
				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 3; i > 0; i-- ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = i - 1; e > -1; e-- ) {
								if ( matrix[ e ][ j ] != 0 ) {
									matrix[ i ][ j ] = matrix[ e ][ j ];
									matrix[ e ][ j ] = 0;
									prav = true; //проверка, был ли сдвиг матрицы
									break;
								}
							}
						}
					}
				}

				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 3; i > 0; i-- ) {
						if ( matrix[ i ][ j ] == matrix[ i - 1 ][ j ]) {
							matrix[ i ][ j ] *= 2;
							matrix[ i - 1 ][ j ] = 0;
							sum += matrix[ i ][ j ];
						}
					}
				}

				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 3; i > 0; i-- ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = i - 1; e > -1; e-- ) {
								if ( matrix[ e ][ j ] != 0 ) {
									matrix[ i ][ j ] = matrix[ e ][ j ];
									matrix[ e ][ j ] = 0;
									break;
								}
							}
						}
					}
				}

				break;


			case 'k':
				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 0; i < 3; i++ ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = i + 1; e < 4; e++ ) {
								if ( matrix[ e ][ j ] != 0 ) {
									matrix[ i ][ j ] = matrix[ e ][ j ];
									matrix[ e ][ j ] = 0;
									prav = true; //проверка, был ли сдвиг матрицы
									break;
								}
							}
						}
					}
				}

				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 0; i < 3; i++ ) {
						if ( matrix[ i ][ j ] == matrix[ i + 1 ][ j ] ) {
							matrix[ i ][ j ] *= 2;
							matrix[ i + 1 ][ j ] = 0;
							sum += matrix[ i ][ j ];
						}
					}
				}

				for ( int j = 0; j < 4; j++ ) {
					for ( int i = 0; i < 3; i++ ) {
						if ( matrix[i][j] == 0 ) {
							for ( int e = i + 1; e < 4; e++ ) {
								if ( matrix[ e ][ j ] != 0 ) {
									matrix[ i ][ j ] = matrix[ e ][ j ];
									matrix[ e ][ j ] = 0;
									break;
								}
							}
						}
					}
				}

				break;


			case 'h':
				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 3; j++ ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = j + 1; e < 4; e++ ) {
								if ( matrix[ i ][ e ] != 0 ) {
									matrix[ i ][ j ] = matrix[ i ][ e ];
									matrix[ i ][ e ] = 0;
									prav = true; //проверка, был ли сдвиг матрицы
									break;
								}
							}
						}
					}
				}

				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 3; j++ ) {
						if ( matrix[ i ][ j ] == matrix[ i ][ j + 1 ] ) {
							matrix[ i ][ j ] *= 2;
							matrix[ i ][ j + 1 ] = 0;
							sum += matrix[ i ][ j ];
						}
					}
				}

				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 0; j < 3; j++ ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = j + 1; e < 4; e++ ) {
								if ( matrix[ i ][ e ] != 0 ) {
									matrix[ i ][ j ] = matrix[ i ][ e ];
									matrix[ i ][ e ] = 0;
									break;
								}
							}
						}
					}
				}
				break;


			case 'l':
				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 3; j > 0; j-- ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = j - 1; e > -1; e-- ) {
								if ( matrix[ i ][ e ] != 0 ) {
									matrix[ i ][ j ] = matrix[ i ][ e ];
									matrix[ i ][ e ] = 0;
									prav = true; //проверка, был ли сдвиг матрицы
									break;
								}
							}
						}
					}
				}

				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 3; j > 0; j-- ) {
						if ( matrix[ i ][ j ] == matrix[ i ][ j - 1 ] ) {
							matrix[ i ][ j ] *= 2;
							matrix[ i ][ j - 1 ] = 0;
							sum += matrix[ i ][ j ];
						}
					}
				}

				for ( int i = 0; i < 4; i++ ) {
					for ( int j = 3; j > 0; j-- ) {
						if ( matrix[ i ][ j ] == 0 ) {
							for ( int e = j - 1; e > -1; e-- ) {
								if ( matrix[ i ][ e ] != 0 ) {
									matrix[ i ][ j ] = matrix[ i ][ e ];
									matrix[ i ][ e ] = 0;
									break;
								}
							}
						}
					}
				}
				break;


			default: break;
			}

			///////Добавление числа в матрицу:
			if ( prav == true ) {
				stroka = rand() % 4;
				stolbec = rand() % 4;
				while ( matrix[ stroka ][ stolbec ] != 0) {
					stroka = rand() % 4;
					stolbec = rand() % 4;
				}

				k = rand() % 11;

				if ( k == 0 ) {
					matrix[ stroka ][ stolbec ] = 4;
				}
				else {
					matrix[ stroka ][ stolbec ] = 2;
				}
			}
			prav = false;
			
			///////Вывод матрицы:
			for ( int i = 0; i < 4; i++ ) {
				for ( int j = 0; j < 4; j++ ) {
					if ( matrix[ i ][ j ] == 0 ) {
						cout << "*	";
					}
					else {
						cout << matrix[ i ][ j ] << "	";
					}
				}
				cout << "\n";
			}
		}

		cout << "\n\n\n";
		cin >> deistvie;
	}

	cout << "Your Score: " << sum;
	cin.get();
	cin.get();
	return 0;
}
