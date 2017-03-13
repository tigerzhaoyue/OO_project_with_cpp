#include <iostream>
#include "dma.h"
#include "lacksDMA.h"
#include "hasDMA.h"
int main()
{
	using std::cout;
	using std::endl;


	baseDMA shirt("Portablelly", 8);
	lacksDMA ballon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffaio Keys", 5);
	cout << "Displaying baseDMA object:" << endl;
	cout << shirt << endl;
	cout << "Displaying lacksDMA object:" << endl;
	cout << ballon << endl;
	cout << "Displaying hasDMA object:" << endl;
	cout << map << endl;


	//manipulate these objects:
	lacksDMA ballon2(ballon);	//	call copy func of lacksDMA
	cout << "Result of lacksDMA copy:" << endl;
	cout << ballon2 << endl;
	hasDMA map2;
	map2 = map;					//	call assign func of hasDMA
	cout << "Result of hasDMA assignment: " << endl;
	cout << map2 << endl;

	system("pause");
	return 0;

}