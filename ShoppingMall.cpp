#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingMall.h"



#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 100
#define FILENAME "products.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int stock; // 添加库存字段
} Product;


typedef struct {
    int productId;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS];
int productCount = 0;
CartItem cart[MAX_PRODUCTS]; // 购物车数组
int cartItemCount = 0;

// Function prototypes
//void addProduct();
//void deleteProduct();
//void updateProduct();
//void findProduct();
//void listProducts();
//void saveProducts();
//void loadProducts();
//void printError(const char* message);
//void addToCart(int productId, int quantity);
//void checkout();

//int main() {
//    loadProducts(); // Load products from file on startup
//
//    int choice;
//    do {
//        printf("\nStore Management System\n");
//        printf("1. Add Product\n");
//        printf("2. Delete Product\n");
//        printf("3. Update Product\n");
//        printf("4. Find Product\n");
//        printf("5. List Products\n");
//        printf("6. Add to Cart\n");
//        printf("7. Checkout\n");
//        printf("8. Exit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            addProduct();
//            break;
//        case 2:
//            deleteProduct();
//            break;
//        case 3:
//            updateProduct();
//            break;
//        case 4:
//            findProduct();
//            break;
//        case 5:
//            listProducts();
//            break;
//        case 6:
//            addToCart(-1, -1); // 参数将在函数内部获取
//            break;
//        case 7:
//            checkout();
//            break;
//        case 8:
//            printf("Exiting...\n");
//            break;
//        default:
//            printf("Invalid choice. Please try again.\n");
//        }
//    } while (choice != 8);
//
//    saveProducts(); // Save products to file on exit
//    return 0;
//}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printError("Product list is full.");
        return;
    }

    Product p;
    printf("Enter product ID: ");
    if (scanf("%d", &p.id) != 1) {
        printError("Invalid input for ID.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    printf("Enter product name: ");
    if (scanf("%99[^\n]", p.name) != 1) { // 支持多词名称输入
        printError("Invalid input for name.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    printf("Enter product price: ");
    if (scanf("%f", &p.price) != 1) {
        printError("Invalid input for price.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    printf("Enter product stock: ");
    if (scanf("%d", &p.stock) != 1) {
        printError("Invalid input for stock.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    products[productCount++] = p;
    printf("Product added successfully.\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printError("Invalid input for ID.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    printError("Product not found.");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    if (scanf("%d", &id) != 1) {
        printError("Invalid input for ID.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Enter new name: ");
            if (scanf("%99[^\n]", products[i].name) != 1) { // 支持多词名称输入
                printError("Invalid input for name.");
                return;
            }
            while (getchar() != '\n'); // Clear buffer

            printf("Enter new price: ");
            if (scanf("%f", &products[i].price) != 1) {
                printError("Invalid input for price.");
                return;
            }
            while (getchar() != '\n'); // Clear buffer

            printf("Enter new stock: ");
            if (scanf("%d", &products[i].stock) != 1) {
                printError("Invalid input for stock.");
                return;
            }
            while (getchar() != '\n'); // Clear buffer

            printf("Product updated successfully.\n");
            return;
        }
    }
    printError("Product not found.");
}

void findProduct() {
    int id;
    printf("Enter product ID to find: ");
    if (scanf("%d", &id) != 1) {
        printError("Invalid input for ID.");
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Product ID: %d, Name: %s, Price: %.2f, Stock: %d\n",
                products[i].id, products[i].name, products[i].price, products[i].stock);
            return;
        }
    }
    printError("Product not found.");
}

void listProducts() {
    if (productCount == 0) {
        printError("No products available.");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Stock: %d\n",
            products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void saveProducts() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printError("Error opening file for writing.");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %.2f %d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
    fclose(file);
    printf("Products saved to file.\n");
}

void loadProducts() {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        printError("No existing file found. Starting with an empty product list.");
        return;
    }
    while (fscanf(file, "%d %s %f %d", &products[productCount].id, products[productCount].name,
        &products[productCount].price, &products[productCount].stock) == 4) 
    {
        productCount++;
        if (productCount >= MAX_PRODUCTS) {
            break;
        }
    }
    fclose(file);
    printf("Products loaded from file.\n");
}

void printError(const char* message) {
    printf("Error: %s\n", message);
}

void addToCart(int productId, int quantity) {
    if (productId == -1) { // 如果参数为-1，则从用户输入获取
        printf("Enter product ID and quantity to add to cart: ");
        if (scanf("%d %d", &productId, &quantity) != 2 || quantity <= 0) {
            printError("Invalid input for product ID or quantity.");
            return;
        }
        while (getchar() != '\n'); // Clear buffer
    }

    for (int i = 0; i < productCount; ++i) {
        if (products[i].id == productId && products[i].stock >= quantity) {
            cart[cartItemCount].productId = productId;
            cart[cartItemCount].quantity = quantity;
            ++cartItemCount;
            printf("Added %d units of product %d to cart.\n", quantity, productId);
            return;
        }
    }
    printError("Product not found or insufficient stock.");
}

void checkout() {
    float total = 0;
    for (int i = 0; i < cartItemCount; ++i) {
        int productId = cart[i].productId;
        int quantity = cart[i].quantity;
        for (int j = 0; j < productCount; ++j) {
            if (products[j].id == productId) {
                total += products[j].price * quantity;
                products[j].stock -= quantity;
                printf("Paid %.2f for %d units of product %d.\n", products[j].price * quantity, quantity, productId);
                break;
            }
        }
    }
    if (cartItemCount > 0) {
        printf("Total payment: %.2f\n", total);
        cartItemCount = 0; // 清空购物车
        saveProducts(); // 更新文件中的库存信息
    }
    else {
        printf("Nothing in the cart.\n");
    }
}