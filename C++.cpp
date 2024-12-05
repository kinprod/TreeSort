#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>
#include "C++.h"

using namespace std;

struct treeNode {
public:
	int field;
	struct treeNode* left;
	struct treeNode* right;
};

vector<int> sortArray(treeNode* tree, vector<int>* array) {
	if (tree != NULL) {
		sortArray(tree->left, array);
		array->push_back(tree->field);
		sortArray(tree->right, array);
	}
	return *array;
}

struct treeNode* addNode(int x, treeNode* tree) {
	if (tree == NULL) {
		tree = new treeNode;
		tree->field = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (x < tree->field) {
			tree->left = addNode(x, tree->left);
		}
		else {
			tree->right = addNode(x, tree->right);
		}
	}
	return tree;
}

int main()
{
	setlocale(0, "");

	vector<int> userArray;
	int count;

	cout << "Сколько чисел вывести?" << endl;
	cin >> count;

	for (int i = 0; i < count; i++) {
		int x;
		cin >> x;
		userArray.push_back(x);
	}

	struct treeNode* tree = 0;
	for (int i : userArray) {
		tree = addNode(i, tree);
	}

	vector<int>* zero = new vector<int>;
	vector<int> answer = sortArray(tree, zero);

	for (int i : answer) {
		cout << i << " ";
	}
}