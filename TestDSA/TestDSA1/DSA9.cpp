#include <bits/stdc++.h>
using namespace std;

struct Item {
	int weight;
	int value;
	double averageValue;
};

bool compareItems(Item item1, Item item2) {
	return item1.averageValue > item2.averageValue;
}

int main() {
	int n, M;
	cin >> n >> M;
	
	vector<Item> items(n);
	for (int i=0; i<n; i++) {
		cin>> items[i].weight >> items[i].value;
		items[i].averageValue = (double) items[i].value / items[i].weight;
	}
	
	sort(items.begin(), items.end(), compareItems);
	 int totalValue = 0;
	 for (int i=0; i<n; i++) {
	 	if( M>=items[i].weight) {
	 		totalValue += items[i].value;
	 		M -= items[i].weight;
		 }
		 else {
		 	totalValue += M * items[i].averageValue;
		 	break;
		 }
	 }
	 
	 cout << totalValue << endl;
	 return 0;
}
