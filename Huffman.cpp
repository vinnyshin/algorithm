//2017029870_신호중

#include<cstdio>
#include<cstdlib>
#include <iostream>
#include<math.h>


using namespace std;
#define MAX_TREE_HT 100 

int sum;

struct MinHeapNode { 
    char* data; 
    unsigned freq; 
    struct MinHeapNode *left, *right; 
}; 
  
struct MinHeap { 
  
    unsigned size; 
    unsigned capacity; 
    struct MinHeapNode** array; 
}; 
  
struct MinHeapNode* newNode(char* data, unsigned freq) 
{ 
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
  
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
  
    return temp; 
} 
  
struct MinHeap* createMinHeap(unsigned capacity) 
{ 
  
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(minHeap-> capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 
 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]-> freq < minHeap->array[smallest]->freq) 
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]-> freq < minHeap->array[smallest]->freq) 
        smallest = right;
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
} 

int isSizeOne(struct MinHeap* minHeap) 
{ 
    return (minHeap->size == 1); 
} 
  
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
  
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
    --minHeap->size; 
    minHeapify(minHeap, 0);
    return temp; 
} 

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) 
{ 
    ++minHeap->size; 
    int i = minHeap->size - 1; 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
    minHeap->array[i] = minHeapNode; 
} 

void buildMinHeap(struct MinHeap* minHeap)  
{ 
    int n = minHeap->size - 1; 
    int i; 
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
} 
   
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
} 
  

int isLeaf(struct MinHeapNode* root) 
{ 
    return !(root->left) && !(root->right); 
} 
  
struct MinHeap* createAndBuildMinHeap(char** data, int freq[], int size) 
{ 
    struct MinHeap* minHeap = createMinHeap(size); 
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
    minHeap->size = size; 
    buildMinHeap(minHeap); 
    return minHeap; 
} 

struct MinHeapNode* buildHuffmanTree(char** data, int freq[], int size) 
{ 
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
  
    // Iterate while size of heap doesn't become 1 
    while (!isSizeOne(minHeap)) { 
  
        // Step 2: Extract the two minimum 
        // freq items from min heap 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
  
        // Step 3:  Create a new internal 
        // node with frequency equal to the 
        // sum of the two nodes frequencies. 
        // Make the two extracted node as 
        // left and right children of this new node. 
        // Add this node to the min heap 
        // '$' is a special value for internal nodes, not used 
        top = newNode("$", left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        insertMinHeap(minHeap, top); 
    } 
  
    // Step 4: The remaining node is the 
    // root node and the tree is complete. 
    return extractMin(minHeap); 
} 
  
// Prints huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 
void printCodes(struct MinHeapNode* root, int arr[], int top) 
  
{ 
  
    // Assign 0 to left edge and recur 
    if (root->left) { 
  
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1); 
    } 
  
    // Assign 1 to right edge and recur 
    if (root->right) { 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    } 
  
    // If this is a leaf node, then 
    // it contains one of the input 
    // characters, print the character 
    // and its code from arr[] 
    if (isLeaf(root)) { 
        sum += root->freq * top;
    } 
} 
  
void HuffmanCodes(char** data, int freq[], int size) 
  
{ 
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
    int arr[MAX_TREE_HT], top = 0; 
    printCodes(root, arr, top); 
} 


int
main(){
    int num;
    int totalNum;

    scanf("%d", &num);
    if(num < 1 || num > 30000){
        return -1;
    }
    
    char ** literals = (char**)malloc(sizeof(char*)*num);

    for(int i = 0; i < num; ++i){
        literals[i] = (char*)malloc(sizeof(char) * 4);
    }

    int* numOfliterals = (int*)malloc(sizeof(int)*num);

    for(int i = 0; i < num; ++i) {
        char temp;
        for(int j = 0; j < 4; ++j) {
            scanf(" %c ", &literals[i][j]);
        }
        scanf("%d", &numOfliterals[i]);
    }
    
    scanf("%d", &totalNum);

    int radix;

    for(int i = 0; i < num; ++i){
        if(pow(2, i) > num){
            radix = i;
            break;
        }
    }

    printf("%d\n", radix*totalNum);

    HuffmanCodes(literals, numOfliterals, num);
    printf("%d", sum);
}

