#include <iostream>
#include <algorithm>

using namespace std;

int lps(string & s, int size_s)
{
	int mat[size_s][size_s];

	// strings de tamanho 1 são palíndromos de tamanho 1
	for(int i = 0; i < size_s; i++)
		mat[i][i] = 1;

	int tam = 2;

	while(tam <= size_s)
	{
		for(int i = 0, j = tam - 1 + i; j < size_s; i++, j++)
		{
			if(s[i] == s[j] && tam == 2)
				mat[i][j] = 2;
			else if(s[i] != s[j])
				mat[i][j] = max(mat[i][j - 1], mat[i + 1][j]);
			else
				mat[i][j] = mat[i + 1][j - 1] + 2;
		}
		tam++;
	}

	return mat[0][size_s - 1];
}

int main(int argc, char *argv[])
{
	string s("ATCATA");

	cout << lps(s, s.size()) << endl;

	return 0;
}
