#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ilosc;
clock_t start, stop;
double czas;

void sortowanie_babelkowe(int* tab, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (tab[j] < tab[j - 1])
			{
				int bufor;
				bufor = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = bufor;
			}
		}
	}
}

int main()
{
	cout << "Porowaneni czasow sortowania v.1" << endl;

	cout << "Ile losowych liczb w tablicy: ";
	cin >> ilosc;

	//dynamiczna alokacja tablicy
	int* tablica;
	tablica = new int[ilosc];

	//inicjowanie generatora
	srand(time(NULL));

	//wczytywanie  liczb do tablicy
	for (int i = 0; i < ilosc; i++)
	{
		tablica[i] = rand() % 100000 + 1;
	}

	cout << "Przed posortowaniem: " << endl;
	for (int i = 0; i < ilosc; i++)
	{
		cout << tablica[i] << " ";
	}

	cout << endl << "Sortuje teraz babelkowo. Prosze czekac!" << endl;

	start = clock();
	sortowanie_babelkowe(tablica, ilosc);
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;

	cout << "Po posortowaniu: " << endl;
	for (int i = 0; i < ilosc; i++)
	{
		cout << tablica[i] << " ";
	}

	cout << endl << "Czas sortowania babelkowego: " << czas << " s" << endl;

	delete[] tablica;

	return 0;
}
