#include <stdio.h>
#include <stdlib.h>

//struct Node{
//	int key;
//	struct Node* next;
//	struct Node* prev;
//};
//
//void insert(struct Node* L, struct Node* x) {
//	x->next = L;
//	if (L != NULL) {
//		L->prev = x;
//	 }
//	L = x;
//	x->prev = NULL;
//}
//
//void listDelete(struct Node* L, struct Node* x) {
//	if (L->prev != NULL) {
//		x->prev->next = x->next;
//	}
//	else {
//		L = x->next;
//	}
//	if (x->next != NULL) {
//		x->next->prev = x->prev;
//	}
//}
//
//struct Node* listSearch(struct Node* L, int k) {
//	struct Node* x = L;
//	while (x != NULL && x->key != k) {
//		x = x->next;
//	}
//
//	return x;
//}

struct Node {
	int value;
	struct Node* next;
};

void insert(struct Node** head, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->value = data;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	//Find last node in the list
	struct Node* last = *head;
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

struct Node searchList(struct Node** head, int key) {
	struct Node* current = head;

	while (current != NULL) {
		if (current->value == key) {
			return *current;
		}
		current = current->next;
	}
}

void deleteNode(struct Node** head, int key) {
	//Make temp nodes
	struct Node* temp = *head;
	struct Node* prev = *head;

	//If the first element has the key, then delete that
	if (temp != NULL && temp->value == key) {
		head = temp->next;
		free(temp);
		return;
	}

	//Keep searching for the key
	while (temp != NULL && temp->value != key) {
		prev = temp;
		temp = temp->next;
	}

	//Check if we found the key or not
	if (temp == NULL) { return; }

	//Now we remove the node
	prev->next = temp->next;
	free(temp);
}

void mergeLists(struct Node** list1, struct Node** list2) {

	struct Node* last = *list1;
	//Find the last element in list1
	while (last->next != NULL) {
		last = last->next;
	}
	//Now that we found the last element, add the list2 node to the end
	last->next = *list2;
}

void insertSorted(struct Node** head, int value) {
	struct Node* temp = *head;

	//Run until we find the values between the value in the element
	while (temp != NULL && temp->next != NULL && !(temp->value <= value && value <= temp->next->value)) {
		temp = temp->next;
	}

	//Make the new node for the value
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;

	if (temp == NULL) {
		*head = newNode;
		return;
	}

	//Then put this new node between the temp and the next temp
	newNode->next = temp->next;
	temp->next = newNode;
}

struct Node deleteQueue(struct Node** head) {
	struct Node* temp = *head;

	//If the first element is null, then dont try to remove it
	if (temp == NULL) {
		return *temp;
	}

	*head = temp->next;
	return *temp;
}

int main() {
	struct Node* list = NULL;
	
	insertSorted(&list, 4);
	insert(&list, 5);
	insert(&list, 6);
	insert(&list, 7);
	struct Node found = searchList(list, 6);
	
	struct Node* list2 = NULL;

	insert(&list2, 10);
	insert(&list2, 11);
	insert(&list2, 12);
	insert(&list2, 13);

	deleteNode(&list2, 12);

	mergeLists(&list, &list2);

	insertSorted(&list, 9);
	insertSorted(&list, 9);
	insertSorted(&list, 8);

	struct Node deletedNode = deleteQueue(&list);
	
	return 0;
}