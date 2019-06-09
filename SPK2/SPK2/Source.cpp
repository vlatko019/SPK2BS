#include "BTree.h"
#include "Node.h"

int main() {
	BTree sapling;

	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) sapling.insert(i * 2 + 1);
		else if (i % 4 == 0) sapling.insert(i - 3);
		else if (i % 2 == 0) sapling.insert(-i + 3);
		else sapling.insert(-i * 2 - 1);
	}
	//Print tree elements
	sapling.traversal(sapling.root);

	std::cout << std::endl << sapling.deleteRightLeaves(sapling.root);

	return 0;
}