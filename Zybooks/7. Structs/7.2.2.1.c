// Write a statement that calls the function IncreaseItemQty with parameters
// notebookInfo and addStock. Assign notebookInfo with the returned value.

#include <stdio.h>

typedef struct ProductInfo_struct {
  char itemName[50];
  int itemQty;
} ProductInfo;

ProductInfo IncreaseItemQty(ProductInfo productToStock, int increaseValue) {
  productToStock.itemQty = productToStock.itemQty + increaseValue;

  return productToStock;
}

int main(void) {
  ProductInfo notebookInfo;
  int addStock;

  scanf("%s", notebookInfo.itemName);
  scanf("%d", &notebookInfo.itemQty);
  scanf("%d", &addStock);

  /* Your code goes here */
  notebookInfo = IncreaseItemQty(notebookInfo, addStock);

  printf("Name: %s, stock: %d\n", notebookInfo.itemName, notebookInfo.itemQty);

  return 0;
}
