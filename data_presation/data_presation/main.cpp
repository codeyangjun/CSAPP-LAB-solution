#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
		printf("%p\t0x%.2x\n", start+i, start[i]);
	printf("\n");
}

int main()
{
    //cout << (233333 + 1) * (233333 + 1) << endl;
    //cout << (1e20 + -1e20) + 3.14 << endl;
    //cout << 1e20 + (-1e20 + 3.14) << endl;
    /*
    short int x = 15213;
    int ix = (int)x;
    cout << ix << endl;

    short int y = -15213;
    int iy = (int)y;
    cout << iy << endl;
    */

    int a = 1;//小端机
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));

    return 0;
}
